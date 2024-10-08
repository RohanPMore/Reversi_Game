# Reversi Board Game

## Overview   
This project implements a simplified version of the board game Reversi (also known as Othello). The program simulates the game mechanics and provides a console-based user interface for gameplay.

The implementation consists of two main classes:

ReversiBoard: Represents the state of the Reversi board.  
ReversiConsoleView: Provides a console-based view of the board state.  
The goal is to build a functioning Reversi game, with proper handling of game rules, such as placing pieces, flipping opponent's pieces, and checking for valid moves.

## Task Description  
### Classes  
### ReversiBoard  

This class represents the game board and manages its state.
It uses an enumeration to represent the state of each board field (empty, player 1's piece, or player 2's piece).
It provides methods for:
Querying the state of any field.
Setting the state of a field (placing a piece).
Checking the validity of a move and updating the board accordingly (flipping opponent's pieces according to Reversi rules).

### ReversiConsoleView  

This class takes a pointer to an instance of ReversiBoard and prints the board state to the console.
The print() method displays the board in its current state.

### Main Function  
The main function contains a loop that:

Queries the user for the location to place the next piece. 
Validates the move and updates the board via the ReversiBoard class. 
Prints the updated board state using the ReversiConsoleView class. 