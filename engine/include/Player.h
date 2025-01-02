#ifndef PLAYER_H
#define PLAYER_H

struct Point2D {
    float x;
    float y;
};

struct Vector2D {
    float x;
    float y;
};


class Player {
public:
    Player(float x, float y, float direction);
    Point2D getPosition() const;
    Vector2D getDirection() const;
    void setPosition(float x, float y);
    void setDirection(float direction);
    void move(float distance);
    void rotate(float angle);


private:
    Point2D position_;
    Vector2D direction_;
};

#endif