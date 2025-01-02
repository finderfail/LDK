#ifndef RAYCASTER_H
#define RAYCASTER_H

#include "../include/Screen.h"
#include "../include/Map.h"
#include "../include/Player.h"

#include <vector>

class Raycaster {
public:
    Raycaster(const Map& map, Screen& screen);
    void castRays(const Player& player);
    float getDistanceToWall(float playerX, float playerY, float angle) const;

private:
    const Map& map_;
    Screen& screen_;
    
    float calculateWallHeight(float distance) const;
    void drawVerticalLine(int x, int wallHeight, float distance) const; 

};

#endif