#define _CRT_SECURE_NO_WARNINGS
#define NbCards 10 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function Exchange the position of two cards
void exchange(int* ActualPosition, int* RdmPosition) {
    int TmpCard = *ActualPosition;
    *ActualPosition = *RdmPosition;
    *RdmPosition = TmpCard;
}


// Function Random position allocation
void random(int Position[]) {
    //Initialise srand sur le temps actuel
    srand(time(NULL));

    int i;

    for (i = NbCards - 1; i > 0; i--) {
        // Random Position between 0 and i
        int RandomPosition = rand() % (i + 1);
        // Starts the function exchange
        exchange(&Position[i], &Position[RandomPosition]);
    }
}


// Main Function
int main() {
    int Position[NbCards];
    int i;
    char* ListCards[] =
    {
    "Carte 1", "Carte 2", "Carte 3", "Carte 4", "Carte 5", "Carte 6", "Carte 7", "Carte 8", "Carte 9", "Carte 10"
    };

    // Generate array with static position
    for (i = 0; i < NbCards; i++) {
        Position[i] = i;
    }

    // Showing the cards before shuffling
    printf("===Before===\n");
    
    for (i = 0; i < NbCards; i++) {
        int DeckPosition = Position[i];
        printf("%2d - %s\n", i + 1, ListCards[DeckPosition]);

    }

    // Showing the cards after shuffling
    printf("\n===After===\n");
    // Starts the function to retrieve the new positions of the cards 
    random(Position);
    for (i = 0; i < NbCards; i++) {
        int DeckPosition = Position[i];
        printf("%2d - %s\n", i + 1, ListCards[DeckPosition]);

    }


    return 0;
}
