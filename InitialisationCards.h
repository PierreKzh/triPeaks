#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void InitialisationCards(sCard* tab) {
    char symboltab[4] = { 'c', 'p', 't', 'h' };
    int i = 1;
    int x = 0;

    while (i <= 13) {
        int j = 0;
        while (j <= 3) {
            // Inite cards
            tab[x].Symbol = symboltab[j];
            tab[x].Number = i;
            tab[x].IdCard = x;
            tab[x].ReturnedCard = 0;
            tab[x].CardSlot = 0;
            tab[x].RightChild = NULL;
            tab[x].LeftChild = NULL;
            tab[x].RightParent = NULL;
            tab[x].LeftParent = NULL;
            tab[x].Next = NULL;
            tab[x].Previous = NULL;
            printf("%d, %c\n", tab[x].Number, tab[x].Symbol);
            printf("%d\n\n", x);
            j += 1;
            x += 1;
        }
        i += 1;
    }
    printf("%d", x);
}

void InitialisationCards(sCard* tab);