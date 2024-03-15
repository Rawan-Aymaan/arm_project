/*********************************************
 * Author:          Sondos Ghieth 
 * Creation Data:   22 OCT, 2022
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
 
 /* Header Guard File */
 #ifndef BIT_MATH_H
 #define BIT_MATH_H
 
 /*  function like macro to Manipulate Over specific bit     */
 #define SET_BIT(REG_NAME,BIT_NUM)         (REG_NAME |=(1 << BIT_NUM))
 #define CLR_BIT(REG_NAME,BIT_NUM)         (REG_NAME &=(~(1 << BIT_NUM)))
 #define TOG_BIT(REG_NAME,BIT_NUM)         (REG_NAME ^=(1 << BIT_NUM))
 #define GET_BIT(REG_NAME,BIT_NUM)         ((REG_NAME>>BIT_NUM)&0b00000001)

  
 #endif 
