#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>
#include <ctype.h>

int getWord(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int isWordGuessed(const char secret[], const char lettersGuessed[]){
int x = -1;
int s = 0;
int l = 0;
for (s = 0; s <= strlen(secret); s++){
        for (l = 0; l <= strlen(lettersGuessed); l++){
                if (secret[s] == lettersGuessed[l]){
                        x++ ;
                }
                
        }
}
if (x == strlen(secret))
         return 1;
                                  
else  return 0;
    
}   

void getGuessedWord(const char secret[], const char lettersGuessed[], char guessedWord[]){
int i = 0;
int counter_l = 0;
int counter_s = 0;
int size=strlen(lettersGuessed);
    for (i=0; i <= strlen(secret); i++){
         guessedWord[i] = '_';}
    for (counter_s = 0; counter_s <= strlen(secret); counter_s++ ){
        for (counter_l = 0; counter_l <= size; counter_l++){
            if (secret[counter_s] == lettersGuessed[counter_l]){
                guessedWord[counter_s] = secret[counter_s];
              
            }
        }
    }
}
void getAvailableLetters(const char lettersGuessed[], char availableLetters[]){
int a = 0;
int g = 0;
int b=0;
char abeceda[]= "abcdefghijklmnopqrstuvwxyz";
int n=strlen(abeceda);
int c =0;

while (c != n ){
        for ( g = 0; g <= strlen(lettersGuessed); g++){
                if (abeceda[c] == lettersGuessed[g]){
                        a=0;
                        break;}
                else a=1;
        }
        if (a!=0){
                availableLetters[b]=abeceda[c];
                b++;}
        c++;
}
availableLetters[b]='\0';
return; 
}



void hangman (const char secret[]){
     int tips =8;
     int o = 0;
     int find = 0;
     char allMentionedLetters[30]={};
     int counter = 0;
     char letter[20] = {0};
     char mozne_pismena[26] = {0};
     char ukazka[26]={0};
     int len= strlen(secret);
     int upper=0;
     int j=0;
     int ask=0;
     
     printf ("Welcome to the game, Hangman!\nI am thinking of a word that is %d letters long.", len);
     
     while ((tips > 0 )&& (isWordGuessed(secret, allMentionedLetters) != 1)){
           printf("\n-------------\n");
           printf("You have %d guesses left.\n",tips);
           printf("Available letters: ");
           getAvailableLetters(allMentionedLetters, mozne_pismena);
          
           printf("%s",mozne_pismena);
           
           printf("\nPlease guess a letter: ");
           scanf("%19s", letter);
           for (upper=0; upper <= strlen(letter);upper++){
                if (isupper(letter[upper]))
                    letter[upper]=tolower(letter[upper]);}
           if(letter[1] == '\0') {
                            
                            
                            for (o =0; o <= strlen(allMentionedLetters); o++){
               					if(allMentionedLetters[o] == letter[0]){
                                         printf (" Oops! You've already guessed that letter: ");
                                         getGuessedWord(secret, allMentionedLetters, ukazka);
                                          for (j=0;  j <= strlen(secret); j++){
                                                printf(" %c ",ukazka[j]);}

                                         ask=1; 
                                         break;
                                }
                                else allMentionedLetters[counter] = letter[0];
           					}                              
                            if(ask!=1){
           
           					for (find=0 ; find <= len; find++){
               					if ( allMentionedLetters[counter] == secret[find]){
                    				isWordGuessed( secret, allMentionedLetters);
                    				getGuessedWord(secret, allMentionedLetters, ukazka);
                    				printf(" Good guess: ");
                    				for (j=0;  j <= strlen(secret); j++){
                                                printf(" %c ",ukazka[j]);}
                    				
                    				
									if (isWordGuessed( secret, allMentionedLetters) == 1){
                       					printf ("\nCongratulations, you won!");
                       					break;
                    				}
                    				break;
               					}
               					else {
                    				printf("Oops! That letter is not in my word: ");
                    				getGuessedWord(secret, allMentionedLetters, ukazka);
                    				for (j=0;  j <= strlen(secret); j++){
                                                printf(" %c ",ukazka[j]);}
                    				tips--;
                    				break;
                    			}
           					}
      						counter++; }
      						
      		}
                         
           else {
                if(strcmp(secret, letter) == 0) {
                                  printf("\nCongratulations, you won!");
                                  break;
                                  
                }
                else tips--;
                }
           
}
     		if (tips == 0)
   				printf("\n-------------\nSorry, you ran out of guesses. The word was %s.",secret);
   				
 }
