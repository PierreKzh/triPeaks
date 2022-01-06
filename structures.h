#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NbCards 52

typedef struct Card sCard;
struct Card {
    int Number;         // 1 to 13
    char Symbol;        // spades, hearts, diamonds and clubs
    int ReturnedCard;   // 0 hiden or 1 visible
    int CardSlot;       // 0 = no slot or 1 = tree or 2 = reserve or 3 = fondation
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

void InitialisationCards(sCard* tab[52]);
void ShuffleCards(sCard* tab[52]);
void InitialisationPyramide(sCard* tab[52]);
void InitialisationListeOaked(sCard* tabCard[52], sListCards* Reserve, sListCards* Fondation);
void AffichagePlateau(sCard* tab[52], sListCards* Fondation, sListCards* Reserve);
void Surname(sPlayer* play);
void DrawCard(sListCards* Reserve, sListCards* Fondation);
void PickCard(sCard* tabcard[52], sListCards* Fondation, int cardvalue, char cardColor);
int LooseWin(sCard* tabCard[52], sListCards* Reserve, sListCards* Fondation);