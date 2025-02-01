// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/SparkRelativeEncoder.h>
#include <rev/SparkClosedLoopController.h>

class Elevator : public frc2::SubsystemBase {
 public:
  Elevator();

  void Stop(void);

  bool GetLowerLimitSwitch(void);
  bool GetUpperLimitSwitch(void);
  double GetPosition(void);
  void SetPosition(double position);
  void SetPower(double power);





  void Periodic() override;

 private:
 bool m_lowerLimitSwitch;
 bool m_upperLimitSwitch;
 rev::spark::SparkMax m_motor{33,rev::spark::SparkMax::MotorType::kBrushless};
 rev::spark::SparkRelativeEncoder m_motorEncoder = m_motor.GetEncoder();
 rev::spark::SparkClosedLoopController m_motorPID = m_motor.GetClosedLoopController();
 double m_goalPosition;



  
};
