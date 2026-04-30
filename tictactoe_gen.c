#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>  /* assert() */

#define SIZE 4
#define CELL_MAX (SIZE * SIZE - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[SIZE][SIZE])
{
    int cell = 0;

    print_sep(SIZE);
    for (int row = 0; row < SIZE; ++row) {
        for (int column = 0; column < SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(SIZE);
    }
}

bool has_free_cell(char board[SIZE][SIZE]){
unsigned int i;
unsigned int j;
bool free_cell;

i = 0;
free_cell = false;

    while (i < SIZE){
        j = 0;
        while (j < SIZE) {
            if (board[i][j] == '-'){
                free_cell = true;
            }
            j++;
        }
        i++;
    }
    return free_cell;
}


char get_winner(char board[SIZE][SIZE]){
    char winner = '-';
    unsigned int i = 0;
    unsigned int j = 0;
    char first;
    bool all_equal;

//filas
    while (i < SIZE) {
        first = board[i][0];
        all_equal = (first != '-');

        j = 1;
        while (j < SIZE && all_equal){
           all_equal = all_equal && (board[i][j] == first);
        
        j++;
    }

    if (all_equal){
        winner = first;
    }

    i++;
}

//columnas
i = 0;

    while (i < SIZE) {
        first = board[0][i];
        all_equal = (first != '-');
        j = 1;

        while (j < SIZE && all_equal){
           all_equal = all_equal && (board[j][i] == first);
        
        j++;
    }

    if (all_equal){
        winner = first;
    }

    i++;
}

//diagonal principal
        first = board[0][0];
        all_equal = (first != '-');
        i = 1;

        while (i < SIZE && all_equal){
            all_equal = all_equal && (board[i][i] == first);
            i++;
        
    }

    if (all_equal){
        winner = first;
    }

    

//diagonal secundaria    
        first = board[0][SIZE - 1];
        all_equal = (first != '-');
        i = 1;

        while (i < SIZE && all_equal){
            all_equal = all_equal && (board[i][SIZE - 1 - i] == first);
            i++;
        
    }

    if (all_equal){
        winner = first;
    }
    return winner;
}
int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[SIZE][SIZE] = {
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' }
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
            int row = cell / SIZE;
            int colum = cell % SIZE;
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