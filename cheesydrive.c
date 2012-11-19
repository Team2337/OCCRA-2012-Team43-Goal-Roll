#include "API.h" //EasyC API
#include "cheesydrive.h"
//****** Thanks to OCCRA 33, retrofitted for OCCRA 43

//Tuning parameters were set as RobotC variables, then passed on. Initially, it believed this would lead to better tuning.
//Final values: turnQuick = 1.5, turnSpeed = 1.0

void cheesyDrive(signed int throttle, signed int wheel, unsigned char turnQuick, unsigned char turnSpeed)
{

    //PrintToScreen("%d\n",throttle); 
    //PrintToScreen("%d\n",wheel); 
    //Do the magic Cheesy Drive
    signed int diff;
    signed int pwmLeft = 0;
    signed int pwmRight = 0;
    
	unsigned int absThrottle = abs(throttle);
    unsigned int absWheel = abs(wheel);
	
    float fthrottle = (float)absThrottle;
    fthrottle /= 127;
    
    float fwheel = (float)absWheel;
    fwheel /= 127;
	
	//Simple custom ramping algorithm
    throttle = (fthrottle)*throttle;
    wheel = (fwheel)*wheel;

    if(absThrottle<50)
    {
        //Add throttle to diff.
        //Wheel is diff
        diff = wheel * turnQuick;

        //Do diff
        pwmLeft = limitMotor((throttle + diff));
        pwmRight = limitMotor((throttle - diff));
    }//End QuickTurn
    else //If SpeedTurn
    {
        //Pull it to a decimal number, -1 to 1
        //Diff = wheel * fthrottle * sens
        diff = (int)wheel * (float)fthrottle * turnSpeed;
        //Add and subtract Diff from each to get pwm
        pwmLeft = limitMotor((throttle + diff));
        pwmRight = limitMotor((throttle - diff));
    }//End SpeedTurn
	
	//The left side of the drivetrain had a Y PWM cable, the right side did not.
	
    SetMotor(2,pwmLeft);
    SetMotor(3,pwmRight);
    SetMotor(4,-pwmRight);

}//End DoCheesyDrive

int abs(int x)
{
    if (x<0)
    {
       x = (-x);
    }
    
     return x;
}

int limitMotor(int x)
{
    if(x>127)
    {
        x=127;
    }
    else if (x<-127)
    {
        x=-127;
    }

    return x;
}
