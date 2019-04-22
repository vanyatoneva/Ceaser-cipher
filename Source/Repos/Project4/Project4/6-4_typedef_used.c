#include<stdio.h>
#include<ctype.h>
#include<string.h>


typedef struct tnode* Treeptr; /*we can use Treeptr instead of struct tnode* */

typedef struct tnode {
	char* word;
	int count;
	Treeptr left;
	Treeptr right;
}Treenode;

#define MAXWORD 100

Treeptr addtree(Treeptr p, char* w);
void treeprint(Treeptr p);

main() {

	Treeptr root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			root = addtree(root, word);
		}
	}
	treeprint(root);
}


Treeptr talloc(void);
char* strdupl(char* s);

Treeptr addtree(Treeptr p, char* w) {

	int cond;
	if (p == NULL) {			/*if it's new word we make new treenode*/
		p = talloc();
		p->word = strdupl(w);
		p->count = 1;
		p->left = p->right = 0;
	}
	else if ((cond = strcmp(w, p->word)) == 0) { /*if it's already in the tree*/
		p->count++;
	}
	else if (cond < 0) {
		p->left = addtree(p->left, w);
	}
	else {
		p->right = addtree(p->right, w);
	}
	return p;
}

void treeprint(Treeptr p) {
	if (p != NULL) {                /*goes to the last right node, which is not NULL and prints the from there */
		treeprint(p->right);
		printf("%d, %s\n", p->count, p->word);
		treeprint(p->left);
	}

}


Treeptr talloc(void) {                     /*returns pointer to new treenode*/
	return (Treeptr)malloc(sizeof(Treenode));
}

#pragma warning(disable : 4996)
char* strdupl(char* s) {      /*returns pointer to the word*/
	char* p;
	p = (char*)malloc(strlen(s) + 1);
	if (p != NULL) {
		strcpy(p, s);    //4996
	}
	return p;
}


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
	while (isspace(c = getch()))
		;
	if (c != EOF) {
		*w++ = c;
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