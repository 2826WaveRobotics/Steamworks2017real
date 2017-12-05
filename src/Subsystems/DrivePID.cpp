// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "CANTalon.h"


#include "DrivePID.h"
#include "../RobotMap.h"
#include "../OI.h"
#include "../Robot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

namespace{
 const int c_CPR = 256; //512??
}

DrivePID::DrivePID() : PIDSubsystem("DrivePID", c_straightP, c_straightI, c_straightD) {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    hopperLeft = RobotMap::driveHopperLeft;
    hopperRight = RobotMap::driveHopperRight;
    intakeLeft = RobotMap::driveIntakeLeft;
    intakeRight = RobotMap::driveIntakeRight;
    robotDrive41 = RobotMap::driveRobotDrive41;
    hLeft = RobotMap::driveHLeft;
    hRight = RobotMap::driveHRight;
//    leftEncoder = RobotMap::driveLeftEncoder;
//    rightEncoder = RobotMap::driveRightEncoder;
//    hEncoder = RobotMap::driveHEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

//    intakeLeft->SetControlMode(frc::CANSpeedController::kPercentVbus);
//    intakeRight->SetControlMode(frc::CANSpeedController::kPercentVbus);
//    hLeft->SetControlMode(frc::CANSpeedController::kPercentVbus);
    intakeLeft->SetFeedbackDevice(CANTalon::QuadEncoder);
    intakeRight->SetFeedbackDevice(CANTalon::QuadEncoder);
    hLeft->SetFeedbackDevice(CANTalon::QuadEncoder);
    antiDriveTrain = RobotMap::driveAntiDriveTrain;
    gyro = NULL;

    //hopperLeft->SetEncPosition();
    intakeLeft->ConfigEncoderCodesPerRev(c_CPR);
    intakeLeft->ConfigPeakOutputVoltage(1.0, -1.0);
    intakeRight->ConfigEncoderCodesPerRev(c_CPR);
    intakeRight->ConfigPeakOutputVoltage(1.0, -1.0);
    hLeft->ConfigEncoderCodesPerRev(c_CPR);
    hLeft->ConfigPeakOutputVoltage(1.0, -1.0);
//
    intakeLeft->SetSafetyEnabled(false);
    intakeRight->SetSafetyEnabled(false);
    hopperLeft->SetSafetyEnabled(false);
    hopperRight->SetSafetyEnabled(false);
    hLeft->SetSafetyEnabled(false);
    hRight->SetSafetyEnabled(false);
    robotDrive41->SetSafetyEnabled(false);


}

void DrivePID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DrivePID::SetSidePower(double move, double turn, double roll, bool reverseDirection){ //no idea if this works
//	if(reverseDirection)
//	{
//		move = -1.0*(move);
//		turn = -1.0*(turn);
//		roll = 1.0*(roll);
//	}

	//std::cout<<"Direction: "<<reverseDirection<< ", Move: "<<move<< "roll: "<<roll<< "turn: "<<turn<< std::endl;

	robotDrive41->ArcadeDrive(move, turn);

	if(roll<0.2){
		hLeft->Set(roll);
		hRight->Set(roll);
	}
	else if(roll>.2){
		hLeft->Set(roll);
		hRight->Set(roll);
	}
	else{
		hLeft->Set(0);
		hRight->Set(0);
	}
//	std::cout << "End of Set Side Power " << std::endl;
}

void DrivePID::DriveStraight(double power, double heading) {

	SetDirection(heading); // make sure function actually does what we want it to do

	std::cout << "Drive: Moving straight with power: " << power << std::endl;
	double correction = GetPIDController()->Get(); //
//	double correction = Robot::drivePID->GetPIDOutput();

	robotDrive41->TankDrive((power-correction), (power+correction));
//	hLeft->Set(0);
//	hRight->Set(0);
	//SetSidePower(power, power+correction, 0, false); //no + correction in turn
	double degreesOff = GetSetpoint() - GetYaw();
//	std::cout << "Correction: " << correction << "\tLeft: " <<
//				(power - correction) << "\tRight: " << (power + correction) << "\tYaw: "
//			<< GetYaw() << "\tSetpoint: " << GetSetpoint() <<  "\tOff By: " << degreesOff << std::endl;

}

void DrivePID::ArcadeDrive(double move, double turn, double heading){
	//SetDirection(heading); // make sure function actually does what we want it to do
	//double correction = GetPIDController()->Get(); //
	robotDrive41->ArcadeDrive(move, turn);
}

void DrivePID :: SetHPower(double power){
	hLeft->Set(power);
	hRight->Set(power);
}

void DrivePID::SetOppArcadeDrive(double move, double turn, double heading)
{
	SetDirection(heading); // make sure function actually does what we want it to do
	double correction = GetPIDController()->Get(); //
	robotDrive41->ArcadeDrive(move, turn-correction);
}
void DrivePID::SetDirection(double heading)
{
	if(GetPIDController()->GetSetpoint() != heading)
	{
		GetPIDController()->Disable();
		GetPIDController()->Reset();
	//    gyro->ZeroYaw();
		GetPIDController()->SetSetpoint(heading); //we are now facing the same way the entire time
		GetPIDController()->Enable();
	}
}

double DrivePID::ReturnPIDInput() {

	return GetYaw();

	// Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
     //   return driveEncoderRight->PIDGet();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void DrivePID::UsePIDOutput(double output) {
	//std::cout << "DrivePID - UsePIDOutput = " << output << std::endl;

//	robotDrive41.get()->TankDrive(-output, output);
//	hLeft->Set(0);
//	hRight->Set(0);
}


void DrivePID::DeployFeet(){
	antiDriveTrain->Set(true);
}

void DrivePID::RetractFeet(){
	antiDriveTrain->Set(false);
}

double DrivePID::GetLeftEncoder()
{
	//17.1.1 - Encoder position read 4x the CPR. So one revolution with 12 CPR will read the position as (12 * 4) = 48
	double encoderCounts = (double)(intakeLeft->GetEncPosition()/4);

	//Circumference = d*pi, d = 3.25inches, pi = 3.1415
	//Distance = (counts/CPR) * circumference
	double distance = (encoderCounts / c_CPR) * (3.25 * 3.1415) ;
	std::cout << "LeftEncoder distance: " << distance << std::endl;
	return distance;
	//Could make this return a distance once wheel size is known. Depends on how we use this
}

double DrivePID::GetRightEncoder()
{
	double encoderCounts = (double)(intakeRight->GetEncPosition()/4);

	double distance = (encoderCounts / c_CPR) * (3.25 * 3.1415)*(-1);
	std::cout << "RightEncoder distance: " << distance << std::endl;
	return distance;
}

double DrivePID::GetHEncoder()
{
	double encoderCounts = (double)(hLeft->GetEncPosition()/4);

	double distance = (encoderCounts / c_CPR) * (3.25 * 3.1415);
	std::cout << "HEncoder distance: " << distance << std::endl;
	return distance;

}

double DrivePID::GetYaw() {
	if(NULL == gyro){
		std::cout << "gyro is null" << std::endl;
		return 0;
	}
	return gyro->GetYaw();
}

void DrivePID::ResetEncoders(){
	intakeRight->SetEncPosition(0);
	intakeLeft->SetEncPosition(0);
	hLeft->SetEncPosition(0);
}

void DrivePID::SetPIDs(double kP, double kI, double kD){
	GetPIDController()->SetPID(kP,kI, kD);
}

void DrivePID::PrintPIDs()
{
  std::cout << "Actual P: " << GetPIDController()->GetP() << " Actual I: " << GetPIDController()->GetI() << " Actual D: " <<
			 GetPIDController()->GetD();

}

double DrivePID::GetDistanceTraveled(){ // distance is in inches
	double xDist = GetHEncoder();
	double yDist = ((abs(GetRightEncoder())+(abs(GetLeftEncoder())))/2);
	double totalDist = sqrt((pow(xDist, 2)+(pow(yDist, 2))))*2;
	return totalDist;
}

void DrivePID::SetGyroPointer(AHRS *newGyro)
{
	gyro = newGyro;
}

void DrivePID::ZeroYaw()
{
	gyro->ZeroYaw();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

