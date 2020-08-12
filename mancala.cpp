//
//  mancala.cpp
//  mancala
//
//  Created by Emma Luukkonen on 5/9/20.
//  Copyright © 2020 Emma Luukkonen. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "mancala.h"

void single_player(Game &g) {
    std::string name1, name2;
    
    std::cout << "Enter Player 1 Name: ";
    std::cin >> name1;
    while (name1 == "") {
        std::cout << "Invalid name." << '\n' << "Enter Player 1 Name: ";
        std::cin >> name1;
    }
    std::cout << "Enter Player 2 Name: ";
    std::cin >> name2;
    while (name2 == "") {
        std::cout << "Invalid name." << '\n' << "Enter Player 2 Name: ";
        std::cin >> name2;
    }
    
    g.player1_name = name1;
    g.player2_name = name2;
    
    int winner = play(g);
    
    if (winner == 0) {
        std::cout << "PLAYER 1 WON BY " <<
        g.player1_collection - g.player2_collection << " BEADS!" << '\n';
    }
    else if (winner == 1) {
        std::cout << "PLAYER 2 WON BY " <<
        g.player2_collection - g.player1_collection << " BEADS!" << '\n';
    }
    else {
        std::cout << "THERE WAS A TIE!" << '\n';
    }
}


void printBoard(Game &game) {
    std::cout << '\n';
    
    std::cout << "-----------------------------------------------------------------" << '\n';
    std::cout << "|       |       |       |       |       |       |       |       |" << '\n';
    
    std::cout << "|       |";
    for (int i = 0; i < 6; ++i) {
        std::cout << "   " << game.player2_side[i];
        if (game.player2_side[i] > 9) {
            std::cout << "  " << "|";
        }
        else {
            std::cout << "   " << "|";
        }
    }
    std::cout << "       |" << '\n';
    
    std::cout << "|       |       |       |       |       |       |       |       |" << '\n';
    if (game.player2_collection > 9) {
        std::cout << "|  " << game.player2_collection;
    }
    else {
        std::cout << "|   " << game.player2_collection;
    }
    std::cout << "   |-----------------------------------------------|   ";
    if (game.player1_collection > 9) {
        std::cout << game.player1_collection << "  |" << '\n';
    }
    else {
        std::cout << game.player1_collection << "   |" << '\n';
    }
    std::cout << "|       |       |       |       |       |       |       |       |" << '\n';
    
    std::cout << "|       |";
    for (int i = 0; i < 6; ++i) {
        std::cout << "   " << game.player1_side[i];
        if (game.player1_side[i] > 9) {
            std::cout << "  " << "|";
        }
        else {
            std::cout << "   " << "|";
        }
    }
    std::cout << "       |" << '\n';
    
    std::cout << "|       |       |       |       |       |       |       |       |" << '\n';
    std::cout << "-----------------------------------------------------------------" << '\n';
    
    std::cout << '\n';
}

int play(Game &game) {
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    
    bool game_over = false;
    bool free_turn = false;
    
    while (!game_over) {
        printBoard(game);
        
        // check if game over
        int player1_empties = 0;
        int player2_empties = 0;
        for (int i = 0; i < 6; ++i) {
            if (!game.player1_side[i]) {
                player1_empties++;
            }
            if (!game.player2_side[i]) {
                player2_empties++;
            }
        }
        if (player1_empties == 6 || player2_empties == 6) {
            if (player1_empties == 6 && player2_empties != 6) {
                for (int i = 0; i < 6; ++i) {
                    game.player2_collection += game.player2_side[i];
                    game.player2_side[i] = 0;
                }
                game_over = true;
                printBoard(game);
                break;
            }
            else if (player2_empties == 6 && player1_empties != 6) {
                for (int i = 0; i < 6; ++i) {
                    game.player1_collection += game.player1_side[i];
                    game.player1_side[i] = 0;
                }
                game_over = true;
                printBoard(game);
                break;
            }
            else {
                game_over = true;
                printBoard(game);
                break;
            }
        }
        
        // player 1 turn
        free_turn = false;
        int player1_select;
        std::cout << game.player1_name << "'s turn!" << '\n' << "Select a space 1-6: ";
        std::cin >> player1_select;
        while (player1_select > 6 || player1_select < 1) {
            std::cout << '\n' << "Invalid election. Please select a space 1-6: ";
            std::cin >> player1_select;
        }
        while (game.player1_side[player1_select - 1] == 0) {
            std::cout << '\n' << "Please select a non-empty space 1-6: ";
            std::cin >> player1_select;
        }
        free_turn = turn(game, 1, player1_select);
        while (free_turn) {
            
            printBoard(game);
            
            std::cout << "FREE TURN" << '\n' << '\n';
            
            std::cout << game.player1_name << "'s turn!" << '\n' << "Select a space 1-6: ";
            std::cin >> player1_select;
            while (player1_select > 6 || player1_select < 1) {
                std::cout << '\n' << "Invalid election. Please select a space 1-6: ";
                std::cin >> player1_select;
            }
            while (game.player1_side[player1_select - 1] == 0) {
                std::cout << '\n' << "Please select a non-empty space 1-6: ";
                std::cin >> player1_select;
            }
            free_turn = turn(game, 1, player1_select);
        }
        
        printBoard(game);
        
        // player 2 turn
        free_turn = false;
        int player2_select;
        std::cout << game.player2_name << "'s turn!" << '\n' << "Select a space 1-6: ";
        std::cin >> player2_select;
        while (player2_select > 6 || player2_select < 1) {
            std::cout << '\n' << "Invalid election. Please select a space 1-6: ";
            std::cin >> player2_select;
        }
        while (game.player2_side[player2_select - 1] == 0) {
            std::cout << '\n' << "Please select a non-empty space 1-6: ";
            std::cin >> player2_select;
        }
        free_turn = turn(game, 2, player2_select);
        while (free_turn) {
            
            printBoard(game);
            
            std::cout << "FREE TURN" << '\n' << '\n';
            
            std::cout << game.player2_name << "'s turn!" << '\n' << "Select a space 1-6: ";
            std::cin >> player2_select;
            while (player2_select > 6 || player2_select < 1) {
                std::cout << '\n' << "Invalid election. Please select a space 1-6: ";
                std::cin >> player2_select;
            }
            while (game.player2_side[player2_select - 1] == 0) {
                std::cout << '\n' << "Please select a non-empty space 1-6: ";
                std::cin >> player2_select;
            }
            free_turn = turn(game, 2, player2_select);
        }
    }
    
    
    if (game.player1_collection > game.player2_collection) {
        return 0;
    }
    else if (game.player2_collection > game.player1_collection) {
        return 1;
    }
    else {
        return 2;
    }
}

bool turn(Game &game, int player, int selection) {
    if (player == 1) {
        int num_beads = game.player1_side[selection - 1];
        game.player1_side[selection - 1] = 0;
        
        for (int i = selection; i < 6 && num_beads > 0; ++i) {
            game.player1_side[i]++;
            
            // CAPTURE
            if ((num_beads == 1) && (game.player1_side[i] == 1) && (game.player2_side[i] != 0)) {
                game.player1_collection = game.player1_collection + 1 +
                game.player2_side[i];
                
                game.player2_side[i] = 0;
                game.player1_side[i] = 0;
                
                std::cout << '\n' << "CAPTURED!" << '\n';;
            }
            
            num_beads--;
        }
        if (num_beads) {
            game.player1_collection++;
            
            // FREE TURN
            if (num_beads == 1) {
                return true;
            }
            
            num_beads--;
        }
        if (num_beads) {
            for (int i = 5; i >= 0 && num_beads > 0; --i) {
                game.player2_side[i]++;
                num_beads--;
            }
        }
        while (num_beads) {
            if (num_beads) {
                for (int i = 0; i < 6 && num_beads > 0; ++i) {
                    game.player1_side[i]++;
                    
                    // CAPTURE
                    if ((num_beads == 1) && (game.player1_side[i] == 1) && (game.player2_side[i] != 0)) {
                        game.player1_collection = game.player1_collection + 1 +
                        game.player2_side[i];
                        
                        game.player2_side[i] = 0;
                        game.player1_side[i] = 0;
                        
                        std::cout << '\n' << "CAPTURED!" << '\n';
                    }
                    
                    num_beads--;
                }
            }
            if (num_beads) {
                game.player1_collection++;
                
                // FREE TURN
                if (num_beads == 1) {
                    return true;
                }
                
                num_beads--;
            }
            if (num_beads) {
                for (int i = 5; i >= 0 && num_beads > 0; --i) {
                    game.player2_side[i]++;
                    num_beads--;
                }
            }
        }
    }
    
    else if (player == 2) {
        int num_beads = game.player2_side[selection - 1];
        game.player2_side[selection - 1] = 0;
        
        for (int i = selection - 2; i >= 0 && num_beads > 0; --i) {
            game.player2_side[i]++;
            
            // CAPTURE
            if ((num_beads == 1) && (game.player2_side[i] == 1) && (game.player1_side[i] != 0)) {
                game.player2_collection = game.player2_collection + 1 +
                game.player1_side[i];
                
                game.player1_side[i] = 0;
                game.player2_side[i] = 0;
                
                std::cout << '\n' << "CAPTURED!" << '\n';
            }
            
            num_beads--;
        }
        if (num_beads) {
            game.player2_collection++;
            
            // FREE TURN
            if (num_beads == 1) {
                return true;
            }
            
            num_beads--;
        }
        if (num_beads) {
            for (int i = 0; i < 6 && num_beads > 0; ++i) {
                game.player1_side[i]++;
                num_beads--;
            }
        }
        while (num_beads) {
            if (num_beads) {
                for (int i = 5; i >= 0 && num_beads > 0; --i) {
                    game.player2_side[i]++;
                    
                    // CAPTURE
                    if ((num_beads == 1) && (game.player2_side[i] == 1) && (game.player1_side[i] != 0)) {
                        game.player2_collection = game.player2_collection + 1 +
                        game.player1_side[i];
                        
                        game.player1_side[i] = 0;
                        game.player2_side[i] = 0;
                        
                        std::cout << '\n' << "CAPTURED!" << '\n';
                    }
                    
                    num_beads--;
                }
            }
            if (num_beads) {
                game.player2_collection++;
                
                // FREE TURN
                if (num_beads == 1) {
                    return true;
                }
                
                num_beads--;
            }
            if (num_beads) {
                for (int i = 0; i < 6 && num_beads > 0; ++i) {
                    game.player1_side[i]++;
                    num_beads--;
                }
            }
        }
    }
    
    return false;
}

void easy(Game &game) {
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    
    bool game_over = false;
    bool free_turn = false;
    
    while (!game_over) {
        printBoard(game);
        
        // check if game over
        int player1_empties = 0;
        int player2_empties = 0;
        for (int i = 0; i < 6; ++i) {
            if (!game.player1_side[i]) {
                player1_empties++;
            }
            if (!game.player2_side[i]) {
                player2_empties++;
            }
        }
        if (player1_empties == 6 || player2_empties == 6) {
            if (player1_empties == 6 && player2_empties != 6) {
                for (int i = 0; i < 6; ++i) {
                    game.player2_collection += game.player2_side[i];
                    game.player2_side[i] = 0;
                }
                game_over = true;
                printBoard(game);
                break;
            }
            else if (player2_empties == 6 && player1_empties != 6) {
                for (int i = 0; i < 6; ++i) {
                    game.player1_collection += game.player1_side[i];
                    game.player1_side[i] = 0;
                }
                game_over = true;
                printBoard(game);
                break;
            }
            else {
                game_over = true;
                printBoard(game);
                break;
            }
        }
        
        // player turn
        free_turn = false;
        int player1_select;
        std::cout << "Your turn!" << '\n' << "Select a space 1-6: ";
        std::cin >> player1_select;
        while (player1_select > 6 || player1_select < 1) {
            std::cout << '\n' << "Invalid election. Please select a space 1-6: ";
            std::cin >> player1_select;
        }
        while (game.player1_side[player1_select - 1] == 0) {
            std::cout << '\n' << "Please select a non-empty space 1-6: ";
            std::cin >> player1_select;
        }
        free_turn = turn(game, 1, player1_select);
        while (free_turn) {
            
            printBoard(game);
            
            std::cout << "FREE TURN" << '\n' << '\n';
            
            std::cout << "Your turn!" << '\n' << "Select a space 1-6: ";
            std::cin >> player1_select;
            while (player1_select > 6 || player1_select < 1) {
                std::cout << '\n' << "Invalid election. Please select a space 1-6: ";
                std::cin >> player1_select;
            }
            while (game.player1_side[player1_select - 1] == 0) {
                std::cout << '\n' << "Please select a non-empty space 1-6: ";
                std::cin >> player1_select;
            }
            free_turn = turn(game, 1, player1_select);
        }
        
        printBoard(game);
        
        // computer turn
        free_turn = false;
        
        std::cout << "Computer's turn!";
        int select = rand() % 6 + 1;
        while (game.player2_side[select] == 0) {
            select = rand() % 6 + 1;
        }
        std::cout << '\n' << "Computer selected space " << select << "!" << '\n';;
        
        free_turn = turn(game, 2, select);
        while (free_turn) {
            
            printBoard(game);
            
            std::cout << "FREE TURN" << '\n' << '\n';
            
            std::cout << "Computer's turn!";
            select = rand() % 7 + 1;
            while (game.player2_side[select] == 0) {
                select = rand() % 6 + 1;
            }
            std::cout << '\n' << "Computer selected space " << select << "!" << '\n';
            
            free_turn = turn(game, 2, select);
        }
    }
    
    if (game.player1_collection > game.player2_collection) {
        std::cout << '\n' << "YOU WON BY " <<
        game.player1_collection - game.player2_collection << "!" << '\n';
    }
    else if (game.player2_collection > game.player1_collection) {
        std::cout << '\n' << "YOU LOST BY " <<
        game.player2_collection - game.player1_collection << "!" << '\n';
    }
    else {
        std::cout << "THERE WAS A TIE!" << '\n';
    }
}

void medium(Game &game) {
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    
    bool game_over = false;
    bool free_turn = false;
    
    while (!game_over) {
        printBoard(game);
        
        // check if game over
        int player1_empties = 0;
        int player2_empties = 0;
        for (int i = 0; i < 6; ++i) {
            if (!game.player1_side[i]) {
                player1_empties++;
            }
            if (!game.player2_side[i]) {
                player2_empties++;
            }
        }
        if (player1_empties == 6 || player2_empties == 6) {
            if (player1_empties == 6 && player2_empties != 6) {
                for (int i = 0; i < 6; ++i) {
                    game.player2_collection += game.player2_side[i];
                }
                game_over = true;
                break;
            }
            else if (player2_empties == 6 && player1_empties != 6) {
                for (int i = 0; i < 6; ++i) {
                    game.player1_collection += game.player1_side[i];
                }
                game_over = true;
                break;
            }
            else {
                game_over = true;
                break;
            }
        }
        
        // player turn
        free_turn = false;
        int player1_select;
        std::cout << "Your turn!" << '\n' << "Select a space 1-6: ";
        std::cin >> player1_select;
        while (player1_select > 6 || player1_select < 1) {
            std::cout << '\n' << "Invalid election. Please select a space 1-6: ";
            std::cin >> player1_select;
        }
        while (game.player1_side[player1_select - 1] == 0) {
            std::cout << '\n' << "Please select a non-empty space 1-6: ";
            std::cin >> player1_select;
        }
        free_turn = turn(game, 1, player1_select);
        while (free_turn) {
            
            printBoard(game);
            
            std::cout << "FREE TURN" << '\n' << '\n';
            
            std::cout << "Your turn!" << '\n' << "Select a space 1-6: ";
            std::cin >> player1_select;
            while (player1_select > 6 || player1_select < 1) {
                std::cout << '\n' << "Invalid election. Please select a space 1-6: ";
                std::cin >> player1_select;
            }
            while (game.player1_side[player1_select - 1] == 0) {
                std::cout << '\n' << "Please select a non-empty space 1-6: ";
                std::cin >> player1_select;
            }
            free_turn = turn(game, 1, player1_select);
        }
        
        printBoard(game);
        
        // computer turn
        free_turn = false;
        
        std::cout << "Computer's turn!";
        
        bool opt = false;
        int select = 0;
        for (int i = 0; i < 6; ++i) {
            // if free turn possible
            if (game.player2_side[i] == i + 1) {
                opt = true;
                select = i + 1;
            }
        }
        if (!opt) {
            select = rand() % 6 + 1;
            while (game.player2_side[select - 1] == 0) {
                select = rand() % 6 + 1;
            }
        }
        
        std::cout << '\n' << "Computer selected space " << select << "!" << '\n';;
        
        free_turn = turn(game, 2, select);
        while (free_turn) {
            
            printBoard(game);
            
            std::cout << "FREE TURN" << '\n' << '\n';
            
            std::cout << "Computer's turn!";
            
            opt = false;
            select = 0;
            for (int i = 0; i < 6; ++i) {
                // if free turn possible
                if (game.player2_side[i] == i + 1) {
                    opt = true;
                    select = i + 1;
                }
            }
            if (!opt) {
                select = rand() % 6 + 1;
                while (game.player2_side[select - 1] == 0) {
                    select = rand() % 6 + 1;
                }
            }
            std::cout << '\n' << "Computer selected space " << select << "!" << '\n';
            
            free_turn = turn(game, 2, select);
        }
    }
    
    if (game.player1_collection > game.player2_collection) {
        std::cout << '\n' << "YOU WON BY " <<
        game.player1_collection - game.player2_collection << "!" << '\n';
    }
    else if (game.player2_collection > game.player1_collection) {
        std::cout << '\n' << "YOU LOST BY " <<
        game.player2_collection - game.player1_collection << "!" << '\n';
    }
    else {
        std::cout << "THERE WAS A TIE!" << '\n';
    }
}

void hard(Game &game) {
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    
    bool game_over = false;
    bool free_turn = false;
    
    while (!game_over) {
        printBoard(game);
        
        // check if game over
        int player1_empties = 0;
        int player2_empties = 0;
        for (int i = 0; i < 6; ++i) {
            if (!game.player1_side[i]) {
                player1_empties++;
            }
            if (!game.player2_side[i]) {
                player2_empties++;
            }
        }
        if (player1_empties == 6 || player2_empties == 6) {
            if (player1_empties == 6 && player2_empties != 6) {
                for (int i = 0; i < 6; ++i) {
                    game.player2_collection += game.player2_side[i];
                }
                game_over = true;
                break;
            }
            else if (player2_empties == 6 && player1_empties != 6) {
                for (int i = 0; i < 6; ++i) {
                    game.player1_collection += game.player1_side[i];
                }
                game_over = true;
                break;
            }
            else {
                game_over = true;
                break;
            }
        }
        
        // player turn
        free_turn = false;
        int player1_select;
        std::cout << "Your turn!" << '\n' << "Select a space 1-6: ";
        std::cin >> player1_select;
        while (player1_select > 6 || player1_select < 1) {
            std::cout << '\n' << "Invalid election. Please select a space 1-6: ";
            std::cin >> player1_select;
        }
        while (game.player1_side[player1_select - 1] == 0) {
            std::cout << '\n' << "Please select a non-empty space 1-6: ";
            std::cin >> player1_select;
        }
        free_turn = turn(game, 1, player1_select);
        while (free_turn) {
            
            printBoard(game);
            
            std::cout << "FREE TURN" << '\n' << '\n';
            
            std::cout << "Your turn!" << '\n' << "Select a space 1-6: ";
            std::cin >> player1_select;
            while (player1_select > 6 || player1_select < 1) {
                std::cout << '\n' << "Invalid election. Please select a space 1-6: ";
                std::cin >> player1_select;
            }
            while (game.player1_side[player1_select] == 0) {
                std::cout << '\n' << "Please select a non-empty space 1-6: ";
                std::cin >> player1_select;
            }
            free_turn = turn(game, 1, player1_select);
        }
        
        printBoard(game);
        
        // computer turn
        free_turn = false;
        
        std::cout << "Computer's turn!";
        
        int select = minimax(&game);
        
        std::cout << '\n' << "Computer selected space " << select << "!" << '\n';;
        
        free_turn = turn(game, 2, select);
        
        while (free_turn) {
            
            printBoard(game);
            
            std::cout << "FREE TURN" << '\n' << '\n';
            
            std::cout << "Computer's turn!";
            
            int select = minimax(&game);
            
            std::cout << '\n' << "Computer selected space " << select << "!" << '\n';
            
            free_turn = turn(game, 2, select);
        }
    }
    
    if (game.player1_collection > game.player2_collection) {
        std::cout << '\n' << "YOU WON BY " <<
        game.player1_collection - game.player2_collection << "!" << '\n';
    }
    else if (game.player2_collection > game.player1_collection) {
        std::cout << '\n' << "YOU LOST BY " <<
        game.player2_collection - game.player1_collection << "!" << '\n';
    }
    else {
        std::cout << "THERE WAS A TIE!" << '\n';
    }
}



// returns the optimal selection, an int 1-6
// MINIMAX search with Alpha-Beta pruning
// g is the current state of the game
int minimax(Game *game) {
    int alpha = -99999;
    int beta = 99999;
    Game new_game;
    // deep copy
    new_game.player1_collection = game->player1_collection;
    new_game.player2_collection = game->player2_collection;
    for (int i = 0; i < 6; ++i) {
        new_game.player1_side[i] = game->player1_side[i];
        new_game.player2_side[i] = game->player2_side[i];
    }
    Game * temp = &new_game;
    int first_action = 1;
    return max_value(temp, alpha, beta, first_action, 0).first;
}

// returns:
// first = action
// second = utility
std::pair<int, int> max_value(Game *game, int& alpha, int& beta, int& last_action, int depth) {
    if (terminal_test(game)) return std::make_pair(last_action, utility(game));
    
    int v = -99999;
    int act = last_action;
    
    static int stop = 0;
    for (int i = 1; i <= 6; ++i) {
        stop++;
        if (stop < 5) {
            int temp = min_value(result(game, i), alpha, beta, i, depth + 1).second;
            if (temp > v) act = i;
            v = std::max(v, temp);
        }
        stop = 0;
    }
    
    if (v >= beta) {
        return std::make_pair(act, v);
    }
    
    alpha = std::max(alpha, v);
    
    return std::make_pair(act, v);
}

std::pair<int, int> min_value(Game *game, int& alpha, int& beta, int& last_action, int depth) {
    if (terminal_test(game)) return std::make_pair(last_action, utility(game));
    
    int v = 99999;
    int act = last_action;
    
    static int stop_min = 0;
    for (int i = 1; i <= 6; ++i) {
        stop_min++;
        if (stop_min < 5) {
            int temp = max_value(result(game, i), alpha, beta, i, depth + 1).second;
            if (temp < v) act = i;
            v = std::min(v, temp);
        }
        stop_min = 0;
    }
    
    if (v <= alpha) {
        return std::make_pair(act, v);
    }
    
    beta = std::min(beta, v);
    
    return std::make_pair(act, v);
}

bool terminal_test(Game *game) {
    int player1_empties = 0;
    int player2_empties = 0;
    for (int i = 0; i < 6; ++i) {
        if (!game->player1_side[i]) {
            player1_empties++;
        }
        if (!game->player2_side[i]) {
            player2_empties++;
        }
    }
    if (player1_empties == 6 || player2_empties == 6) {
        return true;
    }
    return false;
}

// zero-sum game
int utility(Game *game) {
    if (game->player2_collection > game->player1_collection) {
        return 1;
    }
    else if (game->player2_collection < game->player1_collection) {
        return -1;
    }
    else {
        return 0;
    }
}

Game* result(Game *game, int action) {
    int num_beads = game->player2_side[action - 1];
    game->player2_side[action - 1] = 0;
    
    for (int i = action - 2; i >= 0 && num_beads > 0; --i) {
        game->player2_side[i]++;
        
        // CAPTURE
        if ((num_beads == 1) && (game->player2_side[i] == 1) && (game->player1_side[i] != 0)) {
            game->player2_collection = game->player2_collection + 1 +
            game->player1_side[i];
            
            game->player1_side[i] = 0;
            game->player2_side[i] = 0;
        }
        
        num_beads--;
    }
    if (num_beads) {
        game->player2_collection++;
        
        // FREE TURN
        if (num_beads == 1) {
            return game;
        }
        
        num_beads--;
    }
    if (num_beads) {
        for (int i = 0; i < 6 && num_beads > 0; ++i) {
            game->player1_side[i]++;
            num_beads--;
        }
    }
    while (num_beads) {
        if (num_beads) {
            for (int i = 5; i >= 0 && num_beads > 0; --i) {
                game->player2_side[i]++;
                
                // CAPTURE
                if ((num_beads == 1) && (game->player2_side[i] == 1) && (game->player1_side[i] != 0)) {
                    game->player2_collection = game->player2_collection + 1 +
                    game->player1_side[i];
                    
                    game->player1_side[i] = 0;
                    game->player2_side[i] = 0;
                }
                
                num_beads--;
            }
        }
        if (num_beads) {
            game->player2_collection++;
            
            // FREE TURN
            if (num_beads == 1) {
                return game;
            }
            
            num_beads--;
        }
        if (num_beads) {
            for (int i = 0; i < 6 && num_beads > 0; ++i) {
                game->player1_side[i]++;
                num_beads--;
            }
        }
    }
    
    return game;
}
