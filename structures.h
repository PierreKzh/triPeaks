#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NbCards 52

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
    sCard* FirstRightImaginary;   // &AdresseMemoire
    sCard* FirstLeftImaginary;    // &AdresseMemoire
};
typedef struct TreeCards sTreeCards;

struct ListCards {
    sCard* First;       // &AdresseMemoire
    sCard* Last;        // &AdresseMemoire
    int NumberElements; // 1 to (max) 52
};
typedef struct ListCards  sListCards;

struct Player {
    char* surname;
};
typedef struct Player sPlayer;

void InitialisationCards(sCard* tab);
void ShuffleCards(sCard* tab);
void InitialisationPyramide(sCard* tab);
int win(sListCards* Reserve, sListCards* Fondation);
void InitialisationListeOaked(sCard* tabCard, sListCards* Reserve, sListCards* Fondation);
void AffichagePlateau(sCard* tab);
void Surname(sPlayer* play);
void DrawCard(sListCards* Reserve, sListCards* Fondation);
