#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Frequency {
    public:
        vector<char> words;
        int alphabet[26];
        void frequency(vector<char> words);
        vector<char> data(vector<char> words, string filename);
};

vector<char> Frequency::data(vector<char> words, string filename) {
    ifstream input;
    char temp;
    input.open(filename);

    while(input.get(temp)) {
        words.push_back(temp);
    }
    input.close();
    return words;
}


void Frequency::frequency(vector<char> words) {
    int i = 0;
    int j;

    for(int x = 0; x < 26; x++) {
        alphabet[x] = 0;
    }

    while(words[i] != '\0') {
        if(words[i] >= 'a' && words[i] <= 'z') {
            j = words[i] - 'a';
            ++alphabet[j];
        }
        i++;
    }
}

int main() {
    Frequency final;

    final.words = final.data(final.words, "data.txt");
    
    final.frequency(final.words);

    for(int i = 0; i < 26; i++) {
        cout << char(i + 'a') << " : " << final.alphabet[i] << endl;
    }
    return 0;
}