// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/AlgeeIntake.h"

using namespace rev::spark;

AlgeeIntake::AlgeeIntake() = default;
// AlgeeIntake::AlgeeIntake(const int Motor1CANID, const int algeeDetectionPort) : m_algeeIntakeMotorController() {}
// This method will be called once per scheduler run
void AlgeeIntake::Periodic() {}

void AlgeeIntake::IntakeAlgee() {
    // code for intaking algee goes here
    // Probably looks something like checking the limmit swich
    // and setting the intake motor speed to pull in the algee
    // if it is NOT pressed
    if (m_algeeDetectionLimmitSwich.Get() == false) {
        m_algeeIntakeMotorController.Set(1.0);
   
    }
    else{
        m_algeeIntakeMotorController.StopMotor();
    }
}

void AlgeeIntake::PlaceAlgee() {
    // This is much simpler. We probably just need to set the
    // motor speed to push the algee out.
        m_algeeIntakeMotorController.Set(-1.0);
}
