#include <stdio.h>
#include <GL/freeglut.h>

typedef struct
{
  int type;
  int numElements;
  int centerPos[2];
  int otherPos[2][3];
} Object;

Object Object_1;
int rotate = 0;  // show direction of object 0-not rotated 1-90 2-180 3-270 4=0

void Render();
void drawObject(Object);
void drawSquare(int, int);
Object getValue(int, int, int);
void Keyboard(unsigned char key, int x, int y );
Object rotateObject(Object);

int main(int argc, char *argv[])
{
  Object_1 = getValue(3, 0, 0); // default properties of element of type 3 with position x=0 y=0
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
  glutInitWindowSize(1024, 680);
  glutCreateWindow("C-turtle Rotate");

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
  glColor3d(7,7,7);
  
  drawObject(Object_1);
  
  glutSwapBuffers(); 
  glutPostRedisplay();
}

Object getValue(int value, int posX, int posY)  // value -number of type eg. 3 for L-typed element with 4 elements
{
  Object returnObject;
  switch(value) 
  {
    case 0 : returnObject.centerPos[0] = posX; // line 1x3
	     returnObject.centerPos[1] = posY;
	     returnObject.numElements = 3;
	     returnObject.type = 0;
	     
	     returnObject.otherPos[0][0] = posX; // top
	     returnObject.otherPos[1][0] = posY - 2;
	     
	     returnObject.otherPos[0][1] = posX; // bot
	     returnObject.otherPos[1][1] = posY + 2;
      break;
    case 1 : returnObject.centerPos[0] = posX;  // L-typed element with 3 blocks
	     returnObject.centerPos[1] = posY;
	     returnObject.numElements = 3;
	     returnObject.type = 1;
	     
	     returnObject.otherPos[0][0] = posX; // top
	     returnObject.otherPos[1][0] = posY - 2;
	     
	     returnObject.otherPos[0][1] = posX + 2; // bot right
	     returnObject.otherPos[1][1] = posY;
      break;
    case 2 : returnObject.centerPos[0] = posX;  // cube 4x4 
	     returnObject.centerPos[1] = posY;
	     returnObject.numElements = 4;
	     returnObject.type = 2;
	     
	     returnObject.otherPos[0][0] = posX - 2; // top left
	     returnObject.otherPos[1][0] = posY - 2;
	     
	     returnObject.otherPos[0][1] = posX; // top right
	     returnObject.otherPos[1][1] = posY - 2;
	     
	     returnObject.otherPos[0][2] = posX - 2; // bot left
	     returnObject.otherPos[1][2] = posY;
      break;
    case 3 : returnObject.centerPos[0] = posX; // L-typed element with 4 blocks
	     returnObject.centerPos[1] = posY;
	     returnObject.numElements = 4;
	     returnObject.type = 3;
	     
	     returnObject.otherPos[0][0] = posX; // top
	     returnObject.otherPos[1][0] = posY + 4;
	     
	     returnObject.otherPos[0][1] = posX; // mid
	     returnObject.otherPos[1][1] = posY + 2;
	     
	     returnObject.otherPos[0][2] = posX + 2; // bot right
	     returnObject.otherPos[1][2] = posY;
      break;
    case 4 : returnObject.centerPos[0] = posX; // S-typed element with 4 blocks 
	     returnObject.centerPos[1] = posY;
	     returnObject.numElements = 4;
	     returnObject.type = 4;
	     
	     returnObject.otherPos[0][0] = posX; // top left
	     returnObject.otherPos[1][0] = posY - 2;
	     
	     returnObject.otherPos[0][1] = posX + 2; // top right
	     returnObject.otherPos[1][1] = posY - 2;
	     
	     returnObject.otherPos[0][2] = posX - 2; // bot left
	     returnObject.otherPos[1][2] = posY;
      break;
  }
  return returnObject;
}

void drawObject(Object draw)
{ 
  if (rotate != 0)
  {
    switch (rotate)
    {
      case 1 : draw = rotateObject(draw);
	     break;
      case 2 : draw = rotateObject(draw);
	       draw = rotateObject(draw);
	break;
      case 3 : draw = rotateObject(draw);
	       draw = rotateObject(draw);
	       draw = rotateObject(draw);
	break;
      case 4: draw = rotateObject(draw);
	      draw = rotateObject(draw);
	      draw = rotateObject(draw);
	break;
    }
  }
  if (rotate == 4) rotate = 0;
  switch (draw.type)
  {
    case 0 : 
    case 1 : drawSquare(draw.centerPos[0], draw.centerPos[1]);
	     drawSquare(draw.otherPos[0][0], draw.otherPos[1][0]);
	     drawSquare(draw.otherPos[0][1], draw.otherPos[1][1]);
      break;
    case 2 : 
    case 3 : 
    case 4 : drawSquare(draw.centerPos[0], draw.centerPos[1]);
	     drawSquare(draw.otherPos[0][0], draw.otherPos[1][0]);
	     drawSquare(draw.otherPos[0][1], draw.otherPos[1][1]);
	     drawSquare(draw.otherPos[0][2], draw.otherPos[1][2]);
      break;
  }
}

void drawSquare(int posX, int posY)
{
  glBegin(GL_LINES);
    
    glVertex3d(posX - 1, posY - 1, 0);
    glVertex3d(posX + 1, posY - 1, 0);
    
    glVertex3d(posX + 1, posY - 1, 0);
    glVertex3d(posX + 1, posY + 1, 0);
    
    glVertex3d(posX + 1, posY + 1, 0);
    glVertex3d(posX - 1, posY + 1, 0);
    
    glVertex3d(posX - 1, posY + 1, 0);
    glVertex3d(posX - 1, posY - 1, 0);
    
  glEnd();
}

void Keyboard(unsigned char key, int x, int y )
{
	switch(key)
	{
	case 49 : rotate++;
		break;
	}
}

Object rotateObject(Object rotateThisObject)
{
  int i;
  int container;
  
  switch (rotateThisObject.numElements)
  {
    case 3 : for (i = 0; i < rotateThisObject.numElements - 2; i++)
	     {
	       rotateThisObject.otherPos[0][i] -= rotateThisObject.centerPos[0];
	       rotateThisObject.otherPos[1][i] -= rotateThisObject.centerPos[1];
	     }
      
	     for (i = 0; i < rotateThisObject.numElements - 2; i++)
	     {
	       container = rotateThisObject.otherPos[0][i];
	       rotateThisObject.otherPos[0][i] = -1 * rotateThisObject.otherPos[1][i];
	       rotateThisObject.otherPos[1][i] = container;
	     }
	     for (i = 0; i < rotateThisObject.numElements - 2; i++)
	     {
	       rotateThisObject.otherPos[0][i] += rotateThisObject.centerPos[0];
	       rotateThisObject.otherPos[1][i] += rotateThisObject.centerPos[1];
	     }
      break;
    case 4 : for (i = 0; i < rotateThisObject.numElements - 1; i++)
	     {
	       rotateThisObject.otherPos[0][i] -= rotateThisObject.centerPos[0];
	       rotateThisObject.otherPos[1][i] -= rotateThisObject.centerPos[1];
	     }
      
	     for (i = 0; i < rotateThisObject.numElements - 1; i++)
	     {
	       container = rotateThisObject.otherPos[0][i];
	       rotateThisObject.otherPos[0][i] = -1 * rotateThisObject.otherPos[1][i];
	       rotateThisObject.otherPos[1][i] = container;
	     }
	     for (i = 0; i < rotateThisObject.numElements - 1; i++)
	     {
	       rotateThisObject.otherPos[0][i] += rotateThisObject.centerPos[0];
	       rotateThisObject.otherPos[1][i] += rotateThisObject.centerPos[1];
	     }
      break;
  }
  return rotateThisObject;
}
