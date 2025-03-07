#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include <utility>

#include "subsystems/DriveSubsystem.h"

class DriveCommand : public frc2::CommandHelper<frc2::Command, DriveCommand> {
    public:
        DriveCommand(DriveSubsystem *driveSubsystem, double xSpeed,
         double ySpeed,
        double zSpeed);
    
    void Initialize() override;
    void Execute() override;
    void End(bool interrupted) override;
    bool IsFinished() override;

    private:
    DriveSubsystem *driveSubsystem;
    double xSpeed;
    double ySpeed;
    double zRotation;
};