#include "main.h"

int main(void) {

    //=========InitialistionCards test=========
    sCard TabCard[52];
    InitialisationCards(&TabCard);
    printf("apres initialisation : %d", TabCard[1].IdCard);
    //=========ShuffleCards test=========
    ShuffleCards(&TabCard);
    printf("apres shuffle : %d", TabCard[1].IdCard);

    //=========win test=========
    sListCards Reserve;
    sListCards Fondation;
    Reserve.NumberElements = 24;
    Fondation.NumberElements = 25;
    printf("\n%d", win(&Reserve, &Fondation));

    //=========initialisationPyramide test=========
    InitialisationPyramide(&TabCard);

    //=========initialisationListOaked test========
    sListCards Reserve2;
    Reserve2.NumberElements = 0;
    sListCards Fondation2;
    Fondation2.NumberElements = 0;
    InitialisationListeOaked(&TabCard, &Reserve2, &Fondation2);
    printf("\nnb elements reserve : %d", Reserve2.NumberElements);
    printf("\nnb element fondation : %d", Fondation2.NumberElements);

    //=========Surname test=========
    sPlayer play;
    Surname(&play);
    free(play.surname);

    return 0;
}
