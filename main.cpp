#include "vector.h"
#include "color.h"

#include <iostream>

int main() {
    // image size 
    const int image_width  = 256;
    const int image_height = 256;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; i++) {
            Color color(
                    double(i) / (image_width - 1),
                    double(j) / (image_height - 1),
                    0.25
                    );

            write_color(std::cout, color);
        }
    }  
}

