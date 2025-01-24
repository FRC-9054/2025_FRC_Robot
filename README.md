# MAXSwerve C++ Template v2025.1

See [the online changelog](https://github.com/REVrobotics/MAXSwerve-Cpp-Template/blob/main/CHANGELOG.md) for information about updates to the template that may have been released since you created your project.

## Description

A template project for an FRC swerve drivetrain that uses REV MAXSwerve Modules.

Note that this is meant to be used with a drivetrain composed of four MAXSwerve Modules, each configured with two SPARKS MAX, a NEO as the driving motor, a NEO 550 as the turning motor, and a REV Through Bore Encoder as the absolute turning encoder.

To get started, make sure you have calibrated the zero offsets for the absolute encoders in the Hardware Client using the `Absolute Encoder` tab under the associated turning SPARK MAX devices.

## Prerequisites

* SPARK MAX Firmware v25.0.0
* REVLib v2025.0.0

## Configuration

It is possible that this project will not work for your robot right out of the box. Various things like the CAN IDs, PIDF gains, chassis configuration, etc. must be determined for your own robot!

These values can be adjusted in the `Configs.h` and `Constants.h` files.





*****************************
********* IMPORTANT *********
*****************************

EVEREY COMMIT NEEDS TO BUILD SUCCESSFULLY AND HAVE UPDATED VERSION HISTORY



           First number in the version number should only increase if the overall structure of
                    the code changes. The code should remain functionally the same. If the
                    first number changes, there should be no other changes to the code and the
                    version should be a single number (ie. V2  or V15       not V2.1)

           Second number in the version number should only change if a feature is added to the
                    code. Removal of a feature (so long as its not the last feature added)
                    should be treated like a change to the overall structure.

           Third number should change only for bug fixes and minor "cosmetic" changes. Use of
                    this number should be avoided by only commiting robot code that works
                    propperly.





*************************************************************************************************************************
***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>THE MORE DETAIL, THE MORE USEFUL THIS FILE WILL BE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***   ***
*************************************************************************************************************************


Picking a version number:
                         ONLY MAKE ONE CHANGE AT A TIME!!
EX. V2.7.3 (B)

1. The first number (2) in the example designates the current framework version. It will only be increased if we
fundamentally change the structure of our code (i.e. from command based to time based). If the framework was
changed, incriment the first didgit and change the following numbers to 0.

2. The second number (7) in the example represents an addition of a feature. If a new feature is added (like a
new subsystem or a new command), the first didgit remains the same, the second number is incrimented, and the
3rd number becomes 0. 

3. The third number represents an adjustment to a feature such as changing the speed of a motor. If a change to
a feature is made, the first 2 numbers stay the same, and the third number gets incrimented.

4. The letter (B) in the parrenthesis represents how the code was verrified. For the example, the code was
built, but not deployed. Refference the chart below for more details


#########################################################################
####                     Verrification Code Key:                     ####
#  #_____________________=======================_____________________#  #
####  B - Built           | The code was BUILT SUCCESSFULY, but was  ####
#  #                      |     not deployed to the robot.           #  #
####  D - Deployed        | The code was deployed to the robot       ####
#  #                      |      and the update recieved some        #  #
#  #                      |      sort of opperational testing to     #  #
#  #                      |      verrify its validity.               #  #
####  M - Mentor approved | A PROGRAMMING mentor has allowed the     ####
#  #                      |     change without additional            #  #
#  #                      |     verrification. note the mentor       #  #
#  #                      |     that approved the change in the      #  #
#  #                      |     'Comments About Change' section.     #  #
####  X - NOT VERIFIED    | This should be avoided, but should be    ####
#  #                      |     used if the code was commited mid    #  #
#  #                      |     change.                              #  #
####_________________________________________________________________####
#########################################################################





         !!!!!!!!!!UPDATE VERSION HISTORY BEFORE COMMIT!!!!!!!!!!
            !!!!!!!!!!UPDATE VERSION HISTORY BEFORE COMMIT!!!!!!!!!!
        !!!!!!!!!!UPDATE VERSION HISTORY BEFORE COMMIT!!!!!!!!!!

            Version     |  Developer   |   Comments About Changes
        ________________|__(Initials)__|_____________________________________________________________________________________________________
         V1.0.0 (B)     |  RAT         |   Initial commit. Started from the rev swerve example code and added an algee intake subsystem with
                        |              |       a couple of empty commands. More needs to be done to make this a functional subsystem.
         V1.0.1 (B)     |  DAH         |   added code to algae intake and outtake functions
         V1.1.0 (B)     |  DAH         |   added coral intake and outtake subsystem
         V1.2.0 (B)     |  DAH         |   added elevator system
         V1.2.1 (B)     |  DAH         |   Variables addedd to constants file for several subsystems
         V1.3.0 (B)     |  DAH         |   added code to elevator subsystem
         !!!!!!!!!!UPDATE VERSION HISTORY BEFORE COMMIT!!!!!!!!!!
    !!!!!!!!!!UPDATE VERSION HISTORY BEFORE COMMIT!!!!!!!!!!
                  !!!!!!!!!!UPDATE VERSION HISTORY BEFORE COMMIT!!!!!!!!!!

