#include "C-turtle.h"
#include <GL/freeglut.h>
#include <string.h>

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

void printMenu(int optionTargeted)
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