#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * removeDuplicates(char[]);
int targetFound(char[], int, char);
void initializeEncryptArray(char[], char[]);
void initializeDecryptArray(char[], char[]);
void processInput(FILE*, FILE*, char[]);

int main(int argc, char* argv[])
{
	char *rawKey, *key = NULL;
	FILE *fin = NULL, *fout = NULL;
	int choice;
	char ch;
	char encrypt[26], decrypt[26];
	
	// check for valid amount of arguments
	if (argc != 5)
	{
		printf("Whoops, looks like you don't the right arguments.\n");
		printf("Try again! You need a key, a choice, and two files.\n");
		exit(1);
	}	
	
	rawKey = argv[1];  // get raw (duplicat letters) encryption key
	choice = atoi(argv[2]);  // encryption (1)  or decryption (2)?
	fin = fopen(argv[3], "r");  // open input file
	fout = fopen(argv[4], "w");  // open output file
	
	// check for valid files
	if (fin == NULL || fout == NULL)
	{
		printf("Sorry, you have at least one non-valid file.\n");
		printf("Please double-check and try again!\n");
		exit(1);
	}
	
	// convert raw key to key without duplicate letters
	key = removeDuplicates(rawKey);
	
	if (choice == 1)  // encryption selected
	{
		initializeEncryptArray(key, encrypt);
	}
	else if (choice == 2)  // decryption selected
	{
		initializeDecryptArray(key, decrypt);
	}
	else  // nothing selected
	{
		printf("Sorry, that's not a valid choice!\n");
		printf("Please try again.\n");
		printf("Enter 1 for encryption, 2 for decryption.\n");
	}
	
	
	while (fscanf(fin, "%c", &ch) != EOF)
	{
		// encrypt/decrypt
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}

// removes duplicate letters from keyword and returns result string
char * removeDuplicates(char word[])
{
	int i, j = 0;
	char* result = malloc(strlen(word) * sizeof(char));  // new key
	char temp[strlen(word)];  // temporary array to hold characters
	
	for(i = 0; i < strlen(word); i++)
	{
		// if character isn't already in result, add it
		if (strchr(temp, word[i]) == NULL)
		{
			temp[j] = word[i];
			j++;
		}
	}
	
	temp[j] = '\0';  // make a string
	result = temp;  // temp is local, so set result to temp
	return result;  // return key w/o duplicate letters
}

// searches for the first num characters in given array
int targetFound(char charArray[], int num, char target)
{
	int found = 0;
	char temp[num];
	
	strncpy(temp, charArray, num);
	if (strchr(temp, target) != NULL)
	{
		found = strchr(temp, target);
	}
	
	return found;
}

// initialize encrypt array with cipher letters from given key
void initializeEncryptArray(char key[], char encrypt[])
{
	//
}

// TODO
void initializeDecryptArray(char encrypt[], char decrypt[])
{
	//
}

// TODO
void processInput(FILE * inf, FILE * outf, char substitute[])
{
	//
}






