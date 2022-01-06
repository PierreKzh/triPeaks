#include "PickCard.h"

void PickCard(sCard* tabcard[52], sListCards* Fondation, int cardvalue, char cardColor) {
    /**
     * This fonction get the Reserve's address and the Fondation's address.
     *  Then take the last card of the reserve ans place it on the last of the fondation
     * @author  Pierre KERZERHO & Romain Gadani
     * @param   sListCards *Reserve : object Reserve
     * @param   sListCards *Fondation : object Fondation
     */
    int i = 0;
    int j = 0;
    sCard *previous; // temp value
    while (i <= 51) {
        // rules of the game
        if (tabcard[i]->Number == cardvalue && tabcard[i]->Symbol == cardColor && tabcard[i]->CardSlot == 1 && tabcard[i]->LeftChild == NULL && tabcard[i]->RightChild == NULL && (Fondation->Last->Number == tabcard[i]->Number + 1 || Fondation->Last->Number == tabcard[i]->Number - 1)) {
            while (j <= 51) {
                if (tabcard[j]->LeftChild == tabcard[i]) {
                    tabcard[j]->LeftChild = NULL;

                }
                else if (tabcard[j]->RightChild == tabcard[i]) {
                    tabcard[j]->RightChild = NULL;
                }
                j++;
            }
            tabcard[i]->CardSlot = 3;
            previous = Fondation->Last; // temp value
            Fondation->Last = tabcard[i];
            previous->Next = Fondation->Last;
            Fondation->Last->Previous = previous;
            break;
        }
        i++;
    }

}
