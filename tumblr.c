#include "API.h" //EasyC API
#include "tumblr.h"

#define TUMBLR_ONE_PWM 7

void tumblrRoutine(char tumblrPositionUp, char tumblrPositionDown)
{
	if(tumblrPositionUp)
	{
		SetMotor(7, 127);
	}
	else if (tumblrPositionDown)
	{
		SetMotor(7, -127);
	}
	else 
	{
         SetMotor(7,0);
    }
}

void tumblrRoutineJoystick(int tumblrPosition)
{
	int absTumblrPosition = abs(tumblrPosition);
	float ftumblrPosition = (float)absTumblrPosition;
	ftumblrPosition /= 127;

	tumblrPosition = ftumblrPosition*tumblrPosition;

	if(tumblrPosition > 30)
	{
		SetMotor(7, tumblrPosition)
	}
	else 
	{
		SetMotor(7, 0);
	}
}