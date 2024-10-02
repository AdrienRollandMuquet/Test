#include <stdint.h>

#define RCC_AHB1ENR (*(volatile uint32_t*) 0x00100030 // On enregistre l'addresse du registre RCC_AHB1ENR
#define GPOIA_EN (1<<0) // Le bit 0 correspond au GPIOA
#define GPIOA_ODR 
int main(void){

  RCC_AHB1ENR |= GPOIA_EN; // On active la clock pour le GPIOA
  
  // PA5 Output			(GPIOA->MODER)

	while(1){
 
		for(uint32_t i = 0 ; i<100000; i++); // On prend du temps processeur afin que le clignotement de la LED ne soit pas trop rapide
		(*GPIOA_ODR) ^= (1<<5); // On fait clignoter la LED	
   
	}
}