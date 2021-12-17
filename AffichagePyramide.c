#include "AffichagePyramide.h"

//JeanBaptiste F & Romain G

char AffichageCaseToLetter(int number) {
    char lettre;

    switch (number) {
    case 1:
        lettre = 'A';
        break;
    case 11:
        lettre = 'J';
        break;
    case 12:
        lettre = 'Q';
        break;
    case 13:
        lettre = 'K';
        break;
    default:
        lettre = 'X';
        break;
    }
    return(lettre);
}

void AffichageCarte(number, symbol) {
    if (number == 10) {
        printf("|%d.%c|  ", number, symbol);
    }
    else if (number > 10 || number == 1) {
        printf("|%c..%c|  ", AffichageCaseToLetter(number), symbol);
    }
    else {
        printf("|%d..%c|  ", number, symbol);
    }
}

void AffichagePyramide(sCard* tab) {

    for (int i = 0; i < 28; i++)
    {
        // Return to the line for each line of the game
        if (i == 3 || i == 9 || i == 18) {
            printf("\n");
        }

        // Line 1 display management
        if (i <= 2)
        {
            if (i == 0) {
                printf("            ");
            }

            else if (i == 1 || i == 2) {
                printf("                ");
            }
        }

        // Line 2 display management
        else if (i <= 8)
        {
            if (i == 3) {
                printf("        ");
            }

            else if (i == 5 || i == 7) {
                printf("        ");
            }
        }

        // Line 3 display management
        else if (i <= 17)
        {
            if (i == 9) {
                printf("    ");
            }
        }

        // Cards display
        if (tab[i].CardSlot = !0) {
            AffichageCarte(tab[i].Number, tab[i].Symbol);
        }

        else {
            printf("         ");
        }
    }
}