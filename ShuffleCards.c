#include "ShuffleCards.h"

//Jean-Baptiste F

// Function Random position allocation
void random(sCard* tab) {
    //Initialise srand sur le temps actuel
    srand(time(NULL));

    for (int i = NbCards - 1; i > 0; i--) {
        // Random Position between 0 and i
        int RandomPosition = rand() % (i + 1);
        // Starts the function exchange
        sCard tmp;
        tmp = tab[i];
        tab[i] = tab[RandomPosition];
        tab[RandomPosition] = tmp;
    }
}

/*==================================================================================================================================*/

// Main Function from ShuffleCards
void ShuffleCards(sCard* tab) {
    int Position[NbCards];
    int i;

    // Generate array with static position
    for (i = 0; i < NbCards; i++) {
        Position[i] = i;
    }

    // Starts the function to retrieve the new positions of the cards 
    //printf("\n===After shuffling===\n");
    random(tab);
    //printf("\n");

    /*for (i = 0; i < NbCards; i++) {
        printf("%2d - %d, %c\n", i + 1, tab[i].Number, tab[i].Symbol);
    }*/
}