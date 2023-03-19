#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
        
    srand(time(NULL));
    cout << "Intizalizng Game\n";

    int currentPile;
    int pile;
    int diff;
    int first;
    int take;
    int humanTake;
    
    //initializes the pile size
    pile = rand() % 100 + 10;
    currentPile = pile;

    cout << pile << "\n";

    //initalizes the difficulty
    diff = rand() % 2;

    if(diff == 1) {
        cout << "Difficulty: Smart\n";
    } else {
        cout << "Difficulty: Dumb\n";
    }

    first = rand() % 2;

    //initalizes who goes first
    if(first == 1) {
        cout << "Human goes first!\n";
    } else {
        cout << "Computer goes first!\n";
    }

    //nim computer
    while(currentPile>0) {
        if(first == 1) {
            cout << "The pile size is: " << currentPile << "\n";
            cout << "Please take some marbles: \n";
            cin >> humanTake;
            if (currentPile == 1) {
                currentPile = currentPile - humanTake;
                break;
                if(humanTake > currentPile/2) {
                cout << "Invalid Move, try again: \n";
                cin >> humanTake;
                }
            }
            currentPile = currentPile - humanTake;
            first = 0;
        } else {
            if(diff == 1 && first == 0) {
                if(currentPile > 64) {
                    currentPile = 63;
                    first = 1;
                } else if(currentPile > 32 && currentPile < 63) {
                    currentPile = 31;
                    first = 1;
                } else if(currentPile > 16 && currentPile < 31) {
                    currentPile = 15;
                    first = 1;
                } else if(currentPile > 8 && currentPile < 15) {
                    currentPile = 7;
                    first = 1;
                } else if(currentPile > 4 && currentPile < 7) {
                    currentPile = 3;
                    first = 1;
                } else if(currentPile = 2) {
                    currentPile = 1;
                    first = 1;
                }
            } else if(first == 0) {
                take = rand() % (1 + currentPile/2);
                currentPile = currentPile - take;
                first = 1;
            }
        }
    }

    cout << "The game is over!\n";

    return 0;
}