#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
int evaluate(struct link *curr_link) {
	/**
	* Check for empty link
	*/
	if(curr_link->data != DASH && curr_link->data != DOT) {
		printf("Invalid list\n");
		return 0;
	}

	int position = 0;
	int iterations = 0;	// keep track of loop iterations, we do not wan to exceed LOOP_LIMIT
  
	while(curr_link != NULL && iterations < LOOP_LIMIT){
    if(curr_link->data == DOT) {
			position = (2 * position) + 1;
    }
    else if(curr_link->data == DASH){
      position = (2 * position) + 2;
     	printf("Right"); 
    }
		//need to free this link
		curr_link->data = INVALID;	// make sure if we accidentally access this memory space we do not evaluate this "list" again
		struct link *temp = curr_link;
		curr_link = curr_link->next;	// move to next link for next iteration
		free(temp);	
		iterations++;
  }
  return position;
}

