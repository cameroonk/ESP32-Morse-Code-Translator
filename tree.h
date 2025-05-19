struct node {
	char letter;
	struct node *left;
	struct node *right;
};

struct node* create_morse_tree(); 
