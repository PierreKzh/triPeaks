#include "structures.h"

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
    Reserve->First = &tabCard[28];
    Reserve->Last = &tabCard[28];
    Reserve->NumberElements++;
    for (int i = 29; i < 51; i++) {
        tabCard[i].CardSlot = 1;
        Reserve->Last->Next = &tabCard[i];
        tabCard[i].Previous = Reserve->Last;
        Reserve->Last = &tabCard[i];
        Reserve->NumberElements++;
    }
    //Fondation
    tabCard[51].CardSlot = 2;
    Fondation->First = &tabCard[51];
    Fondation->Last = &tabCard[51];
    Fondation->NumberElements++;
}
