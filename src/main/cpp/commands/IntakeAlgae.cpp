// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakeAlgae.h"

IntakeAlgae::IntakeAlgae(AlgeeIntake* subsystem) : m_algaeIntake(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_algaeIntake);
}

// Called when the command is initially scheduled.
void IntakeAlgae::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IntakeAlgae::Execute() {}

// Called once the command ends or is interrupted.
void IntakeAlgae::End(bool interrupted) {}

// Returns true when the command should end.
bool IntakeAlgae::IsFinished() {
  return false;
}
