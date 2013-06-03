#ifndef VIDEO_H
#define VIDEO_H


/* video errors */
unsigned int video_errors = 0;
/* error flag, raised when writing to fle failed */
const unsigned int WRITE_ERROR = 1;
/* error flag, raised when editing item failed */
const unsigned int EDIT_ERROR = 2;
/* error flag, raised when reading video fails */
const unsigned int VIDEO_RERROR = 4;

typedef struct
{
	long int id;
	char[50] title;
	char[50] director;
	float length;
	int year;
} t_video;

/**
 * function: to_file
 * 	Writes data to binary file
 * params:
 *	t_list_item* - head of list to be written
 *  char* - file path to write to
 * errors: raises WRITE_ERROR flag when writing failed
 *				 or file does not exist
 * returns: < 0 on failure, > 0 on success
 */
int to_file(t_list_item*, char*);

/**
 * function: edit_video
 * 	Edits a video record
 * params:
 *  t_list_item* - list head
 *	t_video* - record to be edited
 * errors: raises EDIT_ERROR flag when editing failed
 * returns: < 0 on failure, > 0 on success
 */
int edit_video(t_list_item*, t_video*);

/**
 * function: delete_video
 * 	Deletes a video record
 * params:
 *  t_list_item* - list head
 *	t_video* - record to be deleted
 * errors: raises EDIT_ERROR flag when editing failed
 * returns: < 0 on failure, > 0 on success
 */
int delete_video(t_list_item*, t_video*);

/**
 * function: print
 * 	Print a video record
 * params:
 *  t_video* - video to be printed
 * errors: raises VIDEO_ERROR flag when dumping failed
 * returns: void
 */
void print(t_video*);

#endif
