/*
Romain Gadani
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Card {
    int Number;         // 1 to 13
    char* Symbol;       // carreau or pic or trefle or coeur
    int ReturnedCard;   // 0 or 1
    int CardSlot;       // 0 or 1 or 2
    int IdCard;         // 1 to 52
    char RightChild;    // FALSE or &AdresseMemoire
    char LeftChild;     // FALSE or &AdresseMemoire
    char RightParent;   // FALSE or &AdresseMemoire
    char LeftParent;    // FALSE or &AdresseMemoire
    char Next;          // FALSE or &AdresseMemoire
    char Previous;      // FALSE or &AdresseMemoire
};
typedef struct Card sCard;

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

void InitialisationCards(sListCards *list) {
    sCard car;
    sCard carnext;
    sCard carprevious;

    int i = 1;
    int x = 1;

    while (i <= 13) {
        int j = 1;
        while (j <= 4) {
            if (j == 1) {
                car.Symbol = "carreau";
            }
            else if (j == 2) {
                car.Symbol = "pic";
            }
            else if (j == 3) {
                car.Symbol = "trefle";
            }
            else if (j == 4) {
                car.Symbol = "coeur";
            }

            if (i == 1 && j == 1) {
                list->First = &car;
                car.Next = &carprevious;
            }
            else if (i == 13 && j == 4) {
                list->Last = &car;
                car.Previous = &carprevious;
            }
            else if () {

            }
            
            car.Number = i;
            j += 1;

            car.IdCard = x;
            x += 1;
            
            list-

        }
        i += 1;    
    }   
}

int main(void) {
    sListCards *list;
    InitialisationCards(*list);
}
