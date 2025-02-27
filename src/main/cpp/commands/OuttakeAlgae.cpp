// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/OuttakeAlgae.h"
#include "subsystems/AlgeeIntake.h"
OuttakeAlgae::OuttakeAlgae(AlgeeIntake* subsystem) : m_algaeIntake(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  //  AddRequirements(m_algaeIntake);
  // AlgeeIntake->PlaceAlgeeInit();

}

// Called when the command is initially scheduled.
void OuttakeAlgae::Initialize() {
  m_algaeIntake->PlaceAlgeeInit();
}

// Called repeatedly when this Command is scheduled to run
void OuttakeAlgae::Execute() {
  m_algaeIntake->PlaceAlgeePeriodic();
}

// Called once the command ends or is interrupted.
void OuttakeAlgae::End(bool interrupted) {
  m_algaeIntake->PlaceAlgeeEnd();
}

// // Returns true when the command should end.
// bool OuttakeAlgae::IsFinished() {
//   return false;
// }
