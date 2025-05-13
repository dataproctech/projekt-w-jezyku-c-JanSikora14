#include <stdio.h>
#include <string.h>

 typedef struct{
    char name[50];
    int win;
    int lose;
    int draw; 
}Player;
void menu();
void startGame();
void printBoard(char board[3][3]);
int checkWin(char board[3][3]);
int checkDraw(char board[3][3]);
int findPlayer(const char *filename, const char *szukany_nick, Player *player);
void addPlayer(const char *filename, Player *player);
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
        if (!findPlayer(filename,player1.name,&player1)) {
            player1.win=player1.lose=player1.draw=0;
            addPlayer(filename,&player1);
        }

        // tutaj jakoś pobranie statystk z pliku

        printf("Podaj nick gracza 2: ");
        fgets(player2.name,50, stdin);
        player2.name[strcspn(player2.name, "\n")] = 0;
        if (!findPlayer(filename,player2.name,&player2)) {
            player2.win=player2.lose=player2.draw=0;
            addPlayer(filename,&player2);
        }


        //game(&player1, &player2); // rozpoczynamy właściową grę

        // po grze musimy zapisać/ nadpisać wyniki do pliku
        //updateStat();


    }
    // void game(Player *player1,Player *player2) {

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
                        return 1; // wygrana w kolumnie
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
    return 1; }

    int findPlayer(const char *filename, const char *szukany_nick, Player *player) {
    FILE *plik = fopen(filename, "r");
    if (!plik) {
        perror("Nie można otworzyć pliku do odczytu");
        return 0;
    }

    char linia[100];
    while (fgets(linia,100, plik)) {
        Player tmp;
        if (sscanf(linia, "%s %d %d %d", tmp.name, &tmp.win, &tmp.lose, &tmp.draw) == 4) { //patrzymy czy gracz jest juz zapisany w pliku
            if (strcmp(tmp.name, szukany_nick) == 0) {
                *player = tmp;
                fclose(plik);
                return 1;
            }
        }
    }

    fclose(plik);
    return 0;
}

void addPlayer(const char *filename,Player *player) {
    FILE *plik = fopen(filename, "a"); // tryb "a" = append (dopisywanie)
    if (!plik) {
        perror("Nie można otworzyć pliku d");
        return;
    }

    fprintf(plik, "%s %d %d %d\n", (*player).name, (*player).win, (*player).lose, (*player).draw); // dopisujemy do pliku
    fclose(plik);
}

    
int main() {
    menu();


    return 0;
}

