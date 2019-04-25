#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"Header.h"

#define MAXW 100

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

