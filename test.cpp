//
//  test.cpp
//  mancala
//
//  Created by Emma Luukkonen on 5/4/20.
//  Copyright © 2020 Emma Luukkonen. All rights reserved.
//

#include <stdio.h>
#include "mancala.h"
#include <assert.h>

void test_1_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 1, 1);
    assert(game.player1_side[0] == 0);
    assert(game.player1_side[1] == 5);
    assert(game.player1_side[2] == 5);
    assert(game.player1_side[3] == 5);
    assert(game.player1_side[4] == 5);
    assert(game.player1_side[5] == 4);
    for (int i = 0; i < 6; ++i) {
        assert(game.player2_side[i] == 4);
    }
    assert(game.player1_collection == 0);
    assert(game.player2_collection == 0);
    
    std::cout << "Test 1 Passed" << '\n';
}

void test_2_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 1, 2);
    assert(game.player1_side[0] == 4);
    assert(game.player1_side[1] == 0);
    assert(game.player1_side[2] == 5);
    assert(game.player1_side[3] == 5);
    assert(game.player1_side[4] == 5);
    assert(game.player1_side[5] == 5);
    for (int i = 0; i < 6; ++i) {
        assert(game.player2_side[i] == 4);
    }
    assert(game.player1_collection == 0);
    assert(game.player2_collection == 0);
    
    std::cout << "Test 2 Passed" << '\n';
}

void test_3_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 1, 3);
    assert(game.player1_side[0] == 4);
    assert(game.player1_side[1] == 4);
    assert(game.player1_side[2] == 0);
    assert(game.player1_side[3] == 5);
    assert(game.player1_side[4] == 5);
    assert(game.player1_side[5] == 5);
    for (int i = 0; i < 6; ++i) {
        assert(game.player2_side[i] == 4);
    }
    assert(game.player1_collection == 1);
    assert(game.player2_collection == 0);
    
    std::cout << "Test 3 Passed" << '\n';
}

void test_4_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 1, 4);
    assert(game.player1_side[0] == 4);
    assert(game.player1_side[1] == 4);
    assert(game.player1_side[2] == 4);
    assert(game.player1_side[3] == 0);
    assert(game.player1_side[4] == 5);
    assert(game.player1_side[5] == 5);
    for (int i = 4; i >= 0; --i) {
        assert(game.player2_side[i] == 4);
    }
    assert(game.player2_side[5] == 5);
    assert(game.player1_collection == 1);
    assert(game.player2_collection == 0);
    
    std::cout << "Test 4 Passed" << '\n';
}

void test_5_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 1, 5);
    assert(game.player1_side[0] == 4);
    assert(game.player1_side[1] == 4);
    assert(game.player1_side[2] == 4);
    assert(game.player1_side[3] == 4);
    assert(game.player1_side[4] == 0);
    assert(game.player1_side[5] == 5);
    for (int i = 3; i >= 0; --i) {
        assert(game.player2_side[i] == 4);
    }
    assert(game.player2_side[5] == 5);
    assert(game.player2_side[4] == 5);
    assert(game.player1_collection == 1);
    assert(game.player2_collection == 0);
    
    std::cout << "Test 5 Passed" << '\n';
}

void test_6_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 1, 6);
    assert(game.player1_side[0] == 4);
    assert(game.player1_side[1] == 4);
    assert(game.player1_side[2] == 4);
    assert(game.player1_side[3] == 4);
    assert(game.player1_side[4] == 4);
    assert(game.player1_side[5] == 0);
    for (int i = 2; i >= 0; --i) {
        assert(game.player2_side[i] == 4);
    }
    assert(game.player2_side[5] == 5);
    assert(game.player2_side[4] == 5);
    assert(game.player2_side[3] == 5);
    assert(game.player1_collection == 1);
    assert(game.player2_collection == 0);
    
    std::cout << "Test 6 Passed" << '\n';
}

void test_1_1_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 2, 1);
    assert(game.player2_side[0] == 0);
    assert(game.player2_side[1] == 4);
    assert(game.player2_side[2] == 4);
    assert(game.player2_side[3] == 4);
    assert(game.player2_side[4] == 4);
    assert(game.player2_side[5] == 4);

    assert(game.player1_side[0] == 5);
    assert(game.player1_side[1] == 5);
    assert(game.player1_side[2] == 5);
    assert(game.player1_side[3] == 4);
    assert(game.player1_side[4] == 4);
    assert(game.player1_side[5] == 4);
    
    assert(game.player1_collection == 0);
    assert(game.player2_collection == 1);
    
    std::cout << "Test 7 Passed" << '\n';
}

void test_1_2_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 2, 2);
    assert(game.player2_side[0] == 5);
    assert(game.player2_side[1] == 0);
    assert(game.player2_side[2] == 4);
    assert(game.player2_side[3] == 4);
    assert(game.player2_side[4] == 4);
    assert(game.player2_side[5] == 4);
    
    assert(game.player1_side[0] == 5);
    assert(game.player1_side[1] == 5);
    assert(game.player1_side[2] == 4);
    assert(game.player1_side[3] == 4);
    assert(game.player1_side[4] == 4);
    assert(game.player1_side[5] == 4);
    
    assert(game.player1_collection == 0);
    assert(game.player2_collection == 1);
    
    std::cout << "Test 8 Passed" << '\n';
}

void test_1_3_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 2, 3);
    assert(game.player2_side[0] == 5);
    assert(game.player2_side[1] == 5);
    assert(game.player2_side[2] == 0);
    assert(game.player2_side[3] == 4);
    assert(game.player2_side[4] == 4);
    assert(game.player2_side[5] == 4);
    
    assert(game.player1_side[0] == 5);
    assert(game.player1_side[1] == 4);
    assert(game.player1_side[2] == 4);
    assert(game.player1_side[3] == 4);
    assert(game.player1_side[4] == 4);
    assert(game.player1_side[5] == 4);
    
    assert(game.player1_collection == 0);
    assert(game.player2_collection == 1);
    
    std::cout << "Test 9 Passed" << '\n';
}

void test_1_4_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 2, 4);
    assert(game.player2_side[0] == 5);
    assert(game.player2_side[1] == 5);
    assert(game.player2_side[2] == 5);
    assert(game.player2_side[3] == 0);
    assert(game.player2_side[4] == 4);
    assert(game.player2_side[5] == 4);
    
    assert(game.player1_side[0] == 4);
    assert(game.player1_side[1] == 4);
    assert(game.player1_side[2] == 4);
    assert(game.player1_side[3] == 4);
    assert(game.player1_side[4] == 4);
    assert(game.player1_side[5] == 4);
    
    assert(game.player1_collection == 0);
    assert(game.player2_collection == 1);
    
    std::cout << "Test 10 Passed" << '\n';
}

void test_1_5_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 2, 5);
    assert(game.player2_side[0] == 5);
    assert(game.player2_side[1] == 5);
    assert(game.player2_side[2] == 5);
    assert(game.player2_side[3] == 5);
    assert(game.player2_side[4] == 0);
    assert(game.player2_side[5] == 4);
    
    assert(game.player1_side[0] == 4);
    assert(game.player1_side[1] == 4);
    assert(game.player1_side[2] == 4);
    assert(game.player1_side[3] == 4);
    assert(game.player1_side[4] == 4);
    assert(game.player1_side[5] == 4);
    
    assert(game.player1_collection == 0);
    assert(game.player2_collection == 0);
    
    std::cout << "Test 11 Passed" << '\n';
}

void test_1_6_multi() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 4;
        game.player2_side[i] = 4;
    }
    turn(game, 2, 6);
    assert(game.player2_side[0] == 4);
    assert(game.player2_side[1] == 5);
    assert(game.player2_side[2] == 5);
    assert(game.player2_side[3] == 5);
    assert(game.player2_side[4] == 5);
    assert(game.player2_side[5] == 0);
    
    assert(game.player1_side[0] == 4);
    assert(game.player1_side[1] == 4);
    assert(game.player1_side[2] == 4);
    assert(game.player1_side[3] == 4);
    assert(game.player1_side[4] == 4);
    assert(game.player1_side[5] == 4);
    
    assert(game.player1_collection == 0);
    assert(game.player2_collection == 0);
    
    std::cout << "Test 12 Passed" << '\n';
}

void test_48_1() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player2_side[i] = 0;
    }
    for (int i = 0; i < 5; ++i) {
        game.player1_side[i] = 0;
    }
    game.player1_side[5] = 48;
    turn(game, 1, 6);
    
    for (int i = 0; i < 6; ++i) {
        assert(game.player2_side[i] == 4);
    }
    
    assert(game.player1_collection == 4);
    assert(game.player2_collection == 0);
    
    std::cout << "Test 48 1 Passed" << '\n';
}

void test_48_2() {
    Game game;
    for (int i = 0; i < 6; ++i) {
        game.player1_side[i] = 0;
    }
    for (int i = 0; i < 5; ++i) {
        game.player2_side[i] = 0;
    }
    game.player2_side[5] = 48;
    turn(game, 2, 6);
    
    assert(game.player1_side[0] == 4);
    assert(game.player1_side[1] == 4);
    assert(game.player1_side[2] == 4);
    assert(game.player1_side[3] == 3);
    assert(game.player1_side[4] == 3);
    assert(game.player1_side[5] == 3);
    
    assert(game.player2_side[0] == 4);
    assert(game.player2_side[1] == 4);
    assert(game.player2_side[2] == 4);
    assert(game.player2_side[3] == 4);
    assert(game.player2_side[4] == 4);
    assert(game.player2_side[5] == 3);
    
    assert(game.player1_collection == 0);
    assert(game.player2_collection == 4);
    
    std::cout << "Test 48 2 Passed" << '\n';
}

int main() {
    test_1_multi();
    test_2_multi();
    test_3_multi();
    test_4_multi();
    test_5_multi();
    test_6_multi();
    test_1_1_multi();
    test_1_2_multi();
    test_1_3_multi();
    test_1_4_multi();
    test_1_5_multi();
    test_1_6_multi();
    test_48_1();
    test_48_2();
    
    return 0;
}
