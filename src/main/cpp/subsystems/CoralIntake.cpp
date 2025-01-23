// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/CoralIntake.h"

CoralIntake::CoralIntake() = default;

// This method will be called once per scheduler run
void CoralIntake::Periodic() {
//spin motors to intake coral, when sensor senses coral, stop motor

}

void CoralIntake::IntakeCoral() {
    if(coralDetector.get_measurement().value().distance_mm < 10){
       m_coralIntakeMotorController.StopMotor();
    }
    else{
        m_coralIntakeMotorController.Set(1.0);
    }

}

void CoralIntake::PlaceCoral() {
    
     m_coralIntakeMotorController.Set(1.0);

}

//Hi Quaid :)


/*Damien, continue to work on the subsystems, and
I will help you with the github uploading when I
get back*/