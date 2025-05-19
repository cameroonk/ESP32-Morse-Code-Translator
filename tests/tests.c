#include "../tree.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	struct node *tree_head = malloc(sizeof(struct node)*27);     // 26 letters + 1 head node

  char alphabet[29] = {NULL,'e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};
	
	for(int i = 0; i < 29; i++) {
		printf("Expected %c : Real %c\n", (char)alphabet[i], (char)(tree_head + (i * sizeof(struct node))));
		  
	}
}
