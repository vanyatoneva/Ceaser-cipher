#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 10000

main() {

	FILE* newfile;
	FILE* myfile;
	char txt[MAX];
	char copy_txt[MAX];
	newfile = fopen("C:\\Users\\User\\Desktop\\newfile.txt", "w");   /*open the file for writing*/
	printf("Enter the text you want to put in newfile : ");
	scanf("%[^\n]", txt);                                           /*get all chars in input, except new line and collect them in txt*/
	fprintf(newfile, "%s", txt);                                           /*put the text in file*/
	fclose(newfile);

	newfile = fopen("C:\\Users\\User\\Desktop\\newfile.txt", "a+"); /*now it's open for adding and reading*/
	fscanf(newfile, "%[^\n]", copy_txt);
	//while (!feof(newfile)) {  
	//	fgets(newtext, MAX, newfile);
	//}                                    *another way to get the text from file*
	myfile = fopen("C:\\Users\\User\\Desktop\\myfile.txt", "w");   /*open other file to copy the text from the first one in it*/
	fprintf(myfile, "%s", copy_txt);
	fclose(myfile);

	fprintf(newfile, "\n some more text here");                     /*add to the first file*/
	fclose(newfile);


	newfile = fopen("C:\\Users\\User\\Desktop\\newfile.txt", "r");
	myfile = fopen("C:\\Users\\User\\Desktop\\myfile.txt", "r");

	fscanf(newfile, "%[^\t]", txt);        /*use '\t' instead of '\n' to get all lines from the text(fgets() also gets only one line)*/
	fscanf(myfile, "%[^\n]", copy_txt);

	fclose(newfile);
	fclose(myfile);
	printf("This is what the first file contains : \n%s\n", txt);
	printf("This is what the second file contains : \n%s\n", copy_txt);

}