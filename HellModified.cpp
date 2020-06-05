#define _CRT_SECURE_NO_DEPRECATE
#include "iGraphics.h"

#define swidth 1200
#define sheight 768

char *Day[7] = {"Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday"};
char *Month[12] = {"January", "February", "March", "April","May", "June", "July", "August","September", "October", "November", "December"};
int day, mon, week; char day_str[9];
bool hell = false;

int dx = 0, dy = 0;
int mouse_x = 0, mouse_y = 0;

int r = 255,g=0,b=0;
int blink = 0;
int sec = 0, min = 0, hr = 0;

int h1_l1 = 255, h1_l2 = 255, h1_l3 = 255, h1_l4 = 255, h1_l5 = 255, h1_l6 = 255, h1_l7 = 15;
int h2_l1 = 255, h2_l2 = 255, h2_l3 = 255, h2_l4 = 255, h2_l5 = 255, h2_l6 = 255, h2_l7 = 15;
int m1_l1 = 255, m1_l2 = 255, m1_l3 = 255, m1_l4 = 255, m1_l5 = 255, m1_l6 = 255, m1_l7 = 10;
int m2_l1 = 255, m2_l2 = 255, m2_l3 = 255, m2_l4 = 255, m2_l5 = 255, m2_l6 = 255, m2_l7 = 15;
int s1_l1 = 255, s1_l2 = 255, s1_l3 = 255, s1_l4 = 255, s1_l5 = 255, s1_l6 = 255, s1_l7 = 15;
int s2_l1 = 255, s2_l2 = 255, s2_l3 = 255, s2_l4 = 255, s2_l5 = 255, s2_l6 = 255, s2_l7 = 15;

void zero(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6, int *l7)
{
	*l7 = 15;
	*l1 = 255; *l2 = 255; *l3 = 255; *l4 = 255; *l5 = 255; *l6 = 255;
}
void one(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6, int *l7)
{
	*l7 = 15;
	*l1 = 15; *l2 = 15; *l3 = 15; *l4 = 255; *l5 = 255; *l6 = 15;
}
void two(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6, int *l7)
{
	*l7 = 255;
	*l1 = 255; *l2 = 15; *l3 = 255; *l4 = 255; *l5 = 15; *l6 = 255;
}
void three(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6, int *l7)
{
	*l7 = 255;
	*l1 = 15; *l2 = 15; *l3 = 255; *l4 = 255; *l5 = 255; *l6 = 255;
}
void four(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6, int *l7)
{
	*l7 = 255;
	*l1 = 15; *l2 = 255; *l3 = 15; *l4 = 255; *l5 = 255; *l6 = 15;
}
void five(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6, int *l7)
{
	*l7 = 255;
	*l1 = 15; *l2 = 255; *l3 = 255; *l4 = 15; *l5 = 255; *l6 = 255;
}
void six(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6, int *l7)
{
	*l7 = 255;
	*l1 = 255; *l2 = 255; *l3 = 255; *l4 = 15; *l5 = 255; *l6 = 255;
}
void seven(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6, int *l7)
{
	*l7 = 15;
	*l1 = 15; *l2 = 15; *l3 = 255; *l4 = 255; *l5 = 255; *l6 = 15;
}
void eight(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6, int *l7)
{
	*l7 = 255;
	*l1 = 255; *l2 = 255; *l3 = 255; *l4 = 255; *l5 = 255; *l6 = 255;
}
void nine(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6, int *l7)
{
	*l7 = 255;
	*l1 = 15; *l2 = 255; *l3 = 255; *l4 = 255; *l5 = 255; *l6 = 255;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
void iDraw()
{
	iClear();
	//************drawing hours************/
	iSetColor(r, g, b);
	iFilledRectangle(dx, dy, 30, 30);
	iText(dx + 50, dy + 8, "TRY ME", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(mouse_x, mouse_y, 5, 1000);
	iRectangle(dx+373, dy+370, 442, 156);
	//iRectangle(400+3, 400, 48, 96);
	int x = dx, y = dy;
	x += 403; y += 400;
	iSetColor(h2_l1, 0, 0);
	iLine(x, y + 2, x, y + 48 - 2); //line 1
	iSetColor(h2_l2, 0, 0);
	iLine(x, y + 48 + 2, x, y + 96 - 2); //line 2
	iSetColor(h2_l3, 0, 0);
	iLine(x + 2, y + 96, x + 48 - 2, y + 96); //line 3
	iSetColor(h2_l4, 0, 0);
	iLine(x + 48, y + 96 - 2, x + 48, y + 48 + 2); //line 4
	iSetColor(h2_l5, 0, 0);
	iLine(x + 48, y + 48 - 2, x + 48, y + 2); //line 5
	iSetColor(h2_l6, 0, 0);
	iLine(x + 48 - 2, y, x + 2, y); //line 6
	iSetColor(h2_l7, 0, 0);
	iLine(x + 2, y + 48, x + 48 - 2, y + 48); //line 7 or the midline

	//iRectangle(468-3, 400, 48, 96);
	x+=62;
	iSetColor(h1_l1, 0, 0);
	iLine(x, y + 2, x, y + 48 - 2); //line 1
	iSetColor(h1_l2, 0, 0);
	iLine(x, y + 48 + 2, x, y + 96 - 2); //line 2
	iSetColor(h1_l3, 0, 0);
	iLine(x + 2, y + 96, x + 48 - 2, y + 96); //line 3
	iSetColor(h1_l4, 0, 0);
	iLine(x + 48, y + 96 - 2, x + 48, y + 48 + 2); //line 4
	iSetColor(h1_l5, 0, 0);
	iLine(x + 48, y + 48 - 2, x + 48, y + 2); //line 5
	iSetColor(h1_l6, 0, 0);
	iLine(x + 48 - 2, y, x + 2, y); //line 6
	iSetColor(h1_l7, 0, 0);
	iLine(x + 2, y + 48, x + 48 - 2, y + 48); //line 7 or the midline


	//***************Drawing Minutes************//
	//iRectangle(536+3, 400, 48, 96);
	x += 74;
	iSetColor(m2_l1, 0, 0);
	iLine(x, y + 2, x, y + 48 - 2); //line 1
	iSetColor(m2_l2, 0, 0);
	iLine(x, y + 48 + 2, x, y + 96 - 2); //line 2
	iSetColor(m2_l3, 0, 0);
	iLine(x + 2, y + 96, x + 48 - 2, y + 96); //line 3
	iSetColor(m2_l4, 0, 0);
	iLine(x + 48, y + 96 - 2, x + 48, y + 48 + 2); //line 4
	iSetColor(m2_l5, 0, 0);
	iLine(x + 48, y + 48 - 2, x + 48, y + 2); //line 5
	iSetColor(m2_l6, 0, 0);
	iLine(x + 48 - 2, y, x + 2, y); //line 6
	iSetColor(m2_l7, 0, 0);
	iLine(x + 2, y + 48, x + 48 - 2, y + 48); //line 7 or the midline
	
	//iRectangle(604-3, 400, 48, 96);
	x += 62;
	iSetColor(m1_l1, 0, 0);
	iLine(x, y + 2, x, y + 48 - 2); //line 1
	iSetColor(m1_l2, 0, 0);
	iLine(x, y + 48 + 2, x, y + 96 - 2); //line 2
	iSetColor(m1_l3, 0, 0);
	iLine(x + 2, y + 96, x + 48 - 2, y + 96); //line 3
	iSetColor(m1_l4, 0, 0);
	iLine(x + 48, y + 96 - 2, x + 48, y + 48 + 2); //line 4
	iSetColor(m1_l5, 0, 0);
	iLine(x + 48, y + 48 - 2, x + 48, y + 2); //line 5
	iSetColor(m1_l6, 0, 0);
	iLine(x + 48 - 2, y, x + 2, y); //line 6
	iSetColor(m1_l7, 0, 0);
	iLine(x + 2, y + 48, x + 48 - 2, y + 48); //line 7 or the midline

	//***************Drawing seconds****************//
	iSetColor(r, 0, 0);
	//iRectangle(672+3, 400, 48, 96);
	x += 74;
	iSetColor(s2_l1, 0, 0);
	iLine(x, y + 2, x, y + 48 - 2); //line 1
	iSetColor(s2_l2, 0, 0);
	iLine(x, y + 48 + 2, x, y + 96 - 2); //line 2
	iSetColor(s2_l3, 0, 0);
	iLine(x + 2, y + 96, x + 48 - 2, y + 96); //line 3
	iSetColor(s2_l4, 0, 0);
	iLine(x + 48, y + 96 - 2, x + 48, y + 48 + 2); //line 4
	iSetColor(s2_l5, 0, 0);
	iLine(x + 48, y + 48 - 2, x + 48, y + 2); //line 5
	iSetColor(s2_l6, 0, 0);
	iLine(x + 48 - 2, y, x + 2, y); //line 6
	iSetColor(s2_l7, 0, 0);
	iLine(x + 2, y + 48, x + 48 - 2, y + 48); //line 7 or the midline
	
	//iRectangle(740-3, 400, 48, 96);
	x += 62;
	iSetColor(s1_l1, 0, 0);
	iLine(x, y + 2, x, y + 48 - 2); //line 1
	iSetColor(s1_l2, 0, 0);
	iLine(x, y + 48 + 2, x, y + 96 - 2); //line 2
	iSetColor(s1_l3, 0, 0);
	iLine(x + 2, y + 96, x + 48 - 2, y + 96); //line 3
	iSetColor(s1_l4, 0, 0);
	iLine(x + 48, y + 96 - 2, x + 48, y + 48 + 2); //line 4
	iSetColor(s1_l5, 0, 0);
	iLine(x + 48, y + 48 - 2, x + 48, y + 2); //line 5
	iSetColor(s1_l6, 0, 0);
	iLine(x + 48 - 2, y, x + 2, y); //line 6
	iSetColor(s1_l7, 0, 0);
	iLine(x + 2, y + 48, x + 48 - 2, y + 48); //line 7 or the midline

	
	
	
	//Blinking Dots
	iSetColor(0, 0, blink);
	iFilledRectangle(dx+522, dy+465, 4, 4);
	iSetColor(0, 0, blink);
	iFilledRectangle(dx+522, dy+431, 4, 4);

	iSetColor(0, 0, blink);
	iFilledRectangle(dx+658, dy+465, 4, 4);
	iSetColor(0, 0, blink);
	iFilledRectangle(dx+658, dy+431, 4, 4);
	iSetColor(r, g, b);
	if (hell)
	{
		iText(dx + 300, dy + 600, Day[week], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(dx + 400, dy + 600, Month[mon], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(dx + 476, dy + 600, day_str, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(dx + 500, dy + 600, ", 2019", GLUT_BITMAP_TIMES_ROMAN_24);
	}
		
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	dx += mx;
	dy += my;
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	mouse_x = mx;
	mouse_y = my;
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		dx = mx;
		dy = my;	
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		printf("x=%d\ny=%d\n", mx, my);
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'k')
	{
		if (r==0)
			r = 255;
		else
			r = 0;
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_INSERT)
	{
		if (hell)
			hell = false;
		else
			hell = true;
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}


void blinking()
{
	if (blink == 0)
		blink = 255;
	else
		blink = 0;
}
void hours()
{
	int h1 = 0, h2 = 0;
	if (hr >= 24)
		hr = 0;
	int h = hr;
	h1 = h % 10;
	h /= 10;
	h2 = h % 10;
	switch (h1)
	{
	case 0:
		zero(&h1_l1, &h1_l2, &h1_l3, &h1_l4, &h1_l5, &h1_l6, &h1_l7);
		break;
	case 1:
		one(&h1_l1, &h1_l2, &h1_l3, &h1_l4, &h1_l5, &h1_l6, &h1_l7);
		break;
	case 2:
		two(&h1_l1, &h1_l2, &h1_l3, &h1_l4, &h1_l5, &h1_l6, &h1_l7);
		break;
	case 3:
		three(&h1_l1, &h1_l2, &h1_l3, &h1_l4, &h1_l5, &h1_l6, &h1_l7);
		break;
	case 4:
		four(&h1_l1, &h1_l2, &h1_l3, &h1_l4, &h1_l5, &h1_l6, &h1_l7);
		break;
	case 5:
		five(&h1_l1, &h1_l2, &h1_l3, &h1_l4, &h1_l5, &h1_l6, &h1_l7);
		break;
	case 6:
		six(&h1_l1, &h1_l2, &h1_l3, &h1_l4, &h1_l5, &h1_l6, &h1_l7);
		break;
	case 7:
		seven(&h1_l1, &h1_l2, &h1_l3, &h1_l4, &h1_l5, &h1_l6, &h1_l7);
		break;
	case 8:
		eight(&h1_l1, &h1_l2, &h1_l3, &h1_l4, &h1_l5, &h1_l6, &h1_l7);
		break;
	case 9:
		nine(&h1_l1, &h1_l2, &h1_l3, &h1_l4, &h1_l5, &h1_l6, &h1_l7);
		break;
	}
	switch (h2)
	{
	case 0:
		zero(&h2_l1, &h2_l2, &h2_l3, &h2_l4, &h2_l5, &h2_l6, &h2_l7);
		break;
	case 1:
		one(&h2_l1, &h2_l2, &h2_l3, &h2_l4, &h2_l5, &h2_l6, &h2_l7);
		break;
	case 2:
		two(&h2_l1, &h2_l2, &h2_l3, &h2_l4, &h2_l5, &h2_l6, &h2_l7);
		break;
	case 3:
		three(&h2_l1, &h2_l2, &h2_l3, &h2_l4, &h2_l5, &h2_l6, &h2_l7);
		break;
	case 4:
		four(&h2_l1, &h2_l2, &h2_l3, &h2_l4, &h2_l5, &h2_l6, &h2_l7);
		break;
	case 5:
		five(&h2_l1, &h2_l2, &h2_l3, &h2_l4, &h2_l5, &h2_l6, &h2_l7);
		break;
	case 6:
		six(&h2_l1, &h2_l2, &h2_l3, &h2_l4, &h2_l5, &h2_l6, &h2_l7);
		break;
	case 7:
		seven(&h2_l1, &h2_l2, &h2_l3, &h2_l4, &h2_l5, &h2_l6, &h2_l7);
		break;
	case 8:
		eight(&h2_l1, &h2_l2, &h2_l3, &h2_l4, &h2_l5, &h2_l6, &h2_l7);
		break;
	case 9:
		nine(&h2_l1, &h2_l2, &h2_l3, &h2_l4, &h2_l5, &h2_l6, &h2_l7);
		break;
	}
	hr++;
}

void minutes()
{
	int m1 = 0, m2 = 0;
	if (min >= 60)
	{
		min = 0;
		hours();
	}	
	int m = min;
	m1 = m % 10;
	m /= 10;
	m2 = m % 10;
	switch (m1)
	{
	case 0:
		zero(&m1_l1, &m1_l2, &m1_l3, &m1_l4, &m1_l5, &m1_l6, &m1_l7);
		break;
	case 1:
		one(&m1_l1, &m1_l2, &m1_l3, &m1_l4, &m1_l5, &m1_l6, &m1_l7);
		break;
	case 2:
		two(&m1_l1, &m1_l2, &m1_l3, &m1_l4, &m1_l5, &m1_l6, &m1_l7);
		break;
	case 3:
		three(&m1_l1, &m1_l2, &m1_l3, &m1_l4, &m1_l5, &m1_l6, &m1_l7);
		break;
	case 4:
		four(&m1_l1, &m1_l2, &m1_l3, &m1_l4, &m1_l5, &m1_l6, &m1_l7);
		break;
	case 5:
		five(&m1_l1, &m1_l2, &m1_l3, &m1_l4, &m1_l5, &m1_l6, &m1_l7);
		break;
	case 6:
		six(&m1_l1, &m1_l2, &m1_l3, &m1_l4, &m1_l5, &m1_l6, &m1_l7);
		break;
	case 7:
		seven(&m1_l1, &m1_l2, &m1_l3, &m1_l4, &m1_l5, &m1_l6, &m1_l7);
		break;
	case 8:
		eight(&m1_l1, &m1_l2, &m1_l3, &m1_l4, &m1_l5, &m1_l6, &m1_l7);
		break;
	case 9:
		nine(&m1_l1, &m1_l2, &m1_l3, &m1_l4, &m1_l5, &m1_l6, &m1_l7);
		break;
	}
	switch (m2)
	{
	case 0:
		zero(&m2_l1, &m2_l2, &m2_l3, &m2_l4, &m2_l5, &m2_l6, &m2_l7);
		break;
	case 1:
		one(&m2_l1, &m2_l2, &m2_l3, &m2_l4, &m2_l5, &m2_l6, &m2_l7);
		break;
	case 2:
		two(&m2_l1, &m2_l2, &m2_l3, &m2_l4, &m2_l5, &m2_l6, &m2_l7);
		break;
	case 3:
		three(&m2_l1, &m2_l2, &m2_l3, &m2_l4, &m2_l5, &m2_l6, &m2_l7);
		break;
	case 4:
		four(&m2_l1, &m2_l2, &m2_l3, &m2_l4, &m2_l5, &m2_l6, &m2_l7);
		break;
	case 5:
		five(&m2_l1, &m2_l2, &m2_l3, &m2_l4, &m2_l5, &m2_l6, &m2_l7);
		break;
	case 6:
		six(&m2_l1, &m2_l2, &m2_l3, &m2_l4, &m2_l5, &m2_l6, &m2_l7);
		break;
	case 7:
		seven(&m2_l1, &m2_l2, &m2_l3, &m2_l4, &m2_l5, &m2_l6, &m2_l7);
		break;
	case 8:
		eight(&m2_l1, &m2_l2, &m2_l3, &m2_l4, &m2_l5, &m2_l6, &m2_l7);
		break;
	case 9:
		nine(&m2_l1, &m2_l2, &m2_l3, &m2_l4, &m2_l5, &m2_l6, &m2_l7);
		break;
	}
	min++;
}
void seconds()
{
	int s1=0, s2=0;
	if (sec >= 60)
	{
		sec = 0;
		minutes();
	}
	int s = sec;
	s1 = s % 10;
	s = s / 10;
	s2 = s % 10;
	switch (s1)
	{
	case 0:
		zero(&s1_l1, &s1_l2, &s1_l3, &s1_l4, &s1_l5, &s1_l6, &s1_l7);
		break;
	case 1:
		one(&s1_l1, &s1_l2, &s1_l3, &s1_l4, &s1_l5, &s1_l6, &s1_l7);
		break;
	case 2:
		two(&s1_l1, &s1_l2, &s1_l3, &s1_l4, &s1_l5, &s1_l6, &s1_l7);
		break;
	case 3:
		three(&s1_l1, &s1_l2, &s1_l3, &s1_l4, &s1_l5, &s1_l6, &s1_l7);
		break;
	case 4:
		four(&s1_l1, &s1_l2, &s1_l3, &s1_l4, &s1_l5, &s1_l6, &s1_l7);
		break;
	case 5:
		five(&s1_l1, &s1_l2, &s1_l3, &s1_l4, &s1_l5, &s1_l6, &s1_l7);
		break;
	case 6:
		six(&s1_l1, &s1_l2, &s1_l3, &s1_l4, &s1_l5, &s1_l6, &s1_l7);
		break;
	case 7:
		seven(&s1_l1, &s1_l2, &s1_l3, &s1_l4, &s1_l5, &s1_l6, &s1_l7);
		break;
	case 8:
		eight(&s1_l1, &s1_l2, &s1_l3, &s1_l4, &s1_l5, &s1_l6, &s1_l7);
		break;
	case 9:
		nine(&s1_l1, &s1_l2, &s1_l3, &s1_l4, &s1_l5, &s1_l6, &s1_l7);
		break;
	}
	switch (s2)
	{
	case 0:
		zero(&s2_l1, &s2_l2, &s2_l3, &s2_l4, &s2_l5, &s2_l6, &s2_l7);
		break;
	case 1:
		one(&s2_l1, &s2_l2, &s2_l3, &s2_l4, &s2_l5, &s2_l6, &s2_l7);
		break;
	case 2:
		two(&s2_l1, &s2_l2, &s2_l3, &s2_l4, &s2_l5, &s2_l6, &s2_l7);
		break;
	case 3:
		three(&s2_l1, &s2_l2, &s2_l3, &s2_l4, &s2_l5, &s2_l6, &s2_l7);
		break;
	case 4:
		four(&s2_l1, &s2_l2, &s2_l3, &s2_l4, &s2_l5, &s2_l6, &s2_l7);
		break;
	case 5:
		five(&s2_l1, &s2_l2, &s2_l3, &s2_l4, &s2_l5, &s2_l6, &s2_l7);
		break;
	case 6:
		six(&s2_l1, &s2_l2, &s2_l3, &s2_l4, &s2_l5, &s2_l6, &s2_l7);
		break;
	case 7:
		seven(&s2_l1, &s2_l2, &s2_l3, &s2_l4, &s2_l5, &s2_l6, &s2_l7);
		break;
	case 8:
		eight(&s2_l1, &s2_l2, &s2_l3, &s2_l4, &s2_l5, &s2_l6, &s2_l7);
		break;
	case 9:
		nine(&s2_l1, &s2_l2, &s2_l3, &s2_l4, &s2_l5, &s2_l6, &s2_l7);
		break;
	}
	sec++;
}

void change()
{
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
}

int main()
{	
	iSetTimer(6666, change);
	time_t tVal;
	tm*ptr;
	tVal = time(NULL);
	ptr = localtime(&tVal);

	sec = ptr->tm_sec;
	printf("seconds: %d\n", sec);
	seconds();
	min = ptr->tm_min;
	printf("minutes: %d\n", min);
	minutes();
	hr = ptr->tm_hour;
	printf("hours: %d\n", hr);
	hours();
	day = ptr->tm_mday;
	sprintf(day_str, "%d", day);
	mon = ptr->tm_mon;
	week = ptr->tm_wday;///1st day is sunday;
	
	iSetTimer(1000, blinking);	
	iSetTimer(1000, seconds);
	//iSetTimer(1000 * 60, minutes);
	//iSetTimer(1000 * 60 * 24, hours);
	
	iInitialize(swidth, sheight, "Digital Watch");

	iStart();
	return 0;
}