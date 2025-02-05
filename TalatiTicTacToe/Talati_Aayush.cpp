#include <iostream>
#include <vector>
using namespace std;
class TicTacToe {
public:
    /* Constructor*/
    TicTacToe(){
        /* Initialize defaults here */
        player = 'X';
    }
    /* This is your game board*/

    vector<vector<char>> gameBoard
    {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
    };
    /* This prints your game board*/
    void printGameBoard()
    {
        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
    /* This method modifies the game board*/
    void modifyGameBoard(char player, int position)
    {
        /*write code to modify the game board here*/
        for (int i = 0; i < gameBoard.size(); i++) {
            for (int j = 0; j < gameBoard[i].size(); j++) {
                if (gameBoard[i][j] == position + '0') {
                    gameBoard[i][j] = player;
                    return;
                }
            }
        }
    }
    bool isMoveValid(int position) {
        if (position < 1 || position > 9) {
            cout << "Invalid move. Please enter a number between 1 and 9." << endl;
            return false;
        }
        for (int i = 0; i < gameBoard.size(); i++) {
            for (int j = 0; j < gameBoard[i].size(); j++) {
                if (gameBoard[i][j] == position + '0') {
                    return true;
                }
            }
        }
        cout << "Invalid move. The position is already taken." << endl;
        return false;
    }
    bool checkWin() {
        // rows
        for (int i = 0; i < 3; i++) {
            if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
                return true;
            }
        }
        // columns
        for (int i = 0; i < 3; i++) {
            if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) {
                return true;
            }
        }
        // Check diagonals
        if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
            return true;
        }
        if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
            return true;
        }

        return false;
    }
    void switchPlayer() {
        player = (player == 'X') ? 'O' : 'X';
    }
    char getCurrentPlayer() const {
        return player;
    }
    private:
        char player;
    };

    int main() {
        TicTacToe game;
        int moveCount = 0;

        while (true) {
            game.printGameBoard();
            cout << "Player " << game.getCurrentPlayer() << ", enter your move (1-9): ";
            int move;
            cin >> move;
            if (game.isMoveValid(move)) {
                game.modifyGameBoard(game.getCurrentPlayer(), move);
                moveCount++;

                if (game.checkWin()) {
                    game.printGameBoard();
                    cout << "Player " << game.getCurrentPlayer() << " wins!" << endl;
                    break;
                }

                if (moveCount == 9) {
                    game.printGameBoard();
                    cout << "It's a draw!" << endl;
                    break;
                }
                game.switchPlayer();
            } else {
                cout << "Please try again." << endl;
            }
        }
        return 0;
    };