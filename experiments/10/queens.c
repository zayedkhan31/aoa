#include<stdio.h>
#include<stdlib.h>
#define BOARD_LENGTH 8

int solve_recursive(int board[BOARD_LENGTH][BOARD_LENGTH], int i) {
    int j;
    if (i >= BOARD_LENGTH) return 1;

    for(j = 0; j < BOARD_LENGTH; j++) {
        if (!check_positions(board, j, i)) 
            continue;

        board[j][i] = 1;
        if (solve_recursive(board, i + 1) > 0) 
            return 1;
        board[j][i] = 0;
    }
    return 0;
}

int check_positions(int board[BOARD_LENGTH][BOARD_LENGTH], int u, int v) {
    int i, j, k;
    j = u - v;
    k = u + v;
    for(i = 0; i < v; i++) {
        if (board[u][i] == 1) return 0;
        if (j >= 0 && board[j][i] == 1) return 0;
        if (k < BOARD_LENGTH && board[k][i] == 1) return 0;
        j++;
        k--;
    }
    return 1;
}

void initialize(int board[BOARD_LENGTH][BOARD_LENGTH]) {
    int i, j;
    for (i = 0; i < BOARD_LENGTH; i++){
        for (j = 0; j < BOARD_LENGTH; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board(int board[BOARD_LENGTH][BOARD_LENGTH]) {
    int i, j;
     
    for (i = 0; i < BOARD_LENGTH; i++){
        printf("--");
    }
    printf("\n");
    for (i = 0; i < BOARD_LENGTH; i++){
        for (j = 0; j < BOARD_LENGTH; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < BOARD_LENGTH; i++){
        printf("--");
    }
    printf("\n");
}

void main(){
    int board[BOARD_LENGTH][BOARD_LENGTH];
    initialize(board);
    print_board(board);
    solve_recursive(board, 0);
    print_board(board);

}
