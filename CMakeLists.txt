cmake_minimum_required(VERSION 3.27)
project(PPM_Image_Upscaler_TDE C)

set(CMAKE_C_STANDARD 23)

add_executable(PPM_Image_Upscaler_TDE zoom.c
        lib_ppm.c)
