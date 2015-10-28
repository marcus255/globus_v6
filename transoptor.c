#include "MKL25Z4.h"
#include "transoptor.h"
#include "pins.h"

void set_cathodes(uint8_t liczba)
{
	/*********************wyczysc wszystkie katody************************************/
		PTA->PCOR |= (1<<CAT_0);										//katoda0
		PTA->PCOR |= (1<<CAT_1);										//katoda1
		PTC->PCOR |= (1<<CAT_2);										//katoda2
		PTC->PCOR |= (1<<CAT_3);										//katoda3
		PTC->PCOR |= (1<<CAT_4);										//katoda4
		PTC->PCOR |= (1<<CAT_5);										//katoda5	
		PTC->PCOR |= (1<<CAT_6);										//katoda6				
		PTC->PCOR |= (1<<CAT_7);										//katoda7
	/*********************ustawienie poszczegolnych katod***************************/
		switch(liczba)
		{
			case 7:
			PTA->PSOR |= (1<<CAT_0);										//katoda0
			break;
			case 6:
			PTA->PSOR |= (1<<CAT_1);										//katoda1
			break;
			case 5:
			PTC->PSOR |= (1<<CAT_2);										//katoda2
			break;
			case 4:
			PTC->PSOR |= (1<<CAT_3);										//katoda3
			break;
			case 3:
			PTC->PSOR |= (1<<CAT_4);										//katoda4
			break;
			case 2:
			PTC->PSOR |= (1<<CAT_5);										//katoda5
			break;
			case 1:
			PTC->PSOR |= (1<<CAT_6);										//katoda6
			break;
			case 0:
			PTC->PSOR |= (1<<CAT_7);										//katoda7
			break;
		}
}


void setCathodes(uint8_t liczba)
{
	/*********************ustawienie poszczegolnych katod***************************/
		switch(liczba)
		{
			case 7:
			PTA->PCOR |= (1UL<<CAT_1);
			PTA->PSOR |= (1UL<<CAT_0);										//katoda0
			break;
			
			case 6:
			PTC->PCOR |= (1UL<<CAT_2);
			PTA->PSOR |= (1UL<<CAT_1);										//katoda1
			break;
			
			case 5:
			PTC->PCOR |= (1UL<<CAT_3);
			PTC->PSOR |= (1UL<<CAT_2);										//katoda2
			break;
			
			case 4:
			PTC->PCOR |= (1UL<<CAT_4);
			PTC->PSOR |= (1UL<<CAT_3);										//katoda3
			break;
			
			case 3:
			PTC->PCOR |= (1UL<<CAT_5);
			PTC->PSOR |= (1UL<<CAT_4);										//katoda4
			break;
			
			case 2:
			PTC->PCOR |= (1UL<<CAT_6);
			PTC->PSOR |= (1UL<<CAT_5);										//katoda5
			break;
			
			case 1:
			PTC->PCOR |= (1UL<<CAT_7);
			PTC->PSOR |= (1UL<<CAT_6);										//katoda6
			break;
			
			case 0:
			PTA->PCOR |= (1UL<<CAT_0);
			PTC->PSOR |= (1UL<<CAT_7);										//katoda7
			break;
		}
}

void setAnodes(uint8_t * pos)
{
		uint8_t byte = *(pos);
		if(128&byte) PTC->PSOR |= (1UL<<RED_7); 	else PTC->PCOR |= (1UL<<RED_7);
		if(64&byte)  PTB->PSOR |= (1UL<<GREEN_7); else PTB->PCOR |= (1UL<<GREEN_7);
		if(32&byte)  PTC->PSOR |= (1UL<<BLUE_7); 	else PTC->PCOR |= (1UL<<BLUE_7);
		if(8&byte)   PTE->PSOR |= (1UL<<RED_6); 	else PTE->PCOR |= (1UL<<RED_6);
		if(4&byte)	 PTB->PSOR |= (1UL<<GREEN_6); else PTB->PCOR |= (1UL<<GREEN_6);
		if(2&byte)	 PTC->PSOR |= (1UL<<BLUE_6); 	else PTC->PCOR |= (1UL<<BLUE_6);
			
		byte = *(pos + 1);
		if(128&byte) PTE->PSOR |= (1UL<<RED_5); 	else PTE->PCOR |= (1UL<<RED_5);
		if(64&byte)  PTB->PSOR |= (1UL<<GREEN_5); else PTB->PCOR |= (1UL<<GREEN_5);
		if(32&byte)  PTC->PSOR |= (1UL<<BLUE_5); 	else PTC->PCOR |= (1UL<<BLUE_5);
		if(8&byte)	 PTE->PSOR |= (1UL<<RED_4); 	else PTE->PCOR |= (1UL<<RED_4);
		if(4&byte)	 PTB->PSOR |= (1UL<<GREEN_4); else PTB->PCOR |= (1UL<<GREEN_4);
		if(2&byte)	 PTC->PSOR |= (1UL<<BLUE_4); 	else PTC->PCOR |= (1UL<<BLUE_4);
		
		byte = *(pos + 2);
		if(128&byte) PTE->PSOR |= (1UL<<RED_3); 	else PTE->PCOR |= (1UL<<RED_3);
		if(64&byte)  PTE->PSOR |= (1UL<<GREEN_3); else PTE->PCOR |= (1UL<<GREEN_3);
		if(32&byte)  PTA->PSOR |= (1UL<<BLUE_3); 	else PTA->PCOR |= (1UL<<BLUE_3); 
		if(8&byte)	 PTE->PSOR |= (1UL<<RED_2); 	else PTE->PCOR |= (1UL<<RED_2);
		if(4&byte)	 PTE->PSOR |= (1UL<<GREEN_2); else PTE->PCOR |= (1UL<<GREEN_2);
		if(2&byte)	 PTA->PSOR |= (1UL<<BLUE_2); 	else PTA->PCOR |= (1UL<<BLUE_2); 

		byte = *(pos + 3);
		if(128&byte) PTE->PSOR |= (1UL<<RED_1); 	else PTE->PCOR |= (1UL<<RED_1); 
		if(64&byte)  PTE->PSOR |= (1UL<<GREEN_1); else PTE->PCOR |= (1UL<<GREEN_1);
		if(32&byte)  PTE->PSOR |= (1ul<<BLUE_1); 	else PTE->PCOR |= (1UL<<BLUE_1);
		if(8&byte)   PTB->PSOR |= (1UL<<RED_0); 	else PTB->PCOR |= (1UL<<RED_0); 
		if(4&byte)	 PTE->PSOR |= (1UL<<GREEN_0); else PTE->PCOR |= (1UL<<GREEN_0);
		if(2&byte)	 PTD->PSOR |= (1UL<<BLUE_0); 	else PTD->PCOR |= (1UL<<BLUE_0);
}

void clear_cathodes(void)
{
		PTA->PCOR |= (1<<CAT_0);										//katoda0
		PTA->PCOR |= (1<<CAT_1);										//katoda1
		PTC->PCOR |= (1<<CAT_2);										//katoda2
		PTC->PCOR |= (1<<CAT_3);										//katoda3
		PTC->PCOR |= (1<<CAT_4);										//katoda4
		PTC->PCOR |= (1<<CAT_5);										//katoda5	
		PTC->PCOR |= (1<<CAT_6);										//katoda6				
		PTC->PCOR |= (1<<CAT_7);										//katoda7
}


void transoptor_initialize(void)
{
	SIM->SCGC5 |=  SIM_SCGC5_PORTD_MASK; 				                 	// Enable clock for port C
	PORTD->PCR[OPTO_PIN] |= PORT_PCR_MUX(1);      	
	PORTD->PCR[OPTO_PIN] |=  PORT_PCR_PS_MASK |	PORT_PCR_PE_MASK;	//Set bit in PCR register to enable pull resistor. See KL46 Sub-Family Reference Manual 
															                                  //bit in PCR register to select pull up. See KL46 Sub-Family Reference Manual 
	PORTD->PCR[OPTO_PIN] |= 	PORT_PCR_IRQC(9);	                	//value for IRQC bit field in PCR register to select falling edge interrupts for PORTC[3]. See KL46 Sub-Family Reference Manual 
	                                                              //ARM's Nested Vector Interrupt Controller configuration
	NVIC_ClearPendingIRQ(PORTD_IRQn);				                // Clear NVIC any pending interrupts on PORTC_D
	NVIC_EnableIRQ(PORTD_IRQn);							                // Enable NVIC interrupts source for PORTC_D module 
	NVIC_SetPriority (PORTD_IRQn, 3);
}

