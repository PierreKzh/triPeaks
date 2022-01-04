#include "InitialisationCards.h"

//Romain G

// Function to init all card
void InitialisationCards(sCard* tab) {
    char symboltab[4] = { 'c', 'p', 't', 'h' };
    int i = 1;
    int x = 0;

    while (i <= 13) {
        int j = 0;
        while (j <= 3) {
            // Init cards
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
            //printf("%d, %c\n", tab[x].Number, tab[x].Symbol);
            j += 1;
            x += 1;
        }
        i += 1;
    }
}