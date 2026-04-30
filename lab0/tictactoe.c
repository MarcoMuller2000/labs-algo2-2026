#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

bool has_free_cell(char board[3][3]){
unsigned int i;
unsigned int j;
bool free_cell;

i = 0;
free_cell = false;

    while (i < 3){
        j = 0;
        while (j < 3) {
            if (board[i][j] == '-'){
                free_cell = true;
            }
            j++;
        }
        i++;
    }
    return free_cell;
}


char get_winner(char board[3][3]){
    char winner = '-';
    unsigned int i = 0;
    unsigned int j = 0;

    while (i < 3) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-'){
            winner = board[i][0];
        }
        i++;
    }

    while (j < 3) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-'){
            winner = board[0][j];
        }
        j++;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-'){
        winner = board [0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-'){
        winner = board [0][2];
    }
    return winner;

}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}