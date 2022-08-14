#include "vector.h"
#include "color.h"
#include "ray.h"

#include <iostream>

Color ray_color(const Ray& r) {
    Vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*Color(1.0, 1.0, 1.0) + t*Color(0.5, 0.7, 1.0);
}

int main() {
    // image size 
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width  = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = Point3(0, 0, 0);
    auto horizontal = Point3(viewport_width, 0, 0);
    auto vertical = Point3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3(0, 0, focal_length);


    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; i++) {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            Ray r(origin, lower_left_corner + u * horizontal + v * vertical);
            /* Color color( */
            /*         double(i) / (image_width - 1), */
            /*         double(j) / (image_height - 1), */
            /*         0.25 */
            /*         ); */

            Color color = ray_color(r);
            write_color(std::cout, color);
        }
    }  
}

