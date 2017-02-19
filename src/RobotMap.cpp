// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "CANTalon.h"
#include "AHRS.h"

//solenoids
int gearEject = 0;
int gearAcquire = 1;
int antiDriveTrain = 2;
int redlightchannel = 3;
int bluelightchannel = 4;


//digital i/o
int fuelDetector = 6;
int climbDetectorForward = 5;
int climbDetectorBack = 8;

//encoder
int wheelSize = 3.25; //small wheel
double distancePerPulse = ((wheelSize * 3.14159) / 256);

#ifdef PracticeBot
int CANTalon_intakeIntakeLeft   = 6;
int CANTalon_intakeIntakeRight	 = 26;
int CANTalon_driveHopperRight    = 9;
int CANTalon_driveHopperLeft     = 25;
int CANTalon_driveIntakeRight    = 16;
int CANTalon_driveIntakeLeft     = 7;
int CANTalon_driveHRight         = 14;
int CANTalon_driveHLeft          = 5;
int CANTalon_climbLeftClimb      = 6;
int CANTalon_climbRightClimb     = 26;
int CANTalon_shooterShooterLeft  = 2;  //follower
int CANTalon_shooterShooterRight = 3; //leader
int CANTalon_shooterFeeder       = 15;

#endif


#ifdef CompBot
int CANTalon_intakeIntakeMotor = 5;
int CANTalon_driveHopperRight= 16;
int CANTalon_driveHopperLeft = 15;
int CANTalon_driveIntakeRight = 1;
int CANTalon_driveIntakeLeft = 14;
int CANTalon_driveHRight = 2;
int CANTalon_driveHLeft = 13;
int CANTalon_climbLeftClimb= 12;
int CANTalon_climbRightClimb = 9;
int CANTalon_shooterShooterLeft = 11;
int CANTalon_shooterShooterRight = 4;
int CANTalon_shooterFeeder = 10;
#endif


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::intakeIntakeLeft;
std::shared_ptr<CANTalon> RobotMap::intakeIntakeRight;
std::shared_ptr<DigitalInput> RobotMap::intakeFuelDetector;
std::shared_ptr<CANTalon> RobotMap::driveHopperLeft;
std::shared_ptr<CANTalon> RobotMap::driveHopperRight;
std::shared_ptr<CANTalon> RobotMap::driveIntakeLeft;
std::shared_ptr<CANTalon> RobotMap::driveIntakeRight;
std::shared_ptr<RobotDrive> RobotMap::driveRobotDrive41;
std::shared_ptr<CANTalon> RobotMap::driveHLeft;
std::shared_ptr<CANTalon> RobotMap::driveHRight;
std::shared_ptr<Encoder> RobotMap::driveLeftEncoder;
std::shared_ptr<Encoder> RobotMap::driveRightEncoder;
std::shared_ptr<Encoder> RobotMap::driveHEncoder;
std::shared_ptr<Solenoid> RobotMap::gearEjector;
std::shared_ptr<Solenoid> RobotMap::gearAcquisition;
std::shared_ptr<CANTalon> RobotMap::climbLeftClimb;
std::shared_ptr<CANTalon> RobotMap::climbRightClimb;
std::shared_ptr<Compressor> RobotMap::compressorSubsystemCompressor;
std::shared_ptr<CANTalon> RobotMap::shooterShooterRight;
std::shared_ptr<CANTalon> RobotMap::shooterShooterLeft;
std::shared_ptr<CANTalon> RobotMap::shooterFeeder;
std::shared_ptr<Encoder> RobotMap::shooterShooterEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

std::shared_ptr<DigitalInput> RobotMap::climbClimbDetectorForward;
std::shared_ptr<DigitalInput> RobotMap::climbClimbDetectorBack;
std::shared_ptr<Solenoid> RobotMap::driveAntiDriveTrain;
std::shared_ptr<Solenoid> RobotMap::lightsRedLight;
std::shared_ptr<Solenoid> RobotMap::lightsBlueLight;

//std::shared_ptr<AHRS> RobotMap::m_gyro;
AHRS* RobotMap::m_gyro;

int RobotMap::shooterRightCANId = CANTalon_shooterShooterRight;

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    intakeIntakeLeft.reset(new CANTalon(CANTalon_intakeIntakeLeft));
    lw->AddActuator("Intake", "IntakeLeft", intakeIntakeLeft);

    intakeIntakeRight.reset(new CANTalon(CANTalon_intakeIntakeRight));
    lw->AddActuator("Intake", "IntakeRight", intakeIntakeRight);
    
    intakeFuelDetector.reset(new DigitalInput(fuelDetector));
    lw->AddSensor("Intake", "FuelDetector", intakeFuelDetector);
    
    driveHopperLeft.reset(new CANTalon(CANTalon_driveHopperLeft));
    lw->AddActuator("Drive", "HopperLeft", driveHopperLeft);
    
    driveHopperRight.reset(new CANTalon(CANTalon_driveHopperRight));
    lw->AddActuator("Drive", "HopperRight", driveHopperRight);
    
    driveIntakeLeft.reset(new CANTalon(CANTalon_driveIntakeLeft));
    lw->AddActuator("Drive", "IntakeLeft", driveIntakeLeft);
    
    driveIntakeRight.reset(new CANTalon(CANTalon_driveIntakeRight));
    lw->AddActuator("Drive", "IntakeRight", driveIntakeRight);
    
    driveRobotDrive41.reset(new RobotDrive(driveIntakeLeft, driveHopperLeft,
              driveIntakeRight, driveHopperRight));
    
    driveRobotDrive41->SetSafetyEnabled(true);
        driveRobotDrive41->SetExpiration(0.1);
        driveRobotDrive41->SetSensitivity(0.5);
        driveRobotDrive41->SetMaxOutput(1.0);

    driveHLeft.reset(new CANTalon(CANTalon_driveHLeft));
    lw->AddActuator("Drive", "HLeft", driveHLeft);
    
    driveHRight.reset(new CANTalon(CANTalon_driveHRight));
    lw->AddActuator("Drive", "HRight", driveHRight);
    
    driveLeftEncoder.reset(new Encoder(4, 5, false, Encoder::k4X));
    lw->AddSensor("Drive", "LeftEncoder", driveLeftEncoder);
    driveLeftEncoder->SetDistancePerPulse(distancePerPulse);
    driveLeftEncoder->SetPIDSourceType(PIDSourceType::kRate);
    driveRightEncoder.reset(new Encoder(6, 7, false, Encoder::k4X));
    lw->AddSensor("Drive", "RightEncoder", driveRightEncoder);
    driveRightEncoder->SetDistancePerPulse(distancePerPulse);
    driveRightEncoder->SetPIDSourceType(PIDSourceType::kRate);
    driveHEncoder.reset(new Encoder(8, 9, false, Encoder::k4X));
    lw->AddSensor("Drive", "HEncoder", driveHEncoder);
    driveHEncoder->SetDistancePerPulse(distancePerPulse);
    driveHEncoder->SetPIDSourceType(PIDSourceType::kRate);

    gearEjector.reset(new Solenoid(0, gearEject));
    lw->AddActuator("Gear", "Ejector", gearEjector);
    
    gearAcquisition.reset(new Solenoid(0, gearAcquire));
    lw->AddActuator("Gear", "Acquisition", gearAcquisition);
    
    climbLeftClimb.reset(new CANTalon(CANTalon_climbLeftClimb));
    lw->AddActuator("Climb", "LeftClimb", climbLeftClimb);
    
    climbRightClimb.reset(new CANTalon(CANTalon_climbRightClimb));
    lw->AddActuator("Climb", "RightClimb", climbRightClimb);
    
    compressorSubsystemCompressor.reset(new Compressor(0));
    
    
    shooterShooterRight.reset(new CANTalon(CANTalon_shooterShooterRight));
    lw->AddActuator("Shooter", "ShooterRight", shooterShooterRight);

    shooterShooterLeft.reset(new CANTalon(CANTalon_shooterShooterLeft));
    lw->AddActuator("Shooter", "ShooterLeft", shooterShooterLeft);

    
    shooterFeeder.reset(new CANTalon(CANTalon_shooterFeeder));
    lw->AddActuator("Shooter", "Feeder", shooterFeeder);
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    climbClimbDetectorForward.reset(new DigitalInput(climbDetectorForward));
       lw->AddSensor("Climb", "ClimbDetectorFront", climbClimbDetectorForward);

     climbClimbDetectorBack.reset(new DigitalInput(climbDetectorBack));
              lw->AddSensor("Climb", "ClimbDetectorBack", climbClimbDetectorBack);

    driveAntiDriveTrain.reset(new Solenoid(0, antiDriveTrain));
    lw->AddActuator("Drive", "AntiDriveTrain", driveAntiDriveTrain);

    shooterShooterEncoder.reset(new Encoder(10, 11, false, Encoder::k4X));
    lw->AddSensor("Shooter", "ShooterEncoder", shooterShooterEncoder);

    lightsRedLight.reset(new Solenoid(0, redlightchannel));
    lightsBlueLight.reset(new Solenoid(0, bluelightchannel));

    try {
    	//m_gyro.reset(new AHRS((SPI::Port::kMXP)));
    	m_gyro = new AHRS(SPI::Port::kMXP);
    	//m_gyro.reset(new AHRS((SerialPort::Port::kMXP)));
    } catch (std::exception& ex ) {
                std::string err_string = "Error instantiating navX MXP:  ";
                err_string += ex.what();
                DriverStation::ReportError(err_string.c_str());
            }
}
