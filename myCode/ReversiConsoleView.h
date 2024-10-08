/*
 * ReversiConsoleView.h
 *
 *  Created on: 25-Oct-2023
 *      Author: ROHAN MORE
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

/**
 * @class ReversiConsoleView
 * @brief Responsible for displaying the Reversi game board on the console.
 */
class ReversiConsoleView {
private:

	/**
	 * A pointer to the ReversiBoard instance associated with this ReversiConsoleView.
	 * It allows the view to access and display the current state of the game board.
	 */
    ReversiBoard* reversiBoard;

public:
    /**
     * @brief Constructor to create a ReversiConsoleView for a given ReversiBoard.
     * It accepts a pointer to a ReversiBoard as a parameter and
     * sets it as the board to be viewed.
     * @param board A pointer to the ReversiBoard to be viewed.
     */
    ReversiConsoleView(ReversiBoard* board);

    /**
     * @brief Print the current state of the ReversiBoard to the console.
     * This function iterates through the game board's fields, retrieves their state,
     * and prints the corresponding symbols ('X', 'O', or '.') to represent the
     * pieces on the board. It uses the console for displaying the game state.
     */
    void print();
};

#endif /* REVERSICONSOLEVIEW_H_ */

