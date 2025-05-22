#include <Arduino.h>
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#define LED 2
#define DOT_BUTTON 12 // WRONG, I will have to find something else to be the second input b/c the EN button I was using actually just resets the ESP OOPS
#define BUTTON 0 // CORRECT

// GLOBAL VARIABLES 
int buttonState = 5; 
char alphabet[29] = {'A','e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};
// GLOBAL VARIABLES

void setup() {
  pinMode(BUTTON, INPUT);
	pinMode(LED, OUTPUT);
	Serial.begin(9600);
	delay(500); 
}


void loop() {	
	struct link *head = (struct link *) malloc(sizeof(struct link));
	head->data = INVALID;
	int iter = 0;
	struct link *curr_link = head;
	
	while(iter < 1000000) {	
		//read the input
		if(digitalRead(BUTTON) == LOW) {	// could be dash or dot
			delay(10000);	// delay to check if dash
			/**
			*	If the button is still held down after a delay -> dash
			* If the button was lifted during the delay -> dot
			*/
			if(digitalRead(BUTTON == LOW)) {
				curr_link->data = DASH;
				curr_link->next = (struct link*)malloc(sizeof(struct link)); 
				curr_link = curr_link->next;
			
				digitalWrite(LED,HIGH);		

				delay(200);
				Serial.print("DASH->");
				iter = 0;	
				continue;
			}
			else {	// DOT
				curr_link->data = DOT;
        curr_link->next = (struct link*)malloc(sizeof(struct link));
        curr_link = curr_link->next;
      
        digitalWrite(LED,LOW); 

        delay(200);
        Serial.print("DOT->");
        iter = 0;
        continue;
			}	
		}

		//MAKE SURE TO MAKE LAST NODE->NEXT NULL TO AVOID INFINITE LOOP		
		iter++;
	}
	curr_link->next=NULL;	// this will make sure that if we do not read any input the evaluation will automatically terminate after this node
	
	//do not want to print anything if no signal was read
	if(head->data == INVALID) {
		return;
	}
	
	Serial.println("END\n");	
	int result = evaluate(head);
	Serial.println(alphabet[result]);
//	free(head);	// wonderful
}
