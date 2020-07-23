#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#define num1 0b11111001
#define num2 0b10100100
#define num3 0b10110000

unsigned char cw[8] = {0b00001000, 0b00001100, 0b00000100, 0b00000110, 0b00000010, 0b00000011, 0b00000001,0b00001001};
unsigned char ccw[8] = {0b00001001, 0b00000001, 0b00000011 , 0b00000010, 0b00000110, 0b00000100, 0b00001100, 0b00001000};

unsigned int i=0, j=0, k=0,n=0, x=0,y=0;
unsigned int count = 0;

unsigned char fnd[3] = {num1,num2,num3};

int main(void){
	DDRA = 0xff;
	DDRB = 0x00;
	DDRC = 0xff;
	PORTC = num1;	              
	                    
	while(1){

		if((PIND&0b00010000) == 0b00000000){
			count++;
			PORTC = fnd[count];
			motorUp();
		}
		
		if((PIND&0b00100000) == 0b00000000){
			count--;
			PORTC = fnd[count];
			motorDown();
		}
	}

	return 0;
}

int motorUp(void) {
		for(y=0; y<4; y++){
			for(x=0;x<80;x++){
				for(i=0;i<8;i++){
					PORTA = cw[i];
					_delay_ms(1);
				}
			}
		}
	return 0;
} 

int motorDown(void) {
	for(y=0; y<4; y++){
		for(x=0;x<80;x++){
			for(i=0;i<8;i++){
				PORTA = ccw[i];
				_delay_ms(1);
			}
		}
	}
	return 0;
}