#include "hangman.h"




int main(){
    cout << "How many people are playing? 1 or 2?" << endl;
    int people;
    cin >> people;

    if (people == 2){
        string word;
        cout << "Player 1: Pick your word" << endl;
        cin >> word;

        play_hangman(word);

    }

    if (people == 1){
        //Have computer randomly pick a word

    }


    return 0;
}

