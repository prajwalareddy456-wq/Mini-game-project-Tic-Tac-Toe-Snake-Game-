#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to initialize board
void initializeBoard()
{
    char ch = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }
}

// Function to display board
void displayBoard()
{
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

// Function to switch player
void switchPlayer()
{
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

// Function to place move
bool makeMove(int choice)
{
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9)
        return false;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = currentPlayer;
    return true;
}

// Function to check winner
bool checkWinner()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to check draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

// Main game function
void playGame()
{
    initializeBoard();
    currentPlayer = 'X';

    int choice;

    while (true)
    {
        displayBoard();

        cout << "Player " << currentPlayer
             << ", enter position (1-9): ";
        cin >> choice;

        if (!makeMove(choice))
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (checkWinner())
        {
            displayBoard();
            cout << "🎉 Player " << currentPlayer
                 << " wins the game!\n";
            break;
        }

        if (checkDraw())
        {
            displayBoard();
            cout << "🤝 Game Draw!\n";
            break;
        }

        switchPlayer();
    }
}

int main()
{
    char replay;

    cout << "===== TIC TAC TOE =====\n";

    do
    {
        playGame();

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "\nThank you for playing!\n";

    return 0;
}
