#include "stdlib.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "C-turtle.h"

pid_t pID;
char sound[20] = "Data/sound.wav";

void Render();
void Keyboard(unsigned char key, int x, int y );

int main(int argc, char *argv[])
{
	int i;
	pID = fork();
	if(pID == 0){
		//child process
		while(!enterBool)
		{
			playSound(sound);
		}
	}else if(pID < 0){
		//failed to fork
		return;
	}
	//parent process
	glutInit(&argc, argv);
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
  	glutInitWindowSize(1024, 680);
  	glutCreateWindow("Tetris");
  
  	glEnable(GL_TEXTURE_2D);

  	gluPerspective(60, 1.5, 1, 200);
  	glTranslatef( 0, 0, -20 );
  	glutDisplayFunc(Render);
  
  	glutFullScreen();
  
  	glutKeyboardFunc(Keyboard);
  
	  LoadGLTextures();		
	
  	glutMainLoop();

	return 0;
}

void Render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3d(7, 7, 7);
	
  glBindTexture(GL_TEXTURE_2D, texture[0]);    
  glBegin(GL_QUADS);		                
    
  glTexCoord2f(0.0f, 0.0f); glVertex3f(-17.0f, -11.0f,  1.0f);	// Bottom Left Of The Texture and Quad
  glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -11.0f,  1.0f);	// Bottom Right Of The Texture and Quad
  glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  11.0f,  1.0f);	// Top Right Of The Texture and Quad
  glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.0f,  11.0f,  1.0f);	// Top Left Of The Texture and Quad

  glEnd();  
  
  int i;
  printMenu();
 
  if (enterBool == 1)  // if enter is pressed
  {
  	 for(i=0; i<30; i++) exitMenu(i);
    switch (optionTargeted)  // calls the functions for play, options, high scores and exit
    {
      case 0 :  
		printGl("Imagine the game starts now...", 8, -5);
	break;
      case 1 :  
		printGl("You are in options now, believe me!", 8, -5);
	break;
      case 2 :  
		printGl("You are the best, don't worry.", 8, -5);
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
    case 13 : enterBool = 1; kill(pID, SIGKILL);
      break;
  }
  if (optionTargeted < 0) optionTargeted = 3;
  if (optionTargeted > 3) optionTargeted = 0;
}