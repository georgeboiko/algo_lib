#include "geometry.h"
#include <algorithm>

std::vector<point> convex_hull(std::vector<point> p){
    point p0 = *min_element(p.begin(), p.end(), compare_points_by_coords);
    for (int i = 0; i < p.size(); ++i) p[i] = p[i] - p0;
    sort(p.begin(), p.end(), compare_points_by_vector_product);
    std::vector<point>st = { p[0], p[1] };
    for (int i = 2; i < p.size(); ++i) {
        while (st.size() >= 2 &&
            vector_product(p[i] - st[st.size() - 1], st[st.size() - 2] - st[st.size() - 1]) <= 0
        ) st.pop_back();
        st.push_back(p[i]);
    }
    for (point& i : st) i = i + p0;
    return st;
}