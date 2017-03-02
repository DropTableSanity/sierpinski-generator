#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
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
    map[y][x] = color;
    
}

void PPM :: draw_line(int x1, int y1, int x2, int y2, int color) {
    // determine whether or not the variables need to be flipped, to the slope
    // equation doesn't get all borked up
    if(x1 > x2) {
        std::swap(x2, x1);
        std::swap(y2, y1);

    }

    double m;
    if(x2 - x1 == 0) {
        m = (double) y2 - y1;

    } else {
        m = ((double) (y2 - y1)) / 
            ((double) (x2 - x1));  // determine slope of the line being drawn

    }
    
    if(y2 - y1 == 0) {
        m = 0;

    }

    cout << m << endl;

    double b = y1 - (m * x1);         // determine line constant

    for(double x = x1; x <= x2; x += .01) {
        int yToBeDrawn = (m * x) + b;
        set_pixel((int) x, yToBeDrawn, color);
    /*
        set_pixel((int) x + 1, yToBeDrawn, color);
        set_pixel((int) x - 1, yToBeDrawn, color);
        set_pixel((int) x, yToBeDrawn + 1, color);
        set_pixel((int) x, yToBeDrawn - 1, color);
    */

    }
    

}

void PPM :: draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    draw_line(x1, y1, x2, y2, color);
    draw_line(x1, y1, x3, y3, color);
    draw_line(x2, y2, x3, y3, color);
    
}

void PPM :: save_ppm() {
    ofstream output;
    output.open(this->name.c_str());
    output << this->type << '\n' << this->width << ' ' << this->height << '\n' << this->max << '\n';
    
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            int color = map[i][j];
            int r = ((color >> 4) & 0xFF) % this->max;
            int g = (color >> 2) & 0xFF % this->max;
            int b = (color) & 0xFF % this->max;
            
            output << r << ' ' << g << ' ' << b << '\n';

        }

    }

}
