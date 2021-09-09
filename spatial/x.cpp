#include "Point.h"
#include "BasicSpatial.hpp"
#include "Validator.h"
#include <iostream>

using namespace utec::spatial;
using data_t = int;
using point_t = Point<data_t, 2>;
template <typename T>
T genRandomNumber(T startRange, T endRange) {
  return startRange + (T)rand() / ((T)RAND_MAX / (T)(endRange - startRange));
}

int main(){
  Validator<point_t> validator;
  BasicSpatial<point_t> instancia;

  const std::size_t num_points = 10;
  const std::size_t min = 0, max = 1000;

  auto cmp = [](point_t a, point_t b) {
    const int x = 0, y = 1;
    return (a.get(x) < b.get(x)) ||
           ((a.get(x) == b.get(x)) && (a.get(y) < b.get(y)));
  };

  std::set<point_t, decltype(cmp)> points(cmp);

  for (std::size_t I = 0; I < num_points; I++)
    points.insert(point_t(
        {genRandomNumber<int>(min, max), genRandomNumber<int>(min, max)}));

  for (auto& p : points) {
    std::cout << p.get(0) << '-' << p.get(1) << '\n';
    validator.insert(p);
    instancia.insert(p);
  }

  std::cout << "\n Resultados: \n";
  auto reference_result = validator.nearest_neighbor(point_t({50, 50}));
  auto result = instancia.nearest_neighbor(point_t({50, 50}));
  std::cout << reference_result.get(0) << '-' << reference_result.get(1) << '\t' << result.get(0) << '-' << result.get(1) <<'\n';
}