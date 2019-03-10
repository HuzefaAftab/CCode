/* Huzefa Aftab */
#include<stdio.h>
#include<stdlib.h>
#include "MyLib.h"
#include<string.h>
#define MAX_INPUT 81
int GuessALetter(char Phrase[],char PhraseCopy[],char UpperPhrase[]){
	char Guess;
	char *FindGuess=NULL;
	char GuessALetterCopy[MAX_INPUT];
	int FoundALetter=0;
	strcpy(GuessALetterCopy,UpperPhrase);
	printf("%s\n",PhraseCopy);
	printf("Player 2 : Guess a letter : ");
	scanf("%c",&Guess);
	Guess = toupper(Guess);
	getchar();
	FindGuess=strchr(GuessALetterCopy,Guess);
	while(FindGuess != NULL){
	FoundALetter=1;
	PhraseCopy[FindGuess - GuessALetterCopy] = Phrase[FindGuess - GuessALetterCopy];
	*FindGuess='-';
	FindGuess=strchr(GuessALetterCopy,Guess);
	}
return FoundALetter;

}

int main(void){
	
	char Phrase[MAX_INPUT];
	char PhraseCopy[MAX_INPUT];
	char UpperPhrase[MAX_INPUT];
	char Alphabet[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char *ReplaceIt= NULL;
	int Strikes=0;
	int YourOut=3;
	printf("Welcome to ");
	ConvertDecimalToBinary(YourOut);
	printf(" Strikes - YOU'RE OUT - the CSE version\n");
	printf("Player 2 - Please look away\n");
	printf("Player 1 - Please enter the phrase that Player 2 will be guessing.\n");
	printf("           Enter a maximum of 81 characters.\n");
    printf("           Your phrase CANNOT contain a dash\n");
	fgets(Phrase,MAX_INPUT,stdin);
	
	if(strchr(Phrase,'-')){
	printf(" You broke the rules. We can't play. BYE!!\n");
	exit(0);
	}
	
	Phrase[strlen(Phrase)-1]='\0';
			
		 int i;
		 for(i=0; i<=strlen(Phrase); i++){
		UpperPhrase[i]=toupper(Phrase[i]);
		
		 }
          strcpy(PhraseCopy,UpperPhrase);
		 
			ReplaceIt=strpbrk(PhraseCopy,Alphabet);
		 while(ReplaceIt != NULL){
				*ReplaceIt='-';
				ReplaceIt=strpbrk(PhraseCopy,Alphabet);
			 }
		
			printf( "Player 2 - Here's the phrase you need to guess\n");
			printf("\n");
		do
		{
			if(GuessALetter(Phrase,PhraseCopy,UpperPhrase)==0){
		
				Strikes++;
				printf("Strike ");
				ConvertDecimalToBinary(Strikes);
				printf("\n");
				if(Strikes >= YourOut){
					ConvertDecimalToBinary(Strikes);
				
		        printf( " STRIKES – YOU'RE OUT!!\n");
				printf("Game over\n");
				return 0;
				}
				
			}
			
			}
		
			while(strchr(PhraseCopy,'-')!=NULL);
		
		printf( "You figured it out!!\n");
		printf("Player 1 entered the phrase\n");
		printf("%s\n",Phrase);
		printf("Player 2 WINS!!!!\n");
		
		return 0;
		
		}
