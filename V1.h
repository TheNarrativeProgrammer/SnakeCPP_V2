#include <iostream>
#include <conio.h>          
#include <windows.h>

// conio is used for directions, and windows.h is being used to slow down the timer on the game.

using namespace std;

// Constants for game dimensions
const int width = 20, height = 20;                              // The width and height of the game area
int x, y, fruitX, fruitY, score;                                // Position of the snake head, fruit, and the game score
int tailX[100], tailY[100], nTail;                              // Arrays for the snake's tail positions and tail length
bool gameOver;                                                  // Flag to check if the game is over
char dir;                                                       // Direction of the snake's movement

// Initializes game variables
void Setup() {
    gameOver = false;                                           // Game starts running
    dir = ' ';                                                  // No initial direction
    x = width / 2;                                              // Snake starts at the center of the screen
    y = height / 2;
    fruitX = rand() % width;                                    // Random position for the fruit within the game area
    fruitY = rand() % height;
    score = 0;                                                  // Initial score
    nTail = 0;                                                  // Snake starts with no tail
}

// Draws the game board
void Draw() {
    system("cls");                                              // Clears the console screen

    // Top border
    for (int i = 0; i < width + 2; i++) cout << "#";            // Draw the top border of the game
    cout << endl;

    // Game area
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#";                            // Left border

            // Snake head
            if (i == y && j == x)
                cout << "O";                                    // Draw the snake's head
            // Fruit
            else if (i == fruitY && j == fruitX)
                cout << "F";                                    // Draw the fruit
            // Snake tail
            else {
                bool print = false;                             // Flag to check if a tail segment is printed
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {       // Check if the current position matches any tail segment
                        cout << "o";                            // Draw the tail segment
                        print = true;
                        break;
                    }
                }
                if (!print) cout << " ";                        // Print empty space if no tail segment is present
            }

            if (j == width - 1) cout << "#";                    // Right border
        }
        cout << endl;
    }

    // Bottom border
    for (int i = 0; i < width + 2; i++) cout << "#";            // Draw the bottom border
    cout << "\nScore: " << score << endl;                       // Display the current score
}

// Handles user input KeyBoardHit, GetCharacter
void Input() {
    if (_kbhit()) {                                             // Check if a key has been pressed
        switch (_getch()) {                                     // Get the key pressed
        case 'a': dir = 'L'; break;                             // Move left
        case 'd': dir = 'R'; break;                             // Move right
        case 'w': dir = 'U'; break;                             // Move up
        case 's': dir = 'D'; break;                             // Move down
        case 'x': gameOver = true; break;                       // Exit game
        }
    }
}

// Updates game logic
void Logic() {
    // Update tail positions
    int prevX = x, prevY = y, prev2X, prev2Y;                   // Store the previous positions of the head and tail segments
    for (int i = 0; i < nTail; i++) {
        prev2X = tailX[i]; prev2Y = tailY[i];                   // Store the current tail segment position
        tailX[i] = prevX; tailY[i] = prevY;                     // Update the tail segment to the previous position
        prevX = prev2X; prevY = prev2Y;                         // Update previous positions for the next segment
    }

    // Move snake head
    switch (dir) {
    case 'L': x--; break;                                       // Move left
    case 'R': x++; break;                                       // Move right
    case 'U': y--; break;                                       // Move up
    case 'D': y++; break;                                       // Move down
    }

    // Handle screen wrap
    if (x >= width) x = 0; else if (x < 0) x = width - 1;       // Wrap horizontally
    if (y >= height) y = 0; else if (y < 0) y = height - 1;     // Wrap vertically

    // Check for collision with tail
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y) gameOver = true;    // End the game if the head touches any tail segment

    // Check for collision with fruit
    if (x == fruitX && y == fruitY) {                           // Check if the snake's head is on the fruit
        score += 10;                                            // Increase score
        fruitX = rand() % width;                                // Generate new random position for the fruit
        fruitY = rand() % height;
        nTail++;                                                // Increase the snake's tail length
    }
}