#include <stdio.h>
#include <string.h>
#include <GL/freeglut.h>

void Render();
void Keyboard(unsigned char key, int x, int y );
void printGl(char *, float, float);
void printMenu();

int optionTargeted = 0; // shows which option from the menu is targeted by the user
int enterBool; // boolean variable which shows if enter is pressed

int main(int argc, char *argv[])
{
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
  glutInitWindowSize(1024, 680);
  glutCreateWindow("Tetris");

  gluPerspective(60, 1.5, 1, 200);
  glTranslatef( 0, 0, -20 );
  glutDisplayFunc(Render);
  
  glutKeyboardFunc(Keyboard);
  
  glutMainLoop();
  
  return 0;
}

void Render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3d(7, 7, 7);
  
  printMenu();
  if (enterBool == 1)  // if enter is pressed
  {
    switch (optionTargeted)  // calls the functions for play, options, high scores and exit
    {
      case 0 : printGl("Imagine the game starts now...", -3, -5);
	break;
      case 1 : printGl("You are in options now, believe me!", -3, -5);
	break;
      case 2 : printGl("You are the best, don't worry.", -3, -5);
	break;
      case 3 : exit(0);
	break;
    }
  }
  
  glutSwapBuffers(); 
  glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y )
{	
  enterBool = 0;
  switch(key)
  {
    case 'w' : 
    case 'W' : optionTargeted--;  // move up in the menu
      break;
    case 's' : 
    case 'S' : optionTargeted++;  // move down in the menu
      break;
    case 13 : enterBool = 1;
      break;
  }
  if (optionTargeted < 0) optionTargeted = 3;
  if (optionTargeted > 3) optionTargeted = 0;
}

void printGl(char* string, float x, float y)
{
  glRasterPos2f(x, y);
  
  int stringLen = strlen(string);
  int i;
  for (i = 0; i < stringLen; ++i)
  {
    char ch = string[i];
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , ch);
  }
}

void printMenu()
{
  if (optionTargeted == 0) glColor3d(1, 1, 0);
    else glColor3d(7, 7, 7);
  printGl("Play", 0, 5);
  if (optionTargeted == 1) glColor3d(1, 1, 0);
    else glColor3d(7, 7, 7);
  printGl("Options", -0.5, 3);
  if (optionTargeted == 2) glColor3d(1, 1, 0);
    else glColor3d(7, 7, 7);
  printGl("High scores", -1.2, 1);
  if (optionTargeted == 3) glColor3d(1, 1, 0);
    else glColor3d(7, 7, 7);
  printGl("Exit", 0, -1);
}

