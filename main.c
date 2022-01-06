//Pierre K, Romain G, Jean-Baptiste F

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(void) {
    /**
     * This is the main function
     * First the function initialize all the cards randommly in a tab.
     * Then she initialize the pyramide with placing all the cards in and define all the childs.
     * The name of the player is asked.
     * We enter in the main loop, to stop it the player have to win or loose.
     * Before each display we clearing the console.
     * If the player enter "0" he can draw a card, if he enter "1" the number and symbole of a card wich is want pick is asked.
     * after each element entered we clearing the console and display again the first display and the last question asked.
     * To finish if the player win or loose, an ascii art is print.
     * @author  Pierre KERZERHO
     * @author  JeanBaptiste FAVE
     * @author  Romain GADANI
     * @return  int : 0
     */
    //=========InitialistionCard=========
    sCard *TabCard[52];

    // Init all card
    char symboltab[4] = { 's', 'h', 'd', 'c' };
    int i = 1;
    int x = 0;
    
    while (i <= 13) { // the number, Ace to King
        int j = 0;
        while (j <= 3) { // the symbol
            // Init eatch parametres for one card
            TabCard[x] = (sCard*)malloc(sizeof(sCard));
            TabCard[x]->Symbol = symboltab[j];
            TabCard[x]->Number = i;
            TabCard[x]->IdCard = x;
            TabCard[x]->ReturnedCard = 0;
            TabCard[x]->CardSlot = 0;
            TabCard[x]->RightChild = NULL;
            TabCard[x]->LeftChild = NULL;
            TabCard[x]->RightParent = NULL;
            TabCard[x]->LeftParent = NULL;
            TabCard[x]->Next = NULL;
            TabCard[x]->Previous = NULL;
            j += 1;
            x += 1;
        }
        i += 1;
    }

    //=========ShuffleCards=========
    ShuffleCards(TabCard);

    //=========initialisationPyramide=========
    InitialisationPyramide(TabCard);

    //=========initialisationListOaked========
    sListCards Reserve;
    Reserve.NumberElements = 0;
    sListCards Fondation;
    Fondation.NumberElements = 0;
    InitialisationListeOaked(TabCard, &Reserve, &Fondation);

    //=========Surname=========
    printf(                                                                                                                                                        
 "####### ######  ### ######  #######    #    #    #  #####  \n"
 "   #    #     #  #  #     # #         # #   #   #  #     # \n"
 "   #    #     #  #  #     # #        #   #  #  #   #       \n"
 "   #    ######   #  ######  #####   #     # ###     #####  \n"
 "   #    #   #    #  #       #       ####### #  #         # \n"
 "   #    #    #   #  #       #       #     # #   #  #     # \n"
 "   #    #     # ### #       ####### #     # #    #  #####  \n\n"                                                                                                                                                              
    );
    sPlayer play;
    Surname(&play);
    
    //==========GameLoop==========
    while (LooseWin(TabCard, &Reserve, &Fondation) == 0) {
        
        for(i=0; i<52; i++){
            if(TabCard[i]->RightChild == NULL && TabCard[i]->LeftChild == NULL){
                TabCard[i]->ReturnedCard = 1;
            }
        }

        system("@cls||clear");
        AffichagePlateau(TabCard, &Fondation, &Reserve);
        
        
        char cardValue;
        char cardColor = ' ';
        int cardNumber = 0;
        
        char entry;
        int Choice;
        
        int verif = 0;
         
        //Menu selection 
        printf("\n0 : Draw card on the reserve\n1 : Pick card on the board\nx : Exit\n> ");
        while (verif == 0){
            scanf(" %c", &entry);
            
            switch (entry) {
            case '0':
                Choice = 0;
                break;
            case '1':
                Choice = 1;
                break;
            case 'x':
                return 0;
                break;
            default:
                Choice = 3;
                break;
            }

            if (Choice == 0 || Choice == 1){
                verif = 1;
            }
            else {
                system("@cls||clear");
                AffichagePlateau(TabCard, &Fondation, &Reserve);
                printf("\n0 : Draw card on the reserve\n1 : Pick card on the board\nx : Exit\n> ");
                verif = 0;
            }
        }
        // action for choice 0 : Draw Card from the reserve then verif if it's win or loose
        if (Choice == 0) {
            DrawCard(&Reserve, &Fondation);
        }

        // action for choice 1 : select card then verif if it's win or loose
        else if (Choice == 1) {
            while (cardNumber == 0) {
                system("@cls||clear");
                AffichagePlateau(TabCard, &Fondation, &Reserve);
                printf("\n0 : Draw card on the reserve\n1 : Pick card on the board\nx : Exit\n> %d", Choice);
                printf("\nEnter value :\n> ");
                scanf(" %c", &cardValue);
                switch (cardValue) {
                case 'a':
                    cardNumber = 1;
                    break;
                case '2':
                    cardNumber = 2;
                    break;
                case '3':
                    cardNumber = 3;
                    break;
                case '4':
                    cardNumber = 4;
                    break;
                case '5':
                    cardNumber = 5;
                    break;
                case '6':
                    cardNumber = 6;
                    break;
                case '7':
                    cardNumber = 7;
                    break;
                case '8':
                    cardNumber = 8;
                    break;
                case '9':
                    cardNumber = 9;
                    break;
                case '1':
                    cardNumber = 10;
                    break;
                case 'j':
                    cardNumber = 11;
                    break;
                case 'q':
                    cardNumber = 12;
                    break;
                case 'k':
                    cardNumber = 13;
                    break;
                default:
                    cardNumber = 0;
                    break;
                }
            }
            //entry verification
            while (cardColor != 's' && cardColor != 'h' && cardColor !='d' && cardColor != 'c') {
                system("@cls||clear");
                AffichagePlateau(TabCard, &Fondation, &Reserve);
                printf("\n0 : Draw card on the reserve\n1 : Pick card on the board\nx : Exit\n> %d", Choice);
                printf("\nEnter value :\n> %c\n", cardValue);
                printf("\nEnter symbol :\n> ");
                scanf(" %c", &cardColor);
            }

            PickCard(TabCard, &Fondation, cardNumber, cardColor);
        }
    }

    if (LooseWin(TabCard, &Reserve, &Fondation) == 2) {
        system("@cls||clear");
        printf(
        ":::     ::: ::::::::::: :::::::: ::::::::::: ::::::::  :::::::::  :::   ::: \n"
        ":+:     :+:     :+:    :+:    :+:    :+:    :+:    :+: :+:    :+: :+:   :+: \n"
        "+:+     +:+     +:+    +:+           +:+    +:+    +:+ +:+    +:+  +:+ +:+  \n"
        "+#+     +:+     +#+    +#+           +#+    +#+    +:+ +#++:++#:    +#++:   \n"
        " +#+   +#+      +#+    +#+           +#+    +#+    +#+ +#+    +#+    +#+    \n"
        "  #+#+#+#       #+#    #+#    #+#    #+#    #+#    #+# #+#    #+#    #+#    \n"
        "    ###     ########### ########     ###     ########  ###    ###    ###    \n"
        );
    }

    else if (LooseWin(TabCard, &Reserve, &Fondation) == 1) {
        system("@cls||clear");
        printf(
        " ::::::::      :::     ::::     :::: ::::::::::       ::::::::  :::     ::: :::::::::: :::::::::  \n"
        ":+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:             :+:    :+: :+:     :+: :+:        :+:    :+: \n"
        "+:+         +:+   +:+  +:+ +:+:+ +:+ +:+             +:+    +:+ +:+     +:+ +:+        +:+    +:+ \n"
        ":#:        +#++:++#++: +#+  +:+  +#+ +#++:++#        +#+    +:+ +#+     +:+ +#++:++#   +#++:++#:  \n"
        "+#+   +#+# +#+     +#+ +#+       +#+ +#+             +#+    +#+  +#+   +#+  +#+        +#+    +#+ \n"
        "#+#    #+# #+#     #+# #+#       #+# #+#             #+#    #+#   #+#+#+#   #+#        #+#    #+# \n"
        " ########  ###     ### ###       ### ##########       ########      ###     ########## ###    ### \n"
        );
    }

    free(play.surname);
    for (i = 0; i < 52; i++) {
        free(TabCard[i]);
    }
    return 0;
}

