/* END SEMESTER PROJECT SUBMISSION */
/* PROJECT IDEA: 2-D Game related to SEECS NUST */
/* Submitted to: Sir Shamyl */
/* Submitted by: Roha Asad & Wajahat Hussain */
/* Class: BESE-6B */

#include <stdlib.h>
#include "glut.h"
#include <stdio.h>
#include <conio.h>
#include "GL.H"                           // GLUT 
#include <iostream>
#include <Windows.h>                      // Sound Library
#include <mmsystem.h>                     // Libraries for sound

int g_Width = 400;		                  //define size of the window
int g_Height = 400;

/* Axis defined for MENU box */
int x_1 = 300;                           
int y_1 = 140;

int x_2 = 300;
int y_2 = 290;

int x_3 = 300;
int y_3 = 440;

int t_x1 = 270;
int t_y1 = 150;

int t_x2 = 290;
int t_y2 = 160;

int t_x3 = 270;
int t_y3 = 170;
/* End of Axis defined for MENU */

int over = 0;                        // controlling the GAME over function images 
int start = 0;                       // controlling the MENU
int help = 0;                        // controlling HELP function
                                     

int presents = 0;                    // presents at the start are zero
int Lives = 5;                       // lives are initialized 5 

//global mouse position
int mouse_X = 0;	                  //xcod              
int mouse_Y = 0;	                 //ycodz

int st_hw = 75;                     /* Width and Height of Student */

int st_x = 10;                      /* Student's Co-ordinates */
int st_y = 300;


int b_h = 75;                       // other characters' height
int b_w = 75;                       // other characters' widths

// Other characters' axis

int b1_x = 1410;                    
int b1_y = 100;

int b2_x = 2130;
int b2_y = 300;

int b3_x = 2930;
int b3_y = 200;

int b4_x = 3500;
int b4_y = 500;

int b5_x = 2200;
int b5_y = 400;

int b6_x = 5070;
int b6_y = 450;

int b7_x = 6570;
int b7_y = 150;

int b8_x = 7000;
int b8_y = 450;

int b9_x = 7250;
int b9_y = 250;

int b10_x = 6070;
int b10_y = 350;

int b11_x = 5070;
int b11_y = 300;

int b12_x = 3070;
int b12_y = 250;

int b13_x = 5070;
int b13_y = 110;

int bdirection = -1;     /* Characters moving from Right to Left  */
int bspeed = 30;         /* Axis Movement for characters */

// Images loading initialization

GLuint image1;                // (initialization) 
GLuint image2;
GLuint image3;
GLuint image4;
GLuint image5;
GLuint image6;
GLuint image7;
GLuint image8;
GLuint image9;
GLuint image10;
GLuint image11;
GLuint image12;
GLuint image13;
GLuint image14;
GLuint image15;
GLuint image16;
GLuint image17;

void init();                                                         /* Function used to initialze other functions */
void myMouseFunction(int button, int state, int mouseX, int mouseY);    /* Mouse Handling Function */
void myKeyboardFunction(unsigned char key, int mouseX, int mouseY);      /* Key board Handling Function */
void mySpecialKeysFunction(int key, int x, int y);                       /* Special Keys i.e: Arrow Keys; Handling Function */
void myReshapeFunction(int width, int height);                           // reshape the window when it is minimized or maximized and change the verticies accordingly
void myTimerFunction(int val);                                           /* Function to refresh the SCREEN */
void myDisplayFunction();
void mymouse_motionfunction(int, int);                                  /* Mouse movement control function */
GLuint loadTexture(char *name);
void draw(GLuint _textureId, int x, int y, int wd, int ht);              /* Function for TEXTURES */

void renderBitmapString(                                                 /* Function for printing SCORES */
	float x,
	float y,
	char *string) {

	char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}




void loadResources()                                       /* Loads IMAGES from folder*/
{
	image1 = loadTexture("nust.tga");
	image2 = loadTexture("quiz.tga");
	image3 = loadTexture("project.tga");
	image4 = loadTexture("quiz2.tga");
	image5 = loadTexture("absent.tga");
	image6 = loadTexture("absent2.tga");
	image7 = loadTexture("present.tga");
	image8 = loadTexture("present2.tga");
	image9 = loadTexture("samosa.tga");
	image10 = loadTexture("oht.tga");
	image11 = loadTexture("student.tga");
	image12 = loadTexture("prog.tga");
	image13 = loadTexture("calculus.tga");
	image14 = loadTexture("fail.tga");
	image15 = loadTexture("passed.tga");
	image16 = loadTexture("help.tga");
	image17 = loadTexture("ict.tga");
}

int main(int argc, char** argv)                                     /* Initialization of MAIN */
{


	glutInit(&argc, argv);		                                    //initilize the GLUT libraray   // arguments and pointers are given

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);		            //has four colour components red, green,blue, and alpha 
	glutInitWindowSize(800, 600);	                                /* Window's size */
	glutInitWindowPosition(0, 0);		                            /* Position of Window */
	glutCreateWindow("BhAAAG !!! SEEECS se BHAAAG !!!");           /* Name of WINDOW */

	loadResources();                                               /* Image load function being called */
	init();
	glutMouseFunc(myMouseFunction);                                /* Callig Mouse Function */
	glutKeyboardFunc(myKeyboardFunction);                          /* Calling keyboard function */
	glutSpecialFunc(mySpecialKeysFunction);

	glutReshapeFunc(myReshapeFunction);
	glutDisplayFunc(myDisplayFunction);
	glutTimerFunc(11, myTimerFunction, 0);
	glutPassiveMotionFunc(mymouse_motionfunction);                   
	glutSetCursor(GLUT_CURSOR_INFO);	                           //Displays the type of cursor u want

	glutMainLoop();                                               // just keep on repeating the loop when changes happen and returns nothing

	return 0;
}




void init(void)                                                                          /* Function Body Initialization */
{

	glClearColor(0.0, 0.0, 0.0, 0.0);		                                                 //background color of openGl window
	//			 ^red, green, blue, alpha(opaquenss) 
	glMatrixMode(GL_PROJECTION);		                       
	glLoadIdentity();
	PlaySound(TEXT("bhag.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);                  // Playing sound over loop by loop
	glOrtho(0.0, g_Width, 0.0, g_Height, -1.0, 1.0);	                                     //set (0,0) on left top
}

void myMouseFunction(int button, int state, int mouseX, int mouseY)

{
	mouse_X = mouseX;                                                    //assigning local values of x and y axis to global axis
	mouse_Y = mouseY;

	if (button == 0 && state == 1)                                       //Click
	{
	
		
	}
	if (button == 2 && state == 0)                                     // I have added the mouse functoning for 2nd button also
	{
		printf("mouse clicked \n");                                     //printf can be removed ; no need 
		printf("\nmouseX: %d mouseY: %d, State: %d", mouseX, mouseY, state);
	}

}

void myKeyboardFunction(unsigned char key, int mouseX, int mouseY)       /* Function Body of Keyboard Function */
{
	if (key == 'n')                     // Reset Function , resets everything by pressing 'n'
	{
		start = 0;
		over = 0;
		help = 0;
		 presents = 0;
		 Lives = 5;

		
		 mouse_X = 0;	//xcod              
		 mouse_Y = 0;	//ycodz

		 st_hw = 75;

		 st_x = 10; /* Student's X-axis */
		 st_y = 300; /* Student's Y-axis*/

		 
		 b_h = 75;/* Height of Student */
		 b_w = 75; /* Width of Student */

		 /* Axis of Other Characters */
		 b1_x = 1410;
		 b1_y = 100;

		 b2_x = 2130;
		 b2_y = 300;

		 b3_x = 2930;
		 b3_y = 200;

		 b4_x = 3500;
		 b4_y = 500;

		 b5_x = 2200;
		 b5_y = 400;

		 b6_x = 5070;
		 b6_y = 450;

		 b7_x = 6570;
		 b7_y = 150;

		 b8_x = 7000;
		 b8_y = 450;

		 b9_x = 7250;
		 b9_y = 250;

		 b10_x = 6070;
		 b10_y = 350;

		 b11_x = 5070;
		 b11_y = 300;

		 b12_x = 3070;
		 b12_y = 250;

		 b13_x = 5070;
		 b13_y = 100;

		 bdirection = -1;
		 bspeed = 30;
		
	}
	
	if (key == 'w')                       /* Controlling MENU up */
	{
		if (t_y1 > 150)
		{
			t_x1 = 270;
			t_x3 = 270;
			t_x2 = 290;

			t_y1 -= 150;
			t_y2 -= 150;
			t_y3 -= 150;

		}
	}

	if (key == 's')              /* Controlling MENU down */
	{
		if (t_y1 < 450)
		{
			t_x1 = 270;
			t_x3 = 270;
			t_x2 = 290;

			t_y1 += 150;
			t_y2 += 150;
			t_y3 += 150;
		}
	}

	if (key == 13)                       // When Enter is pressed condition to control game flags
	{
		if (t_y2 == 160)                // our menu pointer at play position 
		{
			start = 1;
		}
		else

		if (t_y2 == 460)                // our menu pointer at exit position
		{
			exit(0);
		}

		else 
		
		if (t_y2 == 310)              // our menu pointer at help position
		{
			help = 1;
		}


	}

	
}
void mymouse_motionfunction(int x, int y)
{
	if (y >= 100 && y <= 575)                      // controlling student by mouse and limiting its movement
	{
		st_y = y - 50;
		st_y = y + 50;
		st_y = y + 50;
		st_y = y - 50;
	}



}

void mySpecialKeysFunction(int key, int x, int y) /* Function Body of Special Keys */
{
	switch (key)
	{
		
	case GLUT_KEY_UP:                         // movement of student by 'up' key        
		if (t_y1 > 150)
		{
			t_x1 = 270;
			t_x3 = 270;
			t_x2 = 290;

			t_y1 -= 150;
			t_y2 -= 150;
			t_y3 -= 150;

		}
		if (st_y >= 100)
		{
			st_y = st_y - 20;
		}
		else
			break;
		break;


	case GLUT_KEY_DOWN:                     // movement of student by 'down' key
		
		if (t_y1 < 450)
		{
			t_x1 = 270;
			t_x3 = 270;
			t_x2 = 290;

			t_y1 += 150;
			t_y2 += 150;
			t_y3 += 150;
		}
		if (st_y <= 525)
		{

			st_y = st_y + 20;
		}
		else
			break;
		
		break;
	
	}
}

void myReshapeFunction(int width, int height)       // when window size changes it changes the axis accordingly but divisions remain the same
{
	glClear(GL_COLOR_BUFFER_BIT);                   //clears the first image to form new image 

	g_Width = width;                               // global axis are assigned to new axis (axis size remains the same)
	g_Height = height;

	glViewport(0, 0, g_Width, g_Height);           //starting point (0,0)

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, g_Width, g_Height, 0.0, -1.0, 1.0);
}	//change the (0,0) to top 

void myTimerFunction(int val)                         /* Function to refresh the Images */
{
	glutTimerFunc(15, myTimerFunction, 0);
	myDisplayFunction();
}

void myDisplayFunction()            /* Drawing Function */
{

		if (start == 1)           // controlling menu
		{

			if (over == 0)        // controlling game over function (either win or loose)  
			{

				draw(image1, 0, 600, 800, 600);       // SEECS image load


				draw(image11, st_x, st_y + st_hw, st_hw, st_hw);    // axis are given where to draw image 


				//// 1st box

				draw(image5, b1_x + 20, b1_y + b_h, b_w, b_h);
				if (b1_x < 0)
				{
					b1_x = 2500;

				}
				b1_x = b1_x + (bdirection*bspeed);

				if (b1_x > 0)
				{
					bdirection = -1;
				}




				if ((st_x + st_hw > b1_x && st_x < b1_x && st_y >= b1_y && st_y <= b1_y + b_h && st_y + st_hw >= b1_y + b_h) || (st_x + st_hw > b1_x && st_x < b1_x      &&     b1_y >= st_y && b1_y <= st_y + st_hw  && st_y + st_hw <= b1_y + b_h))
				{
					b1_x = 2500;
					b1_y = 100;
					Lives--;
					printf("%d", Lives);
				}


				//2nd box
				draw(image2, b2_x + 20, b2_y + b_h, b_w, b_h);

				if (b2_x < 0)
				{
					b2_x = 2630;

				}
				b2_x = b2_x + (bdirection*bspeed);
				if (b2_x < 0)
				{
					bdirection = -1;
				}


				if ((st_x + st_hw > b2_x && st_x < b2_x && st_y >= b2_y && st_y <= b2_y + b_h && st_y + st_hw >= b2_y + b_h) || (st_x + st_hw > b2_x && st_x < b2_x      &&     b2_y >= st_y && b2_y <= st_y + st_hw  && st_y + st_hw <= b2_y + b_h))
				{
					b2_x = 1400;
					b2_y = 300;
					Lives--;
					printf("%d", Lives);
				}


				// 3rd box
				draw(image10, b3_x + 20, b3_y + b_h, b_w, b_h);

				if (b3_x < 0)
				{
					b3_x = 3000;

				}
				b3_x = b3_x + (bdirection*bspeed);
				if (b3_x < 0)
				{
					bdirection = -1;
				}


				if ((st_x + st_hw > b3_x && st_x < b3_x && st_y >= b3_y && st_y <= b3_y + b_h && st_y + st_hw >= b3_y + b_h) || (st_x + st_hw > b3_x && st_x < b3_x      &&     b3_y >= st_y && b3_y <= st_y + st_hw  && st_y + st_hw <= b3_y + b_h))
				{
					b3_x = 3000;
					b3_y = 200;
					Lives--;
					printf("%d", Lives);
				}


				// 4th box
				draw(image6, b4_x + 20, b4_y + b_h, b_w, b_h);

				if (b4_x < 0)
				{
					b4_x = 5000;

				}
				b4_x = b4_x + (bdirection*bspeed);
				if (b4_x < 0)
				{
					bdirection = -1;
				}



				if ((st_x + st_hw > b4_x && st_x < b4_x && st_y >= b4_y && st_y <= b4_y + b_h && st_y + st_hw >= b4_y + b_h) || (st_x + st_hw > b4_x && st_x < b4_x      &&     b4_y >= st_y && b4_y <= st_y + st_hw  && st_y + st_hw <= b4_y + b_h))
				{
					b4_x = 5000;
					b4_y = 300;
					Lives--;
					printf("%d", Lives);
				}

				// 5th box
				draw(image8, b5_x + 20, b5_y + b_h, b_w, b_h);

				if (b5_x < 0)
				{
					b5_x = 3500;

				}
				b5_x = b5_x + (bdirection*bspeed);
				if (b5_x < 0)
				{
					bdirection = -1;
				}


				if ((st_x + st_hw > b5_x && st_x < b5_x && st_y >= b5_y && st_y <= b5_y + b_h && st_y + st_hw >= b5_y + b_h) || (st_x + st_hw > b5_x && st_x < b5_x      &&     b5_y >= st_y && b5_y <= st_y + st_hw  && st_y + st_hw <= b5_y + b_h))
				{
					b5_x = 3500;
					b5_y = 400;
					presents++;
					printf("%d", presents);


				}

				// 6th box
				draw(image4, b6_x + 20, b6_y + b_h, b_w, b_h);

				if (b6_x < 0)
				{
					b6_x = 5070;

				}
				b6_x = b6_x + (bdirection*bspeed);
				if (b6_x < 0)
				{
					bdirection = -1;
				}


				if ((st_x + st_hw > b6_x && st_x < b6_x && st_y >= b6_y && st_y <= b6_y + b_h && st_y + st_hw >= b6_y + b_h) || (st_x + st_hw > b6_x && st_x < b6_x      &&     b6_y >= st_y && b6_y <= st_y + st_hw  && st_y + st_hw <= b6_y + b_h))
				{
					b6_x = 2000;
					b6_y = 550;
					Lives--;
					printf("%d", Lives);
				}



				// 7th box
				draw(image9, b7_x + 20, b7_y + b_h, b_w, b_h);

				if (b7_x < 0)
				{
					b7_x = 3050;

				}
				b7_x = b7_x + (bdirection*bspeed);
				if (b7_x < 0)
				{
					bdirection = -1;
				}


				if ((st_x + st_hw > b7_x && st_x < b7_x && st_y >= b7_y && st_y <= b7_y + b_h && st_y + st_hw >= b7_y + b_h) || (st_x + st_hw > b7_x && st_x < b7_x      &&     b7_y >= st_y && b7_y <= st_y + st_hw  && st_y + st_hw <= b7_y + b_h))
				{
					b7_x = 3050;
					b7_y = 150;
					Lives++;
					printf("%d", Lives);
				}

				// 8th box
				draw(image3, b8_x + 20, b8_y + b_h, b_w, b_h);


				if (b8_x < 0)
				{
					b8_x = 4000;

				}
				b8_x = b8_x + (bdirection*bspeed);
				if (b8_x < 0)
				{
					bdirection = -1;
				}


				if ((st_x + st_hw > b8_x && st_x < b8_x && st_y >= b8_y && st_y <= b8_y + b_h && st_y + st_hw >= b8_y + b_h) || (st_x + st_hw > b8_x && st_x < b8_x      &&     b8_y >= st_y && b8_y <= st_y + st_hw  && st_y + st_hw <= b8_y + b_h))
				{
					b8_x = 4000;
					b8_y = 450;
					Lives--;
					printf("%d", Lives);
				}



				// 9th box
				draw(image7, b9_x + 20, b9_y + b_h, b_w, b_h);

				if (b9_x < 0)
				{
					b9_x = 1500;

				}
				b9_x = b9_x + (bdirection*bspeed);
				if (b9_x < 0)
				{
					bdirection = -1;
				}


				if ((st_x + st_hw > b9_x && st_x < b9_x && st_y >= b9_y && st_y <= b9_y + b_h && st_y + st_hw >= b9_y + b_h) || (st_x + st_hw > b9_x && st_x < b9_x      &&     b9_y >= st_y && b9_y <= st_y + st_hw  && st_y + st_hw <= b9_y + b_h))
				{
					b9_x = 1500;
					b9_y = 150;
					presents++;
					
					printf("%d", presents);
				}



				// 10th box
				draw(image10, b10_x + 20, b10_y + b_h, b_w, b_h);

				if (b10_x < 0)
				{
					b10_x = 2000;

				}
				b10_x = b10_x + (bdirection*bspeed);
				if (b10_x < 0)
				{
					bdirection = -1;
				}
				glEnd();

				if ((st_x + st_hw > b10_x && st_x < b10_x && st_y >= b10_y && st_y <= b10_y + b_h && st_y + st_hw >= b10_y + b_h) || (st_x + st_hw > b10_x && st_x < b10_x      &&     b10_y >= st_y && b10_y <= st_y + st_hw  && st_y + st_hw <= b10_y + b_h))
				{
					b10_x = 2000;
					b10_y = 550;
					Lives--;
					printf("%d", Lives);
				}

				// 11th box
				draw(image12, b11_x + 20, b11_y + b_h, b_w, b_h);

				if (b11_x < 0)
				{
					b11_x = 3000;

				}
				b11_x = b11_x + (bdirection*bspeed);
				if (b11_x < 0)
				{
					bdirection = -1;
				}
				glEnd();

				if ((st_x + st_hw > b11_x && st_x < b11_x && st_y >= b11_y && st_y <= b11_y + b_h && st_y + st_hw >= b11_y + b_h) || (st_x + st_hw > b11_x && st_x < b11_x      &&     b11_y >= st_y && b11_y <= st_y + st_hw  && st_y + st_hw <= b11_y + b_h))
				{
					b11_x = 3000;
					b11_y = 350;
					Lives--;
					printf("%d", Lives);
				}

				// 12th box
				draw(image13, b12_x + 20, b12_y + b_h, b_w, b_h);

				if (b12_x < 0)
				{
					b12_x = 3000;

				}
				b12_x = b12_x + (bdirection*bspeed);
				if (b12_x < 0)
				{
					bdirection = -1;
				}


				if ((st_x + st_hw > b12_x && st_x < b12_x && st_y >= b12_y && st_y <= b12_y + b_h && st_y + st_hw >= b12_y + b_h) || (st_x + st_hw > b12_x && st_x < b12_x      &&     b12_y >= st_y && b12_y <= st_y + st_hw  && st_y + st_hw <= b12_y + b_h))
				{
					b12_x = 3000;
					b12_y = 350;
					Lives--;
					printf("%d", Lives);
				}

				// 13th box
				draw(image17, b13_x + 20, b13_y + b_h, b_w, b_h);

				if (b13_x < 0)
				{
					b13_x = 3000;

				}
				b13_x = b13_x + (bdirection*bspeed);
				if (b13_x < 0)
				{
					bdirection = -1;
				}


				if ((st_x + st_hw > b13_x && st_x < b13_x && st_y >= b13_y && st_y <= b13_y + b_h && st_y + st_hw >= b13_y + b_h) || (st_x + st_hw > b13_x && st_x < b13_x && b13_y >= st_y && b13_y <= st_y + st_hw  && st_y + st_hw <= b13_y + b_h))
				{
					b13_x = 5000;
					b13_y = 110;
					Lives--;
					printf("%d", Lives);
				}
				/* Printing LIVES REMAINING */
				char score[5]; 
				renderBitmapString(10, 20, "Lives remaining:");
				renderBitmapString(150, 20, itoa(Lives, score, 10));

				/* Printing PRESENTS */
				char timer[7];
				renderBitmapString(10, 40, "Presents:");
				renderBitmapString(150, 40, itoa(presents, timer, 10));

				if (Lives == 0)
					over = 1; /* Loads FAIL Image */
				if (presents == 7)
					over = 2; /* Loads PASS Image */

			}
			else
			if (over == 1) /* Condtion to Load FAIL Image */
			{

				glClear(GL_COLOR_BUFFER_BIT);
				draw(image14, 0, 600, 800, 600);


			}
			else
			if (over == 2) /* Condtion to load PASS Image */
			{

				glClear(GL_COLOR_BUFFER_BIT);
				draw(image15, 0, 600, 800, 600);


			}
		}
	
	else
	if (start == 0 && help == 0) /* Drawing MENU */
	{
		draw(image1, 0, 600, 800, 600);


		glBegin(GL_POLYGON);
		glColor3f(0.5, 0.2, 0.9);

		glVertex2f(x_1, y_1);
		glVertex2f(x_1, y_1 + 40);
		glVertex2f(x_1 + 200, y_1 + 40);
		glVertex2f(x_1 + 200, y_1);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.5, 0.2, 0.9);

		glVertex2f(x_2, y_2);
		glVertex2f(x_2, y_2 + 40);
		glVertex2f(x_2 + 200, y_2 + 40);
		glVertex2f(x_2 + 200, y_2);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.5, 0.2, 0.9);

		glVertex2f(x_3, y_3);
		glVertex2f(x_3, y_3 + 40);
		glVertex2f(x_3 + 200, y_3 + 40);
		glVertex2f(x_3 + 200, y_3);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.8, 0.2, 0.4);

		glVertex2f(t_x1, t_y1);
		glVertex2f(t_x2, t_y2);
		glVertex2f(t_x3, t_y3);

		glEnd();
		glColor3f(1.0, 1.0, 0.0);
		renderBitmapString(380, 165, "PLAY");
		renderBitmapString(380, 315, "HELP");
		renderBitmapString(380, 465, "QUIT");


		glutSwapBuffers();
		printf("\n.");


	}
	else 
	if (help == 1) /* HELP Image */
	{
		draw(image16, 0, 600, 800, 600);

		glutSwapBuffers();
		printf("\n.");
	}
	

		glutSwapBuffers();

	}

	/* END */

