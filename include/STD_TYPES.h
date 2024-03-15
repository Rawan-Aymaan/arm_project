/*********************************************
 * Author:          Sondos Ghieth 
 * Creation Data:   22 OCT, 2022
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
 
 /* Header Guard File */
 #ifndef STD_TYPES_H
 #define STD_TYPES_H
 
 
 typedef  unsigned char          u8  ;
 typedef  signed char            s8  ;
 
 typedef  unsigned short int     u16 ;
 typedef  signed short int       s16 ;
 typedef  unsigned long int      u32 ;
 typedef  signed long int        s32 ;
 
 typedef  float            		f32 ;
 
 typedef  double           		f64;
 typedef  long double            f128;

 #define TRUE                     1 
 #define FALSE                    0

 #define  NULL                    (void *)0   /* NULL --> void pointer point to zero */

 typedef void (*pf)(void);

 #define NULL_PTR ((void*)0)
 #endif
