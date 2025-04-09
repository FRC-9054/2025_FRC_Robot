// // Copyright (c) FIRST and other WPILib contributors.
// // Open Source Software; you can modify and/or share it under the terms of
// // the WPILib BSD license file in the root directory of this project.

// #include "commands/OuttakeCoral.h"

// #include <iostream>


// #define DEBUG true
// #if DEBUG
//   #define dbgln(x) std::cout << "DEBUG::   :" << x << std::endl;
// #else
//   #define dbgln(x)
// #endif



// OuttakeCoral::OuttakeCoral(CoralIntake* subsystem) : m_coralIntake(subsystem) {
//   // Use addRequirements() here to declare subsystem dependencies.
//   AddRequirements(m_coralIntake);
//   dbgln("Coral Outtake Command - COnstructor");
// }

// // Called when the command is initially scheduled.
// void OuttakeCoral::Initialize() {
//   m_coralIntake->PlaceCoralInit();
//   dbgln("Coral Outtake Command - Initalize");
// }

// // Called repeatedly when this Command is scheduled to run
// void OuttakeCoral::Execute() {
//   m_coralIntake->PlaceCoralPeriodic();
//   dbgln("Coral Outtake Command - Execute");
// }

// // Called once the command ends or is interrupted.
// void OuttakeCoral::End(bool interrupted) {
//   m_coralIntake->PlaceCoralEnd();
//   dbgln("Coral Outtake Command - End");
// }

// //lmao who even neds an IsFinished function
