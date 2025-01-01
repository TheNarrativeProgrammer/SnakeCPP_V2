#include <iostream>
#include "CollectableSpawner.h"
#include "Collectables.h"
#include "GameBoard.h"
#include "Draw.h"
#include "Utils.h"
#include "Snake.h"
#include "V1.h"
#include "InputManager.h"
#include "InputState.h"
#include "Score.h"

#define V1 0
#define V2 1


// Main game loop
int main()
{
#if V2
    GameBoard GB(100, 20);
    Snake playerSnake(5, 5, GB);
    Score* ScorePtr = new Score();


    InputManager InputManager;

    CollectableSpawner* CollectableSpawnerPtr = &CollectableSpawner::GetInstance();
    std::vector<Collectables<int>*> CollectablesArray;

    CollectablesArray = CollectableSpawnerPtr->SpawnNewCollectable(GB);

    
    while (true)
    {
        InputManager.Update();
        InputManager.MoveSnake(playerSnake);
        renderGame(GB, playerSnake, CollectablesArray, ScorePtr);

        for (int i = 0; i < CollectablesArray.size(); i++)
        {
            if (CollectablesArray[i]->GetHasBeenCollected() == false)
            {
                break;
            }
            if (CollectablesArray[i]->GetHasBeenCollected() == true && i == CollectablesArray.size() - 1)
            {
                CollectablesArray = CollectableSpawnerPtr->SpawnNewCollectable(GB);
            }
        }

    }
#endif // V2

   
#if V1

    Setup();                                                    // Initialize game variables
    while (!gameOver) {                                         // Run the game until the player loses
        Draw();                                                 // Display the game board
        Input();                                                // Handle user input
        Logic();                                                // Update the game state
        Sleep(100);                                             // Slow down the game loop for better playability
    }
#endif // V1



}
