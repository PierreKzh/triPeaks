#include "InitialisationPyramide.h"

//Romain G

void InitialisationPyramide(sCard* tab) {
    int i = 0;
    while (i < 28) {
        tab->ReturnedCard = 1;
        tab->CardSlot = 0;
        i += 1;
    }

    i = 0;
    int x = 3;
    while (i < 3) {
        tab[i].LeftChild = &tab[i + x];
        x += 1;
        tab[i].RightChild = &tab[i + x];
        i += 1;
    }

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

    x = 9;
    while (i < 18) {
        tab[i].LeftChild = &tab[i + x];
        tab[i].RightChild = &tab[i + x + 1];
        i += 1;
    }

    while (i < 28) {
        i += 1;
    }
}