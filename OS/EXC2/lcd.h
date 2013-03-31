void lcd_init(void);
void lcd_home(void);
void lcd_clear(void);
void lcd_e_clock(void);
void lcd_text_clock(void);
void lcd_ddram_clock(void);
void lcd_go_xy(char,char);
void lcd_print_text(char *, int);
void lcd_delay(void);
void lcd_print_text(char *, int );

// Porta is used for 		LCD DATABYTE
// Portb bit 2 is used for 	LCD E
// Portb bit 1 is used for 	LCD R/W
// Portb bit 0 is used for 	LCD RS

void lcd_init(void)
{
	PORTA=56;			// Function set to 8-bit, 2 rows, 5x8 dots 56
	lcd_e_clock();

	PORTA=12;			// Display on/off, cursor on var 12
	lcd_e_clock();

	PORTA=6;			// Entry mode set to automatically step right 4
	lcd_e_clock();

	PORTA=1;			// Clear display 1
	lcd_e_clock();
}

void lcd_home(void)	// Move cursor to home position
{
	PORTA=2;
	lcd_delay();
	lcd_e_clock();
}

void lcd_clear(void)	// Clear LCD
{
	PORTA=1;
	lcd_delay();
	lcd_e_clock();
}

void lcd_e_clock(void)		// E-clock
{
	PORTC=PORTC|0x80;
	lcd_delay();
	PORTC=PORTC&~0x80;
}

void lcd_text_clock(void)	// E- and RS-clock
{
	PORTC=PORTC|0xA0;
	lcd_delay();
	PORTC=PORTC&~0xA0;
}

void lcd_ddram_clock(void)	// DDRAM-clock, activate next row in LCD
{
	PORTA=192;
	//lcd_delay();
	lcd_e_clock();
}

void lcd_go_xy(char y,char x)	// Go to x-pos, y-pos on LCD
{
	lcd_home();
	if(y==1)
		PORTA=(x+128);
	if(y==2)
		PORTA=(64+x+128);
	//lcd_delay();
	lcd_e_clock();
}

void lcd_delay(void)		// A small time lcd_delay
{
	long i;
	for(i=0;i<=200;i=i+1)	// Var 10000
	{}
}

void lcd_print_text(char * textin, int length)	// Print text to LCD
{
	int temp;
	for(temp=0;temp<length;temp=temp+1)
	{
		if(temp==20)
			lcd_ddram_clock();

		PORTA=*(textin+temp);
		lcd_text_clock();
	}
}
