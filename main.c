#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
int bar(int argc, char *argv[])  {
	char alphabet[29] = {'A','e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};
//	struct tree morse_tree* = create_morse_tree();
	struct link *head = malloc(sizeof(struct link));

	//main loop
	while(1) {
		struct link *curr_link = head;

		//read input
		//
		//if short add left
		curr_link->data = DOT;		
		//if long add right
		curr_link->data = DASH;
		//MAKE SURE TO MAKE LAST NODE->NEXT NULL TO AVOID INFINITE LOOP		
		//timeout
		int result = evaluate(head);
		printf("%c...", alphabet[result]);


	}

int evaluate(struct link *curr_link) {
	int position = 0;
	
	while(curr_link->next != NULL){
		if(curr_link->data == DOT) {
			position = (2 * position) + 1;
		}
		else if(curr_link->data == DASH){
			position = (2 * position) + 2;
		}
	}
	return position;
}
return 0;
}
