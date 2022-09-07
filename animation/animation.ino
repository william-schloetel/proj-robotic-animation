/**
    Code for The Shining "DOGMAN" prop using the ServoEasing library.

    Functions simulate movement.

*/

#include "ServoEasing.hpp"

ServoEasing rightServo;   //RIGHT TILT
ServoEasing leftServo;    //LEFT TILT
ServoEasing rotateServo;  //ROTATE the head
ServoEasing leanServo;    //LEAN body forward

#define RIGHT_SERVO_PIN 9
#define LEFT_SERVO_PIN 10
#define ROTATE_SERVO_PIN 6
#define LEAN_SERVO_PIN 11

#define START_DEGREE_VALUE  90

class dogman {
    //Degree positions for each servo
  public:
    uint8_t rightDeg = START_DEGREE_VALUE;
    uint8_t leftDeg = START_DEGREE_VALUE;
    uint8_t rotateDeg = START_DEGREE_VALUE;
    uint8_t leanDeg = START_DEGREE_VALUE;

    //subtle head movement
    void subtleHead() { 
      rotateServo.setSpeed(20);       //set speeds
      rightServo.setSpeed(15);
      leftServo.setSpeed(15);
      leanServo.setSpeed(20);
      delay(500);

      leanServo.startEaseTo(90);      //make sure he's upright
                   
      rightServo.startEaseTo(100);    //tilt head up 10 deg
      leftServo.startEaseTo(80);    
      delay(2000);

      rightServo.startEaseTo(80);     //tilt head down 10 deg
      leftServo.startEaseTo(100);
      delay(500);
      rotateServo.startEaseTo(70);    //rotate to left
      delay(1500);

      rightServo.startEaseTo(100);    //tilt head up 20 deg
      delay(500);
      leftServo.startEaseTo(80);
      delay(1000);
      rightServo.setSpeed(25);        //increase rightServo speed
      delay(500);
      rightServo.startEaseTo(80);   
      delay(500);
      leftServo.startEaseTo(90);
      delay(1500);
      
      rightServo.startEaseTo(50);     //tilt  head down
      leftServo.startEaseTo(100); 
      delay(1500);
      
      rightServo.setSpeed(40);        //increase rightServo speed
      rightServo.startEaseTo(90);     //tilt head up quickly
      delay(2000);

      rotateServo.startEaseTo(120);   //rotate right
      delay(500);
      rightServo.startEaseTo(50);     //tilt head down
      leftServo.startEaseTo(110);
      leanServo.startEaseTo(150);     //lean in
      delay(2000);
      //leftServo.startEaseTo(90);
      delay(1000);

      rightServo.setSpeed(10);        //reduce rightServo speed
      rightServo.startEaseTo(100);
      leftServo.startEaseTo(70);
      delay(3000);

      rightServo.startEaseTo(80);
      leftServo.startEaseTo(110);
      rotateServo.setSpeed(10);
      delay(1000);
      rotateServo.startEaseTo(90);
      delay(1000);

      rightServo.startEaseTo(90);
      leftServo.startEaseTo(65);
      leanServo.startEaseTo(90);       //lean up
      delay(3000);

      leftServo.startEaseTo(90);
      delay(3000);
      Serial.println("end subtlehead()");
    }

    void quickHead() {
      rotateServo.setSpeed(20);       //set speeds
      rightServo.setSpeed(10);
      leftServo.setSpeed(10);
      leanServo.setSpeed(20);
      
      rightServo.startEaseTo(90);     //default position
      leftServo.startEaseTo(90);
      rotateServo.startEaseTo(90);
      leanServo.startEaseTo(90);
      delay(1000);

      rotateServo.startEaseTo(70);    //rotate to left
      delay(300);
      rightServo.startEaseTo(100);    //tilt head up 10 deg
      delay(200);
      leftServo.startEaseTo(80);
      delay(2000);

      leanServo.startEaseTo(140);     //lean in  
      delay(500);
      rightServo.startEaseTo(70);     //tilt head down 10 deg
      leftServo.startEaseTo(110);
      delay(4000);
      
      leanServo.startEaseTo(90);      //lean up
      rightServo.startEaseTo(90);     //default position
      leftServo.startEaseTo(90);
      delay(4000);

      //-----
      
      rotateServo.setSpeed(20); 
      rotateServo.startEaseTo(120);   //rotate to right
      delay(1000);
      rightServo.startEaseTo(80);     //tilt head down 10 deg
      leftServo.startEaseTo(100);
      delay(1000);
      leanServo.startEaseTo(130);     //lean in  
      delay(2000);
      
      rotateServo.setSpeed(40);       //increase speeds
      rightServo.setSpeed(20);
      leftServo.setSpeed(20);
      leanServo.setSpeed(30);
      
      rotateServo.startEaseTo(90);    //rotate center
      leanServo.startEaseTo(90);      //lean up
      delay(200);
      rightServo.startEaseTo(105);    //curious head
      leftServo.startEaseTo(100);
      delay(1500);
      rightServo.startEaseTo(75);     //curious head flipped
      leftServo.startEaseTo(80);
      delay(2500);

      rightServo.startEaseTo(90);     //reset head
      leftServo.startEaseTo(90);
      delay(1000);
      
      rotateServo.setSpeed(20);       //reset speeds
      rightServo.setSpeed(15);
      leftServo.setSpeed(15);
      leanServo.setSpeed(20);
      Serial.println("end quickhead()");
    }

    void dickHead(){
      Serial.println("dickhead");
      delay(1000);
    }
};

dogman dog;                           //instantiate dogman

String quit;                          //only if using inputCheck() to read serial data


/***************************************************************
 *                           SETUP                             *
 ***************************************************************/

void setup() {
  Serial.begin(9600);
  delay(2000);

  //Attach servos. Setting initial positions
  Serial.println("----------------------------");
  Serial.print("Attaching Servos. Setting initial degree value of ");
  Serial.println(START_DEGREE_VALUE);
  rightServo.attach(RIGHT_SERVO_PIN, START_DEGREE_VALUE);
  leftServo.attach(LEFT_SERVO_PIN, START_DEGREE_VALUE);
  rotateServo.attach(ROTATE_SERVO_PIN, START_DEGREE_VALUE);
  leanServo.attach(LEAN_SERVO_PIN, START_DEGREE_VALUE);
  delay(2000);

  //Set initial speed; this will change throughout the animation
  Serial.println("Setting initial servo speed");
  rightServo.setSpeed(20);
  leftServo.setSpeed(15);
  rotateServo.setSpeed(15);
  leanServo.setSpeed(20);
  delay(1500);

  //Set easing type
  Serial.println("Setting servo easing type");
  rightServo.setEasingType(EASE_SINE_IN_OUT);
  leftServo.setEasingType(EASE_SINE_IN_OUT);
  rotateServo.setEasingType(EASE_SINE_IN_OUT);
  leanServo.setEasingType(EASE_SINE_IN_OUT);
  delay(4000);

  Serial.println("----------------------------");
  Serial.println("Begin test animation");
}


/***************************************************************
 *                           LOOP                              *
 ***************************************************************/
 
void loop() {

  dog.subtleHead();
  dog.quickHead();
 

/*
  Serial.println("End test animation");
  Serial.println("----------------------------");
  rightServo.detach();
  leftServo.detach();
  
  while (1) {

  }

*/
}

void inputCheck() {
  if (Serial.available() != 0) {
    quit = Serial.readString();
    if (quit == "quit") {
      Serial.println("Quiting Program");
      homeServos();
    }
  }
}

void homeServos() {
  rightServo.startEaseTo(90);
  leftServo.startEaseTo(90);
  rotateServo.startEaseTo(90);
  leanServo.startEaseTo(90);
  delay(5000);

  rightServo.detach();
  leftServo.detach();
  rotateServo.detach();
  leanServo.detach();

  while (1) {
    //end the animation
  }
}
