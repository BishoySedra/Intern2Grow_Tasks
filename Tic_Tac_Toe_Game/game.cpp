// implement the game class in game.cpp
#include "game.h"
#include <iostream>
#include <fstream>

using namespace std;

// file handling function
void Game::fileHandling()
{
    // check if the playerData.txt file exists
    ifstream readFile("playerData.txt");

    if (!readFile)
    {
        ofstream writeFile("playerData.txt");
        writeFile << "0";
        writeFile.close();
    }

    // read the file
    readFile >> counter;
    readFile.close();

    // display the counter
    cout << "You have won " << counter << " times!" << "\n";
}

// function to write the new counter
void Game::writeCounter()
{
    // write the new counter
    ofstream writeFile("playerData.txt");
    writeFile << counter;
    writeFile.close();
}

// file to choose the symbol
void Game::chooseSymbol()
{
    // ask the player to enter the symbol
    cout << "Enter your symbol (X or O): ";
    cin >> playerSymbol;

    if (playerSymbol == 'X')
    {
        computerSymbol = 'O';
    }

    if (playerSymbol == 'x')
    {
        computerSymbol = 'o';
    }

    if (playerSymbol == 'O')
    {
        computerSymbol = 'X';
    }

    if (playerSymbol == 'o')
    {
        computerSymbol = 'x';
    }
}

// function to initialize the board
void Game::readBoard()
{
    cout << "Enter the board: \n";
    // initialize the board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> board[i][j];
        }
    }
}

// function to check if the player has won
void Game::checkPlayerWon()
{
    playerWon = false;

    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol)
        {
            playerWon = true;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol)
        {
            playerWon = true;
        }
    }

    // check diagonals
    if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
    {
        playerWon = true;
    }

    if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
    {
        playerWon = true;
    }

    // display the message
    if (playerWon)
    {
        cout << "You have won!" << "\n";
        counter++;
        writeCounter();
    }
}

// function to check if the computer has won
void Game::checkComputerWon()
{

    computerWon = false;

    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == computerSymbol && board[i][1] == computerSymbol && board[i][2] == computerSymbol)
        {
            computerWon = true;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == computerSymbol && board[1][i] == computerSymbol && board[2][i] == computerSymbol)
        {
            computerWon = true;
        }
    }

    // check diagonals
    if (board[0][0] == computerSymbol && board[1][1] == computerSymbol && board[2][2] == computerSymbol)
    {
        computerWon = true;
    }

    if (board[0][2] == computerSymbol && board[1][1] == computerSymbol && board[2][0] == computerSymbol)
    {
        computerWon = true;
    }

    // display the message
    if (computerWon)
    {
        cout << "Computer has won!" << "\n";
    }
}

// function to check if the game is a draw
void Game::isDraw()
{
    // check if the game is a draw
    if (!playerWon && !computerWon)
    {
        cout << "The game is a draw!" << "\n";
    }
}

// function to ask for play again
void Game::playAgain()
{
    // ask the player if they want to play again
    char choice;
    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        startGame();
    }
    else if (choice == 'N' || choice == 'n')
    {
        cout << "Thank you for playing!" << "\n";
        cout << "Exiting the game..." << "\n";
    }
    else
    {
        cout << "Invalid choice!" << "\n";
        playAgain();
    }
}

// function to start the game
void Game::startGame()
{
    // printing separator
    cout << "---------------------------------" << "\n";

    // printing the welcome message
    cout << "Welcome to the Tic Tac Toe Game!" << "\n";

    // file handling
    fileHandling();

    // choose the symbol
    chooseSymbol();

    // if the choosen symbol isn't X or O
    if (playerSymbol != 'X' && playerSymbol != 'O' && playerSymbol != 'x' && playerSymbol != 'o')
    {
        cout << "Invalid symbol!" << "\n";
        cout << "Please enter X or O!" << "\n";
        startGame();
        return;
    }

    // initialize the board
    readBoard();

    // check if the player has won
    checkPlayerWon();

    // if the player has won ask for play again
    if (playerWon)
    {
        playAgain();
        return;
    }

    // check if the computer has won
    checkComputerWon();

    // if the computer has won ask for play again
    if (computerWon)
    {
        playAgain();
        return;
    }

    // check if the game is a draw
    isDraw();

    // ask for play again
    playAgain();
}