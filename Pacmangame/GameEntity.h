#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <iostream>
#include <vector>
using namespace std;

// Base class for all game entities (Player, Enemy, etc.)
class GameEntity {
protected:
    int x, y;

public:
    GameEntity(int startX, int startY) : x(startX), y(startY) {}
    virtual void move(const vector<vector<char>>& maze) = 0; // Pure virtual function for movement
    int getX() const { return x; }
    int getY() const { return y; }
    void setPosition(int newX, int newY) { x = newX; y = newY; }
};

#endif
