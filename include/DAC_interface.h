

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_


void HR2RDAC_vInit(void);
void HR2RDAC_vSetData(const u8*arr,u32 arrsize,u8*stp_dac, u8*pause_flag);


#endif /* DAC_INTERFACE_H_ */
