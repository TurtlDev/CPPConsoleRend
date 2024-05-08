#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class canvas {
private:
    //width and height wont be changed once assinged a value
    const int width;//NUH UH
    const int height; 
    std::vector<std::vector<std::string>> grid;
public:
    bool initialized = false;
    int dims[2] = {2};

    canvas(int x, int y) : width(x), height(y) {
        //std::vector<std::vector<int>> grid;
        grid.resize(height);
        for(int y = 0; y < height; y++){
            grid[y].resize(width);
            for (int x = 0; x < width; x++) {
                grid[y][x] = "  ";
            }
            grid[y].push_back("\n");
        }
        
        
        
    }
    
    void setcord(int x, int y, int color){
        if (x >= width || y >= height){
            std::cout << "Improper cords";
            return;
        }
        std::cout << color;
        
    }

};


class obj {
private:
    float x;
    float y;
    std::vector<std::vector<std::vector<int>>> points;//{[(x,y),(connections),[(x,y),(connections)]])]}
    int color = 0;

public:
    obj(float x1, float y1, std::vector<std::vector<std::vector<int>>> points1) : x(x1), y(y1), points(points1) {}
    void DrawSelf(canvas canv){
        for (int i = 0; i < points.size(); i++){
            canv.setcord(std::round(points[i][0][0]+x), std::round(points[i][0][1]+y), color);
        }
    }
};

int main() {
    std::cout << "started" << "\n";
    canvas x(15,5);
    obj y(0,0,{{{0,0},{1,2}},{{2,2},{0,2}},{{2,0},{0,1}}});
    y.DrawSelf(x);
    return 0;
}
