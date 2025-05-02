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

// AlgeeIntake::AlgeeIntake() = default;
AlgeeIntake::AlgeeIntake() {
  m_algeeIntakeMotorController.SetInverted(true);
  m_winchMotorEncoder.SetPosition(1000);
  m_algaeIntakeMotorEncoder.SetPosition(1000);
  m_holdingPos = m_winchMotorEncoder.GetPosition();
  m_intakeMotorHoldingPosition = m_algaeIntakeMotorEncoder.GetPosition();
}
// AlgeeIntake::AlgeeIntake(const int Motor1CANID, const int algeeDetectionPort)
// : m_algeeIntakeMotorController() {} This method will be called once per
// scheduler run

void AlgeeIntake::HoldAlgeeInit() {
  m_algaeIntakeMotorEncoder.SetPosition(1000);
  m_intakeMotorHoldingPosition = m_algaeIntakeMotorEncoder.GetPosition();
  dbgln("position set to 1000")
}

void AlgeeIntake::HoldAlgeePeriodic() {
  dbgln(currentlySelectedIntakeCommand);
  switch (currentlySelectedIntakeCommand)
  {
  case holdAlgae: {
      float maxSpeedErrorAmmount = .125;
      float positionTargetTollerence = maxSpeedErrorAmmount * .2;   // use the slowest speed the motor can run to get the smallest realistic tollerence
      float currentPosition = m_algaeIntakeMotorEncoder.GetPosition();
      float correctionVal;
      float speed;
      float pVal = 1 / maxSpeedErrorAmmount;
      float error = m_holdingPos - currentPosition;
      
      if (currentPosition < (m_intakeMotorHoldingPosition-positionTargetTollerence)) {   // if less than target position
        if (error >= maxSpeedErrorAmmount) {   // if large error, set speed to max
          speed = 0.5;
        } else {    // else calculate error and ammount of motor speed to remove error
          correctionVal = pVal * error;
          correctionVal = correctionVal * -1;      /////////////// if it corrects backward, remove -1 from this line and put in "too large correction" code
        }
        m_algeeIntakeMotorController.Set(correctionVal);
       
      } else if (currentPosition >= (m_intakeMotorHoldingPosition + positionTargetTollerence)) {        // else if greater than the target position
        if (error >= maxSpeedErrorAmmount) {   // if large error, set speed to max
          speed = 0.5;
          correctionVal = speed;
        } else {    // else calculate error and ammount of motor speed to remove error
          correctionVal = pVal * error;
          
        }
        m_algeeIntakeMotorController.Set(correctionVal);
      }
       dbgln(correctionVal)
    }
  break;
    
  case intake:
    m_algaeIntakeMotorEncoder.SetPosition(1000);
    m_holdingPos = m_algaeIntakeMotorEncoder.GetPosition();
  break;
    
  case place:
    m_algaeIntakeMotorEncoder.SetPosition(1000);
    m_holdingPos = m_algaeIntakeMotorEncoder.GetPosition();
  break;
  
  default:
  break;
  }
}

void AlgeeIntake::HoldAlgeeEnd() {
dbgln("function ended")
}


void AlgeeIntake::Periodic() {
  // dbgln("void AlgeeIntake::Periodic()")
  // switch (currentlySelectedCommand)
  // {
  // case holdPosition: {
  //     float maxSpeedErrorAmmount = 15;
  //     float positionTargetTollerence = maxSpeedErrorAmmount * .15;   // use the slowest speed the motor can run to get the smallest realistic tollerence
  //     float currentPosition = m_winchMotorEncoder.GetPosition();
  //     float correctionVal;
  //     float speed;
  //     float pVal = 1 / maxSpeedErrorAmmount;
  //     float error = m_holdingPos - currentPosition;
      
  //     if (currentPosition < (m_holdingPos-positionTargetTollerence)) {   // if less than target position
  //       if (error >= maxSpeedErrorAmmount) {   // if large error, set speed to max
  //         speed = 1.0;
  //       } else {    // else calculate error and ammount of motor speed to remove error
  //         correctionVal = pVal * error;
  //       }
  //       m_winchMotorController.Set(correctionVal);
  //     } else if (currentPosition >= (m_holdingPos + positionTargetTollerence)) {        // else if greater than the target position
  //       if (error >= maxSpeedErrorAmmount) {   // if large error, set speed to max
  //         speed = 1.0;
  //         correctionVal = speed;
  //       } else {    // else calculate error and ammount of motor speed to remove error
  //         correctionVal = pVal * error;
  //         correctionVal = correctionVal * -1;      /////////////// if it corrects backward, remove -1 from this line and put in "too large correction" code
  //       }
  //       m_winchMotorController.Set(correctionVal);
  //     }
  //   }
  // break;
    
  // case retract:
  //   m_winchMotorEncoder.SetPosition(1000);
  //   m_holdingPos = m_winchMotorEncoder.GetPosition();
  // break;
    
  // case extend:
  //   m_winchMotorEncoder.SetPosition(1000);
  //   m_holdingPos = m_winchMotorEncoder.GetPosition();
  // break;
  
  // default:
  // break;
  // }
  
  
}

void AlgeeIntake::IntakeAlgeeInit() {
  // code for intaking algee goes here
  // Probably looks something like checking the limmit swich
  // and setting the intake motor speed to pull in the algee
  // m_algeeIntakeMotorController.Set(1.0);

  // dbgln("Eat my shorts!")
  currentlySelectedIntakeCommand = intake;
}

void AlgeeIntake::IntakeAlgeePeriodic() {
  // m_algeeIntakeMotorController.Set(1.0);
  // if (m_algeeDetectionLimmitSwich1.Get() == false &&
  // m_algeeDetectionLimmitSwich2.Get() == false) {
  //   dbgln("I have algae!");
  //   AlgeeIntake::IntakeAlgeeEnd();
  // } else{
  //   dbgln(" no algae :( ");
  //   m_algeeIntakeMotorController.Set(AlgeeIntakeConstants::IntakeSpeed);
  // }
  m_algeeIntakeMotorController.Set(AlgeeIntakeConstants::IntakeSpeed);
  currentlySelectedIntakeCommand = intake;
}

void AlgeeIntake::IntakeAlgeeEnd() { 
  m_algeeIntakeMotorController.StopMotor();
  currentlySelectedIntakeCommand = holdAlgae;
}

/*

 B O R D E R

 F O R

 O R G A N I Z A T I O N

*/

void AlgeeIntake::PlaceAlgeeInit() {
  // This is much simpler. We probably just need to set the
  // motor speed to push the algee out.
  currentlySelectedIntakeCommand = place;
}

void AlgeeIntake::PlaceAlgeePeriodic() {
  // This is much simpler. We probably just need to set the
  // motor speed to push the algee out.

  m_algeeIntakeMotorController.Set(-AlgeeIntakeConstants::OuttakeSpeed);
  currentlySelectedIntakeCommand = place;
}

void AlgeeIntake::PlaceAlgeeEnd() {
  // This is much simpler. We probably just need to set the
  // motor speed to push the algee out.
  m_algeeIntakeMotorController.StopMotor();
  currentlySelectedIntakeCommand = holdAlgae;
}

/*

 B O R D E R

 F O R

 O R G A N I Z A T I O N

*/




void AlgeeIntake::WinchRetractInit() {
  currentlySelectedCommand = retract;
}

void AlgeeIntake::WinchRetractPeriodic() {
  m_winchMotorController.Set(AlgeeIntakeConstants::WinchSpeedPull);
  currentlySelectedCommand = retract;
}

void AlgeeIntake::WinchRetractEnd() { 
  m_winchMotorController.StopMotor();
  currentlySelectedCommand = holdPosition;
}







void AlgeeIntake::WinchExtendInit() {
  currentlySelectedCommand = extend;
}

void AlgeeIntake::WinchExtendPeriodic() {
  m_winchMotorController.Set(AlgeeIntakeConstants::WinchSpeedPush);
  currentlySelectedCommand = extend;
}

void AlgeeIntake::WinchExtendEnd() { 
  m_winchMotorController.StopMotor();
  currentlySelectedCommand = holdPosition;
}