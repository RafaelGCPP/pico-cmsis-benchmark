# pico-cmsis-benchmark

This repository contains a benchmark for CMSIS-DSP FFT library running on the Raspberry Pi Pico.

## Installation

To run the benchmark, you'll need to have the following prerequisites:

- Raspberry Pi Pico board
- CMSIS-DSP library

Follow these steps to install and run the benchmark:

1. Clone this repository:

    ```shell
    git clone --recursive https://github.com/your-username/pico-cmsis-benchmark.git
    ```

2. Connect your Raspberry Pi Pico board to your computer.

3. Build and flash the benchmark code to your Raspberry Pi Pico using your preferred development environment.

    ```shell
    cd pico-cmsis-benchmark
    mkdir build
    cd build
    cmake ..
    make
    ```

## Usage

Once the benchmark code is flashed to your Raspberry Pi Pico, you can run the benchmark by following these steps:

1. Power on your Raspberry Pi Pico.

2. Open a serial terminal to view the benchmark results.

3. The benchmark will run and display the performance metrics on the serial terminal.
4. The tests will restart automatically after 10 seconds.

## Results 

The following table presents the benchmark results for a Raspberry Pi Pico running at 125MHz. It shows the time per transformation for fixed and floating-point operations at different numbers of data points (N).




| N    | Floating Point | Fixed Point |
| ----:| --------------:| -----------:|
| 32   |     308.39001&mu;s      |     104.19200&mu;s   |
| 64   |     707.64001&mu;s      |     246.43700&mu;s   |
| 128  |    1531.06006&mu;s      |     509.28000&mu;s   |
| 256  |    3537.73999&mu;s      |    1167.73206&mu;s   |
| 512  |    7919.04980&mu;s      |    2386.26904&mu;s   |
| 1024 |   16755.06055&mu;s      |    5492.20996&mu;s   |
| 2048 |   37605.87891&mu;s      |   11090.58496&mu;s   |

Compared to my [simple-fft](https://github.com/RafaelGCPP/simple-fft), not much difference can be noted

| N    | Floating Point | Fixed Point |
| ----:| --------------:| -----------:|
| 32   | 476.32&mu;s   | 87.18&mu;s  |
| 64   | 1110.21&mu;s  | 215.32&mu;s |
| 128  | 2529.58&mu;s  | 516.06&mu;s |
| 256  | 5666.06&mu;s  | 1203.62&mu;s |
| 512  | 12545.85&mu;s | 2754.44&mu;s |
| 1024 | 27511.37&mu;s | 6202.91&mu;s |
| 2048 | 59864.60&mu;s | 13799.99&mu;s |

