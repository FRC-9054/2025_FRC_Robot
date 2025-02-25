// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/CoralIntake.h"

CoralIntake::CoralIntake() = default;

// This method will be called once per scheduler run
void CoralIntake::Periodic() {
//spin motors to intake coral, when sensor senses coral, stop motor

}

void CoralIntake::IntakeCoralInit() {
    // if(coralDetector.get_measurement().value().distance_mm < 10){
    //    m_coralIntakeMotorController.StopMotor();
    // }
    // else{
    //     m_coralIntakeMotorController.Set(1.0);
    // }
}

void CoralIntake::IntakeCoralPeriodic() {
    // spin motor
    // don't spin motor while limit switch is pressed though

    //I don't remember why, but the limit switch returns false when it is pressed
    if (m_coralDetectionLimitSwitch.Get() == false) {
        m_coralIntakeMotorController.Set(0.0);
    }
    else {
        m_coralIntakeMotorController.Set(CoralIntakeConstants::IntakeSpeed);
    }
}

void CoralIntake::IntakeCoralEnd() {
    m_coralIntakeMotorController.Set(0.0);
}

void CoralIntake::PlaceCoralInit() {
    // nothing ever happens in these functions
}

void CoralIntake::PlaceCoralPeriodic() {
    // spin the motor
    // no one cares about the limit switch here
    // or maybe only spin if the limit switch is pressed?
    // but then it'd only stop half way
    // yeah, ignore that. bad plan, bad plan.
    m_coralIntakeMotorController.Set(CoralIntakeConstants::IntakeSpeed);
}

void CoralIntake::PlaceCoralEnd() {
    m_coralIntakeMotorController.Set(0.0);
}
