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
	int i;
	char* key = NULL;
	FILE *fin = NULL, *fout = NULL;
	
	key = argv[1];  // get encryption key
	fin = fopen(argv[2], "r");  // open input file
	fout = fopen(argv[3], "w");  // open output file
	
	char keyArr[strlen(key)];  // array of characters in encryption key
	
	for (i = 0; i < strlen(key); i++)  // key into array for functions
	{
		keyArr[i] = key[i] % 26;
	}
	
	return 0;
}

// removes duplicate letters from keyword and returns result string
char * removeDuplicates(char word[])
{
	return 0;
}

// searches for the first num characters in given array
int targetFound(char charArray[], int num, char target)
{
	return 0;
}

// initialize encrypt array with cipher letters from given key
void initializeEncryptArray(char key[], char encrypt[])
{
	//
}

// TODO
void initalizeDecryptArray(char encrypt[], char decrypt[])
{
	//
}

// TODO
void processInput(FILE * inf, FILE * outf, char substitute[])
{
	//
}






