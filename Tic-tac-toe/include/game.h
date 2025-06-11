#ifndef GAME_H
#define GAME_H

typedef struct {
    char name[50];
    int win;
    int lose;
    int draw;
    char symbol; // 'X' or 'O'
} Player;

void menu();
void game(Player *player1, Player *player2);
void startGame();
void printBoard(char board[3][3]);
int checkWin(char board[3][3]);
int checkDraw(char board[3][3]);
int findPlayer(const char *filename, const char *szukany_nick, Player *player);
void addPlayer(const char *filename, Player *player);
void showStatistics(const char *filename);
void updateStat(const char *filename, Player *player);
void resetStat(const char *filename);

#endif
