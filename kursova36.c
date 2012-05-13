#include <stdio.h> // vkluchvame bibliotekata za rabota sys standartniq vhod i izhod
#include <stdlib.h> // za malloc
#include <string.h> // za rabota sys stringove

typedef struct // deklarirame tip structura sys kluchovo ime stoka
{
  long int nomer;
  char ime[30];
  float cena;
  int kolichestvo;
} stoka;

int broiStoki = 0; // broi stoki vyvedeni v programatas

void dobaviStoka(stoka *);
void pokajiStoka(stoka *);
void promeniNalichnost(stoka *);
void iztriiStoka(stoka *, int);
void cheteneOtFail(stoka *);
void zadelqneNaMasiva(stoka **, int);

int main()
{
  stoka *stoki; // deklarirame ukzatel kum stoka, koito shte polzvame za da syzdadem masiva
  char key; // za da chetem izbora na potrebitelq
  
  zadelqneNaMasiva(&stoki, 0); // zadelqme pamet za masiva
  
  printf("-------------------------------------------------------\n");
  printf(" Natisni 1 za dobavyane na stoka.                    \n");
  printf(" Natisni 2 za dobavqne na masiv ot stoki.            \n");
  printf(" Natisni 3 za da vidish stoka.                       \n");
  printf(" Natisni 4 za da promenish nalichnasta na stoka.     \n");
  printf(" Natisni 5 za da prochetesh stoki ot fail            \n");
  printf("                                                     \n");
  printf(" Press 6 to exit.                                    \n");
  printf("-------------------------------------------------------\n");
 
  while(1)
  {
    printf("\nChoose option from the menu: ");
    key = getchar(); // chetem izbora na potrebitelqs
  
    switch(key) // izvikvame funkciite v zavisimost ot izbora na potrebitelq
    {
      case 49 : dobaviStoka(stoki);
	break;
      case 50 : do
		{
		  dobaviStoka(stoki);
		  printf("\nZa da dobavish nova stoka vyvedi 1, za za izlezesh natisni 2.\n");
		} while (getchar() == 49);
		getchar();
	break;
      case 51 : pokajiStoka(stoki);
	break;
      case 52 : promeniNalichnost(stoki);
	break;
      case 53 : cheteneOtFail(stoki);
	break;
      case 54 : free(stoki);
		return 0;
	break;
    }
  }
  
  
  return 0;
}

void dobaviStoka(stoka* stoki)
{
  int i;
  
  if (broiStoki/5 == 1) zadelqneNaMasiva(&stoki, 1); // proverqvame dali sme izrazhodili 5(10, 15...)te zadeleni elementa na masiva
  
  // vuvejdame stoinosti za stokata
  printf("\nNomer na stoka: ");
  scanf("%ld", &stoki[broiStoki].nomer);
  
  printf("\nIme na stoka: ");
  scanf("%s", stoki[broiStoki].ime);
  
  printf("Cena: ");
  scanf("%f", &stoki[broiStoki].cena);
  
  printf("Kolichestvo: ");
  scanf("%d", &stoki[broiStoki].kolichestvo);
  
  broiStoki++; // uvelichavame promenlivata, koqto pazi broq stolo
  getchar();
}

void pokajiStoka(stoka* stoki)
{
  long int nomer;
  int i, k;
  
  printf("\nVuvedi nomer na artikul: ");
  scanf("%ld", &nomer);
  
  for (i = 0; i < broiStoki; i++)
  {
    if (nomer == stoki[i].nomer) // sravnqvame dali vyvedeniq ot potrebitelq nomer e ednakyv s tozi na poredniq element na masiva
    {
      printf("\nNomer: %ld\n", stoki[i].nomer);
      printf("Ime: %s\n", stoki[i].ime);
      printf("Cena: %f\n", stoki[i].cena);
      printf("Kolichestvo: %d\n", stoki[i].kolichestvo);
    }
  }
  
  getchar();
}

void promeniNalichnost(stoka *stoki)
{
  int i, kolichestvo;
  char key;
  long int nomer;
  
  printf("Vyvedi nomer na stoka: ");
  scanf("%ld", &nomer);
  
  getchar();
  
  for (i = 0; i < broiStoki; i++) 
  {
    if (stoki[i].nomer == nomer) // ako vyvedeniq e = na tozi na poredniq element ot masiva
    {
      printf("Vyvedi 1 za da dobavish, 2 za da izvadish ot nalichnostta na stokata.");
      key = getchar();
      if (key == 49) // ako e 1
      {
	printf("Vyvedi stoinost: ");
	scanf("%d", &kolichestvo);
	stoki[i].kolichestvo += kolichestvo; // uvelichavame s vyvedenoto
      }
      if (key == 50) // ako e 2
      {
	printf("Vyvedi stoinost: ");
	scanf("%d", &kolichestvo);
	if (stoki[i].kolichestvo - kolichestvo < 0) // proverka dali potrebitelq ne izvajda poveche ot kolkoto ima v nalichnost
	{
	  printf("\nOperaciqta ne moje da byde izvyrshena.\n");
	} else if (stoki[i].kolichestvo - kolichestvo == 0) // proverka dali e 0 (ako e go iztrivame)
	       {
		 iztriiStoka(stoki, i);
	       } else
	       {
		 stoki[i].kolichestvo -= kolichestvo; // ako izvajda po-malko ot kolkoto ima v nalichnost prosto si se vadi...
	       }
      }
    }
  }
}

void iztriiStoka(stoka *stoki, int nomerNaStokata)
{
  int length = strlen(stoki[broiStoki-1].ime); // vzimame dyljinata na stringa i q zapisvame v promenlivata length
  int i;
  
  if (broiStoki != 1) // proverka dali stokata e samo 1, ako ne e q iztriwame kato zapisvame poslednata na neino mqsto
  {
    stoki[nomerNaStokata].nomer = stoki[broiStoki-1].nomer;
    for (i = 0; i < length; i++) stoki[nomerNaStokata].ime[i] = stoki[broiStoki-1].ime[i];
    stoki[nomerNaStokata].cena = stoki[broiStoki-1].cena;
    stoki[nomerNaStokata].kolichestvo = stoki[broiStoki-1].kolichestvo;
  } else
  {
    printf("Ne mojesh da iztriesh stokata, tyi kato imash samo 1.");
  }
  
}

void cheteneOtFail(stoka *stoki)
{
  FILE *fp;
  char key;
  
  fp = fopen("kursova36Read.txt", "r"); // otwarqme file-a
  if (fp != NULL) // prowerqwame dali e otworen prawilno i ima informaciq
  {
    key = fgetc(fp); // chetem simvol ot file-a i go zapisvame v promenlivata key
    rewind(fp); // vryshtame pokazatelq, koito sochi do kude  v file-a sme stignali v nachaloto
    while (key != EOF) // dokato ne sme stignali kraq na file-a (EndOfFile)
    {
      key = fgetc(fp);
      printf("%c", key); 
    }
  } else
  {
    printf("\nVyznikna greshka pri cheteneto ot fail.\n");
  }
  
  fclose(fp); // zatwarqme file-a
  getchar();
}

void zadelqneNaMasiva(stoka** stoki, int mode)
{
  stoka * container;
 
  if (mode != 0 && mode != 1) return; // prowerqwame dali e vyveden pozwolen argument
  
  if (mode == 0) 
  {
    *stoki = (stoka *)malloc(5 * sizeof(stoka)); // zadelqme pamet za 5 elementa s goleminata na strukturata ni
  } else
  {
    container = *stoki; // zapisvame v container informaciqta ot masiva 
    *stoki = (stoka *)malloc(((broiStoki/5) + 5) * sizeof(stoka)); // i malokwame masiva
    *stoki = container; // sled towa wryshtame informaciqta
  }
}
