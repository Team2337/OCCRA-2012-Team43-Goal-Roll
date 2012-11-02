#include "API.h" //EasyC API        
#include "cheesydrive.h"
#include "math.h"

//*** OCCRA 43 - the Holly Knights - CheesyDrive (inspired by FRC254, built upon OCCRA/VRC 33's 2011 code)
//One axis controls turning; the other, forward and backward.

void cheesyDrive(signed int throttle, signed int wheel, unsigned char turnQuick, unsigned char turnSpeed)
{   
    //Do the magic Cheesy Drive
    int diff;
    int pwmLeft = 0;
    int pwmRight = 0;
    
    int absThrottle = 0;
    absThrottle = abs(throttle);
    int absWheel = 0;
    absWheel = abs(wheel);
    
    unsigned char quickTurn = (absThrottle<0.4);
    
    //Deadbands for each joystick
    if(absThrottle <.2)
    {
       throttle = 0;
    }
    
    if(absWheel <.2)
    {
       wheel = 0;
    }
    
    if(quickTurn)
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
        //Diff = wheel * throttle * sens
        diff = wheel * throttle * turnSpeed;
        //Add and subtract Diff from each to get pwm
        pwmLeft = limitMotor((throttle + diff));
        pwmRight = limitMotor((throttle - diff));
    }
    
    int inputVectorLength = sqrt(pow(throttle,2)+pow(wheel,2));
    
    float fudgeFactor = pow(sin(asin(throttle/(inputVectorLength))),3);
    
    SetMotor(6,pwmLeft);
    SetMotor(7,pwmLeft);
    SetMotor(8,pwmRight);
    SetMotor(9,pwmRight);

    }   
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
    if (x>127)
    {
      x=127;
    }
    else if (x<-127)
    {
      x=-127;
    }
    return x;
}
