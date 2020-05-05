#ifndef DEF_PENDU
#define DEF_PENDU
// Function for avoiding the iteration problem of scanf()
char lireCaractere();

void whatMysteryWord(int *arrayFound, char *word);

int gamewin(int *arr, int arrLength);

int checkLetter(char alpha,char *mysteryWord, int length, int *arr);
int nombreAllea(int nombreMax);



#endif // DEF_PENDU
