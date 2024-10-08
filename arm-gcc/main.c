#include <stdint.h>

#define RCC_AHB1ENR *(volatile uint32_t*) 0x40023830 // On enregistre l'addresse du registre RCC_AHB1ENR
#define GPIOA_ODR *(volatile uint32_t*) 0x40020014 // On enregistre l'adresse du registre GPIOA_ODR
#define GPIOA_MODER *(volatile uint32_t*) 0x40020000 // On enregistre l'adresse du registre GPIOA_MODER

int main(void){

  RCC_AHB1ENR |= (1<<0); // On active la clock pour le GPIOA
  GPIOA_MODER |= (1<<10); // On met le bit 10 du registre GPIOA_MODER à 1 pour que PA5 soit une sortie

	while(1){

		for(uint32_t i = 0 ; i<100000; i++); // On prend du temps processeur afin que le clignotement de la LED ne soit pas trop rapide
		(GPIOA_ODR) ^= (1<<5); // On fait clignoter la LED PA5
   
	}
}
