#include "../tree.h"
#include <stdlib.h>
#include <stdio.h>

	char alphabet[29] = {NULL,'e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};
int test_evaluate() {

	struct link *e_link_head = (struct link *)malloc(sizeof(struct link));
	e_link_head->data = DOT;
	e_link_head->next = (struct link *)malloc(sizeof(struct link));
	e_link_head->next->data = DOT;
	e_link_head->next->next = NULL;	
	int result = evaluate(e_link_head);
	printf("Expected : i | Actual : %c\n", alphabet[result]);
	e_link_head = (struct link *)malloc(sizeof(struct link));
  e_link_head->data = DOT;
  e_link_head->next = (struct link *)malloc(sizeof(struct link));
  e_link_head->next->data = DOT;
	
	e_link_head->next->next = (struct link *)malloc(sizeof(struct link));
	e_link_head->next->next->data = DASH;

	e_link_head->next->next->next = (struct link *)malloc(sizeof(struct link));
  e_link_head->next->next->next->data = DOT;

	result = evaluate(e_link_head);
  printf("Expected : f | Actual : %c\n", alphabet[result]);	

/**	free(e_link_head->next->next->next);
	free(e_link_head->next->next);
	free(e_link_head->next);	
	free(e_link_head);	
	**/
	return 0;
}

/**
* Rewriting the code of morse.ino 's loop function
*/
int loop_test() {
	struct link *head = (struct link *)malloc(sizeof(struct link));
	struct link *curr_link = head;	
	curr_link->data = DASH;
  curr_link->next = (struct link*)malloc(sizeof(struct link));
  curr_link = curr_link->next;
	
	curr_link->next=NULL;
	int result = evaluate(head);
	printf("Expected : t | Actual : %c\n", alphabet[result]);

	return 0;
		
}

/**
* Test handling of empty lists
*/
int empty_test() {
	struct link *head = (struct link *)malloc(sizeof(struct link));
	printf("Inputting list with no data\n");
	int result = evaluate(head);
	return 0;	
}

/**
* Tests the freeing of the linked list
*	Ideally, the head should not keep its data after evaluation
*/
int use_after_free_test() {
	struct link *head = (struct link *)malloc(sizeof(struct link));
  struct link *curr_link = head;
  curr_link->data = DASH;
  curr_link->next = (struct link *)malloc(sizeof(struct link));
  curr_link = curr_link->next;
	
	printf("Inputting valid list===========\n");
  curr_link->next=NULL;
  int result = evaluate(head);
  printf("Expected : t | Actual : %c\n", alphabet[result]);	
	
	printf("Inputting list after free'd===========\n");
	head = (struct link *)malloc(sizeof(struct link));
	result = evaluate(head);
	printf("Expected : PLACEHOLDER | Actual : %c\n", alphabet[result]);	

	return 0;
}
int main(int argc, char *argv[]) {
  test_evaluate();
	loop_test();
	empty_test();
	use_after_free_test();	
	return 0;
}
