// Standard (system) header files
#include <iostream>

// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

// Main program
int main() {
    int x,y;
    cout << "Reversi started." << endl << endl;
    cout << "Please enter the size (x,y) of the game:";
    cin >> x>>y;

    ReversiBoard board(x,y);
    ReversiConsoleView view(&board);

    board.initializeBoard();
    cout << "The initial state of the board:" << endl;
    view.print();

    bool player1Turn = true;
    int totalMoves = 0;

    while (totalMoves < x * y) {
        int a, b;
        char stone;
        FieldState currentPlayer = (player1Turn) ? FieldState::PLAYER1 : FieldState::PLAYER2;

        cout << "Player " << (player1Turn ? "1 (X)" : "2 (O)") << ", Please enter a position (x,y) and a stone character: ";
        cin >> a >> b >> stone;


        if (stone != 'X' && stone != 'O')
        {
            cout << "Invalid stone character. Please enter 'X' or 'O'." << endl;
            continue; // Skip this iteration of the loop if the character is invalid
        }


        if (board.makeMove(a - 1, b - 1, currentPlayer,stone))
        {
            totalMoves++;
            cout << "Updated board:" << endl;
            view.print();
            player1Turn = !player1Turn;
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }


    int scorePlayer1 = board.countPieces(FieldState::PLAYER1);
    int scorePlayer2 = board.countPieces(FieldState::PLAYER2);

    cout << "Game over!" << endl;
    cout << "Player 1 (X): " << scorePlayer1 << " points" << endl;
    cout << "Player 2 (O): " << scorePlayer2 << " points" << endl;

    if (scorePlayer1 > scorePlayer2)
    {
        cout << "Player 1 wins!" << endl;
    }
    else if (scorePlayer2 > scorePlayer1)
    {
        cout << "Player 2 wins!" << endl;
    }
    else
    {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
