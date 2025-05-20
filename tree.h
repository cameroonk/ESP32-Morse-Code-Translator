#define LOOP_LIMIT 6 

enum signal {
  DOT, DASH
};

struct node {
	char letter;
	struct node *left;
	struct node *right;
};

struct link {
	enum signal data;
	struct link *next;
};

int evaluate(struct link *curr_link);

struct node* create_morse_tree();

void populate_node(struct node* curr_node, char alphabet[], int letter, int level); 
