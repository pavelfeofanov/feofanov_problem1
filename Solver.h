#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "Point.h"

class Solver {
public:
    std::vector<int> two_opt(const std::vector<Point>& points);
    double calculate_tour_length(const std::vector<Point>& points, const std::vector<int>& tour);

private:
    double euclidean_distance(const Point& a, const Point& b);
};

#endif // SOLVER_H
