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


#include "Intake.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Intake::Intake() : Subsystem("Intake") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    intakeLeft = RobotMap::intakeIntakeLeft;
    intakeRight = RobotMap::intakeIntakeRight;
    fuelDetector = RobotMap::intakeFuelDetector;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    intakeRight->SetInverted(true);
    m_userOveride = false;
    m_reverse = false;
}

void Intake::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Intake:: SetUserOveride(bool userInput){
	m_userOveride = userInput;
}

void Intake::SetReverse(bool reverse){
	m_reverse = reverse;
}
void Intake::SetHighPower(bool highPower){
	m_highPower = highPower;
}

bool Intake:: IsFuelDetectorTripped(){
	return (fuelDetector->Get()); //Return True if sensor value is 0
}
void Intake:: StartIntake(){
	//printouts
	if(m_userOveride)
	{
		//std::cout << " <<<<<<<<<<<<<<<<<<<<<<<  User override" << std::endl;
	}
	if(IsFuelDetectorTripped())
	{
		//std::cout << " <<<<<<<<<<<<<<<<<<<<<<<  Fuel Detector" << std::endl;
	}
	if(m_reverse){
		std::cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<< Reverse" << std::endl;
	}

	//sets motors
	if (m_userOveride){
		intakeRight->Set(-.6); //negative for comp bot
		intakeLeft->Set(-.6);
	}
	else if(m_reverse){
		intakeRight->Set(.6);
		intakeLeft->Set(.6);
	}
	else if(m_highPower){
		intakeRight->Set(-.9);
		intakeLeft->Set(-.9);
	}
//	else if(IsFuelDetectorTripped()){
//		intakeRight->Set(-.8);
//		intakeLeft->Set(.8);
//	}
	else{
        intakeRight->Set(0);
        intakeLeft->Set(0);
	}
}
void Intake:: StopIntake(){
	intakeRight->Set(0);
	intakeLeft->Set(0);
}

void Intake::RunIntakeWithSensor(){

	if(IsFuelDetectorTripped()){
		StartIntake();
	}
	else if(m_userOveride == true){
		StartIntake();
	}
	else{
		StopIntake();
	}
}

void Intake::ReverseIntake(){
	intakeRight->Set(.5);
	intakeLeft->Set(-.5);
}

void Intake::StartIntakeAuto(){
	intakeRight->Set(-.8);
	intakeLeft->Set(-.8);
}
