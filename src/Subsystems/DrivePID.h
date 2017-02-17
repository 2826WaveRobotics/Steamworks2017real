// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVEPID_H
#define DRIVEPID_H
#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "../AHRS.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DrivePID: public PIDSubsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<CANTalon> hopperLeft;
	std::shared_ptr<CANTalon> hopperRight;
	std::shared_ptr<CANTalon> intakeLeft;
	std::shared_ptr<CANTalon> intakeRight;
	std::shared_ptr<RobotDrive> robotDrive41;
	std::shared_ptr<CANTalon> hLeft;
	std::shared_ptr<CANTalon> hRight;
	//std::shared_ptr<Encoder> leftEncoder;
	//std::shared_ptr<Encoder> rightEncoder;
	//std::shared_ptr<Encoder> hEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<Solenoid> antiDriveTrain;
	std::shared_ptr<AHRS> gyro;

public:
	DrivePID();
	void InitDefaultCommand();
	void SetSidePower(double move, double roll, double turn, bool reverseDirection);
	void DeployFeet();
	void RetractFeet();
	double GetLeftEncoder();
	double GetRightEncoder();
	double GetHEncoder();
	double GetYaw();
	void SetDistance(double distance);
	void SetHeading(double heading);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	void DriveStraight(double power);
	void SetDirection(double heading);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void ResetEncoders();
	void SetPIDs(double kP, double kI, double kD);
	double GetDistanceTraveled();


};

#endif
