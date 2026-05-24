# Proiect TP
# 2048 - The Game

A recreation of the classic 2048 puzzle game, built in C using the [Raylib](https://www.raylib.com/) graphics library.

## About

The goal of the game is to slide numbered tiles on a 4x4 or larger grid and merge matching tiles to reach the **2048** tile. The game ends when no more moves are possible.

## Features

- Main menu screen with a Start button
- Arrow key controls to move tiles in all four directions
- Score tracker and high score display
- Game over screen that returns to the main menu after 5 seconds
- Tile colors that change based on their value (matching the original 2048 style)

## Controls

| Key | Action |
|-----|--------|
| `Arrow Keys` | Move tiles (Left / Right / Up / Down) |
| `Enter` | Start the game from the menu |
| Mouse click on START | Start the game from the menu |

## Project Structure

```
ProiectTP/
├── main.c      # Main game loop, menu and game state logic
├── extra.c     # Tile movement, grid drawing, and helper functions
├── extra.h     # Header file with function declarations and constants
└── Makefile    # Build instructions
```

## How to Build and Run

### Requirements

- GCC compiler
- [Raylib](https://www.raylib.com/) installed on your system

### Build

```bash
make
```

### Run

```bash
make all
```

### Clean

```bash
make clean
```

## Author

Developed as a college project using C and Raylib.
