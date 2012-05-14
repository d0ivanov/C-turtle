#include <stdio.h> // vkluchvame bibliotekata za rabota sys standarten vhod i izhod
#include <stdlib.h> // za malloc
#include <string.h> // za rabota sys stringove

typedef struct // deklarirame tip sturktura s kluchovo ime book i elementi name, isbn, year...
{
  char ime[40];
  int ISBN;
  int godina;
  int nalichna;
} kniga;

int broiKnigi = 0; // promenliva koqto pazi broq knigi vyvedeni w programata

void dobaviKniga(kniga *); // dobavq kniga
void chetiFile(kniga *); // chete ot file
void zadeliMasiv(kniga **, int); // zadelq pamet za masiva
void vzemiKniga(kniga *);
void proveriKniga(kniga *);
void snemiKniga(kniga *);
void pokajiSneti();

int main()
{
  kniga *knigi; // deklarirame ukazatel kum tipa book, koito shte malloc-nem za da poluchim masiv
  char key; // za da chetem izbora na porebitelq
  
  zadeliMasiv(&knigi, 0); // izvikwame zadelqneto na pamet s argumenti masiva(ukazatelq) i 0 za towa che samo zadelq 5 elementa bez stoinosti
  
  while(1)
  {
    printf("\n");
    
    printf("Natisni 1 za da dobavish kniga. \n");
    printf("Natisni 2 za da vzemesh kniga. \n");
    printf("Natisni 3 za da prowerish dali knigata e nalichna. \n");
    printf("Natisni 4 za da snemesh ot otchet dadena kniga. \n");
    printf("Natisni 5 za da izvedesh knigite sneti ot otchet. \n");
    printf("Natisni 6 za da prochetesh knigite ot fail. \n");
    printf("\nNatisni 7 za da izleznesh. \n");
    
    printf("\nChoose option from the menu: ");
    key = getchar(); // chetem izbora na potrebitelq
  
    switch(key) // izvikvame funkciite v zavisimost ot izbora
    {
      case 49 : dobaviKniga(knigi);
	break;
      case 50 : vzemiKniga(knigi);
	break;
      case 51 : proveriKniga(knigi);
	break;
      case 52 : snemiKniga(knigi);
	break;
      case 53 : pokajiSneti();
	break;
      case 54 : chetiFile(knigi);
	break;
      case 55 : free(knigi);
		return 0;
	break;
    }
  }
  
  
  return 0;
}

void dobaviKniga(kniga *knigi)
{
  int i;
  
  if (broiKnigi/5 == 1) zadeliMasiv(&knigi, 1); // prowerqvame dali sme zapulnili elementite na masiva i ako sme - zadelqme oshte 5
  
  // chetem stoinostite na elementite na structurata
  printf("\nVyvedi ISBN: "); 
  scanf("%d", &knigi[broiKnigi].ISBN);
  
  printf("\nVyvedi ime: ");
  scanf("%s", knigi[broiKnigi].ime);
  
  printf("\nVyvedi godina: ");
  scanf("%d", &knigi[broiKnigi].godina);
  
  printf("\nVyvedi 1 za nalichna, 0 za nenalichna.");
  do
    scanf("%d", &knigi[broiKnigi].nalichna);
  while (knigi[broiKnigi].nalichna != 0 && knigi[broiKnigi].nalichna != 1);
  
  broiKnigi++; // uvelichavame promenlivata, koqto pazi broq knigi vyvedeni v programata
  getchar();
}

void chetiFile(kniga* knigi)
{
  FILE *fp;
  char key;
  
  fp = fopen("kursova34.txt", "r"); // otwarqme faila za chetene
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

void zadeliMasiv(kniga **knigi, int mode)
{
  kniga * container;
  if (mode != 0 && mode != 1) return; // prowerqvame dali sa vyvedeni pozvoleni argumenti
  
  if (mode == 0)
  {
    *knigi = (kniga *)malloc(5 * sizeof(kniga)); // zadelqme pamet za 5 elementa s goleminata na strukturata
  } else
  { 
    container = *knigi; // kopirame informaciqta ot masiva v container
    *knigi = (kniga *)malloc(((broiKnigi/5) + 5) * sizeof(kniga)); // allocirame go s oshte 5 elementa
    *knigi = container; // vryshtame informaciqta
  }
}

void vzemiKniga(kniga *knigi)
{
  int isbn;
  int bool = 0, i;
  
  printf("Vavedi ISBN: ");
  scanf("%d", &isbn);
  
  for (i = 0; i < broiKnigi; i++)
  {
    if (knigi[i].ISBN == isbn) 
    {
      if (knigi[i].ISBN > 0)
      {
	knigi[i].nalichna = 0;
	printf("\nVie vzehte knigata.\n");
	bool = 1;
      } else
      {
	printf("\nKnigata ne e nalichna.\n");
      }
    }
  }
  
  if (bool == 0) printf("Kniga s takowa ISBN ne e zapisana v bazata danni.");
  
  getchar();
}

void proveriKniga(kniga *knigi)
{
  int isbn;
  int i;
  
  printf("Vavedi ISBN: ");
  scanf("%d", &isbn);
  
  for (i = 0; i < broiKnigi; i++)
  {
    if (knigi[i].ISBN == isbn) 
    {
      if (knigi[i].nalichna > 0)
      {
	printf("Knigata e nalichna.\n");
      } else
      {
	printf("Knigata ne e nalichna.\n");
      }
    }
  }
  
  getchar();
}

void snemiKniga(kniga *knigi)
{
  FILE *fp;
  int isbn;
  int i, k, length;
  
  printf("Vavedi ISBN: ");
  scanf("%d", &isbn);
  
  for (i = 0; i < broiKnigi; i++)
  {
    if (knigi[i].ISBN == isbn) 
    {
      break;
    }
  }
  
  if (broiKnigi > 1) // nqma da si triesh poslednata kniga, shto za biblioteka nqma nito edna kniga...
  {
    fp = fopen("snetiKnigi.txt", "a");
    
    if (fp != NULL)
    {
      // zapisvame innformaciq za knigata koqto shte iztrivame v file
      fprintf(fp, "\nIme na knigata: %s", knigi[i].ime);
      fprintf(fp, "\nISBN na knigata: %d", knigi[i].ISBN);
      fprintf(fp, "\nGodina na izdavane: %d\n", knigi[i].godina);
      
      // iztrivame knigata
      length = strlen(knigi[i].ime); // vzimame dyljinata na imeto
      for (k = 0; k < length; k++) knigi[i].ime[k] = knigi[broiKnigi-1].ime[k];
      knigi[i].ISBN = knigi[broiKnigi-1].ISBN;
      knigi[i].godina = knigi[broiKnigi-1].godina;
      knigi[i].nalichna = knigi[broiKnigi-1].nalichna;
    } else
    {
      printf("\nGreshka pri cheteneto ot faila. \n");
    }
    
    fclose(fp);
  } else
  {
    printf("\nKoq biblioteka shte ostane bez nito 1 kniga...\n");
  }
  
  getchar();
}

void pokajiSneti()
{
  FILE *fp;
  char key;
  
  fp = fopen("snetiKnigi.txt", "r");
  
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
    printf("\nGreshka pri cheteneto na file-a.\n");
  }
  
  fclose(fp);
  getchar();
}
