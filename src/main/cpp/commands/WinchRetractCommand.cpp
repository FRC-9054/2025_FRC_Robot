// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/WinchRetractCommand.h"

WinchRetractCommand::WinchRetractCommand(AlgeeIntake* subsystem) : m_algaeIntake(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void WinchRetractCommand::Initialize() {
   m_algaeIntake->WinchRetractInit();
}

// Called repeatedly when this Command is scheduled to run
void WinchRetractCommand::Execute() {
    m_algaeIntake->WinchRetractPeriodic();
}

// Called once the command ends or is interrupted.
void WinchRetractCommand::End(bool interrupted) {
    m_algaeIntake->WinchRetractEnd();
}
