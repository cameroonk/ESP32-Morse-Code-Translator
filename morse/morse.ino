/**
* TODO: need to do buffer overflow detection when the amount of dots / dashes exceeds the bounds of the tree
* OR alternatively when an overflow occurs just start reading the next letter
*/

#include <Arduino.h>
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

// USEFUL DEFINITIONS
#define LED 2										// pin for LED; not incredibly useful
#define DOT_BUTTON 12 					// WRONG, I will have to find something else to be the second input b/c the EN button I was using actually just resets the ESP OOPS
#define BUTTON 0 // CORRECT			// pin for input button
#define DASH_TIME 250 //ms 			// time of press needed to record a dash
#define LETTER_WINDOW 200000		// iterations before we stop polling for a letter
// USEFUL DEFINITIONS

// GLOBAL VARIABLES 
int buttonState = 5;						// records if a button is pressed or not 
char alphabet[29] = {'A','e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};	// alphabet to be 'traversed'
unsigned long button_down = 0;	// record time button pressed
unsigned long button_up = 0;		// record time button released
bool pressed = 0;								// record if the button has been pressed or not
// GLOBAL VARIABLES

void setup() {
  pinMode(BUTTON, INPUT);
	pinMode(LED, OUTPUT);
	Serial.begin(9600);
	Serial.println("\nWelcome. Tap for Dots ( * ) Hold for Dashes ( - )"); 
}

/**
* Each loop iteration will hold out for a button input
* Once button is pressed, record the time it was pressed down to determine if it was a dot or a dash
* After each button press, the countdown on the inner loop resets to allow for input of another dot / dash
* Each dot / dash will be added to the linked list
* Once LETTER_WINDOW number of inner loop iterations is reached, the linked list is passed to the evaluate() function to determine what letter was typed
* Loop restarts to wait for another button press representing the start of a new word
*/
void loop() {	
	struct link *head = (struct link *) malloc(sizeof(struct link));	// create our linked list for this iteration's letter  
	head->data = INVALID;																							// without any dots / dashes this linked list is invalid
	int iter = 0;																											// iterations counter for inner (letter) loop
	struct link *curr_link = head;																		// create a pointer b/c each letter loop iteration will be pointing to a new link


	/**
	* TODO: All of this logic can be cleaned up
	* There is a lot of redundant computations on each iterations
	*/	
	while(iter < LETTER_WINDOW) {	
		pressed = 0;	// button has not been pressed for this iteration yet	
    digitalWrite(LED,LOW); 
		
		button_down = millis();	// record button down time
		while(digitalRead(BUTTON) == LOW) {	
			pressed = 1;	// wait until button released
			button_up = millis();	// record button release time
			
			if(button_up - button_down == DASH_TIME) { 
				digitalWrite(LED,HIGH);	// light blink indicating time for dash has been reached	
			}
		}
		
		//dont bother seeing if dash or dot if not pressed
		if(!pressed) { 
			iter++;
			continue;
		 }	
		
		//if button was held for more than DASH_TIME -> dash
		if(button_up - button_down < DASH_TIME) {
			curr_link->data = DOT;																				// add dot to linked list
			curr_link->next = (struct link*)malloc(sizeof(struct link));	// create new node attached to end
			curr_link = curr_link->next;																	// move to next link for next iteration
			Serial.print("*");		
			iter = 0;	// reset iteration timer to allow for more time to wait for next dot / dash
			continue;	// move to next iteration to poll for next dot / dash
		}
		else {	// DASH // same process as above
			curr_link->data = DASH;
      curr_link->next = (struct link*)malloc(sizeof(struct link));
      curr_link = curr_link->next;
     
      delay(100);
			Serial.print("-");
      iter = 0;
			continue;
		}
				
		iter++;	
	}
	curr_link->next=NULL;	// this will make sure that if we do not read any input the evaluation will automatically terminate after this node
	
	//do not want to print anything if no signal was read
	if(head->data == INVALID) {
		return;
	}
	
	Serial.print("|\n");	
	int result = evaluate(head);
	Serial.println(alphabet[result]);
}
