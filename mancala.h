//
//  mancala.h
//  mancala
//
//  Created by Emma Luukkonen on 5/4/20.
//  Copyright © 2020 Emma Luukkonen. All rights reserved.
//

#ifndef mancala_h
#define mancala_h

#include <string>
#include <iostream>
#include <stdlib.h>
#include <algorithm> // for std::max

struct Game {
    std::string player1_name;
    std::string player2_name;
    
    int player1_side[6] = {0};
    int player1_collection = 0;
    int player2_side[6] = {0};
    int player2_collection = 0;
};

void printBoard(Game &game);
int play(Game &game);
bool turn(Game &game, int player, int selection);
void single_player(Game &game);
void easy(Game &g);
void medium(Game &game);
void hard(Game &game);
int utility(Game *game);
bool terminal_test(Game *game);
std::pair<int, int> min_value(Game *game, int &alpha, int &beta, int& last_action, int depth);
std::pair<int, int> max_value(Game *game, int &alpha, int &beta, int& last_action, int depth);
int minimax(Game *game);
Game* result(Game *game, int action);


#endif /* mancala_h */
