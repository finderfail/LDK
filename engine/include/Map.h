#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class Map {
public:
    Map();
    ~Map();
    bool load(const std::string& filename);
    char getTile(int x, int y) const;
    int getWidth() const;
    int getHeight() const;
private:
    std::vector<std::string> mapData_;
    int width_;
    int height_;
};

#endif