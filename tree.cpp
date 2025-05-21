#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
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
		//need to free this link
		struct link *temp = curr_link;
		curr_link = curr_link->next;	// move to next link for next iteration
//		free(temp);	
		iterations++;
  }
  return position;
}

