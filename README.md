# PPM Image Zoom Enhancer
## Overview
This project is a university assignment for a Software Engineering bachelor’s degree. It entails developing a C program that performs zoom enhancement on images using sub-pixel resolution. Specifically, the program scales PPM (Portable Pixmap) images by a factor of three, adjusting the output image to show enhanced pixels made up purely of sub-pixels that are either red, green, blue, or black.

## Project Details
- Input: Color image in PPM format with 24-bit color depth.
- Output: Scaled image with a 3x zoom factor, utilizing a matrix of sub-pixels.
Functionality
For each pixel in the input image, the program generates a 3x3 matrix of sub-pixels based on the color intensity levels. This matrix is arranged to reflect the intensity and color as follows:

- Intensities 0-74: All sub-pixels are black.
- Intensities 75-134: The center sub-pixel is colored (R, G, or B) and the others are black.
- Intensities 135-179: The center sub-pixel is black and the two other sub-pixels are colored.
- Intensities 180-255: All sub-pixels are of the respective color.
## Context
This project is part of an assignment where students are expected to handle file I/O operations, manipulate image data at a binary level, and apply concepts of image processing using C programming.
