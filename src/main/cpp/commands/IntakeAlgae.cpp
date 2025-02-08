// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakeAlgae.h"

#include <iostream>


#define DEBUG true
#if DEBUG
  #define dbgln(x) std::cout << "DEBUG::   :" << x << std::endl;
#else
  #define dbgln(x)
#endif





IntakeAlgae::IntakeAlgae(AlgeeIntake* subsystem) : m_algaeIntake(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_algaeIntake);
  dbgln("IntakeAlgae(AlgeeIntake* subsystem) : m_algaeIntake(subsystem)")
}

// Called when the command is initially scheduled.
void IntakeAlgae::Initialize() {
  dbgln("Initialize()")
}

// Called repeatedly when this Command is scheduled to run
void IntakeAlgae::Execute() {
  dbgln("Execute()")
}

// Called once the command ends or is interrupted.
void IntakeAlgae::End(bool interrupted) {
  dbgln("End(bool interrupted)")
}

// Returns true when the command should end.
bool IntakeAlgae::IsFinished() {
  dbgln("IsFinished()")
  return false;
}
