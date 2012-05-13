#include <stdio.h> // vkluchvame bibliotekata za rabota sus standarten vhod izhod
#include <stdlib.h> // za vseki sluchai
#include <string.h> // biblioteka za rabota sys stringove

char string[300], symbol; // string-text-a, symbol simvola, koito se tyrsi
int foundNum = 0, length = 0; // duljina i dali e nameren

void inputString(); // vuvejdane na string
void inputSymbol(); // vyvejdane na simvola, koito se tyrsi
void workWithString(); //rabota s stringa
void searchSymbol(); // tyrsi simvola

int main()
{
  char key;
  
  printf("\n");
  printf("Press 1 to add a string.\n");
  printf("Press 2 to add symbol.\n");
  printf("Press 3 to append to the string.\n");
  printf("Press 4 to find how often your symbol is used in the text.\n");
  printf("\n");
  printf("Press 5 to exit.\n");
  printf("\n");
 
  while(1)
  {
    printf("Choose option from the menu: ");
    key = getchar(); // chetem izbora na potrebitelq
    
    // izvikvame funkciq v zavisimost ot izbora na potrebitelq
    switch(key)
    {
      case 49 : inputString();
	break;
      case 50 : inputSymbol();
	break;
      case 51 : workWithString();
		printf("Your text is now: ");
		printf("%s\n", string);
	break;
      case 52 : searchSymbol();
	break;
      case 53 : return 0;
	break;
    }
  }
  
  return 0;
}

void inputString()
{
  getchar(); // za da ne chete enter-a ot ot menu-to i da smqta che e za gets
  printf("Write text: ");
  
  gets(string); // chete stringa
  length = strlen(string); // vzimame duljinata na stringa
}

void inputSymbol()
{
  getchar(); // -||-
  printf("Enter symbol: ");
  
  symbol = getchar(); // chetem simvola
  getchar();
}

void workWithString()
{
  char string2[100]; // deklarirame wtori string
  
  getchar(); //-||-
  
  printf("Enter text to append: ");
  gets(string2); // chetem stringa
  strcat(string, string2);  // append-vame string2 kym kraq na string
}

void searchSymbol()
{
  int i;
  foundNum = 0;
  
  // cikul, koito gleda kolko puti simvola e vuveden v texta
  for (i = 0; i < length - 1; i++)
  {
    if (string[i] == symbol) foundNum++;
  }
  
  printf("Symbol \"%c\" is found %d times in your text.\n", symbol, foundNum); // izkarvame rezultata
  getchar();
}
