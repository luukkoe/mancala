//
//  main.cpp
//  mancala
//
//  Created by Emma Luukkonen on 4/29/20.
//  Copyright © 2020 Emma Luukkonen. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "mancala.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Game g;
    int num_players;
    
    cout << "WELCOME TO MANCALA!!" << '\n' << '\n' << "Enter number of players (1 or 2): ";
    cin >> num_players;
    while ((num_players != 1) && (num_players != 2)) {
        cout << '\n' << "Invalid number. Pick 1 or 2: ";
        cin >> num_players;
    }
    
    if (num_players == 2) {
        single_player(g);
    }
    else {
        string diff;
        cout << '\n' << "Select difficulty (easy, medium, or hard): ";
        cin >> diff;
        transform(diff.begin(), diff.end(), diff.begin(), ::tolower);
        while (diff != "easy" && diff != "medium" && diff != "hard") {
            cout << '\n' << "Invalid difficulty. Select easy, medium, or hard: ";
        }
        if (diff == "easy") {
            easy(g);
        }
        else if (diff == "hard") {
            hard(g);
        }
        else {
            medium(g);
        }
    }
    
    return 0;
}
