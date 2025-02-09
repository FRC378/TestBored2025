// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include "subsystems/Elevator.h"


// #include <frc/XboxController.h>
// #include <frc2/command/button/JoystickButton.h>
//#include <frc2/command/button/POVButton.h>

#include <frc2/command/button/CommandXboxController.h>



class RobotContainer {
 public:
  RobotContainer();
 
  //****************Controllers*******************
//frc2::CommandXboxController m_driver {0};
  frc2::CommandXboxController m_ctrl   {1};

  //****************Subsystems*******************
  Elevator m_elevator;


  frc2::CommandPtr GetAutonomousCommand();

 private:


  void ConfigureBindings();
};
