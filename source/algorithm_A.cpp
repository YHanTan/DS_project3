#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/algorithm.h"

using namespace std;

/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions
 * 1. ~ 4. are listed in next block)
 *
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 *
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/
int total_explo=0;


void algorithm_A(Board board, Player player, int index[]){

    // cout << board.get_capacity(0, 0) << endl;
    // cout << board.get_orbs_num(0, 0) << endl;
    // cout << board.get_cell_color(0, 0) << endl;
    // board.print_current_board(0, 0, 0);

    //////////// Random Algorithm ////////////
    // Here is the random algorithm for your reference, you can delete or comment it.
    srand(time(NULL));
    int row, col;
    int row_tmp, col_tmp;
    int color = player.get_color();

    /*while(1){
        row = rand() % 5;
        col = rand() % 6;
        if(board.get_cell_color(row, col) == color || board.get_cell_color(row, col) == 'w') break;
    }*/
    if(board.get_cell_color(0, 0) == 'w'){
        index[0] = 0;
        index[1] = 0;
    }
    else if(board.get_cell_color(4, 5) == 'w'){
        index[0] = 4;
        index[1] = 5;
    }
    else if(board.get_cell_color(4, 0) == 'w'){
        index[0] = 4;
        index[1] = 0;
    }
    else if(board.get_cell_color(0, 5) == 'w'){
        index[0] = 0;
        index[1] = 5;
    }
    else if(board.get_cell_color(0,0)==color && ((board.get_cell_color(0,1)!=color && board.get_orbs_num(0,1)==2) || (board.get_cell_color(1,0)!=color && board.get_orbs_num(1,0)==2))){
        index[0] = 0;
        index[1] = 0;
    }
    else if(board.get_cell_color(4,5)==color && ((board.get_cell_color(4,4)!=color && board.get_orbs_num(4,4)==2) || (board.get_cell_color(3,5)!=color && board.get_orbs_num(3,5)==2))){
        index[0] = 4;
        index[1] = 5;
    }
    else if(board.get_cell_color(4,0)==color && ((board.get_cell_color(3,0)!=color && board.get_orbs_num(3,0)==2) || (board.get_cell_color(4,1)!=color && board.get_orbs_num(4,1)==2))){
        index[0] = 4;
        index[1] = 0;
    }
    else if(board.get_cell_color(0,5)==color && ((board.get_cell_color(0,4)!=color && board.get_orbs_num(0,4)==2) || (board.get_cell_color(1,5)!=color && board.get_orbs_num(1,5)==2))){
        index[0] = 0;
        index[1] = 5;
    }
    else{
        /*while(1){
            row = rand() % 5;
            col = rand() % 6;
            if(board.get_cell_color(row, col) == color || board.get_cell_color(row, col) == 'w') break;
        }
        int orbLack = board.get_capacity(row,col)-board.get_orbs_num(row,col);
*/
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(board.get_cell_color(i,j)==color || board.get_cell_color(i,j)=='w'){
                    if( (board.get_capacity(i,j)-board.get_orbs_num(i,j))>1 ){
                        row=i;
                        row_tmp=i;
                        col=j;
                        col_tmp=j;
                    }
                    else{
                        row = row_tmp;
                        col = col_tmp;
                    }
                }
            }
        }
        bool explode=false;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(board.get_cell_color(i,j)==color || board.get_cell_color(i,j)=='w'){
                    if( (board.get_capacity(i,j)-board.get_orbs_num(i,j))==1 ){
                        if((i-1)>=0 && board.get_cell_color(i-1, j)!=color && (board.get_capacity(i-1,j)-board.get_orbs_num(i-1,j))==1){
                            row=i;
                            col=j;
                            explode=true;
                            total_explo++;
                            break;
                        }
                        else if((i+1)<5 && board.get_cell_color(i+1, j)!=color && (board.get_capacity(i+1,j)-board.get_orbs_num(i+1,j))==1){
                            row=i;
                            col=j;
                            explode=true;
                            total_explo++;
                            break;
                        }
                        else if((j-1)>=0 && board.get_cell_color(i, j-1)!=color && (board.get_capacity(i,j-1)-board.get_orbs_num(i,j-1))==1){
                            row=i;
                            col=j;
                            explode=true;
                            total_explo++;
                            break;
                        }
                        else if((j+1)<6 && board.get_cell_color(i, j+1)!=color && (board.get_capacity(i,j+1)-board.get_orbs_num(i,j+1))==1){
                            row=i;
                            col=j;
                            explode=true;
                            total_explo++;
                            break;
                        }
                    }
                }
            }
            if(explode){
                break;
            }
        }
        index[0] = row;
        index[1] = col;
        cout << total_explo << endl;
    }
}
