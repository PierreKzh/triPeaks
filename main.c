#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(void) {

    //=========InitialistionCards test=========
    sCard TabCard[52];
    InitialisationCards(&TabCard);
    //printf("apres initialisation : %d", TabCard[1].IdCard);
    //=========ShuffleCards test=========
    ShuffleCards(&TabCard);
    //printf("apres shuffle : %d", TabCard[1].IdCard);

    //=========win test=========
    /*sListCards Reserve2;
    sListCards Fondation2;
    Reserve.NumberElements = 24;
    Fondation.NumberElements = 25;
    printf("\n%d", win(&Reserve2, &Fondation2));*/

    //=========initialisationPyramide test=========
    InitialisationPyramide(&TabCard);

    //=========initialisationListOaked test========
    sListCards Reserve;
    Reserve.NumberElements = 0;
    sListCards Fondation;
    Fondation.NumberElements = 0;
    InitialisationListeOaked(&TabCard, &Reserve, &Fondation);
    //printf("\nnb elements reserve : %d", Reserve.NumberElements);
    //printf("\nnb element fondation : %d\n", Fondation.NumberElements);

    //=========AffichagePyramide test=========
    /*AffichagePlateau(&TabCard, &Fondation2);*/

    //=========Surname test=========
    /*sPlayer play;
    Surname(&play);
    free(play.surname);*/

    //==========DrawCard test==================
    /*printf("\ndernier de reserve  : %d", Reserve.Last->IdCard);
    printf("\ndernier de fondation  : %d", Fondation.Last->IdCard);
    DrawCard(&Reserve, &Fondation);
    printf("\ndernier de reserve  : %d", Reserve.Last->IdCard);
    printf("\ndernier de fondation  : %d", Fondation.Last->IdCard);*/

    //========== Jeu ==============
    while (win(&Reserve, &Fondation) == 0) {
        system("@cls||clear");;
        AffichagePlateau(&TabCard, &Fondation);
        char cardColor;
        char cardValue;
        int cardNumber;
        int Choice;

        printf("\n0 : Draw card on the reserve\n1 : Pick card on the board [X..X] ");
        scanf("%d", &Choice);

        if (Choice == 0) {
            DrawCard(&Reserve, &Fondation);
        }
        else if (Choice == 1) {
            printf("\nEnter value :\n> ");
            scanf("%s", &cardValue);
            printf("\nEnter symbol :\n> ");
            scanf(" %c", &cardColor);
            printf("%c\n", cardColor);
            switch (cardValue) {
            case 'a':
                cardNumber = 1;
                break;
            case '2':
                cardNumber = 2;
                break;
            case '3':
                cardNumber = 3;
                break;
            case '4':
                cardNumber = 4;
                break;
            case '5':
                cardNumber = 5;
                break;
            case '6':
                cardNumber = 6;
                break;
            case '7':
                cardNumber = 7;
                break;
            case '8':
                cardNumber = 8;
                break;
            case '9':
                cardNumber = 9;
                break;
            case '10':
                cardNumber = 10;
                break;
            case 'j':
                cardNumber = 11;
                break;
            case 'q':
                cardNumber = 12;
                break;
            case 'k':
                cardNumber = 13;
                break;
            default:
                cardNumber = 0;
                break;
            }
            PickCard(&TabCard, &Fondation, cardNumber, cardColor);
        }
    }
    return 0;
}
