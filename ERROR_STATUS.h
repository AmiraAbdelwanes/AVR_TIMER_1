/**********************************************/
/*Auther  :YASMIN ASHRAF TOEMA                */
/*Version :V01                                */  
/*Date    :25/3/2020                          */
/*Descriotion :Error Status                   */ 
/**********************************************/

/***********************************************/
/* Guard of file will call one time in .c      */
/***********************************************/


#ifndef _ERROR_STATUS_H_ 
#define _ERROR_STATUS_H_

typedef enum Error
{
	ES_OK,
	ES_NOK,
	ES_OUT_OF_RANGE,
	ES_NULL_POINTER
}ErrorStatus;

#endif