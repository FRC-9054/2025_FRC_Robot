// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ElevatorUp.h"

#include <iostream>

#define DEBUG true
#if DEBUG
#define dbgln(x) std::cout << "DEBUG::   :" << x << std::endl;
#else
#define dbgln(x)
#endif

ElevatorUp::ElevatorUp(Elevator* subsystem) : m_elevator(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_elevator);
  //   dbgln("Coral Outtake Command - COnstructor");
}

// Called when the command is initially scheduled.
void ElevatorUp::Initialize() {
  m_elevator->ElevatorUpInit();
  //   dbgln("Coral Outtake Command - Initalize");
}

// Called repeatedly when this Command is scheduled to run
void ElevatorUp::Execute() {
  m_elevator->ElevatorUpPeriodic();
  //   dbgln("Coral Outtake Command - Execute");
}

// Called once the command ends or is interrupted.
void ElevatorUp::End(bool interrupted) {
  m_elevator->ElevatorUpEnd();
  //   dbgln("Coral Outtake Command - End");
}

// lmao who even neds an IsFinished function
