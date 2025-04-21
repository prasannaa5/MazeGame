# MazeGame
## Features
- **10x10 Maze Grid**: Walls (`#`), paths (` `), player (`P`), exit (`E`), collectibles (`*`), and enemies (`X`).
- **Player Movement**: Use `W`, `A`, `S`, `D` keys to move the player.
- **Score Tracking**: Collect items (`*`) to increase your score.
- **Enemies**: Avoid enemies (`X`). Collision ends the game.
- **Multiple Levels**: Reach `E` to progress to the next level.
- **File I/O**: Save and load maze layouts to/from a file.

## How to Play
1. Move the player with `W`, `A`, `S`, `D`.
2. Collect `*` to gain points.
3. Avoid `X` and reach `E` to complete the level.

## Compilation
To compile:
```bash
g++ main.cpp PacmanGame.cpp -o PacmanGame
```

To run:
```bash
./PacmanGame
```
