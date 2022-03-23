/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 15/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : TIMER (1)                   */
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _TIMER1_INT_H_
#define   _TIMER1_INT_H_


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION TIMER(1)     */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

ErrorStatus   TIMER1_enuInit(void);

/************************************************/
/* THIS FUNCTION FOR SETTING TIMER(1) REGISTERS */
/* INPUTS : UNSIGHNED SHORT                     */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuSetTimerReg(u16 Copy_u16Value);


/************************************************/
/* THIS FUNCTION FOR SETTING THE COMPARE VALUE  */
/*            FOR TIMER(1) CHANNEL(A)           */
/* INPUTS : UNSIGHNED SHORT                     */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuSetCompareChannelA(u16 Copy_u16Value);


/************************************************/
/* THIS FUNCTION FOR SETTING THE COMPARE VALUE  */
/*            FOR TIMER(1) CHANNEL(B)           */
/* INPUTS : UNSIGHNED SHORT                     */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuSetCompareChannelB(u16 Copy_u16Value);


/************************************************/
/* THIS FUNCTION FOR SETTING INPUT CAPTURE      */
/*            REGISTERS FOR TIMER(1)            */
/* INPUTS : UNSIGHNED SHORT                     */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuSetICR(u16 Copy_u16Value);


/************************************************/
/* THIS FUNCTION FOR ENABLING OVER-FLOW         */
/*          INTERRUOT  FOR TIMER (1)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuEnableOVInt(void);



/************************************************/
/* THIS FUNCTION FOR DISABLING OVER-FLOW        */
/*           INTERRUPT FOR TIMER (1)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuDisableOVInt(void);


/************************************************/
/* THIS FUNCTION FOR ENABLING OUTPUT COMPARE    */
/*  INTERRUPT ENABLE FOR TIMER(1) CHANNEL(B)    */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuEnableOCBInt(void);


/************************************************/
/* THIS FUNCTION FOR DISABLING OUTPUT COMPARE   */
/*  INTERRUPT ENABLE FOR TIMER(1) CHANNEL(B)    */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuDisableOCBInt(void);


/************************************************/
/* THIS FUNCTION FOR ENABLING OUTPUT COMPARE    */
/*  INTERRUPT ENABLE FOR TIMER(1) CHANNEL(A)    */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuEnableOCAInt(void);


/************************************************/
/* THIS FUNCTION FOR DISABLING OUTPUT COMPARE   */
/*  INTERRUPT ENABLE FOR TIMER(1) CHANNEL(A)    */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuDisableOCAInt(void);


/************************************************/
/* THIS FUNCTION FOR ENABLING INPUT CAPTURE     */
/*  INTERRUPT ENABLE FOR TIMER(1)               */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuEnableICRInt(void);

/************************************************/
/* THIS FUNCTION FOR DISABLING INPUT CAPTURE    */
/*  INTERRUPT ENABLE FOR TIMER(1)               */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER1_enuDisableICRInt(void);

/************************************************/
/* THIS FUNCTION FOR POINT TO THE OVER-FLOW     */
/*                 TIMER(1)  FUNCTION           */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER1_vidSetOVCallBack( void (*Copy_ptr)(void));


/************************************************/
/* THIS FUNCTION FOR POINT TO THE COMPARE MODE  */
/*     TIMER(1) FUNCTION  CHANNEL(B)            */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER1_vidSetOCBCallBack( void (*Copy_ptr)(void));


/************************************************/
/* THIS FUNCTION FOR POINT TO THE COMPARE MODE  */
/*     TIMER(1) FUNCTION  CHANNEL(A)            */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER1_vidSetOCACallBack( void (*Copy_ptr)(void));


/************************************************/
/* THIS FUNCTION FOR POINT TO THE CAPTURE EVENT */
/*     TIMER(1) FUNCTION                        */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER1_vidSetICRCallBack( void (*Copy_ptr)(void));

//
void Init_Fast_PWM_CHB(void);

#endif
