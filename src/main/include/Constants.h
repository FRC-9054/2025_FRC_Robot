// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/trajectory/TrapezoidProfile.h>
#include <rev/SparkMax.h>
#include <units/acceleration.h>
#include <units/angular_acceleration.h>
#include <units/angular_velocity.h>
#include <units/current.h>
#include <units/length.h>
#include <units/velocity.h>

#include <numbers>

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or bool constants.  This should not be used for any other purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {
// Driving Parameters - Note that these are not the maximum capable speeds of
// the robot, rather the allowed maximum speeds
constexpr units::meters_per_second_t kMaxSpeed = 3.6_mps;  // 4.8_mps
constexpr units::radians_per_second_t kMaxAngularSpeed{
    1.5 * std::numbers::pi};  // kMaxAngularSpeed{2 * std::numbers::pi}

constexpr double kDirectionSlewRate = 0.28;  // radians per second // 1.2    // .3   //0.25
constexpr double kMagnitudeSlewRate =
    0.63;  // percent per second (1 = 100%)    // 1.8    // .8   //0.6
constexpr double kRotationalSlewRate =
    0.8;  // percent per second (1 = 100%)    // 2.0
    
constexpr double kxInputCurveFactor = 1.8;
constexpr double kyInputCurveFactor = 1.8;
constexpr double krotInputCurveFactor = 1;

// Chassis configuration
constexpr units::meter_t kTrackWidth =
    0.5334_m;  // Distance between centers of right and left wheels on robot
constexpr units::meter_t kWheelBase =
    0.5334_m;  // Distance between centers of front and back wheels on robot //
               // 0.6731_m

// Angular offsets of the modules relative to the chassis in radians
constexpr double kFrontLeftChassisAngularOffset = -std::numbers::pi / 2;
constexpr double kFrontRightChassisAngularOffset = 0;
constexpr double kRearLeftChassisAngularOffset = std::numbers::pi;
constexpr double kRearRightChassisAngularOffset = std::numbers::pi / 2;

// SPARK MAX CAN IDs
constexpr int kFrontLeftDrivingCanId = 10;
constexpr int kRearLeftDrivingCanId = 12;
constexpr int kFrontRightDrivingCanId = 14;
constexpr int kRearRightDrivingCanId = 16;

constexpr int kFrontLeftTurningCanId = 11;
constexpr int kRearLeftTurningCanId = 13;
constexpr int kFrontRightTurningCanId = 15;
constexpr int kRearRightTurningCanId = 17;
}  // namespace DriveConstants

namespace ModuleConstants {
// The MAXSwerve module can be configured with one of three pinion gears: 12T,
// 13T, or 14T. This changes the drive speed of the module (a pinion gear with
// more teeth will result in a robot that drives faster).
constexpr int kDrivingMotorPinionTeeth = 14;

// Calculations required for driving motor conversion factors and feed forward
constexpr double kDrivingMotorFreeSpeedRps =
    5676.0 / 60;  // NEO free speed is 5676 RPM
constexpr units::meter_t kWheelDiameter = 0.0762_m;
constexpr units::meter_t kWheelCircumference =
    kWheelDiameter * std::numbers::pi;
// 45 teeth on the wheel's bevel gear, 22 teeth on the first-stage spur gear, 15
// teeth on the bevel pinion
constexpr double kDrivingMotorReduction =
    (45.0 * 22) / (kDrivingMotorPinionTeeth * 15);
constexpr double kDriveWheelFreeSpeedRps =
    (kDrivingMotorFreeSpeedRps * kWheelCircumference.value()) /
    kDrivingMotorReduction;
}  // namespace ModuleConstants

namespace AutoConstants {
constexpr auto kMaxSpeed = 3_mps;
constexpr auto kMaxAcceleration = 3_mps_sq;
constexpr auto kMaxAngularSpeed = 3.142_rad_per_s;
constexpr auto kMaxAngularAcceleration = 3.142_rad_per_s_sq;

constexpr double kPXController = 0.5;
constexpr double kPYController = 0.5;
constexpr double kPThetaController = 0.5;

extern const frc::TrapezoidProfile<units::radians>::Constraints
    kThetaControllerConstraints;
}  // namespace AutoConstants

namespace OIConstants {
constexpr int kDriverControllerPort = 0;
constexpr int kOperatorControllerPort = 1;
constexpr double kDriveDeadband = 0.05;

const int leftXAxis = 0;
const int leftYAxis = 1;
const int rightXAxis = 4;
const int rightYAxis = 5;
const int leftBumper = 5;
const int rightBumper = 6;
const int aButton = 1;
const int bButton = 2;
const int xButton = 3;
const int yButton = 4;
const int leftTrigger = 2;
const int rightTrigger = 3;
const int POVup = 0;
const int POVdown = 180;
}  // namespace OIConstants

namespace OIControllMapping {
// Driver
const int driveX = OIConstants::leftXAxis;
const int driveY = OIConstants::leftYAxis;
const int driveRotate = OIConstants::rightXAxis;
const int setBreaks = OIConstants::rightBumper;
// Operator
const int intakeAlgae = OIConstants::xButton;
const int outtakeAlgae = OIConstants::aButton;
const int intakeCoral = OIConstants::leftBumper;
const int outtakeCoral = OIConstants::leftTrigger;
const int elevatorUp = OIConstants::yButton;
const int elevatorDown = OIConstants::bButton;
const int winchUp = OIConstants::rightBumper;
const int winchDown = OIConstants::rightTrigger;

}  // namespace OIControllMapping

namespace AlgeeIntakeConstants {
const int intakeMotor1CANID = 21;
const int winchMotorCANID = 20;
const int algeeDetectionLimmitSwich1Port = 1;
const int algeeDetectionLimmitSwich2Port = 2;
const int intakeSetDetectionLimmitSwichPort = 3;
const float IntakeSpeed = 0.25;    // 0.3
const float OuttakeSpeed = 0.15;  // -.3
const float WinchSpeedPull = 0.5f;
const float WinchSpeedPush = -0.5f;
}  // namespace AlgeeIntakeConstants

namespace CoralIntakeConstants {
const int intakeMotorCoralCANID = 40;
const int intakeLimitSwitchPort = 4;
const float IntakeSpeed = 0.2f;
const float OuttakeSpeed = 0.2f;
const int coralDetector = 99;
}  // namespace CoralIntakeConstants

namespace ElevatorConstants {
const int MotorElevatorCANID = 30;
const int ElevatorLimitSwID = 0;
const float HomeDownSlowSpeed = -0.1;
const float HomeDownFastSpeed = -0.5;
const float HomeUpSpeed = 0.1;
const double HomePositionBackOffValue = 7.3;
const float ElevatorUpSpeed = 0.2f;
const float ElevatorDownSpeed = -0.2f;
}  // namespace ElevatorConstants

/*
 * Limit switch ports
 * 0 - Elevator
 * 1 - One of two algae detectors
 * 2 - One of two algae detectors
 * 3 - Algae intake home switch
 * 4 - Coral intake
 */
