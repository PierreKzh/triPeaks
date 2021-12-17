#include "Surname.h"

void Surname(sPlayer* play) {
    printf("\n\nEntrez un pseudo\n: ");
    play->surname = malloc(sizeof(sPlayer));
    scanf("%s", play->surname);
    printf("Vous avez choisi le pseudo \"%s\"\n", play->surname);
    printf("\n");
}