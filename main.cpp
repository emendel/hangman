#include "hangman.h"
#include <fstream>
#include <cstdlib>

int main(){
    cout << "How many people are playing? 1 or 2?" << endl;
    int people;
    cin >> people;
    string word;

    if (people == 2){
        cout << "Player 1: Pick your word" << endl;
        cin >> word;

        play_hangman(word);

    }

    if (people == 1){
        //Have computer randomly pick a word
        vector <string> words;
        ifstream file;
        file.open("dictionary.txt");
        string line;
        if (file.is_open()){
            cout << "123" << endl;
            while (!file.eof()){
                getline(file, line);
                words.push_back(line);
                    
            }
        }
        srand(time(NULL));
        line = words[rand() % words.size()];
        play_hangman(line);

        
    }


    return 0;
}

