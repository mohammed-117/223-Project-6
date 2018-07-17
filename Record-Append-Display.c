//---------------------------------
// Mohammed Hassnain
// Austin Philp
// cpsc 223c
// Oct. 8, 2015
// Project No.6
// Question 1.
// purpose: the purpose of this program is to append records to a file given and then display the file //including the new records, then convert the file to a binary file and then display the binary file.
//----------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Append(char FullText[]);
void DisplayAppend(char FullText[]);
void TextToBin(char FullText[]);
void DisplayBinFile(char FullText[]);


int main()
{

	char FullText[300];

	Append(FullText);
	DisplayAppend(FullText);
	printf("\n\n");
	TextToBin(FullText);
	DisplayBinFile("binary.txt");

	printf("\n\n");
	system("PAUSE");
	return 0;
}

void Append(char FullText[])
{
	FILE * fpointer;
	fpointer = fopen("data.txt", "a");

	fprintf(fpointer, "\n60 6600.60 Bill Clinton\n");
	fprintf(fpointer, "40 440.40  George W Bush");

	free(FullText);

	fclose(fpointer);

	return 0;
}

void DisplayAppend(char FullText[])
{
	FILE * fpointer;
	fpointer = fopen("data.txt", "r");

	int i;
	for (i = 0; i < 7; i++)
	{
		fgets(FullText, 300, fpointer);
		printf("%s", FullText);
	}
	printf("\n");

	free(FullText);

	fclose(fpointer);

	return 0;

}

void TextToBin(char FullText[])
{
	FILE * ftxt;
	FILE * fbin;

	// OPEN TEXT FILE
	ftxt = fopen("data.txt", "r");

	//OPEN BINARY FILE
	fbin = fopen("binary.txt", "w");
	char buff[300];
	//COPY TEXT FILE TO BINARY FILE

	while (!feof(ftxt))
	{
		fgets(buff, 255, ftxt);
		fprintf(fbin, "%s", buff);
	}

	fclose(ftxt);
	fclose(fbin);

	return 0;
}

void DisplayBinFile(char FullText[])
{
	//OPEN THE FILE TO READ FROM
	FILE * fbin;
	char buff[300];
	int i;

	fbin = fopen(FullText, "r");


	for (i = 0; i < 7; i++)
	{
		fgets(buff, 300, fbin);
		printf("%s", buff);
	}
	fclose(fbin);
	return 0;
}
