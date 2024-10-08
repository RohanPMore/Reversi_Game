/*
 * ReversiConsoleView.cpp
 *
 *  Created on: 25-Oct-2023
 *      Author: ROHAN MORE
 */

#include "ReversiConsoleView.h"
#include <iostream>


ReversiConsoleView::ReversiConsoleView(ReversiBoard* board) : reversiBoard(board) {}


void ReversiConsoleView::print() {
    int sizeX = reversiBoard->getSizeX();
    int sizeY = reversiBoard->getSizeY();

    for (int y = 0; y <sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            FieldState state = reversiBoard->getFieldState(x, y);
            char symbol;

            switch (state) {
                case FieldState::PLAYER1:
                    symbol = 'X';
                    break;
                case FieldState::PLAYER2:
                    symbol = 'O';
                    break;
                default:
                    symbol = '.';
                    break;
            }

            std::cout << symbol << ' ';
        }
        std::cout << std::endl;
    }
}
