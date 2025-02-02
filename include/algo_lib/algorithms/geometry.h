#pragma once

#include <math.h>
#include <iostream>
#include <vector>
#include "../constants.h"

struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
};
 
inline std::istream& operator >> (std::istream& is, point& a) {
    return is >> a.x >> a.y;
}
 
inline std::ostream& operator << (std::ostream& os, const point& a) {
    return os << a.x << " " << a.y;
}
 
inline point operator + (point& a, point& b) {
    return point(a.x + b.x, a.y + b.y);
}
 
inline point operator - (point& a, point& b) {
    return point(a.x - b.x, a.y - b.y);
}
 
inline double vector_product(const point& a, const point& b) {
    return a.x * b.y - b.x * a.y;
}
 
inline double scalar_product(const point& a, const point& b) {
    return a.x * b.x + a.y * b.y;
}
 
inline double len(const point& a) {
    return a.x * a.x + a.y * a.y;
}
 
inline double triangle_square(const point& a, const point& b) {
    return abs(vector_product(a, b) / (double)2);
}
 
inline double get_angle(const point& a, const point& b) {
    return atan2(
        vector_product(a, b),
        scalar_product(a, b)
    );
}
 
inline bool equal(const double& a, const double& b) {
    return abs(a - b) < eps;
}
 
inline bool compare_points_by_coords(const point& a, const point& b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
 
inline bool compare_points_by_vector_product(point& a, point& b) {
    if (vector_product(a, b) == 0) return len(a) < len(b);
    return vector_product(a, b) > 0;
}
 
std::vector<point> convex_hull(std::vector<point> p);