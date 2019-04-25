#include<stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];    /*buffer for ungetch*/
int bufp = 0;            /*next free position in buf*/

int getch(void) {   /*get a (possibly pushed back) character*/
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /*push character back on input*/
	if (bufp >= BUFSIZE) {
		printf("ungetch : too many charachetrs \n");
	}
	else {
		buf[bufp++] = c;
	}
}

int getword(char* word, int lim) {   /*gets word from input*/
	int c, getch(void);
	void ungetch(int);
	char* w = word;
	while (isspace(c = getch()))  /*if space, do nothing*/
		;
	if (c != EOF) {
		*w++ = c;   /*copy chars from input*/
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

int compare_string(char* s1, char* s2) {                        /*check if are the same - returns 0 even if one of them is upper*/
	for (; *s1 == *s2 || is_same_letter(*s1, *s2); s1++, s2++) {
		if (*s1 == 0) {
			return 0;
		}
	}
	return *(unsigned char*)s1 < *(unsigned char*)s2 ? -1 : 1;

}


int is_same_letter(char s, char t) {   /*if chars are letters check if they are not the same, but one upper*/
	if (isalpha(s) && isalpha(t)) {     /*if yes, return 0*/
		if (s + 32 == t || s - 32 == t) {
			return 1;
		}
	}
	else {
		return 0;
	}
}