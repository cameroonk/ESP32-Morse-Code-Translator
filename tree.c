#include "tree.h"
#include <stdlib.h>

struct node*  create_morse_tree() {
  //TODO: automate this
  struct node *tree_head = malloc(sizeof(struct node)*27);     // 26 letters + 1 head node

  char alphabet[29] = [NULL,'e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'];

  struct node curr_node* = tree_head->left;     // begin traversal at head's left child

  //iterate through alphabet 
  for(int i = 0; i < 29; i++) {
    struct node to_be_edited* = curr_node + (i * sizeof(struct node));  // address ith tree node
                to_be_edited->letter = alphabet[i];     // insert letter
  }
}
