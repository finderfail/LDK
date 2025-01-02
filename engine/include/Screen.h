#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>

class Screen {
public:
    Screen(int width, int height);
    ~Screen();
    void clear();
    void draw();
    void setPixel(int x, int y, char c);
    int getWidth() const;
    int getHeight() const;

private:
    int width_;
    int height_;
    std::vector<char> buffer_;
};

#endif