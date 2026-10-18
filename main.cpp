#include <iostream>
#include <vector>
using namespace std;

class TicTacToe
{
private:
    vector<char> board;

public:
    TicTacToe()
    {
        board.resize(9);

        for (int i = 0; i < 9; i++)
        {
            board[i] = '1' + i;
        }
    }
    void displayBoard()
    {
        for (int i = 0; i < 9; i++)
        {
            if (i % 3 == 0 && i != 0)
            {
                cout << endl;
            }
            cout << board[i] << " ";
        }
    }
    void playerTurn(char Player)
    {
        int choose;
        cout << "Enter a num (1-9)" << endl;
        cin >> choose;

        if (choose < 1 || choose > 9)
        {
            cout << "Invalid input. Please enter a number between 1 & 9." << endl;
        }
        else if (board[choose - 1] == 'X' || board[choose - 1] == 'O')
        {
            cout << "the move is already taken. Please choose another one." << endl;
        }
        else
        {
            board[choose - 1] = Player;
        }
    }

    char checkwinner()
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i] == board[i + 1] && board[i + 1] == board[i + 2])
            {
                return board[i];
            }
            for (int i = 0; i < 3; i++)
            {
                if (board[i] == board[i + 3] && board[i + 3] == board[i + 6])
                {
                    return board[i];
                }
            }
            if (board[0] == board[4] && board[4] == board[8])
            {
                return board[0];
            }
            if (board[2] == board[4] && board[4] == board[6])
            {
                return board[2];
            }
            return ' ';
        }
    }
};

int main()
{
    TicTacToe game;
    char currentPlayer = 'X';
    bool gameOver = false;

    for (int i = 0; i < 9; i++)
    {
        game.displayBoard();
        game.playerTurn(currentPlayer);
        if (game.checkwinner() == 'X' || game.checkwinner() == 'O')
        {
            game.displayBoard();
            cout << endl;
            cout << endl;
            cout << game.checkwinner() << " wins!" << endl;
            gameOver = true;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        if (i == 8 && !gameOver)
        {
            game.displayBoard();
            cout << endl;
            cout << endl;
            cout << "It's a draw!" << endl;
        }
    }

    return 0;
}