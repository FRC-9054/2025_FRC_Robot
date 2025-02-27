// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/WinchExtendCommand.h"

WinchExtendCommand::WinchExtendCommand(AlgeeIntake* subsystem) : m_algaeIntake(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void WinchExtendCommand::Initialize() {
  m_algaeIntake->WinchExtendInit();
}

// Called repeatedly when this Command is scheduled to run
void WinchExtendCommand::Execute() {
  m_algaeIntake->WinchExtendPeriodic();
}

// Called once the command ends or is interrupted.
void WinchExtendCommand::End(bool interrupted) {
  m_algaeIntake->WinchExtendEnd();
}

