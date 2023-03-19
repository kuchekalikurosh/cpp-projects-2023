#include <iostream>
#include <string>
using namespace std;

/*
* Kurosh Kuchekali
* 26 August 2022
*/

//main function
int main() {
    //creates a new string variable
    string user_input;
    
    //prints lines onto the terminal
    cout << "Hello, my name is Hal! \n\n";
    cout << "What would you like me to do? \n\n";
   
    //allows for recording inputs
    getline(cin, user_input);

    cout << "\nI am sorry, I cannot do that.";
    return 0;
}