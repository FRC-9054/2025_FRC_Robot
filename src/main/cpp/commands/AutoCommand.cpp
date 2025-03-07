// #include <utility>
// #include "commands/AutoCommand.h"
// #include "subsystems/DriveSubsystem.h"

// AutoCommand::AutoCommand(DriveSubsystem *driveSubsystem)
//         : driveSubsystem(driveSubsystem) {

//         }
        
// void AutoCommand::Initialize() {
//     timer.Restart();
// }

// void AutoCommand::Execute() {
//     DriveSubsystem->Drive(0.5_mps, 0.0_mps, 0.0_mps, false);
// }

// void AutoCommand::End(bool interrupted) {
//     timer.Stop();
//     DriveSubsystem->Drive(0.0_mps, 0.0_mps, 0.0_mps, false);
// }

// bool AutoCommand::IsFinished() {
//     return timer.Get().value() >= seconds;
// }