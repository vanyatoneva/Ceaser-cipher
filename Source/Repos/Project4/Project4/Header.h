#pragma once

int getch(void);
void ungetch(int c);
int getword(char* word, int lim);   /*gets word from input*/

typedef struct treenode* Treeptr;
struct treenode {
	char* word;
	int count;
	Treeptr left;
	Treeptr right;
}Treenode;


Treeptr addtree(Treeptr node, char* word);
char* strdupl(char* word);
Treeptr makeNode(char* word);
void printTree(Treeptr node);

int compare_string(char* s1, char* s2);
int is_same_letter(char s, char t);
