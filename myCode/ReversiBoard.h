/*
 * ReversiBoard.h
 *
 *  Created on: 25-Oct-2023
 *      Author: ROHAN MORE
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_


// Enumeration to represent the state of a field on the Reversi board.
enum class FieldState { EMPTY, PLAYER1, PLAYER2 };

/**
 * @class ReversiBoard
 * @brief Representing the game board for Reversi and responsible for maintaining the state of the game board.
 */
class ReversiBoard {

private:

    int sizeX;	/**< Number of columns */
    int sizeY;	/**< Number of rows */

    FieldState** board;	/**< 2D array to represent the state of each field on the board. */

    /**
     * @brief Check if a move at coordinates (x, y) by the specified player is valid.
     * @param a The X-coordinate.
     * @param b The Y-coordinate.
     * @param player The player making the move (PLAYER1 or PLAYER2).
     * @return true if the move is valid according to Reversi rules.
     */
    bool isMoveValid(int a, int b, FieldState player);

    /**
     * @brief Flip the opponent's stones based on the rules of Reversi when a player makes a move.
     * @param a The X-coordinate.
     * @param b The Y-coordinate.
     * @param player The player making the move (PLAYER1 or PLAYER2).
     */
    void flipTiles(int a, int b, FieldState player);

public:
	/**
	 * @brief Constructor to create a Reversi board with dimensions.
	 * @param x The number of columns.
	 * @param y The number of rows.
	 */
    ReversiBoard(int sizeX, int sizeY);

    /**
     * @brief Destructor to clean up resources when the board is destroyed.
     */
    ~ReversiBoard();


    /**
     * @brief Get the size of the board in the X dimension (number of columns).
     * @return Returns the number of columns on the board.
     */
     int getSizeX();

    /**
     * @brief Get the size of the board in the Y dimension (number of rows).
     * @return Returns the number of rows on the board.
     */
     int getSizeY();


    /**
     * @brief Initialize the Reversi board with initial pieces to start the game.
     */
     void initializeBoard();

    /**
     * @brief Get the state of the field at coordinates (a, b) on the board.
     * @param a The X-coordinate.
     * @param b The Y-coordinate.
     * @return the state of the field (EMPTY, PLAYER1, or PLAYER2).
     */
    FieldState getFieldState(int a, int b);

    /**
     * @brief Make a move on the board by placing a stone of the specified player at (a, b).
     * @param a The X-coordinate.
     * @param b The Y-coordinate.
     * @param player The player making the move (PLAYER1 or PLAYER2).
     * @return true if the move is valid and was made, otherwise returns false.
     */
    bool makeMove(int a, int b, FieldState currentFieldState,char stone);

    /**
     * @brief Count the number of pieces of a specific player (PLAYER1 or PLAYER2) on the board.
     * @param player The player to count pieces for (PLAYER1 or PLAYER2).
     * @return the count of pieces belonging to the specified player.
     */
    int countPieces(FieldState player);
};


#endif /* REVERSIBOARD_H_ */
