#include "PPM.h"
#include "Triangle.h"
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    PPM * image = new PPM("test.ppm", "P3", 1000, 1000, 10);
    //image->draw_line(10, 10, 50, 50, 0xFFFFFF);
    
    double thing = sqrt(pow(900, 2) - pow(450, 2));
    Triangle * test;   
    test = new Triangle(10, 10, 910, 10, 460, (int) thing);
    image->draw_triangle(10, 10, 910, 10, 460, (int) thing, 0xFFFFFF);
    for(int j = 0; j < 10; j++) {
        
        double * points = test->get_halfway_points();
        for(int i = 0; i < 6; i++) cout << points[i] << endl;
        
        image->draw_triangle(points[0], points[1], points[2], points[3], points[4], points[5], 0xFFFFFF);
        
        test->~Triangle();
        new (&test) Triangle(points[0], points[1], points[2], points[3], points[4], points[5]);
    
    }

    image->save_ppm();

    return 0;


}
