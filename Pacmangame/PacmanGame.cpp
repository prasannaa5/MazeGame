#include "PacmanGame.h"
#include <ctime>  // Include this header for 'time()'.

PacmanGame::PacmanGame()
    : player(1, 1), level(1), gameOver(false) {
    srand(time(0));
    generateMaze();
    placeCollectibles();
    placeEnemies();
}

void PacmanGame::generateMaze() {
    maze = vector<vector<char>>(10, vector<char>(10, ' '));

    // Create walls
    for (int i = 0; i < 10; i++) {
        maze[0][i] = maze[9][i] = '#';
        maze[i][0] = maze[i][9] = '#';
    }

    // Random internal walls
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (rand() % 5 == 0) {
                maze[i][j] = '#';
            }
        }
    }

    // Place exit
    maze[8][8] = 'E'; // Exit
}

void PacmanGame::placeCollectibles() {
    for (int i = 0; i < 5; i++) {
        int x, y;
        do {
            x = rand() % 8 + 1;
            y = rand() % 8 + 1;
        } while (maze[y][x] != ' ');
        maze[y][x] = '*'; // Collectibles
    }
}

void PacmanGame::placeEnemies() {
    enemies.clear();
    for (int i = 0; i < 2; i++) {
        int x, y;
        do {
            x = rand() % 8 + 1;
            y = rand() % 8 + 1;
        } while (maze[y][x] != ' ');
        enemies.emplace_back(x, y);
    }
}

void PacmanGame::saveMazeToFile() {
    ofstream file("maze.txt");
    for (const auto& row : maze) {
        for (const char cell : row) {
            file << cell;
        }
        file << endl;
    }
    file.close();
}

void PacmanGame::loadMazeFromFile() {
    ifstream file("maze.txt");
    if (file.is_open()) {
        maze.clear();
        string line;
        while (getline(file, line)) {
            maze.emplace_back(line.begin(), line.end());
        }
        file.close();
    }
}

void PacmanGame::displayMaze() {
    system("cls");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == player.getY() && j == player.getX()) {
                cout << 'P'; // Player
            } else {
                bool isEnemy = false;
                for (const auto& enemy : enemies) {
                    if (enemy.getY() == i && enemy.getX() == j) {
                        cout << 'X'; // Enemy
                        isEnemy = true;
                        break;
                    }
                }
                if (!isEnemy) {
                    cout << maze[i][j];
                }
            }
        }
        cout << endl;
    }
    cout << "Score: " << player.getScore() << "  Moves: " << player.getMoves() << "  Level: " << level << endl;
}

void PacmanGame::handleInput(char input) {
    player.move(input, maze);
    if (maze[player.getY()][player.getX()] == '*') {
        player.collectItem();
        maze[player.getY()][player.getX()] = ' ';
    } else if (maze[player.getY()][player.getX()] == 'E') {
        cout << "Level Complete!" << endl;
        level++;
        generateMaze();
        placeCollectibles();
        placeEnemies();
    }
}

void PacmanGame::updateGame() {
    for (auto& enemy : enemies) {
        enemy.move(maze);
        if (enemy.getX() == player.getX() && enemy.getY() == player.getY()) {
            gameOver = true;
        }
    }
}


void PacmanGame::run() {
    while (!gameOver) {
        displayMaze();
        if (_kbhit()) {
            char input = _getch();
            handleInput(input);
        }
        updateGame();
        Sleep(200);
    }

    cout << "Game Over! Final Score: " << player.getScore() << endl;
}
