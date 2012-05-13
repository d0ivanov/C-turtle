#include <stdio.h> // vkluchvame bibliotekata za rabota sys standarten vhod i izhod
#include <stdlib.h> // za malloc
#include <string.h> // za rabota sys stringove

typedef struct // deklarirame tip sturktura s kluchovo ime client i promenlivi ime i nomer
{
  char name[40];
  long int number;
} client;

int client_num = 0; // promenliva, koqto pazi broq clienti vyvedeni w programata
client *clients; // deklarirame ukazatel kum tipa client, koito shte malloc-nem za da poluchim masiv

void add_client(); // dobavq client
void show_clients(); // pokazva spisyk s clienti
void read_from_file(); // chete ot file
void search_client(); // tyrsi nomer po zadadeno ime
void allocate_array(int); // zadelq pamet za masiva

int main()
{
  char key; // za da chetem izbora na porebitelq
  
  allocate_array(0); // izvikwame zadelqneto na pamet s argumenti masiva(ukazatelq) i 0 za towa che samo zadelq 5 elementa bez stoinosti
  
  while(1)
  {
    printf("\n");
    
    printf(" Press 1 to add client. \n");
    printf(" Press 2 to search client. \n");
    printf(" Press 3 to show all clients. \n");
    printf(" Press 4 to read from file. \n");
    printf("\n Press 5 to exit.\n");
    
    printf("\nChoose option from the menu: ");
    key = getchar(); // chetem izbora na potrebitelq
  
    switch(key) // izvikvame funkciite v zavisimost ot izbora
    {
      case 49 : add_client();
	break;
      case 50 : search_client();
	break;
      case 51 : show_clients();
	break;
      case 52 : read_from_file();
	break;
      case 53 : free(clients);
		return 0;
	break;
    }
  }
  
  return 0;
}

void add_client()
{
  int i;
  
  if (client_num/5 == 1) allocate_array(1); // prowerqvame dali sme zapulnili elementite na masiva i ako sme - zadelqme oshte 5
  
  // chetem stoinostite na elementite na structurata
  printf("\nEnter client name: ");
  scanf("%s", clients[client_num].name);
  
  printf("\nEnter client number: ");
  scanf("%ld", &clients[client_num].number);
  
  client_num++; // uvelichavame promenlivata, koqto pazi broq knigi vyvedeni v programata
  getchar();
}

void show_clients()
{
  int i, k;
  
  getchar();
  printf("\n");
  
  for (i = 0; i < client_num; i++) 
  {
    printf("%s\n", clients[i].name);
    printf("%ld\n", clients[i].number);
  }
  printf("Press any key...");
  getchar();
}

void read_from_file()
{
  FILE *fp;
  char key;
  
  fp = fopen("kursova23.txt", "r"); // otwarqme faila za chetene
  if (fp != NULL) // ako uspeem da go otworim i ima informaciq
  {
    key = fgetc(fp); // chetem simvol ot file-a
    rewind(fp); // vryshtame pokazatelq, koioto pokazva do kyde v file-a sme stignalo v nachaloto
    while (key != EOF) // dokato ne sme stignali kraq na file-a (EndOfFile)
    {
      key = fgetc(fp);
      printf("%c", key);
    }
  } else
  {
    printf("\nThere was error while trying to read the file.\n");
  }
  
  fclose(fp);
  getchar();
}

void allocate_array(int mode)
{
  client * temp;
  if (mode != 0 && mode != 1) return; // prowerqvame dali sa vyvedeni pozvoleni argumenti
  
  if (mode == 0)
  {
    clients = (client *)malloc(5 * sizeof(client)); // zadelqme pamet za 5 elementa s goleminata na strukturata
  } else
  { 
    temp = clients; // kopirame informaciqta ot masiva v temp
    clients = (client *)malloc(((client_num/5) + 5) * sizeof(client)); // allocirame go s oshte 5 elementa
    clients = temp; // vryshtame informaciqta
  }
}

void search_client()
{
  int i;
  char name[40];
  
  printf("Enter client name: ");
  scanf("%s", name); // chetem imeto na clienta, chiito nomer potrebitelq tyrsi
  
  for (i = 0; i < client_num; i++)
  {
    if (strcmp(clients[i].name, name) == 0) printf("Client number is: %ld\n", clients[i].number); // ako ima syvpadenie izkarvame nomera
  }
  
  getchar();
}

