// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <Constants.h>

#include <grpl/LaserCan.h> 


using namespace rev::spark;

class CoralIntake : public frc2::SubsystemBase {
 public:
  CoralIntake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

// Subsystem methods go here.
  // vvvvvvvvvvvvvvvvvvvvvvvvv
  void IntakeCoral();

  void PlaceCoral();
  // ^^^^^^^^^^^^^^^^^^^^^^^^^
  // Subsystem methods go here.

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
 SparkMax m_coralIntakeMotorController{CoralIntakeConstants::intakeMotorCoralCANID, rev::spark::SparkLowLevel::MotorType::kBrushless};
 grpl::LaserCan coralDetector{CoralIntakeConstants::intakeMotorCoralCANID};
};
