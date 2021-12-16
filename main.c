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
    printf("\n\n");

    //=========initialisationPyramide test=========
    InitialisationPyramide(&TabCard);

    //=========AffichagePyramide test=========
    //AffichagePyramide(&TabCard);

    AffichagePyramidev2(&TabCard);

    return 0;
}