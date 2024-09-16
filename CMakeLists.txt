# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/rafael/pico/pico-sdk")

#set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(pico-cmsis-benchmark C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(pico-cmsis-benchmark
   pico-cmsis-benchmark.c 
   real-fft-tests.c
   real-fft-tests-fixed-point.c

)

pico_set_program_name(pico-cmsis-benchmark "pico-cmsis-benchmark")
pico_set_program_version(pico-cmsis-benchmark "0.1")

pico_enable_stdio_uart(pico-cmsis-benchmark 0)
pico_enable_stdio_usb(pico-cmsis-benchmark 1)

# Add the standard library to the build
target_link_libraries(pico-cmsis-benchmark        
        pico_rand
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(pico-cmsis-benchmark PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
  ${CMAKE_CURRENT_LIST_DIR}/CMSIS/CMSIS/Core/Include
  ${CMAKE_CURRENT_LIST_DIR}/CMSIS-DSP/Include  
)
set(CMSISCORE ${PICO_SDK_PATH}/src/rp2_common/cmsis/stub/CMSIS/Core)
add_subdirectory(CMSIS-DSP/Source)

# Add any user requested libraries
target_link_libraries(pico-cmsis-benchmark 
        CMSISDSP
        )

pico_add_extra_outputs(pico-cmsis-benchmark)

