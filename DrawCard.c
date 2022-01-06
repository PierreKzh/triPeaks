#include "DrawCard.h"

void DrawCard(sListCards* Reserve, sListCards* Fondation) {
    /**
     * This fonction get the Reserve's address and the Fondation's address.
     *  Then take the last card of the reserve ans place it on the last of the fondation
     * @author  Pierre KERZERHO
     * @param   sListCards *Reserve : object Reserve
     * @param   sListCards *Fondation : object Fondation
     */
    if (Reserve->NumberElements != 0) {
        sCard *previousFondation = Fondation->Last;
        sCard* lastReserve = Reserve->Last->Previous;
        Fondation->Last->Next = Reserve->Last;
        Fondation->Last = Reserve->Last;
        Fondation->Last->CardSlot = 3;
        Fondation->Last->Next = NULL;
        Fondation->Last->Previous = previousFondation;
        if (Reserve->Last == Reserve->First) {
            Reserve->Last = NULL;
            Reserve->First = NULL;
        }
        else {
            Reserve->Last = lastReserve;
            Reserve->Last->Next = NULL;
        }
        Reserve->NumberElements--;
        Fondation->NumberElements++;
    }
}
