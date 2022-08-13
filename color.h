#ifndef COLOR_H
#define COLOR_H

#include "vector.h"

#include <iostream>

void write_color(std::ostream &out, Color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.r()) << ' '
        << static_cast<int>(255.999 * pixel_color.g()) << ' '
        << static_cast<int>(255.999 * pixel_color.b()) << '\n';
}

#endif
