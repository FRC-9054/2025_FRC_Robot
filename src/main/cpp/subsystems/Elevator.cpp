// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Elevator.h"

#include <iostream>

#define DEBUG true
#if DEBUG
#define dbgln(x) std::cout << "DEBUG::   :" << x << std::endl;
#define dbg2(x, y) std::cout << x << y;
#define dbgln2(x, y) std::cout << x << y << std::endl;
#else
#define dbgln(x)
#define dbg2(x, y)
#define dbgln2(x, y)
#endif

Elevator::Elevator() {
  m_elevatorEncoder.SetPosition(100.0);
  holdingPosition = m_elevatorEncoder.GetPosition();
  holdCurrentPosition = true;
  m_elevatorSparkBaseConfig.SetIdleMode(
      rev::spark::SparkBaseConfig::IdleMode::kCoast);
  // m_elevatorClosedLoopConfig.Pid();
  m_elevatorController.Configure(
      m_elevatorSparkBaseConfig,
      rev::spark::SparkMax::ResetMode::kNoResetSafeParameters,
      rev::spark::SparkMax::PersistMode::kNoPersistParameters);
  m_pidController.SetP(kP);
  m_pidController.SetI(kI);
  m_pidController.SetD(kD);
  m_pidController.SetIZone(kIz);
  m_pidController.SetFF(kFF);
  m_pidController.SetOutputRange(kMinOutput, kMaxOutput);
  
}

// This method will be called once per sccPheduler run
void Elevator::Periodic() {
  // m_elevatorClosedLoopController.SetReference(1, SparkMax::ControlType::kPosition, ClosedLoopSlot::kSlot0);
  // spin motors to intake coral, when sensor senses coral, stop motor
  if (holdCurrentPosition) {
    // hold current position
    HoldPosition(holdingPosition);
  } else {
    // do nothing...
  }
  // thats it
  // what were you expecting?
  // go home
  // move on
  // quit reading
  // stop
  // Stop
  // STOP
  // i give up
  // 💀
}

void Elevator::HoldPosition(float desiredPosition) {
  // m_elevatorClosedLoopController.SetReference(desiredPosition,
  // rev::spark::SparkLowLevel::ControlType::kPosition);
  // m_pidController.SetReference(
  //     desiredPosition, rev::spark::SparkLowLevel::ControlType::kPosition);
  m_elevatorClosedLoopController.SetReference(desiredPosition, SparkMax::ControlType::kPosition, ClosedLoopSlot::kSlot0);
}

void Elevator::ElevatorUpInit() {
  // if(coralDetector.get_measurement().value().distance_mm < 10){
  //    m_coralIntakeMotorController.StopMotor();
  // }
  // else{
  //     m_coralIntakeMotorController.Set(1.0);
  // }
  holdCurrentPosition = false;
}

void Elevator::ElevatorUpPeriodic() {
  // spin motor
  // don't spin motor while limit switch is pressed though

  // I don't remember why, but the limit switch returns false when it is pressed
  //   if (m_coralDetectionLimitSwitch.Get() == false) {
  //     m_coralIntakeMotorController.Set(0.0);
  //   } else {
  //     m_coralIntakeMotorController.Set(CoralIntakeConstants::OuttakeSpeed);
  //   }
  m_elevatorController.Set(ElevatorConstants::ElevatorUpSpeed);
  dbgln(m_elevatorEncoder.GetPosition())
}

void Elevator::ElevatorUpEnd() {
  m_elevatorController.StopMotor();
  holdingPosition = m_elevatorEncoder.GetPosition();
  dbgln(holdingPosition) holdCurrentPosition = true;
}

void Elevator::ElevatorDownInit() {
  // if(coralDetector.get_measurement().value().distance_mm < 10){
  //    m_coralIntakeMotorController.StopMotor();
  // }
  // else{
  //     m_coralIntakeMotorController.Set(1.0);
  // }
}

void Elevator::ElevatorDownPeriodic() {
  // spin motor
  // don't spin motor while limit switch is pressed though

  // I don't remember why, but the limit switch returns false when it is pressed
  //   if (m_coralDetectionLimitSwitch.Get() == false) {
  //     m_coralIntakeMotorController.Set(0.0);
  //   } else {
  //     m_coralIntakeMotorController.Set(CoralIntakeConstants::OuttakeSpeed);
  //   }
  m_elevatorController.Set(ElevatorConstants::ElevatorDownSpeed);
  dbgln(m_elevatorEncoder.GetPosition())
}

void Elevator::ElevatorDownEnd() {
  m_elevatorController.StopMotor();
  dbgln(m_elevatorEncoder.GetPosition())
}

double Elevator::getElevatorPosition() {
  return m_elevatorEncoder.GetPosition();
}

bool Elevator::getLimitSwitch() {
  bool l_swPos = m_elevatorLimitSwitch.Get();
  dbg2("", l_swPos) return l_swPos;
}

void Elevator::homeInit() {
  backingOff = false;
  firstStep = true;
  // isHomed = false;
}

void Elevator::homePeriodic() {
  // dbg2("backingOff = ", backingOff)
  // dbg2("      firstStep = ", firstStep)
  // dbgln2("      isHomed = ", isHomed)
  if (isHomed == false) {
    dbgln("NOT AT HOME");
    if (firstStep) {           // if this is the first step
      if (getLimitSwitch()) {  // if we just hit the limit sw for the first time
        dbgln("if we just hit the limmit sw for the first time");
        m_elevatorController.Set(0.0);
        m_elevatorEncoder.SetPosition(0);  // zero the encoder
        // m_elevatorController.Set(ElevatorConstants::HomeUpSpeed);
        backingOff = true;
        firstStep = false;
        return;
      } else {  // If we havent hit the limit sw yet
        dbgln("If we havent hit the limit sw yet");
        m_elevatorController.Set(ElevatorConstants::HomeDownFastSpeed);
        return;
      }
    } else {  // If its not the first step
      dbgln("if its not the first step");
      if (backingOff) {  // if we are backing off of the limmit sw
        dbgln("if we are backing off the limmit switch");
        m_elevatorController.Set(ElevatorConstants::HomeUpSpeed);
        if (getElevatorPosition() >=
            ElevatorConstants::HomePositionBackOffValue) {  // If we have gone
                                                            // up far enough
          dbgln("if we have gone far enough");
          m_elevatorController.Set(ElevatorConstants::HomeDownSlowSpeed);
          backingOff = false;
          return;
        } else {  // If we havent gone far enough up
          dbgln("if we havent gone far enough up");
          return;
        }
      } else {  // if we arent backing off of the limmit sw and it's the second
                // step
        dbgln("if we arent backing off the limmit sw");
        if (getLimitSwitch()) {  // limit sw is triggered
          dbgln("limit sw is triggered");
          m_elevatorController.Set(0.0);
          isHomed = true;
          m_elevatorEncoder.SetPosition(0);
          return;
        } else {  // limit sw not pressed
          dbgln("limit sw not pressed");
          m_elevatorController.Set(ElevatorConstants::HomeDownSlowSpeed);
          return;
        }
        return;
      }
      return;
    }
    return;
  }
  dbgln("ALREADY HOME");
  return;
}

bool Elevator::homeEnd() { return isHomed; }

// void ElevatorSubsystem::PlaceCoralInit() {
//   // nothing ever happens in these functions
// }

// void ElevatorSubsystem::PlaceCoralPeriodic() {
//   // spin the motor
//   // no one cares about the limit switch here
//   // or maybe only spin if the limit switch is pressed?
//   // but then it'd only stop half way
//   // yeah, ignore that. bad plan, bad plan.
//   m_coralIntakeMotorController.Set(CoralIntakeConstants::OuttakeSpeed);
// }

// void ElevatorSubsystem::PlaceCoralEnd() {
//   m_coralIntakeMotorController.Set(0.0);
// }
