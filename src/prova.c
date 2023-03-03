#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 10000
#define BOUNDARY 2

int main() {
    int width = 800, height = 600; // image dimensions
    double xmin = -2.0, xmax = 1.0; // x-axis limits
    double ymin = -1.5, ymax = 1.5; // y-axis limits
    double dx = (xmax - xmin) / width; // pixel width
    double dy = (ymax - ymin) / height; // pixel height
    int max_color = 255; // maximum color value
    int pixels[height][width]; // array to store pixel colors

    // iterate over all pixels in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double cr = xmin + x * dx; // real part of c
            double ci = ymin + y * dy; // imaginary part of c
            double zr = 0.0, zi = 0.0; // real and imaginary parts of z
            int iterations = 0; // number of iterations

            // iterate the Mandelbrot set formula
            while (iterations < MAX_ITERATIONS && zr*zr + zi*zi < BOUNDARY*BOUNDARY) {
                double new_zr = zr*zr - zi*zi + cr;
                double new_zi = 2.0*zr*zi + ci;
                zr = new_zr;
                zi = new_zi;
                iterations++;
            }

            // map number of iterations to a color value
            int color = (int) round((double) max_color * iterations / MAX_ITERATIONS);

            // set the pixel color
            pixels[y][x] = color;
        }
    }

    // write the pixel data to a PPM image file
    FILE *fp;
    fp = fopen("mandelbrot.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n%d\n", width, height, max_color);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char rgb[3];
            rgb[0] = (unsigned char) pixels[y][x];
            rgb[1] = (unsigned char) pixels[y][x];
            rgb[2] = (unsigned char) pixels[y][x];
            fwrite(rgb, 1, 3, fp);
        }
    }
    fclose(fp);

    return 0;
}

