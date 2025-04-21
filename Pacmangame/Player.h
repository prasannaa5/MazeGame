#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"

class Player : public GameEntity {
private:
    int score;
    int moves;

public:
    Player(int startX, int startY) : GameEntity(startX, startY), score(0), moves(0) {}

    void move(const vector<vector<char>>& maze) override {
        // This is a dummy function as player movement is handled elsewhere
    }

    void move(char direction, const vector<vector<char>>& maze) {
        int newX = x, newY = y;
        switch (direction) {
            case 'w': newY--; break; // Up
            case 's': newY++; break; // Down
            case 'a': newX--; break; // Left
            case 'd': newX++; break; // Right
        }

        // Check for collisions with walls
        if (maze[newY][newX] != '#') {
            x = newX;
            y = newY;
            moves++;
        }
    }

    void collectItem() { score += 10; }
    int getScore() const { return score; }
    int getMoves() const { return moves; }
};

#endif
