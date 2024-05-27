#include "Solver.h"
#include <cmath>
#include <algorithm>

double Solver::euclidean_distance(const Point& a, const Point& b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

double Solver::calculate_tour_length(const std::vector<Point>& points, const std::vector<int>& tour) {
    double length = 0.0;
    for (int i = 0; i < tour.size(); ++i) {
        int next_index = (i + 1) % tour.size();
        length += euclidean_distance(points[tour[i]], points[tour[next_index]]);
    }
    return length;
}

std::vector<int> Solver::two_opt(const std::vector<Point>& points) {
    int n = points.size();
    std::vector<int> tour(n);
    for (int i = 0; i < n; ++i) tour[i] = i; // Начальный тур

    bool improvement = true;
    while (improvement) {
        improvement = false;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 2; j < n + (i > 0); ++j) {
                int next_j = (j + 1) % n;
                double current_dist = euclidean_distance(points[tour[i]], points[tour[i+1]]) +
                                      euclidean_distance(points[tour[j]], points[tour[next_j]]);
                double new_dist = euclidean_distance(points[tour[i]], points[tour[j]]) +
                                  euclidean_distance(points[tour[i+1]], points[tour[next_j]]);
                if (new_dist < current_dist) {
                    std::reverse(tour.begin() + i + 1, tour.begin() + j + 1);
                    improvement = true;
                }
            }
        }
    }

    return tour;
}
