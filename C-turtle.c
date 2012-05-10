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

	/*
	*	RATE - Frequency of audio playback
	*	FORMAT - Format of the audio we're playing
	*	CHANNELS - 2 channels = stereo
	*	BUFFERS - Size of the audio buffers in memory
	*/
#define RATE 22050
#define FORMAT AUDIO_S16SYS
#define CHANNELS 2
#define BUFFER 4096

int optionTargeted = 0; // shows which option from the menu is targeted by the user
int enterBool = 0; // boolean variable which shows if enter is pressed
int texture[4];
char *t;
	/*
	*	Loads image
	*	@arg char* filename - file to load
	*	@arg Image* image  
	*/
int ImageLoad(char *filename, Image *image)
{
FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1) 
    unsigned short int bpp;             // number of bits per pixel (must be 24)
    char temp;                          // temporary color storage for bgr-rgb conversion.

    // make sure the file is there.
    if ((file = fopen(filename, "rb"))==NULL)
    {
	printf("File Not Found : %s\n",filename);
	return 0;
    }
    
    image->sizeY = 0;
    image->sizeX = 0;

    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);

    // read the width
    if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
	printf("Error reading width from %s.\n", filename);
	return 0;
    }
    printf("Width of %s: %lu\n", filename, image->sizeX);
    
    // read the height 
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
	printf("Error reading height from %s.\n", filename);
	return 0;
    }
    printf("Height of %s: %lu\n", filename, image->sizeY);
    
    // calculate the size (assuming 24 bits or 3 bytes per pixel).
    size = image->sizeX * image->sizeY * 3;

    // read the planes
    if ((fread(&planes, 2, 1, file)) != 1) {
	printf("Error reading planes from %s.\n", filename);
	return 0;
    }
    if (planes != 1) {
	printf("Planes from %s is not 1: %u\n", filename, planes);
	return 0;
    }

    // read the bpp
    if ((i = fread(&bpp, 2, 1, file)) != 1) {
	printf("Error reading bpp from %s.\n", filename);
	return 0;
    }
    if (bpp != 24) {
	printf("Bpp from %s is not 24: %u\n", filename, bpp);
	return 0;
    }
	
    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);

    // read the data. 
    image->data = (char *) malloc(size);
    if (image->data == NULL) {
	printf("Error allocating memory for color-corrected image data");
	return 0;	
    }

    if ((i = fread(image->data, size, 1, file)) != 1) {
	printf("Error reading image data from %s.\n", filename);
	return 0;
    }
	
    for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
	temp = image->data[i];
	image->data[i] = image->data[i+2];
	image->data[i+2] = temp;
    }
    
    // we're done.
    return 1;
}


	/*
	* ???
	*/
void LoadGLTextures()
{
    Image *image1, *image2, *image3, *image4;
    
    // allocate space for texture
    image1 = (Image *) malloc(sizeof(Image));
    if (image1 == NULL) {
	printf("Error allocating space for image");
	exit(0);
    }

    if (!ImageLoad("Data/menu1.bmp", image1)) {
	exit(1);
    }        

    // Create Texture	
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);   // 2d texture (x and y size)

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture

    // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
    
//    ------------------------------------------------------------------------------------
    
    // allocate space for texture
    image2 = (Image *) malloc(sizeof(Image));
    if (image2 == NULL) {
	printf("Error allocating space for image");
	exit(0);
    }

    if (!ImageLoad("Data/menu2.bmp", image2)) {
	exit(1);
    }        

    // Create Texture	
    glGenTextures(1, &texture[1]);
    glBindTexture(GL_TEXTURE_2D, texture[1]);   // 2d texture (x and y size)

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture

    // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);
    
    
//    ------------------------------------------------------------------------------------
    
    // allocate space for texture
    image3 = (Image *) malloc(sizeof(Image));
    if (image3 == NULL) {
	printf("Error allocating space for image");
	exit(0);
    }

    if (!ImageLoad("Data/menu3.bmp", image3)) {
	exit(1);
    }        

    // Create Texture	
    glGenTextures(1, &texture[2]);
    glBindTexture(GL_TEXTURE_2D, texture[2]);   // 2d texture (x and y size)

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture

    // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image3->sizeX, image3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image3->data);
    
    
//    ------------------------------------------------------------------------------------
    
    // allocate space for texture
    image4 = (Image *) malloc(sizeof(Image));
    if (image4 == NULL) {
	printf("Error allocating space for image");
	exit(0);
    }

    if (!ImageLoad("Data/menu4.bmp", image4)) {
	exit(1);
    }        

    // Create Texture	
    glGenTextures(1, &texture[3]);
    glBindTexture(GL_TEXTURE_2D, texture[3]);   // 2d texture (x and y size)

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture

    // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image4->sizeX, image4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image4->data);
}

	/*
	*	Prints string to screen
	*	string char* string to print
	*	float x x pos to start printing
	*	float y y pos to start printing
	*/
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

	/*
	*	Prints out the menu
	*/
void printMenu()
{
   if (optionTargeted == 0) 
  	{  		
  		glBindTexture(GL_TEXTURE_2D, texture[optionTargeted]);    
  		glBegin(GL_QUADS);		                
    
		  glTexCoord2f(0.0f, 0.0f); glVertex3f(-17.0f, -11.0f,  1.0f);	// Bottom Left Of The Texture and Quad
		  glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -11.0f,  1.0f);	// Bottom Right Of The Texture and Quad
		  glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  11.0f,  1.0f);	// Top Right Of The Texture and Quad
		  glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.0f,  11.0f,  1.0f);	// Top Left Of The Texture and Quad

  		glEnd();  
                t = GLUT_BITMAP_TIMES_ROMAN_24;
  		glColor3d(1, 0, 0);
		printGl("~> Play <~", 11.6, 5);  
                		
  	}
    else 
	{
                t = GLUT_BITMAP_HELVETICA_18;
		glColor3d(7, 7, 7);
  		printGl("Play", 12.4, 5);
	}
  
  if (optionTargeted == 1) 
  	{  		
  		glBindTexture(GL_TEXTURE_2D, texture[optionTargeted]);    
  		glBegin(GL_QUADS);		                
    
		  glTexCoord2f(0.0f, 0.0f); glVertex3f(-17.0f, -11.0f,  1.0f);	// Bottom Left Of The Texture and Quad
		  glTexCoord2f(1.0f, 0.0f); glVertex3f( 08.0f, -11.0f,  1.0f);	// Bottom Right Of The Texture and Quad
		  glTexCoord2f(1.0f, 1.0f); glVertex3f( 08.0f,  11.0f,  1.0f);	// Top Right Of The Texture and Quad
		  glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.0f,  11.0f,  1.0f);	// Top Left Of The Texture and Quad
    
  		glEnd(); 
                t = GLUT_BITMAP_TIMES_ROMAN_24; 
  		glColor3d(1, 0, 0);
		printGl("~> Options <~", 11.2, 3);  	
  	}
    else 
	{
                t = GLUT_BITMAP_HELVETICA_18;
		glColor3d(7, 7, 7);
		printGl("Options", 12, 3);
	}  

  if (optionTargeted == 2) 
  	{  		
  		glBindTexture(GL_TEXTURE_2D, texture[optionTargeted]);    
  		glBegin(GL_QUADS);		                
    
		  glTexCoord2f(0.0f, 0.0f); glVertex3f(-17.0f, -11.0f,  1.0f);	// Bottom Left Of The Texture and Quad
		  glTexCoord2f(1.0f, 0.0f); glVertex3f( 07.1f, -11.0f,  1.0f);	// Bottom Right Of The Texture and Quad
		  glTexCoord2f(1.0f, 1.0f); glVertex3f( 07.1f,  11.0f,  1.0f);	// Top Right Of The Texture and Quad
		  glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.0f,  11.0f,  1.0f);	// Top Left Of The Texture and Quad

  		glEnd(); 
                t = GLUT_BITMAP_TIMES_ROMAN_24; 
  		glColor3d(1, 0, 0);
		printGl("~> High scores <~", 10.8, 1);  	
  	}
    else 
	{
                t = GLUT_BITMAP_HELVETICA_18;
		glColor3d(7, 7, 7);
  		printGl("High scores", 11.6, 1);
  	}

  if (optionTargeted == 3) 
  	{  		
  		glBindTexture(GL_TEXTURE_2D, texture[0]);    
  		glBegin(GL_QUADS);		                
    
		  glTexCoord2f(0.0f, 0.0f); glVertex3f(-17.0f, -11.0f,  1.0f);	// Bottom Left Of The Texture and Quad
		  glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -11.0f,  1.0f);	// Bottom Right Of The Texture and Quad
		  glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  11.0f,  1.0f);	// Top Right Of The Texture and Quad
		  glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.0f,  11.0f,  1.0f);	// Top Left Of The Texture and Quad

  		glEnd();
                t = GLUT_BITMAP_TIMES_ROMAN_24; 
  		glColor3d(1, 0, 0);
		printGl("~> Exit <~", 11.6, -1); 	
  	}
    else 
	{
                t = GLUT_BITMAP_HELVETICA_18;
		glColor3d(7, 7, 7);
		printGl("Exit", 12.4, -1);
	}
}	

	/*
	*	???
	*/
void exitMenu(int i)
{
float j, k, n;
  char sl[60]="~>";
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3d(7, 7, 7);

  glBindTexture(GL_TEXTURE_2D, texture[0]);    
  glBegin(GL_QUADS);		                
   
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-17.0f, -11.0f,  1.0f);	// Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -11.0f,  1.0f);	// Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  11.0f,  1.0f);	// Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.0f,  11.0f,  1.0f);	// Top Left Of The Texture and Quad

  glEnd();

    switch (optionTargeted)
    {
      case 0 :  k=i/10;
		j=12.4+k;
		n=5.0;
		glColor3d(7, 7, 7);
		printGl("Options", 12, 3);
		printGl("High scores", 11.6, 1);
		printGl("Exit", 12.4, -1);
	break;
      case 1 :  k=i/10;
		j=12+k;
		n=3.0;
		glColor3d(7, 7, 7);
		printGl("Play", 12.4, 5);
		printGl("High scores", 11.6, 1);
		printGl("Exit", 12.4, -1);
	break;
      case 2 :  k=i/10;
		j=11.6+k;
		n=1.0;
		glColor3d(7, 7, 7);
		printGl("Options", 12, 3);
		printGl("Play", 12.4, 5);
		printGl("Exit", 12.4, -1);
	break;
    }
    glColor3d(1, 0, 0);
    printGl(sl, j, n);
}
	/*
	*	Loads and plays sound file
	*	@arg char* soundName
	*/
int playSound(char *soundName)
{
	Mix_Chunk *sound = NULL;		//Pointer to our sound, in memory
	int channel;				//Channel on which our sound is played
	
	//Initialize SDL audio
	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	
	//Initialize SDL_mixer with our chosen audio settings
	if(Mix_OpenAudio(RATE, FORMAT, CHANNELS, BUFFER) != 0) {
		printf("Unable to initialize audio: %s\n", Mix_GetError());
		return 1;
	}
	
	//Load our WAV file from disk
	sound = Mix_LoadWAV(soundName);
	if(sound == NULL) {
		return 1;
	}
	
	//Play our sound file, and capture the channel on which it is played
	channel = Mix_PlayChannel(-1, sound, 0);
	if(channel == -1) {
		return 1;
	}
	
	//Wait until the sound has stopped playing
	while(Mix_Playing(channel) != 0);
	
	//Release the memory allocated to our sound
	Mix_FreeChunk(sound);
	
	//Need to make sure that SDL_mixer and SDL have a chance to clean up
	Mix_CloseAudio();
	SDL_Quit();	
	
	//Return success!
	return 0;
}

void defMatrix(int x, int y, int ***matrix) // x - width, y - height of matrix
{
  int row, column, i;
  int ** temp = (int **)malloc(sizeof(int *) * x); // allocating memory for x
  
  for (i = 0; i < x; i++)
  {
    temp[i]= (int *) malloc(y * sizeof(int)); // allocating y*sizeof(int) for every x
  }
  *matrix = temp;
  
  for (row = 0; row < x; row++)
  {
    for (column = 0; column < y; column++)
    {
      (*matrix)[row][column] = 0; // define every element of the matrix with 0
    }
  }
}

void showUp(int score) 
{
  static int cover = 11;
  
  glBegin(GL_QUADS); // drawing plane which hides the pic
  
    glVertex3f(-17.0f, cover-22, 2.01f);
    glVertex3f( 10.0f, cover-22, 2.01f);
    glVertex3f( 10.0f,    cover, 2.01f);
    glVertex3f(-17.0f,    cover, 2.01f);
  
  glEnd();
  
  if ((score % 10) == 0)
  {
    cover++;
  }
}

int rotateObjectCheck(Object rotateThisObject, int ***matrix)
{
  int i;
  int container;
  Object ObjectCopy = rotateThisObject;
  
  switch (ObjectCopy.numElements)
  {
    case 3 : // Rotate the copy object
	     for (i = 0; i <= ObjectCopy.numElements - 2; i++)
	     {
	       ObjectCopy.otherPos[0][i] -= ObjectCopy.centerPos[0];
	       ObjectCopy.otherPos[1][i] -= ObjectCopy.centerPos[1];
	     }
      
	     for (i = 0; i <= ObjectCopy.numElements - 2; i++)
	     {
	       container = ObjectCopy.otherPos[0][i];
	       ObjectCopy.otherPos[0][i] = -1 * ObjectCopy.otherPos[1][i];
	       ObjectCopy.otherPos[1][i] = container;
	     }
	     for (i = 0; i <= ObjectCopy.numElements - 2; i++)
	     {
	       ObjectCopy.otherPos[0][i] += ObjectCopy.centerPos[0];
	       ObjectCopy.otherPos[1][i] += ObjectCopy.centerPos[1];
	     }
	     
	     // Check for matches
	    
	     /* if matrix field with coordiantes == coordinates of this squere,
     	      * then return 1 - match found
	      */
	    
	     for (i = 0; i <= ObjectCopy.numElements - 2; i++)
	     {
	       if ((*matrix)[ObjectCopy.otherPos[0][i]][ObjectCopy.otherPos[1][i]] == 1) return 1;
	     }
	     
      break;
    case 4 : for (i = 0; i < ObjectCopy.numElements - 1; i++)
	     {
	       ObjectCopy.otherPos[0][i] -= ObjectCopy.centerPos[0];
	       ObjectCopy.otherPos[1][i] -= ObjectCopy.centerPos[1];
	     }
      
	     for (i = 0; i < ObjectCopy.numElements - 1; i++)
	     {
	       container = ObjectCopy.otherPos[0][i];
	       ObjectCopy.otherPos[0][i] = -1 * ObjectCopy.otherPos[1][i];
	       ObjectCopy.otherPos[1][i] = container;
	     }
	     for (i = 0; i < ObjectCopy.numElements - 1; i++)
	     {
	       ObjectCopy.otherPos[0][i] += ObjectCopy.centerPos[0];
	       ObjectCopy.otherPos[1][i] += ObjectCopy.centerPos[1];
	     }
	     
	     // Check for matches
	    
	     /* if matrix field with coordiantes == coord of this squere,
     	      * then return 1 - match found
	      */
	    
	     for (i = 0; i <= ObjectCopy.numElements - 1; i++)
	     {
	       if ((*matrix)[ObjectCopy.otherPos[0][i]][ObjectCopy.otherPos[1][i]] == 1) return 1;
	     }
      break;
  }
  
  return 0; // if there are no matches
}

Object rotateObject(Object rotateThisObject, int ***matrix)
{
  int i;
  int container;
  
  if (rotateThisObject.type == 2) return rotateThisObject;
  
  if (rotateObjectCheck(rotateThisObject, matrix) == 1) return rotateThisObject; 
  
  switch (rotateThisObject.numElements)
  {
    case 3 : for (i = 0; i <= rotateThisObject.numElements - 2; i++)
	     {
	       rotateThisObject.otherPos[0][i] -= rotateThisObject.centerPos[0];
	       rotateThisObject.otherPos[1][i] -= rotateThisObject.centerPos[1];
	     }
      
	     for (i = 0; i <= rotateThisObject.numElements - 2; i++)
	     {
	       container = rotateThisObject.otherPos[0][i];
	       rotateThisObject.otherPos[0][i] = -1 * rotateThisObject.otherPos[1][i];
	       rotateThisObject.otherPos[1][i] = container;
	     }
	     for (i = 0; i <= rotateThisObject.numElements - 2; i++)
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