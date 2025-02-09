// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>

#include "commands/CmdPrintText.h"
#include "commands/CmdElevatorSetPosition.h"
#include "commands/CmdElevatorDefault.h"
#include "commands/CmdWhileTrueTest.h"

RobotContainer::RobotContainer() 
{

  //******************** Subsystem Defaults ******************************
  m_elevator.SetDefaultCommand( CmdElevatorDefault() );
  

  //******************** Dashboard Buttons *******************************


  //*************************************Auto**********************************************

  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{

  //Controller Buttons
  m_ctrl.A().OnTrue(new CmdPrintText("A Button"));
  m_ctrl.B().OnTrue(new CmdPrintText("B Button"));
  m_ctrl.X().OnTrue(new CmdPrintText("X Button"));
  m_ctrl.Y().OnTrue(new CmdPrintText("Y Button"));

  m_ctrl.RightBumper().OnTrue( new CmdPrintText("R Bumper") );
  m_ctrl.LeftBumper().OnTrue( new CmdPrintText("L Bumper") );

  m_ctrl.Start().OnTrue( new CmdPrintText("Start") );

  m_ctrl.RightTrigger().WhileTrue( new CmdWhileTrueTest("R Trigger") );
  m_ctrl.LeftTrigger().WhileTrue(  new CmdWhileTrueTest("L Trigger") );


  // DPAD
  m_ctrl.POVUp().OnTrue(    new CmdElevatorSetPosition(10.0) );
  m_ctrl.POVLeft().OnTrue(  new CmdElevatorSetPosition( 7.0) );
  m_ctrl.POVRight().OnTrue( new CmdElevatorSetPosition( 5.0) );
  m_ctrl.POVDown().OnTrue(  new CmdElevatorSetPosition( 0.0) );


}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
