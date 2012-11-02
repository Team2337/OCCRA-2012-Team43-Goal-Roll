#include "API.h" //EasyC API
#include "tumblr.h"

#define TUMBLR_ONE_PWM 7

void tumblrRoutine(char tumblrPositionUp, char tumblrPositionDown)
{
	if(tumblrPositionUp)
	{
		SetMotor(8, 95);
	else if (tumblrPositionDown)
	{
		SetMotor(8, -95);
	}
	else 
	{
         SetMotor(8,0);
         }
}
