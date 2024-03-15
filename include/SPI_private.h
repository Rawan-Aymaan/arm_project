

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI1_BASE_ADDRESS (0x40013000)

typedef struct{
	u32 CR1;
	u32 Reserved1;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}tstrSPI_registers;

#define SPI1_REG ((volatile tstrSPI_registers *) SPI1_BASE_ADDRESS)

#endif /* SPI_PRIVATE_H_ */
