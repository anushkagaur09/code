/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// rightFront           motor         1               
// leftFront            motor         3               
// leftBack             motor         7               
// rightBack            motor         8               
// Intake               motor         9               
// Intake2              motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
   
  // User control code here, inside the loop
  while (1) {
    float frontBack = Controller1.Axis3.position();
    float strafe = Controller1.Axis4.position();
    float spinny = Controller1.Axis1.position();
    /*
    to code the x-drive, we should first establish the directions 
    the motors must spin in order
    to move in certain directions
    forward: ++++
    backward: ----
    right: +-+-
    left: -+-+
    clockwise: +--+
    counterclockwise: -++-
*/
//

  if (Controller1.ButtonL1.pressing()){
    Intake.spin(forward);
    Intake2.spin(forward);
  }
  else if(Controller1.ButtonL1.pressing()
  else if (Controller1.ButtonL2.pressing()){
    Intake.spin(reverse);
    Intake2.spin(reverse);
  }
  leftFront.setVelocity(100, percent);
  rightFront.setVelocity(100, percent);
  rightBack.setVelocity(100, percent);
  leftBack.setVelocity(100, percent);

  rightFront.spin(forward, frontBack - strafe - spinny, percent);
  rightBack.spin(forward, frontBack - strafe + spinny, percent);
  leftFront.spin(forward, frontBack + strafe + spinny , percent);
  leftBack.spin(forward, frontBack + strafe - spinny , percent);
  


  vex::task::sleep(20);
}
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
