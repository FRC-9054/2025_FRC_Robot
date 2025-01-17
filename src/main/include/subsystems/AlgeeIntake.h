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
  void IntakeAlgee();

  void PlaceAlgee();
  // ^^^^^^^^^^^^^^^^^^^^^^^^^
  // Subsystem methods go here.

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  SparkMax m_algeeIntakeMotorController{AlgeeIntakeConstants::intakeMotor1CANID, rev::spark::SparkLowLevel::MotorType::kBrushless};
  frc::DigitalInput m_algeeDetectionLimmitSwich{AlgeeIntakeConstants::algeeDetectionLimmitSwichPort};
};
