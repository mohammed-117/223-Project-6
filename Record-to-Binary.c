//---------------------------------
// Question 2.
// purpose: the purpose of this program is to copy array a into a binary file one number at a time ,then //append 4 new numbers to the binary file ,then copy all the numbers from the binary file into the array //b and then display array b. 
//----------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CopyArrayToBinary(int a[]);
void AppendNumbers(int a[]);
void DisplayBinFile(char fname[]);

int main()
{
	int a[6] = { 30,60,10,90,40,70 };

	CopyArrayToBinary(a);
	AppendNumbers(a);
	DisplayBinFile("binary.txt");


	printf("\n\n");
	system("PAUSE");
	return 0;
}

void CopyArrayToBinary(int a[])
{
	FILE * fbin;
	fbin = fopen("binary.txt", "w");
	int i;

	for (i = 0; i < 6; ++i)
	{
		fwrite(&a[i], sizeof(int), 1, fbin);
	}

	fclose(fbin);

	return 0;
}
void AppendNumbers(int a[])
{
	int c[4] = { 15,45,35,74 };
	FILE * fpointer;
	fpointer = fopen("binary.txt", "a");

	fwrite((char *)c, sizeof(int), 4, fpointer);

	free(a);
	fclose(fpointer);

	return 0;
}

void DisplayBinFile(char fname[])
{
	FILE * fpointer;
	int i;
	int b[10];

	fpointer = fopen(fname, "r");
	fread((char *)b, sizeof(int), 10, fpointer);

	//DISPLAY ARRAY B
	for (i = 0; i < 10; i++)
	{
		printf("%d ", b[i]);
	}

	fclose(fpointer);

	return 0;
}
