#include <commands/DriveCommand.h>

DriveCommand::DriveCommand(DriveSubsystem *driveSubsystem,
 double xSpeed, 
 double ySpeed,
 double zRotation)
 : driveSubsystem(driveSubsystem), xSpeed(xSpeed), ySpeed(ySpeed), zRotation(zRotation) {
    
 }

 void DriveCommand::Initialize() {}
 void DriveCommand::Execute() {
    driveSubsystem->Drive(units::meters_per_second_t(xSpeed), units::meters_per_second_t(ySpeed), units::radians_per_second_t(zRotation), false);
 }

 void DriveCommand::End(bool interrupted) {}

 bool DriveCommand::IsFinished() {return false;}
