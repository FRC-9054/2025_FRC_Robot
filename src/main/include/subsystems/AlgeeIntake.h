// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <frc/DigitalInput.h>
#include <Constants.h>

using namespace rev::spark;

class AlgeeIntake : public frc2::SubsystemBase {
 public:
  AlgeeIntake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.
  // vvvvvvvvvvvvvvvvvvvvvvvvv
  void IntakeAlgeeInit();

  void IntakeAlgeePeriodic();

  void IntakeAlgeeEnd();



  void PlaceAlgeeInit();

  void PlaceAlgeePeriodic();

  void PlaceAlgeeEnd();



  void WinchRetractInit();

  void WinchRetractPeriodic();

  void WinchRetractEnd();

   void WinchExtendInit();

  void WinchExtendPeriodic();

  void WinchExtendEnd();
  // ^^^^^^^^^^^^^^^^^^^^^^^^^
  // Subsystem methods go here.

//  private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  SparkMax m_algeeIntakeMotorController{AlgeeIntakeConstants::intakeMotor1CANID, rev::spark::SparkLowLevel::MotorType::kBrushless};
  SparkMax m_winchMotorController{AlgeeIntakeConstants::winchMotorCANID, rev::spark::SparkLowLevel::MotorType::kBrushless};
  frc::DigitalInput m_algeeDetectionLimmitSwich1{AlgeeIntakeConstants::algeeDetectionLimmitSwich1Port};
  frc::DigitalInput m_algeeDetectionLimmitSwich2{AlgeeIntakeConstants::algeeDetectionLimmitSwich2Port};
  frc::DigitalInput m_intakeInPlaceDetectionSwitch{AlgeeIntakeConstants::intakeSetDetectionLimmitSwichPort};
};
