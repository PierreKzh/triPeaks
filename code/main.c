/*
Romain Gadani
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Card sCard;
struct Card {
    int Number;         // 1 to 13
    char Symbol;        // carreau or pic or trefle or coeur
    int ReturnedCard;   // 0 or 1
    int CardSlot;       // 0 or 1 or 2
    int IdCard;         // 1 to 52
    sCard* RightChild;  // FALSE or &AdresseMemoire
    sCard* LeftChild;   // FALSE or &AdresseMemoire
    sCard* RightParent; // FALSE or &AdresseMemoire
    sCard* LeftParent;  // FALSE or &AdresseMemoire
    sCard* Next;        // FALSE or &AdresseMemoire
    sCard* Previous;    // FALSE or &AdresseMemoire
};


struct TreeCards {
    struct sCard* IdCard;
    char FirstRightImaginary;   // &AdresseMemoire
    char FirstLeftImaginary;    // &AdresseMemoire
};
typedef struct TreeCards sTreeCards;

struct ListCards {
    struct sCard* IdCard;
    char First;         // &AdresseMemoire
    char Last;          // &AdresseMemoire
    int NumberElements; // 1 to (max) 52
};
typedef struct ListCards  sListCards;




void InitialisationCards(sListCards *list, sCard *tab) {
    sCard next;
    sCard previous;

    char symboltab[4] = { 'c', 'p', 't', 'h' };

    int i = 1;
    int x = 1;

    while (i <= 13) {
        int j = 0;
        while (j <= 3) {
            tab[x].Symbol = symboltab[j];
            tab[x].Number = i;
            j += 1;
            tab[x].IdCard = x;
            x += 1;
            printf("%d, %s\n", tab[x].Number, tab[x].Symbol);
        }
        i += 1;    
    }
    printf("%p, %", list->Last, list->First);
}

int main(void) {
    sListCards list;
    sCard tab[52];
    InitialisationCards(&list, *tab);
}
