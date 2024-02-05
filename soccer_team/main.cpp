//
//  main.cpp
//  soccer_team
//
//  Created by Austin Wright on 2/2/24.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector <int> player_number;
    vector <int> player_rating;
    int player;
    int rating;

    for (int i = 1; i <= 5; ++i) {
        cout << "Enter player " << i << "'s jersey number: " << endl;
        cin >> player;
        player_number.push_back(player);
        cout << "Enter player " << i << "'s rating: " << endl;
        cin >> rating;
        player_rating.push_back(rating);
    }
    char coach_input = 'j';
    while (coach_input != 'q'){
        cout << "Menu" << endl;
        cout << "a - Add player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option: " << endl;
        cin >> coach_input;
        
        if (coach_input == 'o') {
            for (int i = 1; i <= player_number.size(); ++i) {
                cout << "Player " << i << " -- Jersey number: " << player_number[i-1] << ", " << "Rating: " << player_rating[i-1] << endl;
            }
            cout << endl;
        }
        else if (coach_input == 'a') {
            cout << "Enter a new player's jersey number: " << endl;
            cin >> player;
            player_number.push_back(player);
            cout << "Enter the player's rating: " << endl;
            cin >> rating;
            player_rating.push_back(rating);
        }
        else if (coach_input == 'd') {
            cout << "Enter a jersey number : " << endl;
            cin >> player;
            auto it = find(player_number.begin(), player_number.end(), player);
            long index = distance(player_number.begin(), it);
            player_number.erase(player_number.begin() + index);
            player_rating.erase(player_rating.begin() + index);
        }
        else if (coach_input == 'u') {
            cout << "Enter a jersey number : " << endl;
            cin >> player;
            auto it = find(player_number.begin(), player_number.end(), player);
            long index = distance(player_number.begin(), it);
            cout << "Enter a new rating for player: " << endl;
            cin >> rating;
            player_rating[index] = rating;
        }
        else if (coach_input == 'r') {
            cout << "Enter a rating: " << endl;
            cin >> rating;
            cout << "ABOVE " << rating << endl;
            for (int i = 0; i < player_number.size(); ++i) {
                if (player_rating[i] > rating) {
                    cout << "Player " << i << " -- Jersey number: " << player_number[i] << ", Rating: " << player_rating[i] << endl;
                }
            }
        }
    }
    return 0;
}
