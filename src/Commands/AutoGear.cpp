// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutoGear.h"
#include "SetShooterSpeed.h"
#include "Fire.h"
#include "WaveWait.h"
#include "GearEject.h"
#include "AutoDrive.h"
#include "ZeroYaw.h"
#include "ResetEncoders.h"
#include "GearUneject.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoGear::AutoGear() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	//AddSequential(new AutoDrive());
	//AddParallel(new SetShooterSpeed(1000));
	//AddSequential(new Fire());
	//AddParallel(new WaveWait(3));
	//AddSequential(new AutoDrive());
	AddSequential(new ZeroYaw());
	AddSequential(new ResetEncoders());
	//AddSequential(new GearEject());
	//AddSequential(new AutoDrive(-20, 0, -.5));
	//AddSequential(new GearUneject());
	AddSequential(new AutoDrive(46, 0, .7));
	//AddSequential(new AutoDrive(-20, 0, -.5));
	//AddSequential(new AutoDrive(54, 0, .7));
	AddSequential(new WaveWait(.5));
	AddSequential(new GearEject());
	AddSequential(new WaveWait(.5));
//	AddSequential(new GearUneject());
	AddSequential(new ZeroYaw());
	AddSequential(new ResetEncoders());
	//AddSequential(new AutoDrive(54, 0, .7));
	AddSequential(new AutoDrive(-7.5, 0, -.7));
	AddSequential(new GearUneject());
	AddSequential(new WaveWait(.5));



     // Add Commands here:
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
