#include<stdio.h>
#include"Header.h"

Treeptr addtree(Treeptr node, char* word) {
	int cmp;
	if (node == NULL) {        /*if there isn't node, make new one*/
		node = makeNode(word);
	}
	else if ((cmp = compare_string(word, node->word)) == 0) { /*if words are the same, increase counter*/
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