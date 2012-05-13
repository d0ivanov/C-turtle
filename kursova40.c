#include <stdio.h> // vkluchvame bibliotekata za rabota sys standarten vhod i izhod
#include <stdlib.h> // za malloc
#include <string.h> // za rabota sys stringove

typedef struct // deklarirame tip sturktura s kluchovo ime book i elementi name, isbn, year...
{
  char name[40];
  int ISBN;
  int year;
  int avaible;
  int condition;
} book;

int book_num = 0; // promenliva koqto pazi broq knigi vyvedeni w programata

void add_book(book *); // dobavq kniga
void show_book(book *); // pokazva spisyk s knigi
void read_from_file(book *); // chete ot file
void sort_books(book *); // sortira knigite po azbuchen red
void allocate_array(book **, int); // zadelq pamet za masiva

int main()
{
  book *book_arr; // deklarirame ukazatel kum tipa book, koito shte malloc-nem za da poluchim masiv
  char key; // za da chetem izbora na porebitelq
  
  allocate_array(&book_arr, 0); // izvikwame zadelqneto na pamet s argumenti masiva(ukazatelq) i 0 za towa che samo zadelq 5 elementa bez stoinosti
  
  while(1)
  {
    printf("\n");
    
    printf("#######################################################\n");
    printf("# Press 1 to add a book.                              #\n");
    printf("# Press 2 to add array of books.                      #\n");
    printf("# Press 3 to show book catalog.                       #\n");
    printf("# Press 4 to sort books.                              #\n");
    printf("# Press 5 to read books from file.                    #\n");
    printf("#                                                     #\n");
    printf("# Press 6 to exit.                                    #\n");
    printf("#######################################################\n");
    
    printf("\nChoose option from the menu: ");
    key = getchar(); // chetem izbora na potrebitelq
  
    switch(key) // izvikvame funkciite v zavisimost ot izbora
    {
      case 49 : add_book(book_arr);
	break;
      case 50 : do
		{
		  add_book(book_arr);
		  printf("\nTo add new book press 1, to exit to menu press 2. \n");
		} while (getchar() == 49);
	break;
      case 51 : show_book(book_arr);
	break;
      case 52 : sort_books(book_arr);
	break;
      case 53 : read_from_file(book_arr);
	break;
      case 54 : free(book_arr);
		return 0;
	break;
    }
  }
  
  
  return 0;
}

void add_book(book *book_arr)
{
  int i;
  
  if (book_num/5 == 1) allocate_array(&book_arr, 1); // prowerqvame dali sme zapulnili elementite na masiva i ako sme - zadelqme oshte 5
  
  // chetem stoinostite na elementite na structurata
  printf("\nEnter book ISBN: "); 
  scanf("%d", &book_arr[book_num].ISBN);
  
  printf("\nEnter book name: ");
  scanf("%s", book_arr[book_num].name);
  
  printf("\nEnter book year: ");
  scanf("%d", &book_arr[book_num].year);
  
  printf("\nEnter 1 if book is avaible, and 0 if not.");
  do
    scanf("%d", &book_arr[book_num].avaible);
  while (book_arr[book_num].avaible != 0 && book_arr[book_num].avaible != 1);
  
  printf("Enter 1 for good book condition, and 0 for bad: ");
  do
    scanf("%d", &book_arr[book_num].condition);
  while (book_arr[book_num].condition != 0 && book_arr[book_num].condition != 1);
  
  book_num++; // uvelichavame promenlivata, koqto pazi broq knigi vyvedeni v programata
  getchar();
}

void show_book(book *book_arr)
{
  int i, k;
  
  printf("");
  
  for (i = 0; i < book_num; i++) 
  {
    if (book_arr[i].avaible == 0 || book_arr[i].condition == 0) // pokazvame knigite s "-" ili bez v zavisimost ot systoqnieto im i towa dali sa v nalichnost
    {
      printf("-%s\n", book_arr[i].name);
    } else
    {
      printf("%s\n", book_arr[i].name);
    }
  }
  getchar();
}

void read_from_file(book* book_arr)
{
  FILE *fp;
  char key;
  
  fp = fopen("kursova40Read.txt", "r"); // otwarqme faila za chetene
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

void allocate_array(book ** book_arr, int mode)
{
  book * temp;
  if (mode != 0 && mode != 1) return; // prowerqvame dali sa vyvedeni pozvoleni argumenti
  
  if (mode == 0)
  {
    *book_arr = (book *)malloc(5 * sizeof(book)); // zadelqme pamet za 5 elementa s goleminata na strukturata
  } else
  { 
    temp = *book_arr; // kopirame informaciqta ot masiva v temp
    *book_arr = (book *)malloc(((book_num/5) + 5) * sizeof(book)); // allocirame go s oshte 5 elementa
    *book_arr = temp; // vryshtame informaciqta
  }
}

void sort_books(book *book_arr)
{
  int i = 0, k = 0;
  book container;
  
  while (i < book_num - 1) 
  {
    while (book_arr[i].name[k] == book_arr[i+1].name[k]) k++; // prowerqvame do koq bukwa sa ednakwi dwete imena
    if (book_arr[i].name[k] > book_arr[i+1].name[k]) // ako pyrwoto e s po-golqma bukwa (b>a) gi razmenqme
    {
      container = book_arr[i+1]; 
      book_arr[i+1] = book_arr[i];
      book_arr[i] = container;
    }
    k = 0; 
    i++;
  }
}
