#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "tusb.h"
#include "hardware/vreg.h"
#include "benchmarks.h"

int main()
{
    // vreg_set_voltage(VREG_VOLTAGE_1_15);

    // set_sys_clock_khz(300000, false);
    stdio_init_all();

    while (!tud_cdc_connected())
    {
        sleep_ms(100);
    }
start:

    putchar(12); // FF - clears screen

    printf("Current clock speed: %6.2f MHz\n", (float)clock_get_hz(clk_sys) / 1000000);
    sleep_ms(2000);

    // cordic_test();
    // twiddle_test();
    // fix_twiddle_test();
    // complex_fft_test();
    real_fft_test();
    // complex_fft_test_fix();
    real_fft_test_fixed_point();

    fft_benchmark();
    fft_benchmark_fixed_point();

    puts("Testing restarts in 10 seconds.");
    sleep_ms(10000);

    goto start;

    return 0;
}
