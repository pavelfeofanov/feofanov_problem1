#include <iostream>
#include <vector>
#include "Parser.h"
#include "Solver.h"

using namespace std;

int main() {
    string filename = "/Users/pavelfeofanov/Downloads/data/ks_4_0"; // путь к файлу
    Parser parser;
    vector<Point> points = parser.read_points(filename);

    Solver solver;
    vector<int> tour = solver.two_opt(points);
    double tour_length = solver.calculate_tour_length(points, tour);

    cout << "Tour length: " << tour_length << endl;
    for (int i : tour) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
