

#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

#define TFT_Arr_Size   20480

void TFT_voidvInit(void);

void TFT_PinsEnable(void);


void TFT_voidDisplay( const u16  * Copy_ptrImage);//2Byte for every pixel


void TFT_voidDisplay_Proutus(const u16  * Copy_ptrImage);



#endif /* TFT_INTERFACE_H_ */
