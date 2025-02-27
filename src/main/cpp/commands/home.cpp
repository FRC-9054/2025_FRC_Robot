// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/home.h"

home::home(Elevator*subsystem) : m_Elevator(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void home::Initialize() {
  m_Elevator->homeInit();
}

// Called repeatedly when this Command is scheduled to run
void home::Execute() {
  m_Elevator->homePeriodic();
}

// Called once the command ends or is interrupted.
void home::End(bool interrupted) {
  m_Elevator->homeEnd();
}


bool home::IsFinished() {
  // dbgln(" ");
  return m_Elevator->homeEnd();
}
