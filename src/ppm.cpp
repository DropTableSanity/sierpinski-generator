#include <string>
#include <stdlib.h>
#include "PPM.h"

using namespace std;

PPM :: PPM(std::string name, std::string type, int width, int height, int max) {
    this->name = name;
    this->type = type;
    this->width = width;
    this->height = height;
    this->max = max;
    
    // initialize map
    this->map = new int*[width];
    for(int i = 0; i < width; i++) this->map[i] = new int[height];
    
}

void PPM :: set_pixel(int x, int y, int color) {
    map[x][y] = color;
    
}

void PPM :: draw_line(int x1, int y1, int x2, int y2, int color) {
    
    
}

void PPM :: draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, bool fill) {
    draw_line(x1, y1, x2, y2, color);
    draw_line(x1, y1, x3, y3, color);
    draw_line(x2, y2, x3, y3, color);
    
}