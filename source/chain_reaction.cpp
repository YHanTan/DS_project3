#include <iostream>
#include "../include/board.h"
#include "../include/player.h"
#include "../include/rules.h"
#include "../include/algorithm.h"

using namespace std;

int main(){

    int test=1;
    int A_win=0, B_win=0;
    int A_vio=0, B_vio=0;

    while(test--){
    Board board;
    Player red_player(RED);
    Player blue_player(BLUE);
    bool first_two_step = true;
    int round = 1;
    int index[2];

    while(1){

        //////////// Red Player operations ////////////
        algorithm_A(board, red_player, index);
        board.place_orb(index[0], index[1], &red_player);

        if(rules_violation(red_player)) {
                A_vio++;
                break;
        }

        board.print_current_board(index[0], index[1], round);
        round++;

        if(board.win_the_game(red_player) && !first_two_step){
            cout << "Red Player won the game !!!" << endl;
            A_win++;
            break;
        }

        //////////// Blue Player operations ////////////
        algorithm_C(board, blue_player, index);
        board.place_orb(index[0], index[1], &blue_player);

        if(rules_violation(blue_player)) {
                B_vio++;
                break;
        }

        board.print_current_board(index[0], index[1], round);
        round++;

        if(board.win_the_game(blue_player) && !first_two_step){
            cout << "Blue Player won the game !!!" << endl;
            B_win++;
            break;
        }

        first_two_step = false;
    }
    }
    cout << "A_win: " << A_win << endl << "B_win: " << B_win << endl << "A_vio: " << A_vio << endl << "B_vio: " << B_vio << endl;
    return 0;
}
