#include <stdio.h>
#include <string.h>

void kmpMatching(char *text, char *word) {
	int failTable[strlen(word)];
	failTable[0] = 0;

	for(int i = 1, j = 0; i < strlen(word); i++, j++) {
		if(word[j] == word[i]) 
			failTable[i] = failTable[i - 1] + 1;
		else { 
			int check = 0;
			while(j - 1 >= 0) {
				j = failTable[j - 1];
				if(word[j] == word[i]) {
					check = 1;
					failTable[i] = j + 1;
					break;
				}
			}
			if(!check) failTable[i] = 0; 
		}
	}

	for(int i = 0, j = 0; i < strlen(text); i++) {
		if(j == strlen(word)) {
			printf("found the word in index %d to %d \n", i - j, i);
			return;
		}
		if(text[i] == word[j])
			j++;
		else 
			if(j > 0) j = failTable[j - 1];
			else j = 0;
	}
}

int main() {
	kmpMatching("BC ABCDAB ABCDABCDABDE", "BCD");
}
