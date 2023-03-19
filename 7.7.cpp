#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ofstream OutFile;
    OutFile.open("output.txt");
    int choice = 1;
    string i;
    vector<string> list;
    while(choice == 1) {
        cout << "Enter word\n";
        cin >> i;

        if(std::count(list.begin(), list.end(), i)) {
            cout << "Element found! Copying address\n";
            list.push_back(i);
        } else {
            cout << "Element was not found, creating new address\n";
            list.push_back(i);
        }
        cout << "Keep adding entries?\n1 or 0\n";
        cin >> choice;
   }

    for(int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
        OutFile << list[i] << " ";
   }

   OutFile.close();
   return 0;
}

