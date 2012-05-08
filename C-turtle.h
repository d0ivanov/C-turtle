#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/* Image type - contains height, width, and data */
struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};

typedef struct Image Image;

extern int optionTargeted; // shows which option from the menu is targeted by the user
extern int enterBool; // boolean variable which shows if enter is pressed
extern int texture[4];
extern char* t;
	
	/*
	*	Loads image
	*	@arg char* filename - file to load
	*	@arg Image* image  
	*/
int ImageLoad(char *filename, Image *image);
	/*
	* ???
	*/
void LoadGLTextures();

	/*
	*	Prints string to screen
	*	string char* string to print
	*	float x x pos to start printing
	*	float y y pos to start printing
	*/
void printGl(char* string, float x, float y);

	/*
	*	Prints the menu using printGL() function.
	*/
void printMenu();	

	/*
	*	???
	*/
void exitMenu(int i);

	/*
	*	Play sound file
	*	@arg char* sound file name of sound file to play
	*/	
int playSound(char*);
	/*
	 *  Defines matrix fields with 0 or 1; Gets argument x and y for matrix width and height.
	 * Use like this: int ** matrix = defMatrix(x, y);
	 */

int **defMatrix(int x, int y);

#endif