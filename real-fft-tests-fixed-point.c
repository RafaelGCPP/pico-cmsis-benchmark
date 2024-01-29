#include <dsp/transform_functions.h>
#include <dsp/support_functions.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "pico/rand.h"
#include "pico/stdlib.h"

void fft_benchmark_fixed_point()
{

    puts("-=-=-=-=-=-= Real FFT benchmark - fixed point =-=-=-=-=-=-");

    int l2n, n;
    long int data[2048];
    float fdata[2048];

    puts("Generating sample data.");
    for (int i = 0; i < 2048; i++)
    {
        fdata[i] = (float)(random() - 0x40000000) / 0x80000000l;
    }
    arm_float_to_q31(fdata, data, 2048);

    for (l2n = 5; l2n < 12; l2n++)
    {
        n = 1 << l2n;

        arm_rfft_instance_q31 fft_instance, ifft_instance;

        printf("%4d-points real-valued fixed-point FFT: ", n);

        arm_rfft_init_q31(&fft_instance, n, 0, 1);
        arm_rfft_init_q31(&ifft_instance, n, 0, 1);

        unsigned int start = time_us_32();
        for (int i = 0; i < 500; i++)
        {
            long int fft[2 * n];
            long int data_out[n];
            arm_rfft_q31(&fft_instance, data, fft);
            arm_rfft_q31(&ifft_instance, fft, data_out);
        }
        unsigned int elapsed = time_us_32() - start;
        printf("%12.5fus per transform\n", (float)elapsed / 1000);
    }
}

void print_rfft_fixed_point(long int *data, int n)
{
    float fdata[n * 2];
    arm_q31_to_float(data, fdata, n * 2);

    for (int i = 0; i < n; i++)
    {
        printf("%10.5f%+10.5fi\n", fdata[2 * i] * n, fdata[2 * i + 1] * n);
    }
}

void real_fft_test_fixed_point()
{
    puts("-=-=-=-=-=-= Real FFT test - fixed point =-=-=-=-=-=-");
    float fdata[32];
    for (int i = 0; i < 32; i++)
    {
        fdata[i] = ((float)i / 16.0 - 0.5) / 2.0;
    }
    long int data[32];
    arm_float_to_q31(fdata, data, 32);

    arm_rfft_instance_q31 instance;
    arm_rfft_init_q31(&instance, 32, 0, 1);

    long int fft[64];
    arm_rfft_q31(&instance, data, fft);
    puts("FFT:");
    print_rfft_fixed_point(fft, 32);

    arm_rfft_init_q31(&instance, 32, 1, 1);
    arm_rfft_q31(&instance, fft, data);
    puts("IFFT:");
    arm_q31_to_float(data, fdata, 32);
    for (int i = 0; i < 32; i++)
    {
        printf("%10.5f\n", fdata[i] * 32);
    }
}