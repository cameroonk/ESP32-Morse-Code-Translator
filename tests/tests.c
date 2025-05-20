#include "../tree.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	test_evaluate();
}

int test_evaluate() {
	char alphabet[29] = {NULL,'e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};

	struct link *e_link_head = malloc(sizeof(struct link));
	e_link_head->data = DOT;
	e_link_head->next = malloc(sizeof(struct link));
	e_link_head->next->data = DOT;
	e_link_head->next->next = NULL;	
	int result = evaluate(e_link_head);
	printf("Expected : i | Actual : %c\n", alphabet[result]);
	
	e_link_head->next->next = malloc(sizeof(struct link));
	e_link_head->next->next->data = DASH;

	e_link_head->next->next->next = malloc(sizeof(struct link));
  e_link_head->next->next->next->data = DOT;

	result = evaluate(e_link_head);
  printf("Expected : f | Actual : %c\n", alphabet[result]);	
	free(e_link_head->next->next->next);
	free(e_link_head->next->next);
	free(e_link_head->next);	
	free(e_link_head);	
	return 0;
}
int evaluate_tree(struct node *curr_node, char expected_letter, char expected_left, char expected_right, int level) {
	if(level > 5) {
		return;
	}
	printf("Expected Node Letter: %c | Actual Node Letter: %c\n", curr_node->letter, expected_letter);
	printf("Expected Left Letter: %c | Actual Left Letter: %c\n", curr_node->left->letter, expected_left);
	printf("Expected Right Letter: %c | Actual Right Letter: %c\n", curr_node->right->letter, expected_right);
	 
	return 0;
}
