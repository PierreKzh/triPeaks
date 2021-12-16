#include "structures.h"

/*==================================================================================================================================*/


/*==================================================================================================================================*/

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
    printf("\n===After shuffling===\n");
    random(tab);
    printf("\n");

    for (i = 0; i < NbCards; i++) {
        printf("%2d - %d, %c\n", i + 1, tab[i].Number, tab[i].Symbol);
    }
}

/*==================================================================================================================================*/

// Function to init all card
void InitialisationCards(sCard* tab) {
    char symboltab[4] = { 'c', 'p', 't', 'h' };
    int i = 1;
    int x = 0;

    while (i <= 13) {
        int j = 0;
        while (j <= 3) {
            // Init cards
            tab[x].Symbol = symboltab[j];
            tab[x].Number = i;
            tab[x].IdCard = x;
            tab[x].ReturnedCard = 0;
            tab[x].CardSlot = 0;
            tab[x].RightChild = NULL;
            tab[x].LeftChild = NULL;
            tab[x].RightParent = NULL;
            tab[x].LeftParent = NULL;
            tab[x].Next = NULL;
            tab[x].Previous = NULL;
            printf("%d, %c\n", tab[x].Number, tab[x].Symbol);
            j += 1;
            x += 1;
        }
        i += 1;
    }
}

/*==================================================================================================================================*/

void InitialisationPyramide(sCard* tab) {
    printf("test");
}