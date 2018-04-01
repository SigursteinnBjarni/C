#include<stdio.h>
#include <stdbool.h>
int main()
{
	bool word;
	int c = 0,words = 0,newline = 0,chars=0;
	while ((c = getchar()) != EOF){
		if( c == '\n'){
			newline++;
		}
		//if we are outside a word
		if( c == '\t' || c == ' ' || c == '\n'){
			word = 0;
		}
		//if we are inside a word, set the word bit to true and count the word
		//set the word bit to 1 so we dont incriment the word counter
		else if (word == 0){
			word = 1;
			words++;
		}

		chars++;

	}
	printf("Lines %d\nWords %d\nCharacters %d\n", newline,words,chars);
	return 0;
}
