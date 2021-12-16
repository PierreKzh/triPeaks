#include "structures.h"


int main(void) {

    //=========InitialistionCards test=========
    sCard TabCard[52];
    InitialisationCards(&TabCard);

    //=========ShuffleCards test=========
    ShuffleCards(&TabCard);

    //=========win test=========
    sListCards Reserve;
    sListCards Fondation;
    Reserve.NumberElements = 24;
    Fondation.NumberElements = 25;
    printf("\n%d", win(&Reserve, &Fondation));

    //=========initialisationPyramide test=========
    InitialisationPyramide(&TabCard);

    return 0;
}