#ifndef ENEMY_H
#define ENEMY_H

#include "GameEntity.h"
#include <cstdlib>

class Enemy : public GameEntity {
public:
    Enemy(int startX, int startY) : GameEntity(startX, startY) {}

    void move(const vector<vector<char>>& maze) override {
        int dx = rand() % 3 - 1; // -1, 0, or 1
        int dy = rand() % 3 - 1; // -1, 0, or 1
        int newX = x + dx;
        int newY = y + dy;

        // Ensure enemy doesn't move into walls
        if (maze[newY][newX] != '#') {
            x = newX;
            y = newY;
        }
    }
};

#endif
