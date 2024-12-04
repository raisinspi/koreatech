#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int lvl[300][300];
char name[300][300][17];
int players[300];
int room = 0;


void new_room(int l, char n[17]) {
    lvl[room][0] = l;
    strcpy(name[room][0], n);
    players[room] = 1;
    room++;
}


void new_player(int l, char n[17], int m) {
    int i;
    
    for(i = 0; i < room; i++) {
        if(players[i] < m && abs(lvl[i][0] - l) <= 10) {
            lvl[i][players[i]] = l;
            strcpy(name[i][players[i]], n);
            players[i]++;
            return;
        }
    }
    new_room(l, n);
}


void salt_and_pepper(int i) {
    int j, k;
    printf(players[i] == players[0] ? "Started!\n" : "Waiting!\n");
    
    //bubble
    for(j = 0; j < players[i]; j++) {
        for(k = j + 1; k < players[i]; k++) {
            if(strcmp(name[i][j], name[i][k]) > 0) {
                int t = lvl[i][j];
                lvl[i][j] = lvl[i][k];
                lvl[i][k] = t;

                char tt[17];
                strcpy(tt, name[i][j]);
                strcpy(name[i][j], name[i][k]);
                strcpy(name[i][k], tt);
            }
        }
        printf("%d %s\n", lvl[i][j], name[i][j]);
    }
}


int main(void) {
    int p, max, i;
    scanf("%d %d", &p, &max);

    for(i = 0; i < p; i++) {
        int l;
        char n[17];
        scanf("%d %s", &l, n);
        new_player(l, n, max);
    }
    for(i = 0; i < room; i++) {
        salt_and_pepper(i);
    }

    return 0;
}

