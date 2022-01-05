#include "Surname.h"

void Surname(sPlayer* play) {
    /**
     * This fonction get the address of the player.
     * Then ask the player to get is pseudonyme.
     * @author  Romain GADANI
     * @param   sPlayer play : object player
     */
    printf("Enter a name : \n> ");
    play->surname = malloc(sizeof(sPlayer));
    scanf("%s", play->surname);
}