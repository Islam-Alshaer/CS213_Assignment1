#include <bits/stdc++.h>
using namespace std;

void scores() {
    list<pair<string, int>> scores;

    while(true) {
        string choice;
        cout << "Choose one of the options in the menu:\n"
        << "A) Add a player to the Leaderboard\n"
        << "B) Show the Leaderboard\n"
        << "C) Search for player score\n"
        << "D) Exit the program:\n";
        getline(cin, choice);
        regex pattern("^[A-D]$");
        if(!regex_match(choice, pattern)) {
            cout << "Please enter a valid option!\n" << endl;
            continue;
        }
        if(choice == "A") { // A) Add
            cout << "Enter the name:\n";
            string name;
            getline(cin, name);
            regex name_match("^[a-zA-Z]+.*$");
            while(!regex_match(name, name_match)) {
                cout << "Please enter a valid name!\n";
                getline(cin, name);
            }

            cout << "Enter the score:\n";
            int score;
            string input_score;
            getline(cin, input_score);
            regex match("\\d+");
            while(!regex_match(input_score, match)) {
                cout << "Please enter a valid number.\n";
                getline(cin, input_score);
            }
            score = stoi(input_score);

            if(scores.empty()) {
                scores.push_front(make_pair(name, score));
                continue;
            }

            auto it = scores.begin();
            bool inserted = false;

            for(auto i : scores) {
                if(score > i.second) {
                    scores.insert(it, make_pair(name, score));
                    inserted = true;
                    break;
                }
                it++;
            }
            if(!inserted)
                scores.push_back(make_pair(name, score));
            if(scores.size() > 10)
                scores.pop_back();
        }
        else if(choice == "B") {

            if(scores.empty()) {
                cout << "The leaderboard is empty!\n" << endl;
                continue;
            }

            cout << "\nThe Scores:\n" << "------------------------------------\n";
            int j = 0;
            for(auto i : scores) {
                cout << ++j << ") " << "Name: " << i.first << "  Score: " << i.second << endl;
            }
            cout << "------------------------------------\n" << endl;
        }
        else if(choice == "C") {
            cout << "Enter the name:\n";
            string name;
            bool found = false;
            getline(cin, name);

            for(auto i : scores) {
                if(name == i.first) {
                    cout << "Name: " << i.first << " ||" << " Score: " << i.second << '\n' << endl;
                    found = true;
                    break;
                }
            }
            if(!found)
                cout << "Name not found in the leaderboard\n" << endl;
        }
        else if(choice == "D") {
            cout << "Exiting the program...\n";
            break;
        }
    }
    scores.clear();
}

int main() {
    scores();

    return 0;
}