// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <rev/SparkClosedLoopController.h>
// #include <ClosedLoopConfig.h>
#include <Constants.h>
#include <frc/DigitalInput.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/SparkRelativeEncoder.h>



using namespace rev::spark;

class Elevator : public frc2::SubsystemBase {
 public:
  Elevator();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void HoldPosition(float desiredPosition);

  // void levelSetter();

  void ElevatorUpInit();

  void ElevatorUpPeriodic();

  void ElevatorUpEnd();

  void ElevatorDownInit();

  void ElevatorDownPeriodic();

  void ElevatorDownEnd();

  double getElevatorPosition();

  bool getLimitSwitch();

  void homeInit();

  void homePeriodic();

  bool homeEnd();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax m_elevatorController{
      ElevatorConstants::MotorElevatorCANID,
      rev::spark::SparkLowLevel::MotorType::kBrushless};
  SparkRelativeEncoder m_elevatorEncoder = m_elevatorController.GetEncoder();
  SparkClosedLoopController m_elevatorClosedLoopController =
      m_elevatorController.GetClosedLoopController();
  ClosedLoopConfig m_elevatorClosedLoopConfig;
  rev::SparkPIDController m_pidController =
      m_elevatorController.GetPIDController();
  SparkBaseConfig m_elevatorSparkBaseConfig;
  frc::DigitalInput m_elevatorLimitSwitch{ElevatorConstants::ElevatorLimitSwID};
  bool isHomed = false;
  bool firstStep = true;
  bool backingOff = false;
  double currentElevatorPosition;
  bool newValueThatWillWorkThisTimeForSure = false;
  bool holdCurrentPosition = false;
  float holdingPosition;
  double kP = 0.1, kI = 1e-4, kD = 1, kIz = 0, kFF = 0, kMaxOutput = 1,
         kMinOutput = -1;
};
