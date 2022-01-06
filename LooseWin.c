#include "LooseWin.h"

int LooseWin(sCard *tabCard[52], sListCards *Reserve, sListCards *Fondation) {
	/**
	 * This function get the Reserve's address and the Fondation's address and the tab of cards.
	 * Then check for the win if the sum of the reserve and fondation equal 52.
	 * Then check for the loose if there is a +1 or -1 card of those displayed.
	 * @author  Pierre KERZERHO
	 * @param   sListCards *Reserve : object Reserve
	 * @param   sListCards *Fondation : object Fondation
	 * @param	sCard *tabCard : object tabCard
	 * @return  int : 1 for loose, 2 for win, 0 for continue
	 */
	int i = 0;
	int NumberCards = 0;
	NumberCards += Reserve->NumberElements;
	NumberCards += Fondation->NumberElements;
	if (NumberCards == 52) {
		return 2;
	}
	else if (Reserve->NumberElements == 0) {
		while (i <= 51) {
			// rules of the game
			if (tabCard[i]->CardSlot == 1 && tabCard[i]->ReturnedCard == 1 && (tabCard[i]->Number == Fondation->Last->Number + 1|| tabCard[i]->Number == Fondation->Last->Number - 1)) {
				return 0;
			}
			i++;
		}
		return 1;
	}
	return 0;
}