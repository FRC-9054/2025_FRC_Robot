#pragma once

#include <frc/Timer.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"

class AutoCommand : public frc2::CommandHelper<frc2::Command, AutoCommand> {
    public:
    AutoCommand(DriveSubsystem * driveSubsystem);

    void Initialize() override;
    void Execute() override;
    void End(bool interrupted) override;
    bool IsFinished() override;

    private:
        DriveSubsystem *driveSubsystem;
        frc::Timer timer;
        double seconds = 1;
};