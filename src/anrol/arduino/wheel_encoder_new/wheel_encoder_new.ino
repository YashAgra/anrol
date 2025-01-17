

#include "CytronMotorDriver.h"
// Configure the motor driver.
CytronMD motor1(PWM_DIR, 3, 2);  // PWM 1 = Pin 2, DIR 1 = Pin 4.
CytronMD motor2(PWM_DIR, 5, 4); // PWM 2 = Pin 3, DIR 2 = Pin 5.

//motor 1 -> left, motor 2 -> right

#include <Encoder.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WProgram.h>
#endif
#include <stdlib.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int16.h>
#include <std_msgs/String.h>
#include <MotorDriver.h>
ros::NodeHandle nh;
geometry_msgs::Twist msg;

float move1;
float move2;
int speed = 100;

//encoded motors inports-------------------
#define ENC_IN_LEFT_A 18
#define ENC_IN_RIGHT_A 20

// Other encoder output to Arduino to keep track of wheel direction
// Tracks the direction of rotation.
#define ENC_IN_LEFT_B 19
#define ENC_IN_RIGHT_B 21

Encoder leftMotor(ENC_IN_LEFT_A, ENC_IN_LEFT_B);
Encoder rightMotor(ENC_IN_RIGHT_A, ENC_IN_RIGHT_B);

// True = Forward; False = Reverse
boolean Direction_left = true;
boolean Direction_right = true;

// Minumum and maximum values for 16-bit integers
const int encoder_minimum = -32768;
const int encoder_maximum = 32767;

//call back function for subscriber
void callback(const geometry_msgs::Twist& cmd_vel)
{
  move1 = cmd_vel.linear.x;
  move2 = cmd_vel.angular.z;
  if (move1 > 0 && move2 == 0)
  {
    back(speed);
  }
  else if (move1 == 0 && move2 > 0 )
  {
    right(speed);
  }
  else if (move1 == 0 && move2 < 0 )
  {
    left(speed);
  }
  else if (move1 < 0)
  {
    front(speed);
  }
  else if (abs(move1) < abs(move2)) {
    if (move2 > 0 )
    {
      right(speed);
    }
    else if (move2 < 0 )
    {
      left(speed);
    }
  }

  else if (abs(move1) > abs(move2)) {
    if (move1 > 0)
    {
      back(speed);
    }
    else if (move1 < 0)
    {
      front(speed);
    }
  }
  else
  {
    die();
  }
}


// Keep track of the number of wheel ticks



ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &callback);

std_msgs::Int16 right_wheel_tick_count;
ros::Publisher rightPub("right_ticks", &right_wheel_tick_count);

std_msgs::Int16 left_wheel_tick_count;
ros::Publisher leftPub("left_ticks", &left_wheel_tick_count);


// 100ms interval for measurements
const int interval = 100;
long previousMillis = 0;
long currentMillis = 0;


//use only two motors here
const int rightback = 4;
const int leftback = 3;

void setup() {
  // pinMode(leftforw, OUTPUT);
  pinMode(leftback, OUTPUT);
  // pinMode(rightforw, OUTPUT);
  pinMode(rightback, OUTPUT);

  pinMode(ENC_IN_LEFT_A , INPUT_PULLUP);
  pinMode(ENC_IN_LEFT_B , INPUT);
  pinMode(ENC_IN_RIGHT_A , INPUT_PULLUP);
  pinMode(ENC_IN_RIGHT_B , INPUT);
  // Every time the pin goes high, this is a tick
  attachInterrupt(digitalPinToInterrupt(ENC_IN_LEFT_A), left_wheel_tick, RISING);
  attachInterrupt(digitalPinToInterrupt(ENC_IN_RIGHT_A), right_wheel_tick, RISING);

  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertise(leftPub);
  nh.advertise(rightPub);
  nh.subscribe(sub);
 
}

void left_wheel_tick(){
  left_wheel_tick_count.data = static_cast<int16_t>(-leftMotor.read());
  
}
void right_wheel_tick(){
  right_wheel_tick_count.data = static_cast<int16_t>(rightMotor.read());  
  
}
void loop() {
  currentMillis = millis();
  leftPub.publish( &left_wheel_tick_count );
  rightPub.publish( &right_wheel_tick_count );
  // If 100ms have passed, print the number of ticks
  nh.spinOnce();
  delay(100);
}

void back(float speed)
{
  // m.motor(leftforw, FORWARD, speed);
  // m.motor(rightforw, FORWARD, speed);
  motor1.setSpeed(-speed);
  motor2.setSpeed(-speed);

  // digitalWrite(leftforw, HIGH);
  // digitalWrite(rightforw, HIGH);
  // digitalWrite(leftback, LOW);
  // digitalWrite(rightback, LOW);
  delay(100);
  

}
void front(float speed)
{
  // m.motor(leftforw, BACKWARD, speed);
  // m.motor(rightforw, BACKWARD, speed);
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  //    m.motor(leftback, BACKWARD, speed);
  //    m.motor(rightback, BACKWARD, speed);
  // digitalWrite(leftforw, LOW);
  // digitalWrite(rightforw, LOW);
  // digitalWrite(leftback, HIGH);
  // digitalWrite(rightback, HIGH);
  delay(100);
  
}
void right(float speed)
{
  // m.motor(leftforw, BACKWARD, speed);
  // m.motor(rightforw, FORWARD, speed);
  motor1.setSpeed(0);
  motor2.setSpeed(-speed);
  // digitalWrite(leftforw, LOW);
  // digitalWrite(rightforw, HIGH);
  // digitalWrite(leftback, LOW);
  // digitalWrite(rightback, LOW);
  delay(100);
  

}
void left(float speed)
{
  //
  motor2.setSpeed(0);
  motor1.setSpeed(-speed);
  //    m.motor(leftback, BACKWARD, speed);
  //    m.motor(rightback, FORWARD, speed);
  // digitalWrite(leftforw, HIGH);
  // digitalWrite(rightforw, LOW);
  // digitalWrite(leftback, LOW);
  // digitalWrite(rightback, LOW);
  delay(100);
  
}
void die()
{
  // m.motor(leftforw, RELEASE, speed);
  // m.motor(rightforw, RELEASE, speed);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  //    m.motor(leftback, RELEASE, speed);
  //    m.motor(rightback, RELEASE, speed);
  // digitalWrite(leftforw, LOW);
  // digitalWrite(rightforw, LOW);
  // digitalWrite(leftback, LOW);
  // digitalWrite(rightback, LOW);
}

//void right_wheel_tick() {
//
// // Read the value for the encoder for the right wheel
// int val = digitalRead(ENC_IN_RIGHT_B);
//
// if(val == LOW) {
//   Direction_right = false; // Reverse
// }
// else {
//   Direction_right = true; // Forward
// }
//
// if (Direction_right) {
//
//   if (right_wheel_tick_count.data == encoder_maximum) {
//     right_wheel_tick_count.data = encoder_minimum;
//   }
//   else {
//     right_wheel_tick_count.data++;
//   }
// }
// else {
//   if (right_wheel_tick_count.data == encoder_minimum) {
//     right_wheel_tick_count.data = encoder_maximum;
//   }
//   else {
//     right_wheel_tick_count.data--;
//   }
// }
//}
////
////// Increment the number of ticks
////void left_wheel_tick() {
////
////  // Read the value for the encoder for the left wheel
////  int val = digitalRead(ENC_IN_LEFT_B);
////
////  if(val == LOW) {
////    Direction_left = true; // Reverse
////  }
////  else {
////    Direction_left = false; // Forward
////  }
////
////  if (Direction_left) {
////    if (left_wheel_tick_count.data == encoder_maximum) {
////      left_wheel_tick_count.data = encoder_minimum;
////    }
////    else {
////      left_wheel_tick_count.data++;
////    }
////  }
////  else {
////    if (left_wheel_tick_count.data == encoder_minimum) {
////      left_wheel_tick_count.data = encoder_maximum;
////    }
////    else {
////      left_wheel_tick_count.data--;
////    }
////  }
////}
//
//void left_wheel_tick() {
//   
//  // Read the value for the encoder for the left wheel
//  int val = digitalRead(ENC_IN_LEFT_B);
// 
//  if(val == LOW) {
//    Direction_left = true; // Reverse
//  }
//  else {
//    Direction_left = false; // Forward
//  }
//   
//  if (Direction_left) {
//    if (left_wheel_tick_count.data == encoder_maximum) {
//      left_wheel_tick_count.data = encoder_minimum;
//    }
//    else {
//      left_wheel_tick_count.data++;  
//    }  
//  }
//  else {
//    if (left_wheel_tick_count.data == encoder_minimum) {
//      left_wheel_tick_count.data = encoder_maximum;
//    }
//    else {
//      left_wheel_tick_count.data--;  
//    }   
//  }
//}
