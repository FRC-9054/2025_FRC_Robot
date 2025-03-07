// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/AlgeeIntake.h"
#include <Constants.h>
#include <iostream>


#define DEBUG true
#if DEBUG
  #define dbgln(x) std::cout << "DEBUG::   :" << x << std::endl;
#else
  #define dbgln(x)
#endif






using namespace rev::spark;

AlgeeIntake::AlgeeIntake() = default;
// AlgeeIntake::AlgeeIntake(const int Motor1CANID, const int algeeDetectionPort) : m_algeeIntakeMotorController() {}
// This method will be called once per scheduler run
void AlgeeIntake::Periodic() {
    // dbgln("void AlgeeIntake::Periodic()")
}


void AlgeeIntake::IntakeAlgeeInit() {
    // code for intaking algee goes here
    // Probably looks something like checking the limmit swich
    // and setting the intake motor speed to pull in the algee
        // m_algeeIntakeMotorController.Set(1.0);
  
    // dbgln("Eat my shorts!")
}

void AlgeeIntake::IntakeAlgeePeriodic() {
  // m_algeeIntakeMotorController.Set(1.0);
  // if (m_algeeDetectionLimmitSwich1.Get() == false && m_algeeDetectionLimmitSwich2.Get() == false) {
  //   dbgln("I have algae!");
  //   AlgeeIntake::IntakeAlgeeEnd();
  // } else{
  //   dbgln(" no algae :( ");
  //   m_algeeIntakeMotorController.Set(AlgeeIntakeConstants::IntakeSpeed);
  // }
  m_algeeIntakeMotorController.Set(AlgeeIntakeConstants::IntakeSpeed);

}

void AlgeeIntake::IntakeAlgeeEnd() {
  m_algeeIntakeMotorController.StopMotor();
}

/*
 
 B O R D E R 

 F O R 

 O R G A N I Z A T I O N

*/

void AlgeeIntake::PlaceAlgeeInit() {
    // This is much simpler. We probably just need to set the
    // motor speed to push the algee out.
   
}

void AlgeeIntake::PlaceAlgeePeriodic() {
    // This is much simpler. We probably just need to set the
    // motor speed to push the algee out.

    m_algeeIntakeMotorController.Set(AlgeeIntakeConstants::OuttakeSpeed);

}

void AlgeeIntake::PlaceAlgeeEnd() {
    // This is much simpler. We probably just need to set the
    // motor speed to push the algee out.
m_algeeIntakeMotorController.StopMotor();
}

/*
 
 B O R D E R 

 F O R 

 O R G A N I Z A T I O N

*/

void AlgeeIntake::WinchRetractInit(){}

void AlgeeIntake::WinchRetractPeriodic(){
  m_winchMotorController.Set(AlgeeIntakeConstants::WinchSpeedPull);
}

void AlgeeIntake::WinchRetractEnd(){
m_winchMotorController.StopMotor();
}

void AlgeeIntake::WinchExtendInit(){}

void AlgeeIntake::WinchExtendPeriodic(){
  m_winchMotorController.Set(AlgeeIntakeConstants::WinchSpeedPush);
}

void AlgeeIntake::WinchExtendEnd(){
m_winchMotorController.StopMotor();
}