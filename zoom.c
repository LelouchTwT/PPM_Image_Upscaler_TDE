#include <stdio.h>
#include <malloc.h>
#include "lib_ppm.h"

unsigned char adjust_pixel_value(unsigned char pixel_value, int k) {
    if (pixel_value >= 180) {
        return 255;
    } else if (pixel_value >= 135 && pixel_value < 180) {
        return (k == 1) ? 0 : 255;
    } else if (pixel_value >= 75 && pixel_value < 135) {
        return (k == 1) ? 255 : 0;
    }
    return 0;
}

int main() {
    struct image_s data;
    struct image_s *image = &data;
    int r = read_ppm("./lena.ppm", image);

    if (r != 0) {
        printf("Error reading PPM file\n");
        return -1;
    }

    struct image_s new_image;
    new_image.width = image->width * 3;
    new_image.height = image->height * 3;
    new_image.pix = malloc(new_image.width * new_image.height * sizeof(struct pixel_s));

    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width; ++j) {
            struct pixel_s current_pixel = image->pix[i * image->width + j];
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    struct pixel_s new_pixel;
                    new_pixel.r = 0;
                    new_pixel.g = 0;
                    new_pixel.b = 0;

                    switch (l) {
                        case 0: //RED
                            new_pixel.r = adjust_pixel_value(current_pixel.r, k);
                            break;
                        case 1: //GREEN
                            new_pixel.g = adjust_pixel_value(current_pixel.g, k);
                            break;
                        case 2: //BLUE
                            new_pixel.b = adjust_pixel_value(current_pixel.b, k);
                            break;
                        default:
                            break;
                    }
                    new_image.pix[(i * 3 + k) * new_image.width + (j * 3 + l)] = new_pixel;
                }
            }
        }
    }

    r = write_ppm("./lena_new.ppm", &new_image);
    free_ppm(&new_image);
    if (r != 0) {
        printf("Error writing PPM file\n");
        return -1;
    }
    return 0;
}