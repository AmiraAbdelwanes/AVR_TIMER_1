/****************************************************/
/****AUTHOR       : Moaaz Rashad Sewilam            */
/****Date         : 15/04/2020                      */
/****Version      : 1.0  V                          */
/*****Description : TIMER(1)FUNCTION IMPLEMENTATION */
/****************************************************/


/***************************************************/
/**********  STANDARD LIB DIRECTIVES ***************/
/***************************************************/

#include <util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"


/***************************************************/
/********** COMPONENTS DIRECTIVES    ***************/
/***************************************************/


#include "TIMER1_int.h"
#include "TIMER1_priv.h"
#include "TIMER1_config.h"
#include "TIMER1_reg.h"


#define    NULL     ((void *)0)


volatile void (*pf_3)(void) = NULL ; 
volatile void (*pf_4)(void) = NULL ;
volatile void (*pf_5)(void) = NULL ; 
volatile void (*pf_6)(void) = NULL ;

/************************************************/
/* THIS FUNCTION FOR INITIALIZTION TIMER(1)     */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

ErrorStatus   TIMER1_enuInit(void)
{
	ErrorStatus  Local_enuError = ES_NOK;
	#if        FORCE_OUTPUT_COMPARE_A    ==   ENABLE_FOC1A
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1A , 3);
	#else
         	Local_enuError = ES_OK;
		    CLR_BIT(TCCR1A , 3);
	#endif
	/****************************************/
	#if        FORCE_OUTPUT_COMPARE_B    ==   ENABLE_FOC1B
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1A , 2);
	#else
         	Local_enuError = ES_OK;
		    CLR_BIT(TCCR1A , 2);
	#endif
    /****************************************/	
	#if        WAVE_GENERATION_MODE_1    ==   NORMAL_1
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1A , 0); //WGM10
			CLR_BIT(TCCR1A , 1); //WGM11
			CLR_BIT(TCCR1B , 3); //WGM12
			CLR_BIT(TCCR1B , 4); //WGM13
			/* Normal port operation, OC1A & OC1B disconnected */
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
	#elif      WAVE_GENERATION_MODE_1    ==   PWM_PHASE_CORRECT_8BITS 
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1A , 0); //WGM10
			CLR_BIT(TCCR1A , 1); //WGM11
			CLR_BIT(TCCR1B , 3); //WGM12
			CLR_BIT(TCCR1B , 4); //WGM13
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE _1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif
	#elif      WAVE_GENERATION_MODE_1    ==   PWM_PHASE_CORRECT_9BITS 
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1A , 0); //WGM10
			SET_BIT(TCCR1A , 1); //WGM11
			CLR_BIT(TCCR1B , 3); //WGM12
			CLR_BIT(TCCR1B , 4); //WGM13
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE _1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif					
	#elif      WAVE_GENERATION_MODE_1    ==   PWM_PHASE_CORRECT_10BITS 
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1A , 0); //WGM10
			SET_BIT(TCCR1A , 1); //WGM11
			CLR_BIT(TCCR1B , 3); //WGM12
			CLR_BIT(TCCR1B , 4); //WGM13
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE _1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif					
	#elif      WAVE_GENERATION_MODE_1    ==   CTC_OCR1A 
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1A , 0); //WGM10
			CLR_BIT(TCCR1A , 1); //WGM11
			SET_BIT(TCCR1B , 3); //WGM12
			CLR_BIT(TCCR1B , 4); //WGM13
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE _1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif					
	#elif      WAVE_GENERATION_MODE_1    ==   FAST_PWM_8BITS 
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1A , 0); //WGM10
			CLR_BIT(TCCR1A , 1); //WGM11
			SET_BIT(TCCR1B , 3); //WGM12
			CLR_BIT(TCCR1B , 4); //WGM13
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE_1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITSA
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif
	#elif      WAVE_GENERATION_MODE_1    ==   FAST_PWM_9BITS 
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1A , 0); //WGM10
			SET_BIT(TCCR1A , 1); //WGM11
			SET_BIT(TCCR1B , 3); //WGM12
			CLR_BIT(TCCR1B , 4); //WGM13
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE _1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif	
	#elif      WAVE_GENERATION_MODE_1    ==   FAST_PWM_10BITS 
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1A , 0); //WGM10
			SET_BIT(TCCR1A , 1); //WGM11
			SET_BIT(TCCR1B , 3); //WGM12
			CLR_BIT(TCCR1B , 4); //WGM13
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE _1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif
	#elif      WAVE_GENERATION_MODE_1    ==   PWM_PHASE_FREQ_ICR1 
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1A , 0); //WGM10
			CLR_BIT(TCCR1A , 1); //WGM11
			CLR_BIT(TCCR1B , 3); //WGM12
			SET_BIT(TCCR1B , 4); //WGM13	
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE _1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif
	#elif      WAVE_GENERATION_MODE_1    ==   PWM_PHASE_FREQ_OCR1A 
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1A , 0); //WGM10
			CLR_BIT(TCCR1A , 1); //WGM11
			CLR_BIT(TCCR1B , 3); //WGM12
			SET_BIT(TCCR1B , 4); //WGM13	
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE_1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif
	#elif      WAVE_GENERATION_MODE_1    ==   PWM_PHASE_ICR1 
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1A , 0); //WGM10
			SET_BIT(TCCR1A , 1); //WGM11
			CLR_BIT(TCCR1B , 3); //WGM12
			SET_BIT(TCCR1B , 4); //WGM13	
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE_1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif
	#elif      WAVE_GENERATION_MODE_1    ==   PWM_PHASE_OCR1A 
	        Local_enuError =ES_OK;
			SET_BIT(TCCR1A , 0); //WGM10
			SET_BIT(TCCR1A , 1); //WGM11
			CLR_BIT(TCCR1B , 3); //WGM12
			SET_BIT(TCCR1B , 4); //WGM13	
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE_1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif	
	#elif      WAVE_GENERATION_MODE_1    ==   CTC_ICR1 
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1A , 0); //WGM10
			CLR_BIT(TCCR1A , 1); //WGM11
			SET_BIT(TCCR1B , 3); //WGM12
			SET_BIT(TCCR1B , 4); //WGM13	
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE_1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif
			
	#elif      WAVE_GENERATION_MODE_1    ==   RESERVED 
			#error "WAVE_GENERATION_MODE PROHIBTED "
			
	#elif      WAVE_GENERATION_MODE_1    ==   FAST_PWM_ICR1 
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1A , 0); //WGM10
			SET_BIT(TCCR1A , 1); //WGM11
			SET_BIT(TCCR1B , 3); //WGM12
			SET_BIT(TCCR1B , 4); //WGM13	
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE_1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif	
	#elif      WAVE_GENERATION_MODE_1    ==   FAST_PWM_OCR1A 
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1A , 0); //WGM10
			SET_BIT(TCCR1A , 1); //WGM11
			SET_BIT(TCCR1B , 3); //WGM12
			SET_BIT(TCCR1B , 4); //WGM13	
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE_1  ==  NORMAL_PORT_OPERATION_1
            CLR_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  TOGGLE_BITS
            SET_BIT(TCCR1A , 4); //COM1B0
			CLR_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			CLR_BIT(TCCR1A , 7); //COM1A1
            #elif   COMPARE_OUTPUT_MODE_1   ==  CLR_BITS
            CLR_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            CLR_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
            #elif   COMPARE_OUTPUT_MODE_1   ==  SET_BITS 
            SET_BIT(TCCR1A , 4); //COM1B0
			SET_BIT(TCCR1A , 5); //COM1B1
            SET_BIT(TCCR1A , 6); //COM1A0
			SET_BIT(TCCR1A , 7); //COM1A1			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif							
    #else
           #error "WAVE_GENERATION_MODE  NOT SELECTED"
    #endif
    /*****************************************/
    #if             CLOCK_SELECT_1            ==   NO_CLOCK_SOURCE_1
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1B , 0); //CS10
			CLR_BIT(TCCR1B , 1); //CS11
			CLR_BIT(TCCR1B , 2); //CS12
    #elif             CLOCK_SELECT_1          ==   NO_PRESCALING_1
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1B , 0); //CS10
			CLR_BIT(TCCR1B , 1); //CS11
			CLR_BIT(TCCR1B , 2); //CS12
    #elif             CLOCK_SELECT_1          ==   PRESCALER1_8
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1B , 0); //CS10
			SET_BIT(TCCR1B , 1); //CS11
			CLR_BIT(TCCR1B , 2); //CS12
    #elif             CLOCK_SELECT_1          ==   PRESCALER1_64
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1B , 0); //CS10
			SET_BIT(TCCR1B , 1); //CS11
			CLR_BIT(TCCR1B , 2); //CS12
    #elif             CLOCK_SELECT_1          ==   PRESCALER1_256
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1B , 0); //CS10
			CLR_BIT(TCCR1B , 1); //CS11
			SET_BIT(TCCR1B , 2); //CS12
    #elif             CLOCK_SELECT_1          ==   PRESCALER1_1024
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1B , 0); //CS10
			CLR_BIT(TCCR1B , 1); //CS11
			SET_BIT(TCCR1B , 2); //CS12
    #elif             CLOCK_SELECT_1          ==   EXT_CLK_T1_FALLING_EDGE
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR1B , 0); //CS10
			SET_BIT(TCCR1B , 1); //CS11
			SET_BIT(TCCR1B , 2); //CS12
    #elif             CLOCK_SELECT_1          ==   EXT_CLK_T1_RISING_EDGE
	        Local_enuError = ES_OK;
			SET_BIT(TCCR1B , 0); //CS10
			SET_BIT(TCCR1B , 1); //CS11
			SET_BIT(TCCR1B , 2); //CS12
    #else 
          #error "CLOCK_SELECT_1 NOT SELECTED"
    #endif	  
	
    return Local_enuError; 	
}
void Init_Fast_PWM_CHB(void)
{
	CLR_BIT(TCCR1A , 3);
	CLR_BIT(TCCR1A , 2);

	SET_BIT(TCCR1A , 0); //WGM10
	CLR_BIT(TCCR1A , 1); //WGM11
	SET_BIT(TCCR1B , 3); //WGM12
	CLR_BIT(TCCR1B , 4); //WGM13
    //Prescaler
	SET_BIT(TCCR1B , 0); //CS10
	CLR_BIT(TCCR1B , 1); //CS11
	CLR_BIT(TCCR1B , 2); //CS12
	//CLR bits compare match mode
	CLR_BIT(TCCR1A , 4); //COM1B0
	SET_BIT(TCCR1A , 5); //COM1B1
	CLR_BIT(TCCR1A , 6); //COM1A0
	CLR_BIT(TCCR1A , 7); //COM1A1
}




/************************************************/
/* THIS FUNCTION FOR SETTING TIMER(1) REGISTERS */
/* INPUTS : UNSIGHNED SHORT                     */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuSetTimerReg(u16 Copy_u16Value)
{
	TCNT1H = (u8)(Copy_u16Value >> 8);
	TCNT1L = (u8)(Copy_u16Value);
}


/************************************************/
/* THIS FUNCTION FOR SETTING THE COMPARE VALUE  */
/*            FOR TIMER(1) CHANNEL(A)           */
/* INPUTS : UNSIGHNED SHORT                     */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuSetCompareChannelA(u16 Copy_u16Value)
{
	OCR1AH = (u8)(Copy_u16Value >> 8);
	OCR1AL = (u8)(Copy_u16Value);
}


/************************************************/
/* THIS FUNCTION FOR SETTING THE COMPARE VALUE  */
/*            FOR TIMER(1) CHANNEL(B)           */
/* INPUTS : UNSIGHNED SHORT                     */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuSetCompareChannelB(u16 Copy_u16Value)
{
	OCR1BH = (u8)(Copy_u16Value >> 8);
	OCR1BL = (u8)(Copy_u16Value);
}


/************************************************/
/* THIS FUNCTION FOR SETTING INPUT CAPTURE      */
/*            REGISTERS FOR TIMER(1)            */
/* INPUTS : UNSIGHNED SHORT                     */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuSetICR(u16 Copy_u16Value)
{
	ICR1H = (u8)(Copy_u16Value >> 8);
	ICR1L = (u8)(Copy_u16Value);
}


/************************************************/
/* THIS FUNCTION FOR ENABLING OVER-FLOW         */
/*          INTERRUOT  FOR TIMER (1)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuEnableOVInt(void)
{
	SET_BIT(TIMSK , 2);
}



/************************************************/
/* THIS FUNCTION FOR DISABLING OVER-FLOW        */
/*           INTERRUPT FOR TIMER (1)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuDisableOVInt(void)
{
	CLR_BIT(TIMSK , 2);
}


/************************************************/
/* THIS FUNCTION FOR ENABLING OUTPUT COMPARE    */
/*  INTERRUPT ENABLE FOR TIMER(1) CHANNEL(B)    */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuEnableOCBInt(void)
{
	SET_BIT(TIMSK , 3);
}


/************************************************/
/* THIS FUNCTION FOR DISABLING OUTPUT COMPARE   */
/*  INTERRUPT ENABLE FOR TIMER(1) CHANNEL(B)    */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuDisableOCBInt(void)
{
	CLR_BIT(TIMSK , 3);
}


/************************************************/
/* THIS FUNCTION FOR ENABLING OUTPUT COMPARE    */
/*  INTERRUPT ENABLE FOR TIMER(1) CHANNEL(A)    */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuEnableOCAInt(void)
{
	SET_BIT(TIMSK , 4);
}


/************************************************/
/* THIS FUNCTION FOR DISABLING OUTPUT COMPARE   */
/*  INTERRUPT ENABLE FOR TIMER(1) CHANNEL(A)    */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuDisableOCAInt(void)
{
	CLR_BIT(TIMSK , 4);
}


/************************************************/
/* THIS FUNCTION FOR ENABLING INPUT CAPTURE     */
/*  INTERRUPT ENABLE FOR TIMER(1)               */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuEnableICRInt(void)
{
	SET_BIT(TIMSK , 5);
}


/************************************************/
/* THIS FUNCTION FOR DISABLING INPUT CAPTURE    */
/*  INTERRUPT ENABLE FOR TIMER(1)               */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuDisableICRInt(void)
{
	CLR_BIT(TIMSK , 5);
}

/************************************************/
/* THIS FUNCTION FOR POINT TO THE OVER-FLOW     */
/*                 TIMER(1)  FUNCTION           */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER1_vidSetOVCallBack( void (*Copy_ptr)(void))
{
	pf_3 = Copy_ptr ;
}

void __vector_9()__attribute__((signal,used));

void __vector_9()
{
	pf_3();
}


/************************************************/
/* THIS FUNCTION FOR POINT TO THE COMPARE MODE  */
/*     TIMER(1) FUNCTION  CHANNEL(B)            */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER1_vidSetOCBCallBack( void (*Copy_ptr)(void))
{
	pf_4 = Copy_ptr ;
}

void __vector_8()__attribute__((signal,used));

void __vector_8()
{
	pf_4();
}

/************************************************/
/* THIS FUNCTION FOR POINT TO THE COMPARE MODE  */
/*     TIMER(1) FUNCTION  CHANNEL(A)            */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER1_vidSetOCACallBack( void (*Copy_ptr)(void))
{
	pf_5 = Copy_ptr ;
}

void __vector_7()__attribute__((signal,used));

void __vector_7()
{
	pf_5();
}

/************************************************/
/* THIS FUNCTION FOR POINT TO THE CAPTURE EVENT */
/*     TIMER(1) FUNCTION                        */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER1_vidSetICRCallBack( void (*Copy_ptr)(void))
{
	pf_6 = Copy_ptr ;
}

void __vector_6()__attribute__((signal,used));

void __vector_6()
{
	pf_6();
}
