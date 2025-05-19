struct node {
	char letter;
	struct node *left;
	struct node *right;
};

struct node* create_morse_tree();

void populate_node(struct node* curr_node, char alphabet[], int letter, int level); 
