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
        .OpenLoopRampRate(0.3);
//      .ClosedLoopRampRate(0.3);

 motorConfig.encoder
        .PositionConversionFactor(1.0)        //Stick with Rotations as a position
        .VelocityConversionFactor(1.0);       //Stick with RPM as a velocity

  motorConfig.closedLoop
            .SetFeedbackSensor(rev::spark::ClosedLoopConfig::FeedbackSensor::kPrimaryEncoder)
            .Pid(0.05, 0, 0)
            .OutputRange(-.09, 0.1);

  motorConfig.closedLoop.maxMotion
            .MaxVelocity( 1000.0 )
            .MaxAcceleration ( 1500.0 )
            .AllowedClosedLoopError( 0.1 );


 m_motor.Configure( motorConfig,
                    rev::spark::SparkMax::ResetMode::kResetSafeParameters,
                    rev::spark::SparkMax::PersistMode::kPersistParameters);




}

// This method will be called once per scheduler run
void Elevator::Periodic() 
{

  //Elevator Debugging
  frc::SmartDashboard::PutNumber("ElevatorPosition", GetPosition() );
  frc::SmartDashboard::PutBoolean("ElevatorUpperSw", GetUpperLimitSwitch() );
  frc::SmartDashboard::PutBoolean("ElevatorLowerSw", GetLowerLimitSwitch() );

  frc::SmartDashboard::PutNumber("ElevatorVelocity", m_motorEncoder.GetVelocity() );



    //  m_goalPosition = frc::SmartDashboard::GetNumber("SetPosition", 0);
    // double currentPosition = GetPosition();
    // double error = m_goalPosition - currentPosition;

    // if( error > 1.0 )
    // {
    //     SetPower(0.1);
    // }
    // else if( error < -1.0 )
    // {
    //     SetPower(-0.1);
    // }
    // else 
    // {
    //     Stop();
    // }





}



  void Elevator::Stop(void)
  {
    m_motor.Set(0.0);
  }
  
  bool Elevator::GetLowerLimitSwitch(void)
  {
    return m_motor.GetReverseLimitSwitch().Get();
  }
  bool Elevator::GetUpperLimitSwitch(void)
  {
    return m_motor.GetForwardLimitSwitch().Get();
  }

  double Elevator::GetPosition(void)
  {
    return m_motorEncoder.GetPosition();
  }
  void Elevator::SetPosition(double position)
  {
    //m_motorPID.SetReference( position, rev::spark::SparkMax::ControlType::kPosition );  //Default PID

    m_motorPID.SetReference( position, rev::spark::SparkMax::ControlType::kMAXMotionPositionControl );  //MaxMotion

    //m_motorPID.SetReference( position, rev::spark::SparkMax::ControlType::kPosition, rev::spark::kSlot0, 0.01 );  //Arbitrary feed forward

  }
  void Elevator::SetPower(double power)
  {
    //std::cout<<"SetPower"<<std::endl;
    m_motor.Set(power);
  }

 void   Elevator::ZeroEncoder(void)
 {
    m_motorEncoder.SetPosition(0.0);
 }




