# Tic-Tac-Toe Game (C++)

A simple, interactive command-line Tic-Tac-Toe game written in C++. This project demonstrates basic object-oriented programming concepts, including classes, encapsulation, and game logic.

## Features

- **Two-player mode:** Play as Player X or Player O.
- **Input validation:** Ensures players enter valid moves.
- **Dynamic board display:** The board updates after every move.
- **Win/draw detection:** Announces the winner or a draw at the end.
- **Clean code structure:** Uses `Player`, `Board`, and `TicTacToe` classes for clarity and maintainability.

## How to Compile and Run

1. **Clone or download this repository.**
2. **Open a terminal and navigate to the project directory.**
3. **Compile the code:**
   ```sh
   g++ tic_tac_toe.cpp -o tic_tac_toe
   ```
4. **Run the executable:**
   ```sh
   ./tic_tac_toe
   ```
   On Windows, use:
   ```sh
   tic_tac_toe.exe
   ```

## How to Play

- The game is played on a 3x3 grid.
- Players take turns entering the row and column (1-3) for their move.
- The board is displayed after each move.
- The first player to get three of their symbols in a row (horizontally, vertically, or diagonally) wins.
- If all cells are filled and there is no winner, the game ends in a draw.

## Example Gameplay

```
Welcome to Tic-Tac-Toe!
Round 1
-------------
|   |   |   | 
-------------
|   |   |   | 
-------------
|   |   |   | 
-------------
Player X (X), enter row (1-3) and column (1-3): 1 1
-------------
| X |   |   | 
-------------
|   |   |   | 
-------------
|   |   |   | 
-------------
Player O (O), enter row (1-3) and column (1-3): 2 2
...
Player X wins!
```

## File Structure

- `tic_tac_toe.cpp` — Main source code file containing all classes and the game logic.

## Code Structure Overview

- **Player class:** Represents a player, storing their symbol and name.
- **Board class:** Manages the 3x3 grid, move validation, win/draw detection, and board display.
- **TicTacToe class:** Controls the game loop, player turns, and overall flow.

## Requirements

- C++11 or later
- A C++ compiler (e.g., g++, clang++, MSVC)

## License

This project is open source and free to use for educational purposes.

---

Enjoy playing Tic-Tac-Toe in your terminal!