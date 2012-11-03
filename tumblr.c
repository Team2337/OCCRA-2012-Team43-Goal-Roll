#include "API.h" //EasyC API
#include "tumblr.h"

#define TUMBLR_ONE_PWM 7

void tumblrRoutine(char tumblrPositionUp, char tumblrPositionDown)
{
	if(tumblrPositionUp)
	{
		SetMotor(5, 127);
	}
	else if (tumblrPositionDown)
	{
		SetMotor(5, -127);
	}
	else 
	{
         SetMotor(5,0);
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
		SetMotor(5, tumblrPosition)
	}
	else if 
	{
		SetMotor(5, 0);
	}
}