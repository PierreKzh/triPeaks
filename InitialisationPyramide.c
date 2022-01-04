#include "InitialisationPyramide.h"

//Romain G

void InitialisationPyramide(sCard* tab) {
    int i = 0;
    while (i < 28) {
        tab[i].ReturnedCard = 1;
        tab[i].CardSlot = 1;
        printf("%d : %d\n", tab[i].IdCard, tab[i].CardSlot);
        i += 1;
    }

    //first line
    i = 0;
    int x = 3;
    while (i < 3) {
        tab[i].LeftChild = &tab[i + x];
        x += 1;
        tab[i].RightChild = &tab[i + x];
        i += 1;
    }

    //seconde line
    x = 6;
    int y = 0;
    while (i < 9) {
        tab[i].LeftChild = &tab[i + x];
        tab[i].RightChild = &tab[i + x + 1];
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
        tab[i].LeftChild = &tab[i + x];
        tab[i].RightChild = &tab[i + x + 1];
        i += 1;
    }

    //last line
    while (i < 28) {
        i += 1;
    }
}