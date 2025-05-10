#include <stdio.h>
#include <string.h>

 typedef struct{
    char name[50];
    int win;
    int lose;
    int draw; 
}Player;

    void menu() {
        
        int option;
        while (1) {
        printf("-----MENU GRY----- \n");
        printf("1.Rozpocznij grę.\n");
        printf("2.Wyświetl statystyki \n");
        printf("3.Wyjdź z gry \n");
        printf("Wybierz opcje:");
        scanf("%d",&option);
        getchar();
        switch (option) {
            case 1:
                //startGame();
                break;
            case 2: // wyswietlanie statystyk
                break;
            case 3:
                printf("Zakończono program.\n");
                return;
            default:
                printf("Nieprawidłowy wybór!\n");
            }
        }

    }


    
    void startGame() {
        Player player1, player2;
        printf("Podaj nick gracza 1: ");
        fgets(player1.name,50, stdin);
        player1.name[strcspn(player1.name, "\n")] = 0;
        // tutaj jakoś pobranie statystk z pliku

        printf("Podaj nick gracza 2: ");
        fgets(player2.name,50, stdin);
        player2.name[strcspn(player2.name, "\n")] = 0;
        //tez pobranie statystyk

        //game(&player1, &player2); // rozpoczynamy właściową grę

        // po grze musimy zapisać/ nadpisać wyniki do pliku
        //updateStat();


    }
    // void game(Player player1,Player player2) {

    // }
    void printBoard(char board[3][3]) { //tutaj niby c tworzy kopie boardu, chyba trzeba użyc wskaźnika, jak nie używamy wskaźnika to nie zmienimy oryginalnej tablicy
        printf("\n  1 2 3\n");
        for (int i = 0; i < 3; i++) {
            printf("%d ", i+1);
            for (int j = 0; j < 3; j++) {
                printf("%c", board[i][j]);
                if (j < 2) printf("|");
            }
            if (i < 2) printf("\n  -+-+-\n");
        }
        printf("\n");
    }
    int checkWin(char board[3][3]) {
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if (board[i][0] != ' '&& board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                    return 1; // wygrana w wierszu
                }
                else if (board[0][j] != ' ' && 
                    board[0][j] == board[1][j] && 
                    board[1][j] == board[2][j]) {
                        return 1; // win by column
                    }
            }
        }//  wygrana przekatne
        if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return 1;}

        if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return 1;}
    }
    int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}
    
int main() {
    menu();
    return 0;
}
