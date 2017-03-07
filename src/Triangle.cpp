using namespace std;

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) { 
    this->x1 = x1;
    this->x2 = x2;
    this->x3 = x3;
    this->y1 = y1;
    this->y2 = y2;
    this->y3 = y3;i

}


std::tuple<double, double, 
           double, double, 
           double, double> Triangle::get_halfvay_points() {
    return std::make_tuple((x1 + x2) / 2, (y1 + y2) / 2,
                           (x1 + x3) / 2, (y1 + y3) / 2,
                           (x2 + x3) / 2, (y2 + y3) / 2)

}
