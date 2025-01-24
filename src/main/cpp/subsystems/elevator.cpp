// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/elevator.h"

elevator::elevator() = default;

// This method will be called once per scheduler run
void elevator::Periodic() {}

void elevator::levelSetter(){
    // the elevator will be moved with the D-pad, which uses POV

    // if up POV is pressed, go up
    if(m_elevator.Get() == true ){
        m_elevatorController.StopMotor();
    }else{
        m_elevatorController.Set(1.0);
    }
    
    // if down POV is pressed, go down
  if(m_elevator.Get() == true ){
        m_elevatorController.StopMotor();
    }else{
        m_elevatorController.Set(-1.0);
    }
}