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
| 32   | 0.03000&mu;s      | 0.01100&mu;s   |
| 64   | 0.08000&mu;s      | 0.02600&mu;s   |
| 128  | 0.15000&mu;s      | 0.05400&mu;s   |
| 256  | 0.37000&mu;s      | 0.12300&mu;s   |
| 512  | 0.81000&mu;s      | 0.25000&mu;s   |
| 1024 | 1.73000&mu;s      | 0.56800&mu;s   |
| 2048 | 3.88000&mu;s      | 1.16100&mu;s   |

Compared to my [simple-fft](https://github.com/RafaelGCPP/simple-fft), it is easy to understand why one should use optimized libraries.

| N    | Floating Point | Fixed Point |
| ----:| --------------:| -----------:|
| 32   | 476.32&mu;s   | 87.18&mu;s  |
| 64   | 1110.21&mu;s  | 215.32&mu;s |
| 128  | 2529.58&mu;s  | 516.06&mu;s |
| 256  | 5666.06&mu;s  | 1203.62&mu;s |
| 512  | 12545.85&mu;s | 2754.44&mu;s |
| 1024 | 27511.37&mu;s | 6202.91&mu;s |
| 2048 | 59864.60&mu;s | 13799.99&mu;s |

