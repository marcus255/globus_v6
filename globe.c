#include "MKL25Z4.h"
#include "pins.h"

void globe_initialize(void) 					//initialize pins of colors and cathodes
{				  	
/***********************cathodes********************************/
  	PORTA->PCR[CAT_0] = PORT_PCR_MUX(1UL);			//katoda0	
		PTA->PDDR |= (1UL<<CAT_0);										//katoda0
		PORTA->PCR[CAT_1] = PORT_PCR_MUX(1UL);			//katoda1	
		PTA->PDDR |= (1UL<<CAT_1);										//katoda1
		PORTC->PCR[CAT_2] = PORT_PCR_MUX(1UL);			//katoda2	
		PTC->PDDR |= (1UL<<CAT_2);										//katoda2
		PORTC->PCR[CAT_3] = PORT_PCR_MUX(1UL);			//katoda3	
		PTC->PDDR |= (1UL<<CAT_3);										//katoda3
		PORTC->PCR[CAT_4] = PORT_PCR_MUX(1UL);			//katoda4	
		PTC->PDDR |= (1UL<<CAT_4);										//katoda4
		PORTC->PCR[CAT_5] = PORT_PCR_MUX(1UL);			//katoda5	
		PTC->PDDR |= (1UL<<CAT_5);										//katoda5	
		PORTC->PCR[CAT_6] = PORT_PCR_MUX(1UL);			//katoda6	
		PTC->PDDR |= (1UL<<CAT_6);										//katoda6				
		PORTC->PCR[CAT_7] = PORT_PCR_MUX(1UL);			//katoda7	
		PTC->PDDR |= (1UL<<CAT_7);										//katoda7
	
/******************color_RED****************************/
	  PORTB->PCR[RED_0] = PORT_PCR_MUX(1UL);			//red0	
		PTB->PDDR |= (1UL<<RED_0);										//red0
		PORTE->PCR[RED_1] = PORT_PCR_MUX(1UL);			//red1	
		PTE->PDDR |= (1UL<<RED_1);										//red1
		PORTE->PCR[RED_2] = PORT_PCR_MUX(1UL);			//red2	
		PTE->PDDR |= (1UL<<RED_2);										//red2
		PORTE->PCR[RED_3] = PORT_PCR_MUX(1UL);			//red3	
		PTE->PDDR |= (1UL<<RED_3);										//red3
		PORTE->PCR[RED_4] = PORT_PCR_MUX(1UL);			//red4	
		PTE->PDDR |= (1UL<<RED_4);										//red4
		PORTE->PCR[RED_5] = PORT_PCR_MUX(1UL);			//red5	
		PTE->PDDR |= (1UL<<RED_5);										//red5	
		PORTE->PCR[RED_6] = PORT_PCR_MUX(1UL);			//red6	
		PTE->PDDR |= (1UL<<RED_6);										//red6				
		PORTC->PCR[RED_7] = PORT_PCR_MUX(1UL);			//red7	
		PTC->PDDR |= (1UL<<RED_7);										//red7
		/******************color_GREEN****************************/
	  PORTE->PCR[GREEN_0] = PORT_PCR_MUX(1UL);		//green0	
		PTE->PDDR |= (1UL<<GREEN_0);									//green0
		PORTE->PCR[GREEN_1] = PORT_PCR_MUX(1UL);		//green1	
		PTE->PDDR |= (1UL<<GREEN_1);									//green1
		PORTE->PCR[GREEN_2] = PORT_PCR_MUX(1UL);		//green2	
		PTE->PDDR |= (1UL<<GREEN_2);									//green2
		PORTE->PCR[GREEN_3] = PORT_PCR_MUX(1UL);		//green3	
		PTE->PDDR |= (1UL<<GREEN_3);									//green3
		PORTB->PCR[GREEN_4] = PORT_PCR_MUX(1UL);		//green4	
		PTB->PDDR |= (1UL<<GREEN_4);									//green4
		PORTB->PCR[GREEN_5] = PORT_PCR_MUX(1UL);		//green5	
		PTB->PDDR |= (1UL<<GREEN_5);									//green5	
		PORTB->PCR[GREEN_6] = PORT_PCR_MUX(1UL);		//green6	
		PTB->PDDR |= (1UL<<GREEN_6);									//green6				
		PORTB->PCR[GREEN_7] = PORT_PCR_MUX(1UL);		//green7	
		PTB->PDDR |= (1UL<<GREEN_7);									//green7
		
		/******************color_BLUE****************************/
	  PORTD->PCR[BLUE_0] = PORT_PCR_MUX(1UL);			//blue0	
		PTD->PDDR |= (1UL<<BLUE_0);										//blue0
		PORTE->PCR[BLUE_1] = PORT_PCR_MUX(1UL);			//blue1	
		PTE->PDDR |= (1UL<<BLUE_1);										//blue1
		PORTA->PCR[BLUE_2] = PORT_PCR_MUX(1UL);			//blue2	
		PTA->PDDR |= (1UL<<BLUE_2);										//blue2
		PORTA->PCR[BLUE_3] = PORT_PCR_MUX(1UL);			//blue3	
		PTA->PDDR |= (1UL<<BLUE_3);										//blue3
		PORTC->PCR[BLUE_4] = PORT_PCR_MUX(1UL);			//blue4	
		PTC->PDDR |= (1UL<<BLUE_4);										//blue4
		PORTC->PCR[BLUE_5] = PORT_PCR_MUX(1UL);			//blue5	
		PTC->PDDR |= (1UL<<BLUE_5);										//blue5	
		PORTC->PCR[BLUE_6] = PORT_PCR_MUX(1UL);			//blue6	
		PTC->PDDR |= (1UL<<BLUE_6);										//blue6				
		PORTC->PCR[BLUE_7] = PORT_PCR_MUX(1UL);			//blue7	
		PTC->PDDR |= (1UL<<BLUE_7);										//blue7

	/*********************wyczysc wszystkie katody************************************/
		PTA->PCOR |= (1<<CAT_0);										//katoda0
		PTA->PCOR |= (1<<CAT_1);										//katoda1
		PTC->PCOR |= (1<<CAT_2);										//katoda2
		PTC->PCOR |= (1<<CAT_3);										//katoda3
		PTC->PCOR |= (1<<CAT_4);										//katoda4
		PTC->PCOR |= (1<<CAT_5);										//katoda5	
		PTC->PCOR |= (1<<CAT_6);										//katoda6				
		PTC->PCOR |= (1<<CAT_7);										//katoda7
}
