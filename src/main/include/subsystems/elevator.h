// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <Constants.h>
#include <frc/DigitalInput.h>
#include <rev/SparkMax.h>

using namespace rev::spark;

class elevator : public frc2::SubsystemBase {
 public:
  elevator();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void levelSetter();
    

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  SparkMax m_elevatorController{ElevatorConstants::MotorElevatorCANID, rev::spark::SparkLowLevel::MotorType::kBrushless};
 frc::DigitalInput m_elevator{ElevatorConstants::ElevatorID};
};
