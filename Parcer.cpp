#include "Parser.h"
#include <fstream>

std::vector<Point> Parser::read_points(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Point> points;
    int n;
    file >> n;
    points.resize(n);

    for (int i = 0; i < n; ++i) {
        file >> points[i].x >> points[i].y;
    }

    return points;
}
