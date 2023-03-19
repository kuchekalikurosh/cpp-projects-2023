#include <iostream>
#include <string>

using namespace std;

//gobal variables
const int ROW = 5;
const int COL = 5;
const char ALIVE = 'O';
const char DEAD = '.';
char newBoard[ROW][COL];

//functions for the logic
void Output(char board[][COL]);
void Simulation(char board [][COL]);
void Switch(char board[][COL]);

int main() 
{
    int turns;
    char currBoard[ROW][COL];
    bool valid = false;

    cout << "Enter number of simulations:\n";
    cin >> turns;

    cout << "The grid is " << ROW << " by " << COL;

    for(int i = 0; i < ROW; i++) 
    {
        for(int j = 0; j < COL; j++) 
        {
            cout << "\n. is a dead cell; capital O is an alive cell\n";
            cout << "Enter cell state on grid at (" << i + 1 << ", " << j + 1 << ")\n";
            cin >> currBoard[i][j];
        }
    }

    cout << "\n";

    for(int x = 0; x <= turns; x++)
    {
        Simulation(currBoard);
        cout << "Generation: " << x;
        Output(currBoard);
        Switch(currBoard);
    }

    cout << "\nSimulation complete, ran for: " << turns << " generations.\n";

    return 0;
}
4
//checks the next state of the simulation
void Simulation(char board[][COL])
{
    int count = 0;
    for(int i = 0; i < ROW; i++) 
    {
        for(int j = 0; j < COL; j++) 
        {
            //bottom left
            if(board[i-1][j-1]==ALIVE)
            {
                count++;
            }
            //bottom
            if(board[i-1][j]==ALIVE)
            {
                count++;
            }
            //bottom right
            if(board[i-1][j+1]==ALIVE)
            {
                count++;
            }
            //left
            if(board[i][j-1]==ALIVE)
            {
                count++;
            }
            //right
            if(board[i][j+1]==ALIVE)
            {
                count++;
            }
            //top left
            if(board[i+1][j-1]==ALIVE)
            {
                count++;
            }
            //top right
            if(board[i+1][j+1]==ALIVE)
            {
                count++;
            }
            //top
            if(board[i+1][j]==ALIVE)
            {
                count++;
            }

            newBoard[i][j] = DEAD;

            if(board[i][j] == ALIVE && count < 2)
            {
                newBoard[i][j] = DEAD;
            }
            else if(board[i][j] == ALIVE && (count == 2 || count == 3))
            {
                newBoard[i][j] = ALIVE;
            }
            else if(board[i][j] == ALIVE && count > 3)
            {
                newBoard[i][j] = DEAD;
            }
            else if(board[i][j] == DEAD && count == 3)
            {
                newBoard[i][j] = ALIVE;
            }

            count = 0;
        }
    }
}

//prints the simulation
void Output(char board[][COL])
{
    for(int i = 0; i < ROW; i++) 
    {
        cout << "\n";
        for(int j = 0; j < COL; j++) 
        {
            cout << board[i][j];
        }
    }
    cout << "\n\n";
}

//copies information from the simulation and passes it onto the current board
void Switch(char board[][COL])
{
    for(int i = 0; i < ROW; i++) 
    {
        for(int j = 0; j < COL; j++) 
        {
            board[i][j] = newBoard[i][j];
        }
    }
}
