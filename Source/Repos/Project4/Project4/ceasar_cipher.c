#include <stdio.h>
#include <string.h>

#define MSGL 1000

void cript(char* msg, int k);
void decript(char* msg, int k);

main() {
	char msg[MSGL];
	char c;
	int i = 0;
	printf("Enter your message : ");
	while ((c = getchar()) != EOF && c != '\n') {
		msg[i++] = c;
	}
	msg[i] = '\0';
	printf("Enter the key : ");
	int k = getchar() - 48;      
	char* ptr = msg;
	cript(&msg, k);
	printf("Your cripted message is : ");
	while (*ptr != '\0') {
		printf("%c", *ptr);
		ptr++;
	}

	decript(&msg, k);
	ptr = msg;
	printf("\nDecripted message : ");
	while (*ptr != '\0') {
		printf("%c", *ptr);
		ptr++;
	}


}


void cript(char* msg, int k) {       /*cript using ascii table*/
	while (*msg != '\0') {       
		if (*msg >= 65 && *msg <= 90) {        /*check if it's upper letter*/
			if ((*msg + k) > 90) {             /*if it's outside the alphabet, goes to the begin*/
				*msg++ = 64 + ((*msg + k) - 90);   
			}
			else {
				*msg++ = *msg + k;         
			}
		}
		if (*msg >= 97 && *msg <= 122) {   /*if its lower*/
			if ((*msg + k) > 122) {
				*msg++ = 96 + ((*msg + k) - 122);
			}
			else {
				*msg++ = *msg + k;
			}
		}
	}
}

void decript(char* msg, int k) {   /*same as cript, but backwards*/
	while (*msg != '\0') {
		if (*msg >= 65 && *msg <= 90) {       
			if ((*msg - k) < 65) {               
				*msg++ = 91 - (65 - (*msg - k));
			}
			else {
				*msg++ = *msg - k;
			}
		}
		if (*msg >= 97 && *msg <= 122) {
			if ((*msg - k) < 97) {
				*msg++ = 123 - (97 - (*msg -k));
			}
			else {
				*msg++ = *msg - k;
			}
		}
	}
}