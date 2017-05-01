// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include <math.h>
#include "Commands/AutoCrab.h"
#include "Commands/AutoDoNothing.h"
#include "Commands/AutoDrive.h"
#include "Commands/AutoGear.h"
#include "Commands/AutoGear5Pt.h"
#include "Commands/AutoRotate.h"
#include "Commands/Blue_AutoCloseHopperShoot.h"
#include "Commands/Blue_AutoFarHopperShoot.h"
#include "Commands/Blue_AutoGearAngle.h"
#include "Commands/Blue_AutoGearAngleShoot.h"
#include "Commands/Blue_AutoGearShoot.h"
#include "Commands/Blue_AutoShootGearShoot.h" //unfinished
#include "Commands/Red_AutoCloseHopperShoot.h"
#include "Commands/Red_AutoFarHopperShoot.h"
#include "Commands/Red_AutoGearAngle.h"
#include "Commands/Red_AutoGearAngleShoot.h"
#include "Commands/Red_AutoGearShoot.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Intake> Robot::intake;
//std::shared_ptr<Drive> Robot::drive;
std::shared_ptr<Gear> Robot::gear;
std::shared_ptr<Climb> Robot::climb;
std::shared_ptr<CompressorSubsystem> Robot::compressorSubsystem;
std::shared_ptr<Shooter> Robot::shooter;
std::unique_ptr<OI> Robot::oi;

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DrivePID> Robot::drivePID;
//std::shared_ptr<ShooterPID> Robot::shooterPID;
//std::shared_ptr<AHRS>Robot::m_gyro;

void Robot::RobotInit() {
	RobotMap::init();


	if (NULL == m_gyro){
		std::cout << "-------------------------- NULL" << std::cout;
	}


	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	std::cout << "------ 1 " << std::endl;
	intake.reset(new Intake());
	std::cout << "------ 2 " << std::endl;
	//    drive.reset(new Drive());
	gear.reset(new Gear());
	std::cout << "------ 3 " << std::endl;
	climb.reset(new Climb());
	std::cout << "------ 4 " << std::endl;
	compressorSubsystem.reset(new CompressorSubsystem());
	std::cout << "------ 5 " << std::endl;
	shooter.reset(new Shooter());
	std::cout << "------ 6 " << std::endl;

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());
	std::cout << "------ 7 " << std::endl;
	drivePID.reset(new DrivePID());
	std::cout << "------ 8 " << std::endl;
	//shooterPID.reset(new ShooterPID());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	m_gyro = new AHRS(SPI::Port::kMXP, 100);
	//	autonomousCommand.reset(new Blue_AutoCloseHopperShoot());

	//	m_gyro = new AHRS(SPI::kMXP);

	std::cout << "------ 9 " << std::endl;
	drivePID->SetGyroPointer(m_gyro);
	m_gyro->ZeroYaw();

	//	if (NULL == m_gyro){
	//				std::cout << "-------------------------- NULL" << std::cout;
	//			}

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	//m_gyro = RobotMap::m_gyro;
	std::cout << "------ 10 " << std::endl;

	//autonomousCommand.reset(new Blue_AutoShootGearShoot());
	//m_gyro.reset(new AHRS((SPI::Port::kMXP)));
	//RobotMap::m_gyro = new AHRS(SPI::Port::kMXP);// Alternatives:  SPI::kMXP, I2C::kMXP or SerialPort::kUSB

	SmartDashboard::init();

	//	m_alliance->AddDefault("Default to Red", new /*command*/);
	//	m_alliance->AddObject("Red Alliance", new /*command*/);
	//	m_alliance->AddObject("Blue Alliance", new /*command*/);
	//	SmartDashboard::PutData("Alliance Colors!", m_alliance);




	//m_autoMode = new SendableChooser();
	m_autoMode = new SendableChooser<Command*>;

	m_autoMode->AddDefault("Default to Do Nothing", new AutoDoNothing());
	m_autoMode->AddObject("Auto Rotate TEST", new AutoRotate(-90, -1, 3));
	m_autoMode->AddObject("Drive Straight", new AutoDrive(100, 0, .6));
	m_autoMode->AddObject(" Crab Drive", new AutoCrab(300, 0, 1, 20000000));
	m_autoMode->AddObject("Center Gear", new AutoGear());
	m_autoMode->AddObject("Center Gear + Drive", new AutoGear5Pt());
	m_autoMode->AddObject("Blue Left Angle Gear", new Blue_AutoGearAngle());
	m_autoMode->AddObject("Blue Right Angle Gear", new Red_AutoGearAngle());
	m_autoMode->AddObject("Blue Close Hopper Shoot", new Blue_AutoCloseHopperShoot());
	m_autoMode->AddObject("Blue Far Hopper Shoot", new Blue_AutoFarHopperShoot());
	m_autoMode->AddObject("Blue Gear Angle Shoot", new Blue_AutoGearAngleShoot());
	m_autoMode->AddObject("Blue Gear Center Shoot", new Blue_AutoGearShoot());
	//m_autoMode->AddObject("Blue Shoot Gear Shoot", new Blue_AutoShootGearShoot());
	m_autoMode->AddObject("Red Left Angle Gear", new Blue_AutoGearAngle());
	m_autoMode->AddObject("Red Right Angle Gear", new Red_AutoGearAngle());
	m_autoMode->AddObject("Red Close Hopper Shoot", new Red_AutoCloseHopperShoot());
	m_autoMode->AddObject("Red Far Hopper Shoot", new Red_AutoFarHopperShoot());
	m_autoMode->AddObject("Red Gear Angle Shoot", new Red_AutoGearAngleShoot());
	m_autoMode->AddObject("Red Gear Center Shoot", new Red_AutoGearShoot());
	SmartDashboard::PutData("Auto Modes", m_autoMode);

}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	compressorSubsystem->StopCompressor();
	intake->StopIntake();
	m_gyro->ZeroYaw();
	//drivePID->ResetEncoders();
}

void Robot::DisabledPeriodic() {

		std::cout << "Yaw: " << m_gyro->GetYaw() << std::endl;
	//			<< " Roll: " << m_gyro->GetRoll()<< " Is Connected? " << (m_gyro->IsConnected() ? "Yes" : "No")
	//			<< " Firmware: " << m_gyro->GetFirmwareVersion() << std::endl;

//	std::cout << " --------------------------- before get yaw" << std::endl;

	//::cout << "Yaw: " << drivePID->GetYaw() << std::endl;
	drivePID->GetHEncoder();
//	drivePID->GetLeftEncoder();
	drivePID->GetRightEncoder();
//	shooter->PrintShooterRPM();
	//std::cout << " ------------------ after get yaw ----------------" << std::endl;

	Scheduler::GetInstance()->Run();
	//	shooter->PrintShooterRPM();


	//drivePID->PrintPIDs();
	//	std::cout /*<< " Distance travelled: " << drivePID->GetDistanceTraveled() */<< "  H encoder: " << RobotMap::driveHEncoder->Get()
	//			<< " Left encoder: "<< RobotMap::driveLeftEncoder->Get() << " Right encoder: " <<RobotMap::driveRightEncoder->Get()
	//			<< " Talon H encoder: " << RobotMap::driveHLeft->GetEncPosition() << " Talon Left encoder: " << RobotMap::driveIntakeLeft->GetEncPosition()
	//			<< " Talon Right encoder: " << RobotMap::driveIntakeRight->GetEncPosition() << " Encoder velocity TEST: "
	//			<< RobotMap::driveIntakeRight->GetEncVel() << " " << RobotMap::driveIntakeLeft->GetEncVel() << " "
	//			<< RobotMap::driveHLeft->GetEncVel() << " Shooter Encoder: " << RobotMap::shooterShooterRight->GetEncVel() <<  " "
	//			<< RobotMap::shooterShooterRight->GetEncPosition() << std::endl ;
	//
	//	double pValue = oi.get()->getTuningJoystick1()->GetRawAxis(4);
	//	double iValue = oi.get()->getTuningJoystick1()->GetRawAxis(2);
	//	double dValue = oi.get()->getTuningJoystick1()->GetRawAxis(3);
	//
	//	if(pValue >= 0 || iValue >= 0 || dValue >= 0){
	//			shooter->SetPIDValues(pValue, iValue, dValue);
	//			std::cout << "P: " << pValue << "  I: " << iValue << "  D: " << dValue << " " /*<< std::endl*/ << " Actual P: " <<
	//							RobotMap::shooterShooterRight->GetP() << " Actual I: " << RobotMap::shooterShooterRight->GetI() << " Actual D: " <<
	//							RobotMap::shooterShooterRight->GetD();
	//			shooter->PrintShooterRPM();
	//			//shooter->UpdateSecondary();
	//		}

	//	std::cout << "Intake " << intake->IsFuelDetectorTripped() << std::endl;

	//		drivePID->GetLeftEncoder();
	//		drivePID->GetRightEncoder();
	//		drivePID->GetHEncoder();
	//shooter->PrintShooterRPM();
	//std::cout << " ------------------ after get instance ----------------" << std::endl;
	compressorSubsystem->StopCompressor();
	//std::cout << " ------------------ end of disabled periodic ----------------" << std::endl;
}

void Robot::AutonomousInit() {
	autonomousCommand.reset(m_autoMode->GetSelected());


	if (autonomousCommand.get() != nullptr){
		std::cout << "Autonomous Init ---------------------------------------" << std::endl;
		autonomousCommand->Start();
	}
	drivePID->ResetEncoders();
	compressorSubsystem->StartCompressor();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	//	if (autonomousCommand.get() != nullptr)
	//		autonomousCommand->Cancel();
	//

	compressorSubsystem->StartCompressor();
	//
	//	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
	//	camera.SetResolution(1280, 960);
	//CameraServer::GetInstance()->SetSize(CameraServer::kSize640x480);
	//	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
	//	const cs::VideoSource source = cs::VideoSource::kUsb;
	//	cs::UsbCamera camera = CameraServer::GetInstance()->AddCamera(source);
	//	camera.SetResolution(640, 480);
	//CameraServer::GetInstance()->StartAutomaticCapture();

	//delete m_gyro;

	m_incrementPressed = false;
	m_decrementPressed = false;
	m_stopPressed = false;
	m_rpmSet = 0;

	//drivePID->SetDirection(0);
}

void Robot::TeleopPeriodic() {
	//////////////////////////////////////////////////////////


	Scheduler::GetInstance()->Run();

	//Shooter
	if(oi->getOperatorJoystick()->GetRawAxis(2) > .15){ //x
				shooter->SetShooterSpeed(925); //CLOSE SHOT: 920, p = 8.5d = 2560
				shooter->UpdateSecondary();
				shooter->SetPIDValues(8.9, -2.625, 2560); //p = 8.9 i = -.001  d=2560

				//p = 8.9 i = -.002 d= 2560 rpm=925
				//p=8.9 i=-100000 d = 3000  rpm=910

//				shooter->SetShooterSpeed(1210); //FAR HOPPER: rpm 1257 p 4.75 d 75
//				shooter->UpdateSecondary();
//				shooter->SetPIDValues(8.5, 0.00000000000000000001 , 2560); //1257 p 4.75 d 2560

//		shooter->SetShooterSpeed(1012);
//		shooter->UpdateSecondary();
//		shooter->SetPIDValues(8.5, 0, 2560);
	}
	else if(oi->getOperatorJoystick()->GetRawAxis(3)){
		shooter->SetShooterSpeed(1012); //CLOSE SHOT: 80% = rpm 958 p 8.5 d 115
		shooter->UpdateSecondary();
		shooter->SetPIDValues(8.9, -0.0008, 2560);
	}
	else{
		shooter->DisablePID();
		shooter->SetShooterSpeed(0);
		shooter->UpdateSecondary();

	}

	//Shintake
	if(oi->getOperatorJoystick()->GetRawButton(1))
	{
		shooter->StartFeeder();
	}
	else if(oi->getOperatorJoystick()->GetRawAxis(5)>.25){
		RobotMap::shooterFeeder->Set(oi->getOperatorJoystick()->GetRawAxis(5));
	}
	else{
		shooter->StopFeeder();
	}

	//Intake
	if((oi->getDriverJoystick()->GetRawAxis(2) > 0.5) || (oi->getOperatorJoystick()->GetRawButton(6))){ //sets m_userOverride
		intake->SetUserOveride(true);
	}
	else if(oi->getDriverJoystick()->GetRawButton(1) || (oi->getOperatorJoystick()->GetRawAxis(1) > .25)){
		intake->SetReverse(true);
	}
	else if(oi->getDriverJoystick()->GetRawAxis(3)>.25 || oi->getOperatorJoystick()->GetRawButton(1)){
		intake->SetHighPower(true);
	}
	else
	{
		intake->SetUserOveride(false);
		intake->SetReverse(false);
		intake->SetHighPower(false);
	}
	intake->StartIntake();
	//std::cout << "Intake command: run" << std::endl;

	//Drive
	double move = oi->getDriverJoystick()->GetRawAxis(1);
	double 	turn = oi->getDriverJoystick()->GetRawAxis(4);
	double roll = oi->getDriverJoystick()->GetRawAxis(0);

	if(fabs(move) < .15){
		move = 0;
	}


	if(fabs(roll) < .15){
		roll = 0;
	}

	if(fabs(turn) < .15){
		turn = 0;
	}

	bool reverseDirection= oi->getDriverJoystick()->GetRawButton(6);
	drivePID->SetSidePower(move, turn, roll, reverseDirection);


	//pneumatic feet
	//	if(oi->getDriverJoystick()->GetRawAxis(3)){
	//		drivePID->DeployFeet();
	//	}
	//	else{
	//		drivePID->RetractFeet();
	//	}

	shooter->PrintShooterRPM();

	Wait(0.007); //seconds
	//std::cout << "End of Teleop periodic" << std::endl;
}

void Robot::TestPeriodic() {
	lw->Run();

	std::cout<<"ClimbDetectorForward : "<<RobotMap::climbClimbDetectorForward<<std::endl;

	std::cout<<"ClimbDetectorBack :"<<RobotMap::climbClimbDetectorBack<<std::endl;

	std::cout<<"FuelDetector :"<<RobotMap::intakeFuelDetector<<std::endl;
}


START_ROBOT_CLASS(Robot);


