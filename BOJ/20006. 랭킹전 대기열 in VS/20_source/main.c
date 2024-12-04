#include <stdio.h>
#include "game.h"

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
        sort_and_print(i);
    }

    return 0;
}

