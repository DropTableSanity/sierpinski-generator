class PPM {

private:
    std::string name;
    std::string type;
    int ** map;
    int width;
    int height;
    int max;
    
public:
    PPM(std::string name, std::string type, int width, int height, int max);
    void set_pixel(int x, int y, int color);
    void draw_line(int x1, int y1, int x2, int y2, int color);
    FILE* save_ppm(std::string name);

};
