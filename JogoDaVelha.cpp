#include <stdio.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int main() {
    int player = 1, pos;
    
    for (int turn = 0; turn < 9; turn++) {
        printBoard();
        printf("\nJogador %d, escolha uma posição (1-9): ", player);
        scanf("%d", &pos);
        
        if (pos < 1 || pos > 9) {
            printf("Posição inválida. Tente novamente.\n");
            turn--;
            continue;
        }

        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Posição já ocupada. Tente novamente.\n");
            turn--;
            continue;
        }

        board[row][col] = (player == 1) ? 'X' : 'O';

        if (checkWin()) {
            printBoard();
            printf("\nJogador %d venceu!\n", player);
            return 0;
        }

        player = (player == 1) ? 2 : 1;
    }

    printBoard();
    printf("\nEmpate!\n");
    return 0;
}