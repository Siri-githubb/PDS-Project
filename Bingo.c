#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int create(int matrix1[5][5],int matrix2[5][5]) 
{
    
    int numbers[25];
    for (int i = 0; i < 25; i++) {
        numbers[i] = i + 1;
    }
    srand((unsigned)clock());
    shuffle(numbers, 25);
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix1[i][j] = numbers[index++];
        }
    }
    srand((unsigned)clock());
    shuffle(numbers, 25);
    index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix2[i][j] = numbers[index++];
        }
    }
    return 0;
}

int matrix(int a[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("  %d\t|", a[i][j]);
        }
        printf("\n");
        printf("  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
        printf("\n\n");
    }
    printf("\n\n");
    return 0;
}


int tocheck(int a[5][5], int b[5][5]) {
    int num;
    printf("Enter your choice ");
    scanf("%d", &num);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i][j] == num)
                a[i][j] = 0;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (b[i][j] == num)
                b[i][j] = 0;
        }
    }
    for(int i=0;i<5;i++){
        int j=i;
        if(a[i][j]==num)
        a[i][j]=0;
    }
    for(int i=0;i<5;i++){
         int j=i;
        if(b[i][j]==num)
        b[i][j]=0;
    }
    return 0;
}


int ifWin(int a[5][5], int b[5][5]) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        int consecutiveZeros = 0;
        for (int j = 0; j < 5; j++) {
            if (a[i][j] == 0) {
                consecutiveZeros++;
                if (consecutiveZeros == 5) {
                    return 1; // Player a has won
                }
            } else {
                consecutiveZeros = 0;
            }
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        int consecutiveZeros = 0;
        for (int i = 0; i < 5; i++) {
            if (a[i][j] == 0) {
                consecutiveZeros++;
                if (consecutiveZeros == 5) {
                    return 1; // Player a has won
                }
            } else {
                consecutiveZeros = 0;
            }
        }
    }

    // Check rows
    for (int i = 0; i < 5; i++) {
        int consecutiveZeros = 0;
        for (int j = 0; j < 5; j++) {
            if (b[i][j] == 0) {
                consecutiveZeros++;
                if (consecutiveZeros == 5) {
                    return 2; // Player b has won
                }
            } else {
                consecutiveZeros = 0;
            }
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        int consecutiveZeros = 0;
        for (int i = 0; i < 5; i++) {
            if (b[i][j] == 0) {
                consecutiveZeros++;
                if (consecutiveZeros == 5) {
                    return 2; // Player b has won
                }
            } else {
                consecutiveZeros = 0;
            }
        }
    }

//diagonals

    int consecutiveZeros1=0;
    for(int i=0;i<5;i++){
        int j=i;
        if(a[i][j]==0)
{
        consecutiveZeros1++;
        if(consecutiveZeros1==5){
        return 1;
        }
    }
    }
    int consecutiveZeros2=0;
    for(int i=0;i<5;i++){
        int j=i;
        if(b[i][j]==0)
{
        consecutiveZeros2++;
        if(consecutiveZeros2==5){
        return 2;
        }
    }
    }
    int consecutiveZeros3 = 0;
    for (int i = 0; i < 5; i++)
    {
            int j=4-i;
            if (a[i][j] == 0)
            {
                consecutiveZeros3++;
                if (consecutiveZeros3 == 5)
                    return 1; 
            } 
        }
    int consecutiveZeros4 = 0;
    for (int i = 0; i < 5; i++) 
    {
        int j=4-i;
            if (b[i][j] == 0)
            {
                consecutiveZeros4++;
                if (consecutiveZeros4 == 5) 
                    return 2; 
            } 
    }

    return 0; // No win yet
}

int main() {
    char s1[30], s2[30];
    printf("\x1b[32mHello Ladies and Gentlemen!\x1b[0m\n");    
    printf("\x1b[31m \t\t\t\t\t\tWelcome to BINGO!\x1b[0m\n");
    printf("\n Player 1, Enter your code name! ");
    gets(s1);
    printf("\n Player 2, Enter your code name! ");
    gets(s2);
    int player1[5][5], player2[5][5];
    printf("The grid for %s is: \n", s1);
    create(player1,player2);
    matrix(player1);
    printf("The grid for %s is: \n", s2);
    printf("\n");
    matrix(player2);
    printf("\n");

    int winner = 0;

    for (int i = 0; i < 25; i++) {
        tocheck(player1, player2);
        printf("%s:\n", s1);
        matrix(player1);
        printf("%s:\n", s2);
        matrix(player2);
        printf("\n\n");
        winner = ifWin(player1, player2);
        if (winner == 1 || winner == 2) {
            break;
        }
    }

    if (winner == 1) {
        printf("Voila %s! Scream bingo!\n", s1);
    } else if (winner == 2) {
        printf("Voila %s! Scream bingo!\n", s2);
    } else {
        printf("Alas! The game ended in a draw. Why not try again?\n");
    }
    printf("\n\t\t\tBINGO!\n\n.");

    return 0;
}