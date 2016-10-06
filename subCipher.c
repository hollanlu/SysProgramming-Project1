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
	char encrypt[26], decrypt[26];
	
	// check for valid amount of arguments
	if (argc != 5)
	{
		printf("Whoops, looks like you don't the right arguments.\n");
		printf("Try again! You need a key, a choice, and two files.\n");
		exit(1);
	}	
	
	//char rawKey[strlen(argv[1])];
	rawKey = argv[1];  // get raw (duplicate letters) encryption key
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
	
	// TODO delete!!
	//int x = targetFound(key, 5, 'l');
	//printf("x: %i\n", x);
	//printf("key: %s\n", key);
	//char key[6] = "hello";
	//char keyPass[100] = key;
	initializeEncryptArray(key, encrypt);
	printf("encrypt: %s\n", encrypt);
	initializeDecryptArray(encrypt, decrypt);
	printf("decrypt: %s\n", decrypt);
	//printf("key: %s\n", key);
	
	if (choice == 1)  // encryption selected
	{
		processInput(fin, fout, encrypt);
	}
	else if (choice == 2)  // decryption selected
	{
		processInput(fin, fout, decrypt);
	}
	else  // nothing selected
	{
		printf("Sorry, that's not a valid choice!\n");
		printf("Please try again.\n");
		printf("Enter 1 for encryption, 2 for decryption.\n");
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

// searches in first num characters for target
// returns 1 if found, 0 if not
int targetFound(char charArray[], int num, char target)
{
	int i, found = 0;
	
	for (i = 0; i < num; i++)
	{
		if (charArray[i] == target)
		{
			found = 1;
			break;
		}		
	}
	
	return found;
}

// initialize encrypt array with cipher letters from given key
void initializeEncryptArray(char key[], char encrypt[])
{
	int i;
	char k, next = 'z';
	
	for (i = 0; i < 26; i++)
	{
		if (i < strlen(key))
		{
			k = key[i];
		}
		else
		{
			while (targetFound(encrypt, i, next) != 0)
			{
				next--;
			}
			k = next;
		}	
		encrypt[i] = k;
	}
}

// initialize decrypt array with substitute letters from encrypt array
void initializeDecryptArray(char encrypt[], char decrypt[])
{
	int i, j = 0;
	char next = 'a';
	char alpha[26] = {'a','b','c','d','e','f','g','h','i','j',
			  'k','l','m','n','o','p','q','r','s','t',
			  'u','v','w','x','y','z'};
	
	for (i = 0; i < 26; i++)
	{
		// search for each letter in alphabetical order
		for (j = 0; j < 26; j++)
		{
			if (encrypt[j] == next)
			{
				// we've found the letter
				decrypt[i] = alpha[j];
				break;
			}
		}
		next++;
	}
}

// process data from input file and write to output file
// substitute is encrypt/decrypt array
void processInput(FILE * inf, FILE * outf, char substitute[])
{
	int pos;  // position of letter in alphabet
	char ch;
	
	while (fscanf(inf, "%c", &ch) != EOF)
	{
		if (isalpha(ch))
		{
			//pos = ch % 26;  // position in array, ie a = 0
			// lower -> upper = lower - 32
			if (isupper(ch))
				ch = ch - 32;
			pos = ch - 'a';// % 26;
			printf("letter: %c pos: %i\n", substitute[pos], pos);
			if (isupper(ch))
				fprintf(outf, "%c", toupper(substitute[pos]));
			else
				fprintf(outf, "%c", substitute[pos]);
		}
		else
			fprintf(outf, "%c", ch);
	}
}






