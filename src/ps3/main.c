#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>
#include <ctype.h>

int main(){

	char secret[30]={};
	
	
	/* comment mocny
	help me */
	getWord(secret);
	hangman(secret);
return 0;}