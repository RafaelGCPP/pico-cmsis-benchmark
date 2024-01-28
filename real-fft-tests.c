#include <dsp/transform_functions.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fft_benchmark()
{

    puts("-=-=-=-=-=-= Real FFT benchmark - floating point =-=-=-=-=-=-");

    int l2n, n;
    float data[2048];

    puts("Generating sample data.");
    for (int i = 0; i < 2048; i++)
    {
        data[i] = (float)(random() - 0x40000000) / 0x80000000l;
    }

    for (l2n = 5; l2n < 12; l2n++)
    {
        n = 1 << l2n;

        arm_rfft_fast_instance_f32 instance;

        printf("%4d-points real-valued fixed-point FFT: ", n);

        arm_rfft_fast_init_f32(&instance, n);

        unsigned int start = clock();
        for (int i = 0; i < 50; i++)
        {
            float fft[n];
            arm_rfft_fast_f32(&instance, data, fft, 0);
            arm_rfft_fast_f32(&instance, fft, data, 1);
        }
        unsigned int elapsed = clock() - start;
        printf("%12.5fus per transform\n", (float)elapsed / 100);
    }
}

void print_rfft(float *data, int n)
{
    printf("%10.5f%+10.5fi\n", data[0], 0.0);
    for (int i = 1; i < n / 2; i++)
    {
        printf("%10.5f%+10.5fi\n", data[2 * i], data[2 * i + 1]);
    }
    printf("%10.5f%+10.5fi\n", data[1], 0.0);
    for (int i = n / 2 - 1; i > 0; i--)
    {
        printf("%10.5f%+10.5fi\n", data[2 * i], -data[2 * i + 1]);
    }
}

void real_fft_test()
{
    puts("-=-=-=-=-=-= Real FFT test - floating point =-=-=-=-=-=-");
    float data[32];
    for (int i = 0; i < 32; i++)
    {
        data[i] = ((float)i / 16.0 - 0.5) / 2.0;
    }
    arm_rfft_fast_instance_f32 instance;
    arm_rfft_fast_init_f32(&instance, 32);
    float fft[32];
    arm_rfft_fast_f32(&instance, data, fft, 0);
    puts("FFT:");
    print_rfft(fft, 32);

    arm_rfft_fast_f32(&instance, fft, data, 1);
    puts("IFFT:");
    for (int i = 0; i < 32; i++)
    {
        printf("%10.5f\n", data[i]);
    }
}