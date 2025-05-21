#include "../tree.h"
#include <stdlib.h>
#include <stdio.h>

int test_evaluate() {
	char alphabet[29] = {NULL,'e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};

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
	free(e_link_head->next->next->next);
	free(e_link_head->next->next);
	free(e_link_head->next);	
	free(e_link_head);	
	return 0;
}

int main(int argc, char *argv[]) {
  test_evaluate();
}
