#include <stdio.h>

FILE *fp;
int input;
char text[600];
char key[3] = "10b";
int i = 0, k = 0;

int main()
{ 
    fp = fopen("secret.txt", "r");
    if (fp != NULL)
    {
      input = fgetc(fp);
      rewind(fp);
      while (input != EOF)
      {
	input = fgetc(fp);
	text[i] = (input + key[k]) % 256;	
	k++;
	i++;
	if (k == 3) k = 0;
      }
    }
    else
    {
      printf("\nError reading file!\n");
    }
    fclose(fp);
    fp = fopen("encripted.txt", "w");
    for (k = 0; k < i; k++)
    {
      fputc(text[k], fp);
    }
    
    fclose(fp);
    return 0;
}