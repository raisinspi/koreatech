#ifndef GAME_H
#define GAME_H


extern int lvl[300][300];
extern char name[300][300][17];
extern int players[300];
extern int room;

void new_room(int l, char n[17]);
void new_player(int l, char n[17], int max);
void sort_and_print(int i);

#endif

