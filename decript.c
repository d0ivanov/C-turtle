#include <stdio.h>

FILE *fp;
int input;
char text[600];
char key[3] = "10b";
int i = 0, k = 0, someInt;

int main()
{
  fp = fopen("encripted.txt", "r");
  if (fp != NULL)
  {
    input = fgetc(fp);
    rewind(fp);
    while (input != EOF)
    {
      input = fgetc(fp);
      someInt = input - key[k];
      if (someInt < 0) text[i] = 256 + someInt;
      else text[i] = (input - key[k]);
      k++;
      i++;
      if (k == 3) k = 0;
    }
  }
  fclose(fp);
  fp = fopen("message.txt", "w");
  for (k = 0; k < i - 2; k++)
  {
    fputc(text[k], fp);
  }
  
  fclose(fp);
  
  
  return 0;
}