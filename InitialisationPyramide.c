//Romain G

#include "InitialisationPyramide.h"

void InitialisationPyramide(sCard* tab[52]) {
    int i = 0;
    while (i < 28) {
        tab[i]->CardSlot = 1;
        i += 1;
    }

    //first line
    i = 0;
    int x = 3;
    while (i < 3) {
        tab[i]->LeftChild = tab[i + x];
        x += 1;
        tab[i]->RightChild = tab[i + x];
        i += 1;
    }

    //seconde line
    x = 6;
    int y = 0;
    while (i < 9) {
        tab[i]->LeftChild = tab[i + x];
        tab[i]->RightChild = tab[i + x + 1];
        i += 1;
        y += 1;
        if (y == 2) {
            x += 1;
            y = 0;
        }
    }

    //third line
    x = 9;
    while (i < 18) {
        tab[i]->LeftChild = tab[i + x];
        tab[i]->RightChild = tab[i + x + 1];
        i += 1;
    }
}