#include <tuple>
#include <cmath>

class Triangle {

private:   
    double x1, x2, x3;
    double y1, y2, y3;
    int color;

public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
    double *  get_halfway_points();    
    double get_side_length();

};
