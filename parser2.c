// .obj to .h parser, by Mihail Zdravkov
// Date 11. 01. 2012


// To convert an .obj file to .h just copy the .obj file to the filder whre this file is. 
// Then open the obj file with wordpad and delete the first few lines where writes info about the object(so there is 1 line empty before all) 
// Then look how many vertices, normals and faces you have and enter them where #defines are. 
// You will have to multiplicate them ( vertice x3, normals x3, faces x6 ).
// change the strings of #defines to the appropriate names ( #define OBJ_NAME "xxxx.obj", #define H_NAME "xxxx.h" ).



#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTICES 45       // number of vertices x3 
#define NUM_NORMALS 54        // number of normals x3
#define NUM_FACES 156          // number of faces x6

#define STRING_NUM_FACES "78" // number of faces x6 inside ""

#define OBJ_NAME "pyramid2.obj"   // .obj file name (with extension)
#define H_NAME "pyramid2.h"       // .h file name (with extension)
#define NAME "pyramid2"           // just the name, without extension



int vertices[NUM_VERTICES];
int normals[NUM_NORMALS];
int faces[NUM_FACES];
char wor_array[];

int main()
{
    
    long int i, w = 0, r, k = 0; // k = broikata na elementite v wor_array
    char ch;
    FILE *fp;   
    int boolean = 0;
 
    // ####### Writing data from .obj to an array #######
 
    fp = fopen( OBJ_NAME, "r");  // ### Opens the .obj file ( here you must change the file name ) 
    
    ch = fgetc( fp );
     while ( ch != EOF)
     {
           ch = fgetc( fp );
           //system("pause"); printf( "w%d\n", w );
           if ( ch == 'v' || ch == 'f' )  // ako e 'v' (ili vn) (v- vertex, vn - normal) f- faces
           {
              while( ch != '\n' )  // do kraq na reda
              {
                     ch = fgetc( fp );      
                     while ( ( ch >= '0' && ch <= '9' ) || ch == '.' || ch == '-') 
                     {
                           wor_array[w] = ch;
                           w++;
                           ch = fgetc( fp );    
                           boolean = 1;                          
                     }      
                     if ( boolean == 1 ) 
                     {
                          wor_array[w] = '#';
                          w++;
                     }
                     boolean = 0;                       
                     
              } 
                    
           }   
     }   
     
     fclose( fp );              
     
     // ####### Output the data #######
     
     printf( "#############################################");
     printf( "\n\n####### .obj to .h parser version 1.0 #######\n\n" );
     printf( "#############################################\n\n" );
     printf( " Your .obj ("); 
     printf( OBJ_NAME ); 
     printf( ") has " );
     printf( "%d", NUM_VERTICES/3 );
     printf( " vertices, " );
     printf( "%d", NUM_NORMALS/3 );
     printf( " normals, " );
     printf( "%d", NUM_FACES/6 );
     printf( " faces:" );
    
    int j = 0; // j - za da slaga po 3 na red
    int boolean2 = 0;
    i = 0;
    boolean = 0;
    ch = wor_array[i];
    printf( "\n\n ### VERTICES ### \n\n" );
     while( ch != '\0' )
     {
         ch = wor_array[i];
         if ( ch != '#' ) 
         {
              printf( "%c", ch );
         }else if ( boolean2 != 1 )
               {
                  j++;
                  printf( "   " );
                  if ( j == 3 )
                  {
                       printf( "\n" );
                       j = 0;
                  }
                  k++;    
               }else
               {
                    j++;
                    if ( j == 1 || j == 3 || j == 5 ) printf( "//" );
                    if ( j == 2 || j == 4 ) printf( " " );
                    if ( j == 6 )
                    {
                         printf( "\n" );
                         j = 0;
                    }
                    k++;                  
               }               
               
         if ( k == NUM_VERTICES && boolean == 0 ) 
         {
              printf( "\n ### NORMALS ### \n\n" );
              boolean = 1;
         }
         if ( k == NUM_NORMALS + NUM_VERTICES && boolean2  == 0 )
         {
              printf( "\n ### FACES ### \n\n" );
              boolean2 = 1;                  
         }
         i++;
     }
     printf( "\n\n To make the .h file " );
     system("pause");
     
     // ####### MAKES .h FILE #######
     
     fp = fopen( H_NAME, "w");  // creates the .h file
     
     // vertices
     
     fprintf( fp, "double " );
     fprintf( fp, NAME );
     fprintf( fp, "_vertices[] = {");
     r = 0;
     i = 0;
     while ( r < NUM_VERTICES)
     {
         ch = wor_array[i];
         if ( ch == '#' )
         {
            
              r++;
              if ( r < NUM_VERTICES )
              {
                   fputc( ',', fp );
              }
              else
              { 
                  fputc( '}', fp );
                  fputc( ';', fp );
              }
              
         }
         else
         {
             fputc( ch, fp );
         }
         i++;
     }
     
     // normals
     
     fprintf( fp, "\ndouble " );
     fprintf( fp, NAME );
     fprintf( fp, "_normals[] = {");
     r = 0;
     while ( r < NUM_NORMALS)
     {
         ch = wor_array[i];
         if ( ch == '#' )
         {
            
              r++;
              if ( r < NUM_NORMALS )
              {
                   fputc( ',', fp );
              }
              else
              { 
                  fputc( '}', fp );
                  fputc( ';', fp );
              }
              
         }
         else
         {
             fputc( ch, fp );
         }
         i++;
     }     
     
     // faces
     
     fprintf( fp, "\nint " );
     fprintf( fp, NAME );
     fprintf( fp, "_faces[] = {");
     r = 0;
     while ( r < NUM_FACES)
     {
         ch = wor_array[i];
         if ( ch == '#' )
         {
            
              r++;
              if ( r < NUM_FACES )
              {
                   fputc( ',', fp );
              }
              else
              { 
                  fputc( '}', fp );
                  fputc( ';', fp );
              }
              
         }
         else
         {
             fputc( ch, fp );
         }
         i++;
     }
             
     fprintf( fp, "\nint " );
     fprintf( fp, NAME );    
     fprintf( fp, "_NUM_FACES = " );
     fprintf( fp, STRING_NUM_FACES );
     fprintf( fp, ";" );            
                 
     fclose ( fp );
     
     printf( "\n\nYour .obj file was succesfully parsed to .h file - " H_NAME "\n " );
     printf( "\nYou can find your .h file in the instalation folder of .obj to .h parser \n\n" );
     
     system("pause");  
}        
