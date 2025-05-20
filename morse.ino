#include <Arduino.h>
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#define LED 2
#define DOT_BUTTON 12
#define DASH_BUTTON 26

// GLOBAL VARIABLES 
int buttonState = 5; 
struct link *head = (struct link *) malloc(sizeof(struct link));
char alphabet[29] = {'A','e','t','i','a','n','m','s','u','r','w','d','k','g','o','h','v','f','A','l','A','p','j','b','x','c','y','z','q'};
// GLOBAL VARIABLES

void setup() {
  pinMode(DOT_BUTTON, INPUT);
  pinMode(DASH_BUTTON, INPUT);
	pinMode(LED, OUTPUT);
}


void loop() {
//	buttonState = digitalRead(DOT_BUTTON);
	/* Serial.begin(9600); */
	int iterations = 0;
	
	struct link *curr_link = head;
	while(iterations < 100000000000) {
		//buttonState = digitalRead(pushButton);	
		curr_link->next=NULL;	// this will make sure that if we do not read any input the evaluation will automatically terminate after this node
				
			delay(200);
		
		//read input
		//
		//if short add left
		if(digitalRead(DOT_BUTTON == LOW)) {
			curr_link->data = DOT;
			curr_link->next = (struct link*)malloc(sizeof(struct link));	// add another node to the linked list to add direction to next cycle
      curr_link = curr_link->next;
			digitalWrite(LED,HIGH);		
			continue;
		}
		//if long add right	
		if(digitalRead(DOT_BUTTON == LOW)) {
			curr_link->data = DASH;
			curr_link->next = (struct link*)malloc(sizeof(struct link)); 
			curr_link = curr_link->next;
			digitalWrite(LED,LOW);		
			continue;	
		}

		//MAKE SURE TO MAKE LAST NODE->NEXT NULL TO AVOID INFINITE LOOP		
	
		iterations++;
	}
	int result = evaluate(head);
	printf("%c...", alphabet[result]);
	free(head);
}
