#define _CRT_SECURE_NO_WARNINGS
#define NbCards 52

#include <stdio.h>
#include <stdlib.h>
#include <time.h>





// Function Random position allocation
void random(sCard* tab) {
    //Initialise srand sur le temps actuel
    srand(time(NULL));
    
    int i;

    for (i = NbCards - 1; i > 0; i--) {
        // Random Position between 0 and i
        int RandomPosition = rand() % (i + 1);
        // Starts the function exchange
        sCard tmp;
        tmp = tab[i];
        tab[i] = tab[RandomPosition];
        tab[RandomPosition] = tmp;

    }

}


// Main Function from ShuffleCards
void ShuffleCards(sCard* tab) {
    int Position[NbCards];
    int i;

    // Generate array with static position
    for (i = 0; i < NbCards; i++) {
        Position[i] = i;

    }

    // Showing the cards before shuffling
    /*
    printf("===Before===\n");

    for (i = 0; i < NbCards; i++) {
        int DeckPosition = Position[i];

        printf("%2d - %d, %c\n", i + 1, tab[DeckPosition].Number, tab[DeckPosition].Symbol);

    }
    */

    // Showing the cards after shuffling
    //printf("\n===After===\n");
    // Starts the function to retrieve the new positions of the cards 
    random(tab);
    printf("\n");

    for (i = 0; i < NbCards; i++) {
        printf("%2d - %d, %c\n", i + 1, tab[i].Number, tab[i].Symbol);

    }

}

void ShuffleCards(sCard* tab);