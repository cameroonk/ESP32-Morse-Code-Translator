# ESP 32 Morse Code Translator
Cameron Kasprzak | cameron-kasprzak@outlook.com

## Motivation
I began this project to gain familiarity with programming in an embedded environment and to keep developing my programming skills after graduation.

## How It Works
![Morse Code Binary Tree](./binary_tree.png)

Morse code can be represented as a binary tree that can be navigated with dots representing Left Branches and Dashes representing Right Branches. I will refer to Dots and Dashes rather than Left or Right traversals henceforth. The ESP32 is programmed to interpret short and long presses and read a this navigate this binary tree based on user input.

### Data Structures
#### Linked List

A Linked List is used to represent the path _(Dash, Dash, Dot, etc.)_ taken for the binary tree. Each short press appends a node in the linked list representing a Dot, and long press appends a node representing a Dash. The use of the linked list allows the program to dynamically store the user input without knowing how long it will be. Once the linked list is passed into the _evaluate()_ function, it is easy to traverse through the list using the _next_ pointer.

#### Binary Tree

As stated above, morse code can be read in a binary tree, so the alphabet needed to be formatted into a binary tree to be traversed. To save memory and time allocating, I used a simple array of characters. This can be used as a binary tree using the following scheme. 
	Array position _i_ can access its "left child" by navigating to the position located at ( (2 * _i_) + 1 )
	Array position _i_ can access its "right child" by navigating to the position located at ( (2 * _i_) + 2 )

### Functions
#### Evaluate

The primary function doing the heavy lifting is the _evaluate()_ function. It takes a pointer to the head of our linked list and traverses the linked list until it hits a null pointer. Along the way, it keeps track of the position in the array that corresponds with each Dash/Dot movement using the scheme in the previous section. It returns the final position which can be used to address the alphabet array to get the correct resulting letter.

#### Loop

The main loop that runs on the arduino sits holds an inner loop that runs for a set amount of iterations. If a button press is read, the program delays. After the delay it checks if the button is still held down, which will result in a Dash appended to the linked list. Otherwise it will append a Dot to the linked list. Any input will reset the iterations counter for the inner loop to allow for more Dots/Dashes to be read. Once the iterations reaches the set limit the linked list is passed into the _evaluate_ function and the inner loop begins again, to poll for another letter.
