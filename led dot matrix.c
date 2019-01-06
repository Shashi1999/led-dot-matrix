/*
 * led_dot_matrix.c
 *
 * Created: 06/01/2019 8:22:58 AM
 *  Author: SHASHI RANJAN
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU100000UL
int main(void)
{
   DDRD=DDRC=0xff;
   char name[6][5]={{ 0xd1,0xb6,0xb6,0xb6,0xc5},   \\S
		    { 0x00,0xf7,0xf7,0xf7,0x00},   \\H
       		    { 0x83,0xf5,0xf6,0xf5,0x83},   \\A
                    { 0xd1,0xb6,0xb6,0xb6,0xc5},   \\S
		    { 0x00,0xf7,0xf7,0xf7,0x00},   \\H
		    { 0x3e,0x3e,0x00,0x3e,0x3e },  \\I
					};
					
			const char colums[]={0x01,0x02,0x04,0x08,0x10};
			for(int j=0;j<100;j++)
			{ 
				for(int k=0;k<6;k++)
				{ 
					for(int i=0;i<5;i++)
					{ _delay_ms(10);
						PORTC=colums[i];
						PORTD=name[k][i];
					    _delay_ms(2);
					}
					
					
					PORTD=0xff;
					_delay_ms(1500);
				}
			}																
    while(1);
   
	
}
