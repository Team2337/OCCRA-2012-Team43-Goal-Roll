#include "API.h" //EasyC API
#include "arm.h"

//Arm is driven by a PG71, intake/outtake is a KoP wheel epoxied onto a window motor

void armRoutine(int armPower, char intake, char outtake)
{
	int absArmPower = abs(armPower);
	float farmpower = (float)absArmPower;
	farmpower /= 127;
	
	armPower = (farmpower)*armPower;
	
	if(absArmPower > 30)
	{
		SetMotor(5, armPower);
    }
	else
	{
		SetMotor(5, 0);
	}
	
	if(outtake)
    {
       SetMotor(6, 127);
        
    }
    else if (intake)
    {
        SetMotor(6, -127);
    }
	else
	{
		SetMotor(6, 0);
	}
}