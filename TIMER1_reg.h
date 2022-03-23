/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 15/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : REGISTERS USED TIMER(1)     */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _TIMER1_REG_H_
#define   _TIMER1_REG_H_

 
#define          TCCR1A         *((volatile u8*)0x4F)
#define          TCCR1B         *((volatile u8*)0x4E)

#define          TIMSK          *((volatile u8*)0x59)

#define          TCNT1          *((volatile u16*)0x4C)

#define          TCNT1L         *((volatile u8*)0x4C)
#define          TCNT1H         *((volatile u8*)0x4D)

#define          OCR1AH         *((volatile u8*)0x4B)
#define          OCR1AL         *((volatile u8*)0x4A)
#define          OCR1BH         *((volatile u8*)0x49)
#define          OCR1BL         *((volatile u8*)0x48)

#define          ICR1H          *((volatile u8*)0x47)
#define          ICR1L          *((volatile u8*)0x46)

#define          SREG           *((volatile u8*)0X5F)

#endif
