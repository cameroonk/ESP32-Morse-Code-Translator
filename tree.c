#include "tree.h"
#include <stdlib.h>

int evaluate(struct link *curr_link) {
  int position = 0;
	int iterations = 0;	// keep track of loop iterations, we do not wan to exceed LOOP_LIMIT
  while(curr_link != NULL && iterations < LOOP_LIMIT){
    if(curr_link->data == DOT) {
     	printf("Left"); 
			position = (2 * position) + 1;
    }
    else if(curr_link->data == DASH){
      position = (2 * position) + 2;
     	printf("Right"); 
    }
		curr_link = curr_link->next;
		iterations++;
  }
  return position;
}

struct node* create_morse_tree() {
  char alphabet[29] = {NULL,'e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};

  struct node *tree_head = malloc(sizeof(struct node)); 

	populate_node(tree_head, alphabet, 0, 0);
	return tree_head;	
}

void populate_node(struct node* curr_node, char alphabet[], int letter, int level) {
	//TODO: make level pointer
	//we've gone too deep please work ???
	if(level > 5) {
		return;
	}
	printf("Level %d | Letter %c\n", level, alphabet[letter]);
	//else
	curr_node->letter = alphabet[letter];

 	curr_node->left = malloc(sizeof(struct node)); 
	curr_node->right = malloc(sizeof(struct node)); 
	populate_node(curr_node->left, alphabet, (2*letter + 1), (level + 1));
	populate_node(curr_node->right, alphabet, (2*letter + 2), (level + 1));
	
}
