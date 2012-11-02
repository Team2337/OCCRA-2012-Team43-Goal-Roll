// kbmath.c : implementation file
#include "Main.h"
//*KB Math.c
//Useful functions for embedded platforms

//Includes
#include "kbmath.h"
#include "gdcolor.h"
#include "API.h"

//Limit to Signed Char (limit_motor
signed char limit_motor(signed int input)
{
if(input > 127)
{
return 127;
}
else if (input < -127)
{
return -127;
}
return input;
}
//Limit signed char passed via pointer
void limit_pointer(signed int *input)
{
if(*input > 127)
{
*input = 127;
}
else if (*input < -127)
{
*input = -127;
}
}//End limit_pointer

//Print Signed Number to GD and handle sign as a character which can be erased - We always use 4 significant digits for val
void print_signed_to_gd(unsigned char row,unsigned char col,unsigned long ulColor, signed int val)
{
if(val < 0)
{
PrintTextToGD(row,col,ulColor,"-%4d\n",Abs(val));
}
else
{
PrintTextToGD(row,col,ulColor," %4d\n",Abs(val));
}
}
//Print Signed char to GD - Same as above but with 3 significantg digits
void print_signed_char_to_gd(unsigned char row,unsigned char col,unsigned long ulColor,signed char val)
{
if(val < 0)
{
PrintTextToGD(row,col,ulColor,"-%3d\n",Abs(val));
}
else
{
PrintTextToGD(row,col,ulColor," %3d\n",Abs(val));
}
}

void print_signed_color_to_gd(unsigned char row, unsigned char col, unsigned long colorNeg,unsigned long colorPos,unsigned long colorZero,signed int val)
{
if(val < 0)
{
PrintTextToGD(row,col,colorNeg,"-%4d",val);
}
if(val > 0)
{
PrintTextToGD(row,col,colorPos," %4d",val);
}
if(val == 0)
{
PrintTextToGD(row,col,colorZero," %4d",val);
}
}

void print_bool_as_yesno_to_gd(unsigned char row, unsigned char col, unsigned char val)
{
if(val)
{
PrintTextToGD(row,col,GDtchicks,"YES");
}
else
{
PrintTextToGD(row,col,GDbloodred," NO");
}
}

void print_bool_as_truefalse_to_gd(unsigned char row,unsigned char col,unsigned char val)
{

if(val)
{
PrintTextToGD(row,col,GDtchicks," TRUE");
}
else
{
PrintTextToGD(row,col,GDbloodred,"FALSE");
}
//I don't know what it wants here
}

