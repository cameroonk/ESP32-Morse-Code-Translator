#include "tree.h"
#include <stdlib.h>

struct node* create_morse_tree() {
  char alphabet[29] = {NULL,'e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};

  struct node *tree_head = malloc(sizeof(struct node)); 

	populate_node(tree_head, alphabet, 0, 0);
	return tree_head;	
}

void populate_node(struct node* curr_node, char alphabet[], int letter, int level) {
	//TODO: make level pointer
	//we've gone too deep
	if(level > 5) {
		return;
	}
	printf("Level %d | Letter %c\n", level, alphabet[letter]);
	//else
	curr_node->letter = alphabet[letter];

 	curr_node->left = malloc(sizeof(struct node)); 
	curr_node->right = malloc(sizeof(struct node)); 
	populate_node(curr_node->left, alphabet, (letter + 1), (level + 1));
	populate_node(curr_node->right, alphabet, (letter + 2), (level + 1));
	
}
