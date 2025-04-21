#ifndef PACMANGAME_H
#define PACMANGAME_H

#include "Player.h"
#include "Enemy.h"
#include <fstream>
#include <conio.h>
#include <windows.h>

class PacmanGame {
private:
    vector<vector<char>> maze;
    Player player;
    vector<Enemy> enemies;
    int level;
    bool gameOver;

    void generateMaze();
    void placeCollectibles();
    void placeEnemies();
    void saveMazeToFile();
    void loadMazeFromFile();

public:
    PacmanGame();
    void displayMaze();
    void handleInput(char input);
    void updateGame();
    void run();
};

#endif
