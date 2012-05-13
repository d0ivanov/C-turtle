#include <stdio.h> // vkluchvame bibliotekata za rabota sus standarten vhod izhod
#include <stdlib.h> // za vseki sluchai
#include <string.h> // biblioteka za rabota sys stringove

char string[300], symbol[7]; // string- texta, symbol - masiv sys simvolite koito sa krai na izrechenieto.
int sentence_length[21], text_length = 0, symbol_num = 0, sentence_num = 0, average_length = 0; // promenlivi za dyljini i broi

void dobavi_string(); // dobavq string
void dobavi_simvol(); // dobavq simvol kum masiva sys simvolite
void rabota_s_texta(); // obrabotka na texta (delene na izrecheniq, duljinata im i tn...

int main()
{
  char key; // za chetene na izbora na potrebitelq
  
  printf("\n");
  printf("Natisni 1 za da vuvedesh tekst.\n");
  printf("Natisni 2 za da vuvedesh simvol za krai na izrechenieto.\n");
  printf("Natisni 3 za da razbersh kolko izrecheniq ima teksta ti i kolko sa dylgi.\n");
  printf("\n");
  printf("Natisni 4 za da izleznesh.\n");
  printf("\n");
 
  while(1)
  {
    printf("Izberi opciq: ");
    key = getchar(); // chete ot klaviaturata
   
    // vikami funkciite v zavisimost ot izbora na potrebitelq
    switch(key)
    {
      case 49 : dobavi_string(); 
	break;
      case 50 : dobavi_simvol();
	break;
      case 51 : rabota_s_texta();
	break;
      case 52 : return;
	break;
    }
  }
  
  return 0;
}

void dobavi_string()
{
  getchar(); // za da ne chete enter-a ot ot menu-to i da smqta che e za gets
  printf("Napishi tekst: ");
  
  gets(string); // chete string
  text_length = strlen(string); // vzimame dyljinata na stringa
}

void dobavi_simvol()
{
  getchar(); // - || -
  printf("Napishi simvol: ");
  
  symbol[symbol_num] = getchar();// chetem simvola
  symbol_num++; // uvelichavame promenlivata, koqto pazi broq na simvolite
  getchar();
}

void rabota_s_texta()
{
  int i, k, j = 1; // iteratori i promenlivata izpolzvana v printf za broi na izrechenieto
  char bukwa; // poredna bukwa ot stringa
  int bool = 0; // buleva promenliva, koqto pokazva dali "bukwa" e nqkoi ot simvolite za krai na izrechenie
  
  sentence_num = 0; // nulirame broq na izrecheniqta
  
  printf("Izrechenie 0: ");
  
  for (i = 0; i < text_length; i++)
  {
    bool = 0; 
    bukwa = string[i]; // vzimame poredniq simvol ot stringa 
    
    for (k = 0; k < symbol_num; k++)
    {
      if (bukwa == symbol[k]) bool = 1; // cikul, koito sledi dali dali bukwa e edin ot simvolite za krai na izrechenieto
    }
    
    printf("%c", bukwa);
    sentence_length[sentence_num]++;
    
    if (bool == 1)
    {
      if ((i+1) == text_length)  // if, koito sledi dali sme na poslednoto izrechenie
      {
	printf(" <- duljina: %d", sentence_length[sentence_num], j);
      } else
      {
	printf(" <- duljina: %d\nIzrechenie %d: ", sentence_length[sentence_num], j);
      }
      j++;
      sentence_num++;
    }
  }
  
  // izchislqvame srednata duljina na izrechenie
  for (i = 0; i <= sentence_num; i++)
  {
    average_length += sentence_length[i];
  }
  average_length /= sentence_num;
 
  printf("\nSredna duljina: %d\n", average_length);
}
