# Rock Paper Scissors (C++)

A simple terminal-based Rock, Paper, Scissors game written in C++. The user plays against the computer, which selects a move at random.

## 🎮 How It Works

- The game prompts the user to enter a choice: 'r' for Rock, 'p' for Paper, or 's' for Scissors.
- The computer randomly selects its own move.
- The winner is determined using the standard rules:
  - Rock beats Scissors
  - Scissors beats Paper
  - Paper beats Rock
- The result is displayed after each round.

## 🛠️ Requirements

- C++11 or higher
- A C++ compiler such as `g++` or `clang++`

## 🚀 How to Compile and Run

### Compile

```bash
g++ -o rps rock_paper_scissors.cpp
