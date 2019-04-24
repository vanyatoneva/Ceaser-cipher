#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXW 100

typedef struct treenode* Treeptr;

Treeptr addtree(void);
Treeptr makeNode(void);
void printTree(void);
int getword(void);

struct treenode {
	char* word;
	int count;
	Treeptr left;
	Treeptr right;
}Treenode;

main() {
	char word[MAXW];
	Treeptr root = NULL;
	while (getword(word, MAXW) != EOF) {
		if (isalpha(word[0])) {  /*only if word starts with letter*/
			root = addtree(root, word);
		}
	}
	printTree(root);
}

Treeptr addtree(Treeptr node, char* word) {
	int cmp;
	if (node == NULL) {        /*if there isn't node, make new one*/
		node = makeNode(word);
	}
	else if ((cmp = strcmp(word, node->word)) == 0) { /*if words are the same, increase counter*/
		node->count++;
	}
	else if (cmp < 0) {							/*check if it goes left or right*/
		node->left = addtree(node->left, word);
	}
	else {
		node->right = addtree(node->right, word);
	}
	return node;
}

/*To initialize values of pointer, first must allocate memory!*/

char* strdupl(char* word) {
	char* copy = (char*)malloc(strlen(word) + 1);          /*allocates memory for the word*/
	if (copy == NULL) {                                 
		return NULL;
	}
	strcpy(copy, word);  /*if there's enought memory, copies the string and return the copy*/
	return copy;
}

Treeptr makeNode(char* word) {
	Treeptr node = (Treeptr)malloc(sizeof(Treenode));   /*allocate memory*/
	node->word = strdupl(word);                      /*copy the word in the new node*/
	node->count = 1;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printTree(Treeptr node) {
	if (node != NULL) {
		printTree(node->left);         /*goes to the left elements, until reaches NULL element, then starts to print them to the right*/
		printf("%d %s\n", node->count, node->word);
		printTree(node->right);
	}
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