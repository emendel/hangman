#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void play_hangman(string word);

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

void play_hangman(string word){
    map <char, int> guesses;
    vector <char> output;
    map <char, int> distinct;
    for (int i = 0; i < word.length(); ++i){
        output.push_back('_');
        if (distinct.find(word[i]) == distinct.end()){
            distinct.insert({word[i], 1});
        }
    }

    for (auto i : output){
        cout << i << " ";
    }

    cout << endl << "Guess a letter!" << endl;
    int num_guessed_correctly = 0;
    int misses;
    char letter;
    while (num_guessed_correctly != distinct.size()){
        cout << "You are allowed " << 10 - misses << " more incorrect guesses" << endl;
        cin >> letter;
        if (guesses.find(letter) != guesses.end()){
            cout << "Sorry you already guessed that letter" << endl;
        }
        else if (distinct.find(letter) == distinct.end()){
            ++misses;
            if (misses == 10){
                cout << "Guesser lost :(" << endl;
                return;
            }

            cout << "Sorry try again :(" << endl;
        }

        else {
            for (int i = 0; i < word.length(); ++i){
                if (word[i] == letter){
                    output.at(i) = letter;
                }
            }
            ++num_guessed_correctly;
            cout << "Great job!  Guess another letter!" << endl;
        }
        guesses.insert({letter, 0});

        for (auto i : output){
            cout << i << " ";
        }
        cout << endl;
    
    }
    cout << "Guesser Won!!" << endl;

}