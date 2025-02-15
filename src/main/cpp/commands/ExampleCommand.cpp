// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>

#include "commands/ExampleCommand.h"

ExampleCommand::ExampleCommand(exampleSubsystem* subsystem) : m_subsystem{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void ExampleCommand::Initialize() {
  std::cout << "command initialized" << std:: endl;
}

// Called repeatedly when this Command is scheduled to run
void ExampleCommand::Execute() {
  std::cout << "command executing" << std:: endl;
}

// Called once the command ends or is interrupted.
void ExampleCommand::End(bool interrupted) {
  std::cout << "command interrupted" << std:: endl;
}

// Returns true when the command should end.
bool ExampleCommand::IsFinished() {
  std::cout << "command isn't finished" << std:: endl;
  return false;
}
