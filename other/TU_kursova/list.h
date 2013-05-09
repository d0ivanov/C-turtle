#ifndef LIST_H
#define LIST_H

#include "video.h"

unsigned int list_errors = 0;

/* Error code, set when list creation unsuccessfull */
const unsigned int CREATE_ERROR = 1;
/* Error code, set when list push unsuccessfull */
const unsigned int PUSH_ERROR = 2;
/* Error code, set when list pop unsuccessfull */
const unsigned int POP_ERROR = 4;
/* Error code, set when walking through list unsuccessfull */
const unsigned int ITEM_ERROR = 8;

typedef struct
{
	t_video *next;
	t_video data;

} t_list_item;

/**
 * function: create_list
 * Initiates a new list
 * params:
 *	t_video* - data to be put in first element
 * errors: raise CREATE_ERROR flag if any errors occured
 * returns: < 0 on error > 0 on success
 */
int create_list(t_video*);

/**
 * function: push
 * Pushes new item at a certain position.
 * params:
 * 	t_video* - data to push
 * 	t_video* - position to push at, item will
 *						 be pushed after it.
 *  t_list_item* - list head
 * errors: raise PUSH_ERROR flag in any errors occured
 * returns: < 0 on error > 0 on success
 */
int push(t_list_item*, t_video*, t_video*);

/**
 * function: pop
 * 	Searches for an item and pops it.
 * params:
 *	t_video* - item to pop
 *  t_list_item - list head
 * errors: raise POP_ERROR flag if any errors occured
 * returns: < 0 on error, > 0 on success
 */
int pop(t_list_item*, t_video*);

/**
 * function: front
 * 	returns the first element of the list
 * params:
 *	t_list_item - list head
 * errors: raise ITEM_ERROR flag if any errors occured
 * returns: < 0 on error, > 0 on success
 */
t_video* front(t_list_item*);

/**
 * function: search
 *	Searches for a video
 * params:
 *	t_list_item* - list head
 *	t_video* - video to search for
 * errors: raise ITEM_ERROR if cannot access list head
 * returns: t_video* if video found, else null
 */
t_video* search(t_list_item*, t_video*);

/**
 * function: dump
 * 	Dumps all records
 * params:
 *  t_list_item* - list head
 *	pointer to print function, that will do the actual printing
 * errors: raises ITEM_ERROR flag when dumping failed
 * returns: < 0 on failure, > 0 on success
 */
int dump(t_list_item*, void (*print)(t_video*));

/**
 * function: list_size
 * 	returns the list size
 * params:
 *	t_list_item* - head of list
 * errors: raise ITEM_ERROR flag if any errors occured
 * returns: size of list, < 0 if errors occured
 */
int list_size(t_list_item*);

/**
 * function: error_handle
 * 	prints and handles errors
 * params: none
 * errors: none
 * returns: void
 */
void error_handle();

#endif
