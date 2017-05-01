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

#define CompBot

#ifdef PracticeBot

const double c_calibrationValue = 2;

const double c_straightP = .006;
const double c_straightI = 0.0;
const double c_straightD = 0.06;

const double c_turnP = .04;
const double c_turnI = 0;
const double c_turnD = .3;

const double c_crabP = .01; //15
const double c_crabI = 0.0;
const double c_crabD = 0; //5
#endif

#ifdef CompBot //for tuning

const double c_calibrationValue = 0;

const double c_straightP = 10;
const double c_straightI = 0.0;
const double c_straightD = 0.1;

const double c_turnP = 0.6;
const double c_turnI = 0;
const double c_turnD = 0;

const double c_crabP = .01; //15
const double c_crabI = 0.0;
const double c_crabD = 0; //5
#endif

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
//	std::shared_ptr<AHRS> gyro;
	AHRS *gyro;

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
	void DriveStraight(double power, double heading);
	void SetDirection(double heading);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void ResetEncoders();
	void SetPIDs(double kP, double kI, double kD);
	double GetDistanceTraveled();
	void SetHPower(double power);
	void SetOppArcadeDrive(double move, double turn, double heading);
	void ArcadeDrive(double move, double turn, double heading);

	void SetGyroPointer(AHRS *newGyro);

	void ZeroYaw();
	void PrintPIDs();
};

#endif
