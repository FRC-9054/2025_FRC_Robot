// // Copyright (c) FIRST and other WPILib contributors.
// // Open Source Software; you can modify and/or share it under the terms of
// // the WPILib BSD license file in the root directory of this project.

// #include "commands/IntakeCoral.h"
// #include "subsystems/CoralIntake.h"

// #include <iostream>


// #define DEBUG true
// #if DEBUG
//   #define dbgln(x) std::cout << "DEBUG::   :" << x << std::endl;
// #else
//   #define dbgln(x)
// #endif



// IntakeCoral::IntakeCoral(CoralIntake* subsystem) : m_coralIntake(subsystem) {
//   // Use addRequirements() here to declare subsystem dependencies.
//   AddRequirements(m_coralIntake);
//   dbgln("Coral Intake Command - Constructor")
// }

// // Called when the command is initially scheduled.
// void IntakeCoral::Initialize() {
//   m_coralIntake->IntakeCoralInit();
//   dbgln("Coral Intake Command - Initialize")
// }

// // Called repeatedly when this Command is scheduled to run
// void IntakeCoral::Execute() {
//   m_coralIntake->IntakeCoralPeriodic();
//   dbgln("Coral Intake Command - Execute")
// }

// // Called once the command ends or is interrupted.
// void IntakeCoral::End(bool interrupted) {
//   m_coralIntake->IntakeCoralEnd();
//   dbgln("Coral Intake Command - End");
// }

// //lmao who even needs an IsFinished function
