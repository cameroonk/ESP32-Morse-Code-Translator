#include <Arduino.h>
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#define LED 2
#define DOT_BUTTON 12 // WRONG, I will have to find something else to be the second input b/c the EN button I was using actually just resets the ESP OOPS
#define DASH_BUTTON 0 // CORRECT

// GLOBAL VARIABLES 
int buttonState = 5; 
struct link *head = (struct link *) malloc(sizeof(struct link));
char alphabet[29] = {'A','e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};
// GLOBAL VARIABLES

void setup() {
  pinMode(DOT_BUTTON, INPUT);
  pinMode(DASH_BUTTON, INPUT);
	pinMode(LED, OUTPUT);

	Serial.begin(9600);
	delay(500); 
}


void loop() {
//	buttonState = digitalRead(DOT_BUTTON);

	int iterations = 0;
	
	struct link *curr_link = head;
	while(iterations < 100000000000) {
		curr_link->next=NULL;	// this will make sure that if we do not read any input the evaluation will automatically terminate after this node
				
		//read input
		//
		//if short add left
		if(digitalRead(DOT_BUTTON) == HIGH && 0) {
			curr_link->data = DOT;
			curr_link->next = (struct link*)malloc(sizeof(struct link));	// add another node to the linked list to add direction to next cycle
      curr_link = curr_link->next;
			
			digitalWrite(LED,HIGH);		
			
			delay(200);
			Serial.print("DOT->");
			iterations = 0;	
			continue;
		}
		//if long add right	
		if(digitalRead(DASH_BUTTON) == LOW) {
			curr_link->data = DASH;
			curr_link->next = (struct link*)malloc(sizeof(struct link)); 
			curr_link = curr_link->next;
			
			digitalWrite(LED,LOW);		

			delay(200);
			Serial.print("DASH->");
			iterations = 0;	
			continue;	
		}

		//MAKE SURE TO MAKE LAST NODE->NEXT NULL TO AVOID INFINITE LOOP		
		iterations++;
	}
	Serial.println("END\n");	
	int result = evaluate(head);
//	Serial.println("%c...", alphabet[result]);
	free(head);	// wonderful
}
