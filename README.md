# Atmega128_ElevatorProject


사진
-------------
<div>
<img width ="200" src= "https://user-images.githubusercontent.com/62198891/88296150-4bfe2c00-cd39-11ea-9854-c3e5bad7d27a.png">
<img width ="200" src= "https://user-images.githubusercontent.com/62198891/88296105-3e48a680-cd39-11ea-9575-9f7171f9c7ca.png">
<img width ="200" src= "https://user-images.githubusercontent.com/62198891/88296215-5ddfcf00-cd39-11ea-9b1f-c84096a959e7.png">
<img width ="200" src= "https://user-images.githubusercontent.com/62198891/88296249-6a642780-cd39-11ea-87ee-78b2b4c2b97f.png">
</div>



흐름도
-------------
<img width = "400" src= "https://user-images.githubusercontent.com/62198891/88299577-794cd900-cd3d-11ea-91b1-933872ef3a61.png">


개발환경
--------------
OS - Windows
Program Tool - Atmel Studio 7.0
Language - C
AVR MCU - ATmega128


사용부품
--------------
ATmega128 MCU module (JMOD-128-1)
브레드보드
FND 
스위치x2
모터드라이버(ULN2003)
스텝모터(28BYJ-48
알루미늄 프레임
고정도르레


코드해석
--------------

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
 
#define num1 0b11111001 //FND에서 1표시
#define num2 0b10100100 //FND에서 2표시
#define num3 0b10110000 //FND에서 3표시
 
unsigned char cw[8] = {0b00001000, 0b00001100, 0b00000100, 0b00000110, 0b00000010, 0b00000011, 0b00000001,0b00001001}; //모터 정방향 회전
unsigned char ccw[8] = {0b00001001, 0b00000001, 0b00000011 , 0b00000010, 0b00000110, 0b00000100, 0b00001100, 0b00001000}; //모터 역방향 회전
 
unsigned int i=0, j=0, k=0,n=0, x=0,y=0;
unsigned int count = 0;
 
unsigned char fnd[3] = {num1,num2,num3};
 
int main(void){
	DDRA = 0xff; //포트 A를 모터출력사용
	DDRB = 0x00; //포트 B를 스위치입력사용
	DDRC = 0xff; //포트C를 FND출력사용
	PORTC = num; //최초 FND 1표시     
	                    
	while(1){
 
		if((PIND&0b00010000) == 0b00000000){
			count++;
			PORTC = fnd[count];
			motorUp(); //버튼 클릭시 FND 숫자가 올라가며 모터 동작
		}
		
		if((PIND&0b00100000) == 0b00000000){
			count--;
			PORTC = fnd[count];
			motorDown(); //버튼 클릭시 FND 숫자가 내려가면 모터 동작
		}
	}
 
	return 0;
}
 
int motorUp(void) { //정방향회전을 for문 사용하여 320회정도 회전
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
 
int motorDown(void) { //역방향회전을 for문 사용하여 320회정도 회전
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

