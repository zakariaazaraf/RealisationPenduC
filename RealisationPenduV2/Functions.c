
#include <stdio.h>
#include <time.h>
char lireCaractere(){ //this function is for avoiding the problems of a scanf() function
    char lettre = 0;

    lettre = getchar();
    lettre = toupper(lettre);
    while(getchar() != '\n'); // ==> while(getchar() != '\n'){}

    return lettre;
}


void whatMysteryWord(int *arrayFound, char *word){
    int length = strlen(word), i = 0;
    printf("quele le mot secret ? ");
    for(i=0; i<length; i++){
        if(arrayFound[i]){
            printf("%c", *(word + i));
            //printf("%c", word[i]);

        }else{
            printf("*");
        }
    }
    printf("\n");

}

int gamewin(int *arr, int arrLength){
    int i = 0;
    for(i=0; i<arrLength; i++){
        if(!arr[i]){
            return 0;
        }
    }
    return 1;
}

int checkLetter(char alpha,char *mysteryWord, int length, int *arr){
    int i = 0,
    found = 0;
    for(i=0; i<length; i++){
        if(alpha == mysteryWord[i]){
            arr[i] = 1;
            found ++;
        }
    }
    return found;
}

int nombreAllea(int nombreMax){

    srand( time( NULL ) );
    return rand() % nombreMax;
}

//int chooseGame(){
//    printf("choissez-vous ce que vous voudraiez \n");
//    scanf("%d")
//    switch ()
//}
