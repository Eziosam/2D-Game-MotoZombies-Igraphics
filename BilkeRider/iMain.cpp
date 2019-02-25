#include "iGraphics.h"
#include "bitmap_loader.h"
#include<iostream>
//Variables::
int bike = 100;
int image[10];
int bikess;
int x = 0;
int y = 1600;
int barrel = 1700;
int bomb;
int bombs = bike + 270;
int life = 500;
int enemy = 500;
bool start = true;

//Game Mode Mechanisms:
bool game = false;
bool gamestart = false;
bool gameover = false;
bool menu = true;
int option = false;
int credit = false;
//page variables
int instructionimage;
int creditpage;
int menupage;
//buttons
int button[50];
int buttonsize[50];
int buttonanimation[6] = { true, true, true, true, true };

//menubutton
int buttonwidth = 220;
int buttonheight = 32;

void iDraw()
{
	
	iClear();

	if (menu)
	{
		iShowImage(0, 0, 1600, 700, menupage);


		if (buttonanimation[1])
			iShowImage(80, 500, buttonwidth, buttonheight, button[0]);
		if (!buttonanimation[1])
			iShowImage(80, 500, buttonwidth, buttonheight, button[4]);
		if (buttonanimation[2])
			iShowImage(80, 400, buttonwidth, buttonheight, button[1]);
		if (!buttonanimation[2])
			iShowImage(80, 400, buttonwidth, buttonheight, button[7]);
		if (buttonanimation[3])
			iShowImage(80, 300, buttonwidth, buttonheight, button[2]);
		if (!buttonanimation[3])
			iShowImage(80, 300, buttonwidth, buttonheight, button[5]);
		if (buttonanimation[4])
			iShowImage(80, 200, buttonwidth, buttonheight, button[3]);
		if (!buttonanimation[4])
			iShowImage(80, 200, buttonwidth, buttonheight, button[6]);


	}
	if (option)
		iShowImage(0, 0, 1600, 700, instructionimage);
	if (credit)
		iShowImage(0, 0, 1600, 700, creditpage);

	if (game)

	{
		iShowImage(x, 0, 1600, 700, image[0]);
		iShowImage(y, 0, 1600, 700, image[1]);
		iShowImage(bike, 255, 270, 230, bikess);
		iShowImage(barrel, 230, 270, 230, image[2]);
		iShowImage(bombs, 250, 200, 130, bomb);
		iShowImage(900, 7, 160, 140, image[4]);
		iShowImage(70, 7, 160, 140, image[3]);
		iSetColor(255, 0, 0);
		iFilledRectangle(250, 40, life, 50);
		iSetColor(255, 0, 0);
		iFilledRectangle(1080, 40, enemy, 50);
		iSetColor(255, 255, 255);
		iRectangle(250, 40, 501, 50);
		iRectangle(1080, 40, 501, 50);
	}

}

void iPassiveMouse(int mx, int my)
{

	if (my >= 500 && my <= 532)
	{

		if (mx >= 80 && mx <= 300)
		{
			buttonanimation[1] = false;
		}
		else
			buttonanimation[1] = true;
	}
	else
		buttonanimation[1] = true;

	if (my >= 400 && my <= 432)
	{

		if (mx >= 80 && mx <= 300)
		{
			buttonanimation[2] = false;
		}
		else
			buttonanimation[2] = true;
	}
	else
		buttonanimation[2] = true;

	if (my >= 300 && my <= 332)
	{

		if (mx >= 80 && mx <= 300)
		{

			buttonanimation[3] = false;
		}
		else
			buttonanimation[3] = true;
	}
	else
		buttonanimation[3] = true;

	if (my >= 200 && my <= 232)
	{

		if (mx >= 80 && mx <= 300)
		{

			buttonanimation[4] = false;

		}
		else
			buttonanimation[4] = true;
	}
	else
		buttonanimation[4] = true;

}

void iMouseMove(int mx, int my)
{
	bike = mx;
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
			printf("x = %d, y= %d\n",mx,my);
		
	}


	if (my >= 500 && my <= 532)
	{

		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{

				menu = false;
				option = false;
				credit = false;
				game = true;
			}
		}
	}
	if (my >= 400 && my <= 432)
	{

		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{

				menu = false;
				option = true;
				credit = false;
				game = false;
			}
		}
	}
	if (my >= 300 && my <= 332)
	{

		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{
				menu = false;
				option = false;
				credit = true;
				game = false;
			}
		}
	}
	if (my >= 200 && my <= 232)
	{

		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
				exit(0);
		}
	}
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		exit(0);
	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	else if (key == 'a')
	{
		if (bike>0)
		bike -= 5;
	}
		
	else if (key == 'd')
	{
		if (bike<1300)
		bike += 5;	
	}
	else if (key == 'p')
	{
		start = false;
	}
	else if (key == 'r')
	{
		start = true;
	}

	if (key == '\b')
	{
		gameover = false;
		game = false;
		menu = true;
		option = false;
		credit = false;
		start = false;
		
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (bike<1300)
		bike += 5;
		
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (bike>0)
		bike -= 5;
		
	}
}
void animation()
{
	if (start)
	{
		barrel -= 10;
		if (barrel <= -200)
		{
			barrel = 1700;
		}
		if (barrel <= bike + 250)
		{
			if (barrel >= bike - 10)
				life -= 2;
			if (life <= 0)
			{
				life = 500;
			}
		}
		if (bombs + 200 >= barrel)
		{
			if (bombs + 200 <= barrel + 300)
				enemy -= 1;
			if (enemy <= 0)
			{
				enemy = 500;
			}
		}

		x -= 5;
		y -= 5;
		if (x <= -1600)
		{
			x = 1600;
		}
		if (y <= -1600)
		{
			y = 1600;
		}
		bombs += 20;
		if (bombs > 1600 || (bombs > barrel&&barrel >= 400))
			bombs = bike + 270;
	}
}

int main()
{
	//place your own initialization codes here.
	iSetTimer(50, animation);

	iInitialize(1600, 700, "Bikerider");
	//Ingame images::
	bikess   = iLoadImage("images\\bike.png");
	image[0] = iLoadImage("images\\back2.png");
	image[1] = iLoadImage("images\\back.png");
	image[2] = iLoadImage("images\\barrel.png");
	image[3] = iLoadImage("images\\life.png");
	image[4] = iLoadImage("images\\enemy.png");
	bomb	 = iLoadImage("images\\bomb.png");

	//Page iMAGES:
	instructionimage = iLoadImage("images\\instructions.png");
	creditpage = iLoadImage("images\\credits.png");
	menupage = iLoadImage("images\\gamecover.png");

	//buttonimages
	button[0] = iLoadImage("images\\button\\newgame.png");
	button[2] = iLoadImage("images\\button\\credits.png");
	button[3] = iLoadImage("images\\button\\quit.png");
	button[1] = iLoadImage("images\\button\\option.png");

	button[4] = iLoadImage("images\\button\\newgame2.png");
	button[5] = iLoadImage("images\\button\\credits2.png");
	button[6] = iLoadImage("images\\button\\quit2.png");
	button[7] = iLoadImage("images\\button\\option2.png");

	iStart(); // it will start drawing

	return 0;
}

