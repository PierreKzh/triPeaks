#include "initialisationListOaked.h"

void InitialisationListeOaked(sCard* tabCard, sListCards* Reserve, sListCards* Fondation) {
    /*
    This fonction get the table card and Reserve and Fondation, create before.
    She initialize the Reserve with 23 cards and Fondation with 1 card.
    @author Pierre KERZERHO
    @param  sCard *tabCard : table of cards suffled
    @param  sListCards *Reserve : object Reserve
    @param  sListCards *Fondation : object Fondation
    */
    //Reserve
    sCard *current;
    Reserve->First = &tabCard[28];
    Reserve->Last = &tabCard[50];
    Reserve->Last->Previous = &tabCard[49];
    Reserve->NumberElements++;
    for (int i = 29; i < 50; i++) {
        current = &tabCard[i];
        current->Next = &tabCard[i + 1];
        current->Previous = &tabCard[i - 1];
        current->CardSlot = 2;
        Reserve->NumberElements++;
    }
    //Fondation
    tabCard[51].CardSlot = 3;
    Fondation->First = &tabCard[51];
    Fondation->Last = &tabCard[51];
    Fondation->NumberElements++;
}