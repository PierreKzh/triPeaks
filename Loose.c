#include "Loose.h"

int Loose(sCard *tabCard, sListCards *Reserve, sListCards *Fondation) {
	/**
	 * This fonction get the Reserve's address and the Fondation's address and the tab of cards.
	 * Then check the lasts card of the reserve and fondation.
	 *  .
	 * @author  Pierre KERZERHO
	 * @param   sListCards *Reserve : object Reserve
	 * @param   sListCards *Fondation : object Fondation
	 * @param	sCard *tabCard : object tabCard
	 * @return  int : 1 for loose, 0 for continue
	 */
	if (Reserve->Last == NULL) {
		for (int i = 0; i < 27; i++) {
			if (tabCard[i].CardSlot != 3 && (Fondation->Last->Number == (tabCard[i].Number + 1) || Fondation->Last->Number == (tabCard[i].Number - 1))) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
}