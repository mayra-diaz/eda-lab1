#pragma once

#include "SpatialBase.h"
#include <vector>

namespace utec {
namespace spatial {

template <typename type>
using vec = std::vector<type>;

using distance_t = double;

/**
 * BasicSpatial implementation
 */
template <typename Point>
class BasicSpatial : public SpatialBase<Point> {
 private:

 public:
  BasicSpatial() {};
  vec<Point> points;
  void insert(const Point& new_point) override { points.push_back(new_point); }

  // El punto de referencia no necesariamente es parte del dataset
  Point nearest_neighbor(const Point& reference) override {
    distance_t min_diff = DBL_MAX;
    Point min_point({0,0});
    for (auto p: points){
      auto d = reference.distance(p);
      if (d < min_diff) {
        min_diff = d;
        min_point = p;
      }
    }
    return min_point;
  }
};

}  // namespace spatial
}  // namespace utec
