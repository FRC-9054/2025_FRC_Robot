// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>

#include "subsystems/exampleSubsystem.h"

exampleSubsystem::exampleSubsystem() = default;

// This method will be called once per scheduler run
void exampleSubsystem::Periodic() {

}

frc2::CommandPtr exampleSubsystem::ExampleMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce([this] { std::cout << "example method command" << std::endl; });
}

bool exampleSubsystem::ExampleCondition() {
  // Query some boolean state, such as a digital sensor.
  return false;
}
