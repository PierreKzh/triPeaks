#include "win.h"

int win(sListCards* Reserve, sListCards* Fondation) {
    /**
     * This fonction get the Reserve's address and the Fondation's address.
     *  Then do a sum of numbersElements of the Reserve and the Fondation.
     *  If the number elements of the Reserve and Fondation equal 52, it would say that all cards of the tree as been set.
     * @author  Pierre KERZERHO
     * @param   sListCards *Reserve : object Reserve
     * @param   sListCards *Fondation : object Fondation
     * @return  int : 1 for win, 0 for loose
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
