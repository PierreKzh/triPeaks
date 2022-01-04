#include "AffichagePlateau.h"

//JeanBaptiste F & Romain G & Pierre K

char AffichageCaseToLetter(int number) {
    char lettre;

    switch (number) {
    case 1:
        lettre = 'a';
        break;
    case 11:
        lettre = 'j';
        break;
    case 12:
        lettre = 'q';
        break;
    case 13:
        lettre = 'k';
        break;
    default:
        lettre = 'x';
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
        if (tab[i].CardSlot == 1) {
            AffichageCarte(tab[i].Number, tab[i].Symbol);
        }

        else {
            printf("         ");
            
        }
    }
}

void AffichageListes(sListCards* Fondation) {
    printf("\n\n\n[X..X]  [>][>]  ");
    AffichageCarte(Fondation->Last->Number, Fondation->Last->Symbol);
    printf("\n");

}

void AffichagePlateau(sCard tab, sListCards* Fondation) {
    AffichagePyramide(&tab);
    AffichageListes(Fondation);
}