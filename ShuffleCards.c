//Jean-Baptiste F
#include "ShuffleCards.h"

// Function Random position allocation
void random(sCard* tab[52]) {
    //Initialise srand sur le temps actuel
    srand(time(NULL));

    for (int i = NbCards - 1; i > 0; i--) {
        // Random Position between 0 and i
        int RandomPosition = rand() % (i + 1);
        // Starts the function exchange
        sCard *tmp;
        tmp = tab[i];
        tab[i] = tab[RandomPosition];
        tab[RandomPosition] = tmp;
    }
}

// Main Function from ShuffleCards
void ShuffleCards(sCard* tab[52]) {
    int Position[NbCards];
    int i;

    // Generate array with static position
    for (i = 0; i < NbCards; i++) {
        Position[i] = i;
    }

    // Starts the function to retrieve the new positions of the cards 
    random(tab);
}