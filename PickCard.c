#include "PickCard.h"

void PickCard(sCard* tabcard, sListCards* Fondation, int cardvalue, char cardColor) {
    /**
     * This fonction get the Reserve's address and the Fondation's address.
     *  Then take the last card of the reserve ans place it on the last of the fondation
     * @author  Pierre KERZERHO & Romain Gadani
     * @param   sListCards *Reserve : object Reserve
     * @param   sListCards *Fondation : object Fondation
     */
    int i = 0;
    int j = 0;
    sCard *previous;
    while (i <= 51) {
        if (tabcard[i].Number == cardvalue && tabcard[i].Symbol == cardColor && tabcard[i].CardSlot == 1 && tabcard[i].LeftChild == NULL && tabcard[i].RightChild == NULL && (Fondation->Last->Number == tabcard[i].Number + 1 || Fondation->Last->Number == tabcard[i].Number - 1)) {
            while (j <= 51) {
                if (tabcard[j].LeftChild == &tabcard[i]) {
                    tabcard[j].LeftChild = NULL;
                    printf("%d", tabcard[j].Number);
                }
                else if (tabcard[j].RightChild == &tabcard[i]) {
                    tabcard[j].RightChild = NULL;
                    printf("%d", tabcard[j].Number);
                }
                j++;
            }
            tabcard[i].CardSlot = 3;
            previous = Fondation->Last;
            Fondation->Last = &tabcard[i];
            previous->Next = Fondation->Last;
            Fondation->Last->Previous = &previous;
            printf("ok");
            break;
        }
        i++;
    }

}
