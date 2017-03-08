#include "Triangle.h"

using namespace std;

Triangle :: Triangle(double x1, double y1, double x2, double y2, double x3, double y3) { 
    this->x1 = x1;
    this->x2 = x2;
    this->x3 = x3;
    this->y1 = y1;
    this->y2 = y2;
    this->y3 = y3;
    this->color = color;

}


double * Triangle :: get_halfway_points() {
    static double halfwayPoints[6] = {(x1 + x2) / 2, (y1 + y2) / 2,
                               (x1 + x3) / 2, (y1 + y3) / 2,
                               (x2 + x3) / 2, (y2 + y3) / 2};
    return halfwayPoints;

}


double Triangle :: get_side_length() {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

}
