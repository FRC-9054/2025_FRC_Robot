// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/HoldAlgee.h"

HoldAlgee::HoldAlgee() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void HoldAlgee::Initialize() {
  m_algaeIntake->HoldAlgeeInit();
}

// Called repeatedly when this Command is scheduled to run
void HoldAlgee::Execute() {
  m_algaeIntake->HoldAlgeePeriodic();
}

// Called once the command ends or is interrupted.
void HoldAlgee::End(bool interrupted) {
  m_algaeIntake->HoldAlgeeEnd();
}

// // Returns true when the command should end.
// bool HoldAlgee::IsFinished() {
//   return false;
// }
