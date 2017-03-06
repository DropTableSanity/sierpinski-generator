#include "ppm.cpp"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    PPM * image = new PPM("test.ppm", "P3", 100, 100, 10);
    //image->draw_line(10, 10, 50, 50, 0xFFFFFF);
    image->draw_triangle(95, 10, 10, 10, 45, 45, 0xFFFFFF);
    image->save_ppm();
    return 0;


}
