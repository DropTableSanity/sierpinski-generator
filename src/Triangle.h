#include <tuple>
#include "Triangle.cpp"

class Triangle {

private:   
    int x1, x2, x3;
    int y1, y2, y3;
    int color;

public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    std::tuple<int, int, int, int, int, int> get_halfway_points();    

};
