#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(void) {

    //=========InitialistionCard=========
    sCard TabCard[52];
    InitialisationCards(&TabCard);

    //=========ShuffleCards=========
    ShuffleCards(&TabCard);

    //=========initialisationPyramide=========
    InitialisationPyramide(&TabCard);

    //=========initialisationListOaked========
    sListCards Reserve;
    Reserve.NumberElements = 0;
    sListCards Fondation;
    Fondation.NumberElements = 0;
    InitialisationListeOaked(&TabCard, &Reserve, &Fondation);

    //=========Surname=========
    sPlayer play;
    Surname(&play);
    
    //==========GameLoop==============
    while (win(&Reserve, &Fondation) == 0 || Loose(&TabCard, &Reserve, &Fondation) == 0) {
        
        system("@cls||clear");
        AffichagePlateau(&TabCard, &Fondation);
        
        
        char cardValue;
        char cardColor = ' ';
        int cardNumber = 0;
        
        char entry;
        int Choice;
        
        int verif = 0;
        printf("\n0 : Draw card on the reserve\n1 : Pick card on the board\n2 : Exit\n> ");
        scanf("%c", &entry);
        while (verif == 0){
            scanf("%c", &entry);
            
            switch (entry) {
            case '0':
                Choice = 0;
                break;
            case '1':
                Choice = 1;
                break;
            case '2':
                Choice = 2;
                break;
            default:
                Choice = 3;
                break;
            }

            if (Choice == 2) {
                cardValue = 'a';
                return 0;
            }

            if (Choice == 0 || Choice == 1){
                verif = 1;
            }
            else {
                system("@cls||clear");
                AffichagePlateau(&TabCard, &Fondation);
                printf("\n0 : Draw card on the reserve\n1 : Pick card on the board\n2 : Exit\n> ");
                verif = 0;
            }
        }

        if (Choice == 0) {
            DrawCard(&Reserve, &Fondation);
            win(&Reserve, &Fondation);
            Loose(&TabCard, &Reserve, &Fondation);
        }

        else if (Choice == 1) {
            while (cardNumber == 0) {
                system("@cls||clear");
                AffichagePlateau(&TabCard, &Fondation);
                printf("\n0 : Draw card on the reserve\n1 : Pick card on the board\n2 : Exit\n> %d", Choice);
                printf("\nEnter value :\n> ");
                scanf("%s", &cardValue);
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

            while (cardColor != 't' && cardColor != 'h' && cardColor !='c' && cardColor != 'p') {
                system("@cls||clear");
                AffichagePlateau(&TabCard, &Fondation);
                printf("\n0 : Draw card on the reserve\n1 : Pick card on the board\n2 : Exit\n> %d", Choice);
                printf("\nEnter value :\n> %c\n", cardValue);
                printf("\nEnter symbol :\n> ");
                scanf(" %c", &cardColor);
            }

            PickCard(&TabCard, &Fondation, cardNumber, cardColor);
            win(&Reserve, &Fondation);
            Loose(&TabCard, &Reserve, &Fondation);
        }
    }
    if (win(&Reserve, &Fondation) == 1) {
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
    else if (Loose(&TabCard, &Reserve, &Fondation) == 1) {
        system("@cls||clear");
        printf(
        " ::::::::      :::     ::::    ::::  ::::::::::       ::::::::  :::     ::: :::::::::: :::::::::  \n"
        ":+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:             :+:    :+: :+:     :+: :+:        :+:    :+: \n"
        "+:+         +:+   +:+  +:+ +:+:+ +:+ +:+             +:+    +:+ +:+     +:+ +:+        +:+    +:+ \n"
        ":#:        +#++:++#++: +#+  +:+  +#+ +#++:++#        +#+    +:+ +#+     +:+ +#++:++#   +#++:++#:  \n"
        "+#+   +#+# +#+     +#+ +#+       +#+ +#+             +#+    +#+  +#+   +#+  +#+        +#+    +#+ \n"
        "#+#    #+# #+#     #+# #+#       #+# #+#             #+#    #+#   #+#+#+#   #+#        #+#    #+# \n"
        " ########  ###     ### ###       ### ##########       ########      ###     ########## ###    ### \n"
        );
    }
    free(play.surname);
    return 0;
}

