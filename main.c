#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "win.h"
#include "InitialisationCards.h"

int main() {

    //=========InitialistionCards test=========
    sCard tab[52];
    InitialisationCards(&tab);

    //=========win test=========
    sListCards Reserve;
    sListCards Fondation;
    Reserve.NumberElements = 24;
    Fondation.NumberElements = 25;
    printf("\n%d",win(&Reserve, &Fondation));
    

    return 0;
}