// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TestCommand.h"
#include <iostream>

#define DEBUG true
#if DEBUG
  #define dbgln(x) std::cout << "DEBUG::   :" << x << std::endl;
#else
  #define dbgln(x)
#endif

/*
https://docs.wpilib.org/en/stable/docs/software/commandbased/command-scheduler.html
*/


TestCommand::TestCommand() {
  // Use addRequirements() here to declare subsystem dependencies.
  dbgln("TestCommand()")
}

// Called when the command is initially scheduled.
void TestCommand::Initialize() {
  dbgln("Initialize()")
}

// Called repeatedly when this Command is scheduled to run
void TestCommand::Execute() {
  dbgln("Execute()")
  // std::cout << "test command is doin somethin" << std::endl;
}

// Called once the command ends or is interrupted.
void TestCommand::End(bool interrupted) {
  dbgln("End(boolinterrupted)")
}

// Returns true when the command should end.
bool TestCommand::IsFinished() {
  dbgln("IsFinished()")
  return false;
}
