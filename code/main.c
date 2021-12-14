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