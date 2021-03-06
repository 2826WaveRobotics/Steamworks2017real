// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"
#include "CANTalon.h"
#include "AHRS.h"

//#define PracticeBot
#define CompBot

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */



class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<CANTalon> intakeIntakeLeft;
	static std::shared_ptr<CANTalon> intakeIntakeRight;
	static std::shared_ptr<DigitalInput> intakeFuelDetector;
	static std::shared_ptr<CANTalon> driveHopperLeft;
	static std::shared_ptr<CANTalon> driveHopperRight;
	static std::shared_ptr<CANTalon> driveIntakeLeft;
	static std::shared_ptr<CANTalon> driveIntakeRight;
	static std::shared_ptr<RobotDrive> driveRobotDrive41;
	static std::shared_ptr<CANTalon> driveHLeft;
	static std::shared_ptr<CANTalon> driveHRight;
	static std::shared_ptr<Encoder> driveLeftEncoder;
	static std::shared_ptr<Encoder> driveRightEncoder;
	static std::shared_ptr<Encoder> driveHEncoder;
	static std::shared_ptr<Solenoid> gearEjector;
	static std::shared_ptr<Solenoid> gearAcquisition;
	static std::shared_ptr<CANTalon> climbLeftClimb;
	static std::shared_ptr<CANTalon> climbRightClimb;
	static std::shared_ptr<Compressor> compressorSubsystemCompressor;
	static std::shared_ptr<CANTalon> shooterShooterRight;
	static std::shared_ptr<CANTalon> shooterShooterLeft;
	static std::shared_ptr<CANTalon> shooterFeeder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static std::shared_ptr<DigitalInput> climbClimbDetectorForward;
	static std::shared_ptr<DigitalInput> climbClimbDetectorBack;
	static std::shared_ptr<Solenoid> climbClimbRelease;
	static std::shared_ptr<Solenoid> driveAntiDriveTrain;
	static std::shared_ptr<Encoder> shooterShooterEncoder;

//	static std::shared_ptr<AHRS> m_gyro;
	//static AHRS *m_gyro;
	static std::shared_ptr<Solenoid> lightsRedLight;
	static std::shared_ptr<Solenoid> lightsBlueLight;

	static void init();

	static int shooterRightCANId;
};
#endif
