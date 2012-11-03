#include "API.h" //EasyC API
#include "tumblr.h"

#define TUMBLR_ONE_PWM 7

void tumblrRoutine(char tumblrPositionUp, char tumblrPositionDown)
{
	if(tumblrPositionUp)
	{
		SetMotor(5, 127);
	else if (tumblrPositionDown)
	{
		SetMotor(5, -127);
	}
	else 
	{
         SetMotor(5,0);
         }
}
