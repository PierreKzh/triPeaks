#include "structures.h"

/*==================================================================================================================================*/

int win(sListCards* Reserve, sListCards* Fondation) {
    /*
    This fonction get the Reserve's address and the Fondation's address.
    Then do a sum of numbersElements of the Reserve and the Fondation.
    If the number elements of the Reserve and Fondation equal 52, it would say that all cards of the tree as been set.
    @param sListCards *Reserve : object Reserve
    @param sListCards *Fondation : object Fondation
    @return int : 1 for win, 0 for loose
    */
    int NumberCards = 0;
    NumberCards += Reserve->NumberElements;
    NumberCards += Fondation->NumberElements;
    if (NumberCards == 52) {
        return 1;
    }
    else {
        return 0;
    }
}

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
    char symboltab[4] = { 'C', 'P', 'T', 'H' };
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
    int i = 0;
    while (i < 28) {
        tab->ReturnedCard = 1;
        tab->CardSlot = 0;
        i += 1;
    }
    
    i = 0;
    int x = 3;
    while (i < 3) {
        tab[i].LeftChild = &tab[i + x];
        x += 1;
        tab[i].RightChild = &tab[i + x];
        tab[i].IdCard = i;
        i += 1;
    }

    x = 6;
    int y = 0;
    while (i < 9) {
        tab[i].LeftChild = &tab[i + x];
        tab[i].RightChild = &tab[i + x + 1];
        tab[i].IdCard = i;
        i += 1;
        y += 1;
        if (y == 2) {
            x += 1;
            y = 0;
        }
    }

    x = 9;
    while (i < 18) {
        tab[i].LeftChild = &tab[i + x];
        tab[i].RightChild = &tab[i + x + 1];
        tab[i].IdCard = i;
        i += 1;
    }

    while (i < 28) {
        tab[i].IdCard = i;
        i += 1;
    }
}

char AffichageCase(int number) {
    char lettre;
    
    switch (number) {
    case 1 :
        lettre = 'A';
        break;
    case 11 :
        lettre = 'J';
        break;
    case 12 :
        lettre = 'Q';
        break;
    case 13 :
        lettre = 'K';
        break;
    default :
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
        printf("|%c..%c|  ", AffichageCase(number), symbol);
    }
    else {
        printf("|%d..%c|  ", number, symbol);
    }
}

void AffichagePyramide(sCard* tab) {
    
    int i = 0;

    printf("            ");
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    printf("                ");
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    printf("                ");
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    
    printf("\n        ");
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    printf("        ");
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    printf("        ");
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    
    printf("\n    ");
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    
    printf("\n");
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else {
        printf("         ");
    }
    i += 1;
    if (tab[i].CardSlot =! 0) {
        afftest(tab[i].Number, tab[i].Symbol);
    }
    else{
        printf("         ");
    }
    i += 1;
}