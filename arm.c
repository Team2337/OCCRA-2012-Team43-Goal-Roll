#include "API.h" //EasyC API
#include "arm.h"


void armRoutine(int armPower, char intake, char outtake)
{
	int absArmPower = abs(armPower);
	float farmpower = (float)armPower;
	farmpower /= 127;
	
	armPower = (farmpower)*(farmpower)*(armPower)/(absArmPower);
	
     SetMotor(4, armPower);
     if(outtake)
     {
        SetMotor(5, -63);
        SetMotor(6, -63);
        SetMotor(7, -97);
        
     }
     else if (intake)
     {
         SetMotor(5, 63);
         SetMotor(6, 63);
         SetMotor(7, 97);
     }
	 else
	 {
		 SetMotor(5, 0);
   	     SetMotor(6, 0);
   	     SetMotor(7, 0);
	}
}

int abs(int x)
{
    if (x<0)
    {
       x = (-x);
    }
    
     return x;
}
