// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Blue_AutoCloseHopperShoot.h"
#include "Fire.h"
#include "SetShooterSpeed.h"
#include "WaveWait.h"
#include "AutoDrive.h"
#include "GearEject.h"
#include "Blue_AutoGearAngle.h"
#include "AutoRotate.h"
#include "ZeroYaw.h"
#include "ResetEncoders.h"
#include "AutoCrab.h"
#include "PlateOpen.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Blue_AutoCloseHopperShoot::Blue_AutoCloseHopperShoot() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:



	AddSequential(new ZeroYaw());
	AddSequential(new ResetEncoders());
	AddSequential(new AutoDrive(-30, 0, -1));
	AddParallel(new SetShooterSpeed(1000, .25));
	AddSequential(new ResetEncoders());
	AddSequential(new WaveWait(.5));
	AddSequential(new AutoRotate(0, -1, .5));
	AddSequential(new ZeroYaw());
	AddSequential(new AutoCrab(-10000000, 0, -1, 2.5));
	AddSequential(new AutoRotate(2, 1, .5));
	AddSequential(new SetShooterSpeed(982, .25));
	//AddParallel(new WaveWait(.25));
	AddParallel(new Fire(6));

    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
                      // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
 }
