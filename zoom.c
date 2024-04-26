#include <stdio.h>
#include <malloc.h>
#include "lib_ppm.h"
int main() {
    struct image_s data;
    struct image_s *image = &data;
    int r = read_ppm("C:\\Users\\joao.antoniazi\\CLionProjects\\PPM_Image_Upscaler_TDE\\lena.ppm", image);

    //Return if error reading PPM file
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
                    switch (k) {
                        case 0:
                            switch (l) {
                                case 0: //red
                                if (current_pixel.r >= 180){
                                    new_pixel.r = 255;
                                }else if(current_pixel.r >= 135 && current_pixel.r <= 179){
                                    new_pixel.r = 255;
                                }else if(current_pixel.r >= 75 && current_pixel.r <= 134){
                                    new_pixel.r = 0;
                                }else{
                                    new_pixel.r = 0;
                                }
                                    break;
                                case 1: //green
                                    if (current_pixel.g >= 180){
                                    new_pixel.g = 255;
                                }else if(current_pixel.g >= 135 && current_pixel.g <= 179){
                                    new_pixel.g = 255;
                                }else if(current_pixel.g >= 75 && current_pixel.g <= 134){
                                    new_pixel.g = 0;
                                }else{
                                    new_pixel.g = 0;
                                }
                                    break;
                                case 2: //blue
                                    if (current_pixel.b >= 180){
                                        new_pixel.b = 255;
                                    }else if(current_pixel.b >= 135 && current_pixel.b <= 179){
                                        new_pixel.b = 255;
                                    }else if(current_pixel.b >= 75 && current_pixel.b <= 134){
                                        new_pixel.b = 0;
                                    }else{
                                        new_pixel.b = 0;
                                    }
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case 1:
                            switch (l) {
                                case 0: //red
                                    if (current_pixel.r >= 180){
                                        new_pixel.r = 255;
                                    }else if(current_pixel.r >= 135 && current_pixel.r <= 179){
                                        new_pixel.r = 0;
                                    }else if(current_pixel.r >= 75 && current_pixel.r <= 134){
                                        new_pixel.r = 255;
                                    }else{
                                        new_pixel.r = 0;
                                    }
                                    break;
                                case 1: //green
                                    if (current_pixel.g >= 180){
                                        new_pixel.g = 255;
                                    }else if(current_pixel.g >= 135 && current_pixel.g <= 179){
                                        new_pixel.g = 0;
                                    }else if(current_pixel.g >= 75 && current_pixel.g <= 134){
                                        new_pixel.g = 255;
                                    }else{
                                        new_pixel.g = 0;
                                    }
                                    break;
                                case 2: //blue
                                    if (current_pixel.b >= 180){
                                        new_pixel.b = 255;
                                    }else if(current_pixel.b >= 135 && current_pixel.b <= 179){
                                        new_pixel.b = 0;
                                    }else if(current_pixel.b >= 75 && current_pixel.b <= 134){
                                        new_pixel.b = 255;
                                    }else{
                                        new_pixel.b = 0;
                                    }
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case 2:
                            switch (l) {
                                case 0: //
                                    if (current_pixel.r >= 180){
                                        new_pixel.r = 255;
                                    }else if(current_pixel.r >= 135 && current_pixel.r <= 179){
                                        new_pixel.r = 255;
                                    }else if(current_pixel.r >= 75 && current_pixel.r <= 134){
                                        new_pixel.r = 0;
                                    }else{
                                        new_pixel.r = 0;
                                    }
                                    break;
                                case 1: //green
                                    if (current_pixel.g >= 180){
                                    new_pixel.g = 255;
                                }else if(current_pixel.g >= 135 && current_pixel.g <= 179){
                                    new_pixel.g = 255;
                                }else if(current_pixel.g >= 75 && current_pixel.g <= 134){
                                    new_pixel.g = 0;
                                }else{
                                    new_pixel.g = 0;
                                }
                                    break;
                                case 2: //blue
                                    if (current_pixel.b >= 180){
                                        new_pixel.b = 255;
                                    }else if(current_pixel.b >= 135 && current_pixel.b <= 179){
                                        new_pixel.b = 255;
                                    }else if(current_pixel.b >= 75 && current_pixel.b <= 134){
                                        new_pixel.b = 0;
                                    }else{
                                        new_pixel.b = 0;
                                    }
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                    new_image.pix[(i*3+k) * new_image.width + (j*3+l)] = new_pixel;
                }
            }
        }
    }

    r = write_ppm("C:\\Users\\joao.antoniazi\\CLionProjects\\PPM_Image_Upscaler_TDE\\lena_new.ppm", &new_image);
    free_ppm(&new_image);
if (r != 0) {
        printf("Error writing PPM file\n");
        return -1;
    }
    return 0;
}