//Header file for kbmath.c

signed char limit_motor(signed int input);
void limit_pointer(signed int *input);
void print_signed_to_gd(unsigned char row,unsigned char col,unsigned long ulColor,signed int val);
void print_signed_char_to_gd(unsigned char row, unsigned char col,unsigned long ulColor,signed char val);
void print_signed_color_to_gd(unsigned char row, unsigned char col, unsigned long colorNeg,unsigned long colorPos,unsigned long colorZero,signed int val);
void print_bool_as_yesno_to_gd(unsigned char row, unsigned char col, unsigned char val);
void print_bool_as_truefalse_to_gd(unsigned char row,unsigned char col,unsigned char val);


