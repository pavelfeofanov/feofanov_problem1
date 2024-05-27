#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "Point.h"

class Parser {
public:
    std::vector<Point> read_points(const std::string& filename);
};

#endif // PARSER_H
