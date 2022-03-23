/**********************************************/
/*Auther      :YASMIN ASHRAF TOEMA            */
/*Version     :V01                            */  
/*Date        :25/3/2020                      */
/*Descriotion :                               */
/*Define how to set bit,clear bit,toggle bit, */
/*get bit and assign bit using bit math       */
/**********************************************/

/***********************************************/
/* Guard of file will call one time in .c      */
/***********************************************/

#ifndef _BIT_MATH_H_ 
#define _BIT_MATH_H_


#define SET_BIT(var,BIT_NO) var|=(1<<BIT_NO)
#define CLR_BIT(var,BIT_NO) var&=~(1<<BIT_NO)
#define TOG_BIT(var,BIT_NO) var^=(1<<BIT_NO)
#define GET_BIT(var,BIT_NO) ((var>>BIT_NO)&1)
#define ASSIGN_BIT(var,BIT_NO,value) var=((var&(~(1<<BIT_NO)))|(val<<BIT_NO)

#endif