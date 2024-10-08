/*
 * ReversiBoard.cpp
 *
 *  Created on: 25-Oct-2023
 *      Author: ROHAN MORE
 */

#include "ReversiBoard.h"
#include <iostream>

ReversiBoard::ReversiBoard(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY) {
    board = new FieldState*[sizeX];
    for (int i = 0; i < sizeX; i++)
    {
        board[i] = new FieldState[sizeY];
        for (int j = 0; j < sizeY; j++)
        {
            board[i][j] = FieldState::EMPTY;
        }
    }
}

ReversiBoard::~ReversiBoard() {
    for (int i = 0; i < sizeX; i++) {
        delete[] board[i];
    }
    delete[] board;
}


int ReversiBoard::getSizeX() {
    return sizeX;
}

int ReversiBoard::getSizeY() {
    return sizeY;
}


void ReversiBoard::initializeBoard() {
    if (sizeX < 4 || sizeY < 4) {
        std::cout << "Board size is too small to start the game." << std::endl;
        return;
    }

    int midX = sizeX / 2;
    int midY = sizeY / 2;

    // Initialize the center of the board with initial pieces
    board[midX - 1][midY - 1] = FieldState::PLAYER1;
    board[midX][midY] = FieldState::PLAYER1;
    board[midX - 1][midY] = FieldState::PLAYER2;
    board[midX][midY - 1] = FieldState::PLAYER2;
}


FieldState ReversiBoard::getFieldState(int a, int b) {
    if (a >= 0 && a < sizeX && b >= 0 && b < sizeY) {
        return board[a][b];
    }
    return FieldState::EMPTY;
}


bool ReversiBoard::makeMove(int a, int b, FieldState currentFieldState,char stone)
{
	FieldState player = (stone == 'X') ? FieldState::PLAYER1 : FieldState::PLAYER2;
    if (isMoveValid(a, b, player))
    {
        board[a][b] = player;
        flipTiles(a, b, player);
        return true;
    }
    return false;
}


bool ReversiBoard::isMoveValid(int a, int b, FieldState player)
{
	// Check if the chosen cell is within the bounds of the board.
	if (a < 0 || a >= sizeX || b < 0 || b >= sizeY || board[a][b] != FieldState::EMPTY)
	{
	    return false;
	}

    // Check in all eight directions for adjacent opponent pieces.
    FieldState opponent = (player == FieldState::PLAYER1) ? FieldState::PLAYER2 : FieldState::PLAYER1;

    // Initialize arrays to represent eight possible directions
    int directionsX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int directionsY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    bool validMove = false;

    for (int i = 0; i < 8; i++)
    {
        int currentX = a + directionsX[i];
        int currentY = b + directionsY[i];
        bool foundOpponent = false;
        bool validDirection = false;

        while (currentX >= 0 && currentX < sizeX && currentY >= 0 && currentY < sizeY)
        {
            if (board[currentX][currentY] == opponent)
            {
                foundOpponent = true;
            }
            else if (board[currentX][currentY] == player)
            {
                if (foundOpponent)
                {
                    validDirection = true;
                }
                break;
            }
            else
            {
                break;
            }
            currentX += directionsX[i];
            currentY += directionsY[i];
        }

        if (validDirection)
        {
            validMove = true;
            break;  // If a valid direction is found, the move is valid.
        }
    }

    return validMove;
}


int ReversiBoard::countPieces(FieldState player)
{
	int count = 0;
	for (int i = 0; i < sizeX; i++)
	{
	   for (int j = 0; j < sizeY; j++)
	   {
	     if (board[i][j] == player)
	     {
	        count++;
	     }
	   }
	}
	    return count;
}


void ReversiBoard::flipTiles(int a, int b, FieldState player)
{
    FieldState opponent = (player == FieldState::PLAYER1) ? FieldState::PLAYER2 : FieldState::PLAYER1;

    // Initialize arrays to represent eight possible directions
    int directionsX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int directionsY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int currentX = a + directionsX[i];
        int currentY = b + directionsY[i];
        bool foundOpponent = false;

        // Continue in the current direction until you reach an empty cell or a cell of the current player.
        while (currentX >= 0 && currentX < sizeX && currentY >= 0 && currentY < sizeY)
        {
            if (board[currentX][currentY] == opponent)
            {
                foundOpponent = true;
            }
            else if (board[currentX][currentY] == player)
            {
                if (foundOpponent)
                {
                    // Flip the opponent's tiles between the player's tiles in the current direction.
                    int flipX = a + directionsX[i];
                    int flipY = b + directionsY[i];
                    while (flipX != currentX || flipY != currentY)
                    {
                        board[flipX][flipY] = player;
                        flipX += directionsX[i];
                        flipY += directionsY[i];
                    }
                }
                break;
            }
            else
            {
                break;
            }
            currentX += directionsX[i];
            currentY += directionsY[i];
        }
    }
}

