// make a header class for the game class

#pragma once
#ifndef GAME_H
#define GAME_H

class Game
{
public:
    char board[3][3];
    char playerSymbol;
    char computerSymbol;
    int counter;
    bool playerWon;
    bool computerWon;

    // file handling function
    void fileHandling();

    // function to write the new counter
    void writeCounter();

    // function to choose the symbol
    void chooseSymbol();

    // function to initialize the board
    void readBoard();

    // function to check if the player has won
    void checkPlayerWon();

    // function to check if the computer has won
    void checkComputerWon();

    // function to check if the game is a draw
    void isDraw();

    // function to ask for play again
    void playAgain();

    // function to start the game
    void startGame();
};

#endif
