// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Elevator.h"
#include <rev/config/SparkMaxConfig.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>


Elevator::Elevator()
{
 std::cout <<"Elevator"<<std::endl;
 //SparkMaxConfigurator
 rev::spark::SparkMaxConfig motorConfig;
 
 motorConfig
        .SetIdleMode(rev::spark::SparkBaseConfig::IdleMode::kBrake)
        .SmartCurrentLimit(50)
        .Inverted(false)
        .ClosedLoopRampRate(0.3);

 motorConfig.encoder
        .PositionConversionFactor(1.0)
        .VelocityConversionFactor(1.0);

 m_motor.Configure( motorConfig,
                    rev::spark::SparkMax::ResetMode::kResetSafeParameters,
                    rev::spark::SparkMax::PersistMode::kPersistParameters);
    frc::SmartDashboard::PutNumber("SetPosition", 0);




}

// This method will be called once per scheduler run
void Elevator::Periodic() 
{
    frc::SmartDashboard::PutNumber("ElevatorPosition", GetPosition() );

     m_goalPosition = frc::SmartDashboard::GetNumber("SetPosition", 0);
    double currentPosition = GetPosition();
    double error = m_goalPosition - currentPosition;

    if( error > 1.0 )
    {
        SetPower(0.1);
    }
    else if( error < -1.0 )
    {
        SetPower(-0.1);
    }
    else 
    {
        Stop();
    }


}



  void Elevator::Stop(void)
  {
    m_motor.Set(0.0);
  }
  
  bool Elevator::GetLowerLimitSwitch(void)
  {
   
  }
  bool Elevator::GetUpperLimitSwitch(void)
  {

  }
  double Elevator::GetPosition(void)
  {
    return m_motorEncoder.GetPosition();
  }
  void Elevator::SetPosition(double position)
  {

  }
  void Elevator::SetPower(double power)
  {
    //std::cout<<"SetPower"<<std::endl;
    m_motor.Set(power);
  }






