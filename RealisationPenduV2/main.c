#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Header.h"

int main()
{
    char mysteryWord[25] = "";
    // file and the opening method
    FILE *myFile = NULL;
    myFile = fopen("FilesGames/SecretWords.txt","r");
    if (myFile == NULL){
        exit(0);
    }

    // Declaration of the variable that we need
    int i = 0,
    triesStill = 10,
    alpha = 0,
    CaracterLu = 0,
    nombreMots = 0,
    nombreAleatoire = 0,
    caracterOfWord = 0,
    min = 0;
    int *alphaFound = NULL; //think to declare a pointer to use the memory allocation for this array

    // Testing the pointer
    if(myFile == NULL){
        printf("impossible \n");
        return 0;
    }

    // Instructions for getting the number of words in my file
    do{
        CaracterLu = fgetc(myFile);
        if(CaracterLu == '\n'){
            nombreMots ++;
        }
    }while(CaracterLu != EOF);

    // Instructions for get the word that we need

    rewind(myFile); // => reposition of the file to zero

    // Those instructions for initialize the time and get the random value between limits
    srand (time(NULL));
    nombreAleatoire = (rand() % (nombreMots - min + 1)) + min;

    while(nombreAleatoire > 0){

        if(fgetc(myFile) == '\n'){
            nombreAleatoire--;
        }
    }

    //calling the function to get the word
    fgets(mysteryWord, 100, myFile);

    mysteryWord[strlen(mysteryWord) - 1] = '\0'; // thing to delete '\n' charter and replace it with special charter
    caracterOfWord = strlen(mysteryWord);
    alphaFound = malloc(caracterOfWord * sizeof(int));
    if(alphaFound == NULL){
        printf("we got some problems \n");
        return 0;
    }else{

        for(i=0; i<caracterOfWord; i++){
            alphaFound[i] = 0;
        }
    }

    do{
        printf("il vous restez %d coups a jouer\n", triesStill);
        whatMysteryWord(alphaFound, mysteryWord);
        printf("proposez une lettre : ");
        alpha = lireCaractere();
        if(!checkLetter(alpha, mysteryWord, caracterOfWord, alphaFound)){
            triesStill--;
        }

    }while(triesStill != 0 && !gamewin(alphaFound, caracterOfWord));

    if(gamewin(alphaFound, caracterOfWord)){
        printf("\nfelecitation vous avez gange !!\nle mot secret etait bien : %s\n", mysteryWord);
    }else{
        printf("vous avez depasser 10 essies .\n");
    }
    printf("le jeu est termine !!\n");


    return 0;
}
