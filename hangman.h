#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

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
                cout << "The word was " << word << endl;
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
        cout << "Letters that you have guessed: ";
        auto it = guesses.begin();
        while (it != guesses.end()){
            cout << it->first << " ";
            ++it;
        }
        cout << endl;
    
    }
    cout << "Guesser Won!!" << endl;
}
