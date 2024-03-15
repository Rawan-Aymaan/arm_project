
#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#define SPI1_MODE_SLAVE  0
#define SPI1_MODE_MASTER 1
/***************************************************/
#define SPI1_MODE SPI1_MODE_MASTER
/***************************************************/
#define SPI1_DATA_LENGTH_8  0
#define SPI1_DATA_LENGTH_16 1
/***************************************************/
#define SPI1_DATA_LENGTH SPI1_DATA_LENGTH_8
/***************************************************/
#define SPI1_FRAME_FORMAT_MSB_FIRST 0
#define SPI1_FRAME_FORMAT_LSB_FIRST 1
/***************************************************/
#define SPI1_FRAME_FORMAT SPI1_FRAME_FORMAT_MSB_FIRST
/***************************************************/
#define SPI1_CLK_BAUDRATE_2   0
#define SPI1_CLK_BAUDRATE_4   1
#define SPI1_CLK_BAUDRATE_8   2
#define SPI1_CLK_BAUDRATE_16  3
#define SPI1_CLK_BAUDRATE_32  4
#define SPI1_CLK_BAUDRATE_64  5
#define SPI1_CLK_BAUDRATE_128 6
#define SPI1_CLK_BAUDRATE_256 7
/***************************************************/
#define SPI1_CLK_BAUDRATE SPI1_CLK_BAUDRATE_2
/***************************************************/
#define SPI1_CLK_POLARITY_IDLE0 0
#define SPI1_CLK_POLARITY_IDLE1 1
/***************************************************/
#define SPI1_CLK_POLARITY SPI1_CLK_POLARITY_IDLE1
/***************************************************/

#define SPI1_CLK_PHASE_LE_CAPTURE 0
#define SPI1_CLK_PHASE_TE_CAPTURE 1
/***************************************************/
#define SPI1_CLK_PHASE SPI1_CLK_PHASE_LE_CAPTURE
/***************************************************/

#endif /* SPI_CONFIG_H_ */
