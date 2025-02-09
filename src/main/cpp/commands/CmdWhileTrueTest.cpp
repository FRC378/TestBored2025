// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdWhileTrueTest.h"
#include "Robot.h"

CmdWhileTrueTest::CmdWhileTrueTest(std::string text) 
{
  m_text = text;
}


void CmdWhileTrueTest::Initialize() 
{
  std::cout << "WhileTrue test START: " << m_text << std::endl;
}

void CmdWhileTrueTest::Execute() {}


void CmdWhileTrueTest::End(bool interrupted) 
{
  std::cout << "WhileTrue test END: " << m_text << "  " << interrupted << std::endl;
}

bool CmdWhileTrueTest::IsFinished() 
{
  return false; //While TRUE test - always FALSE
}
