/*
 * BCDSevSeg_cfg.h
 *
 * Created: 9/29/2020 11:14:15 PM
 *  Author: Moataz
 */ 


#ifndef BCDSEVSEG_CFG_H_
#define BCDSEVSEG_CFG_H_

/***seven segment ports***/
#define BCDSevSeg_Data		('C')
#define BCDSevSeg_Ctrl		('B')

/***4 PINS for the BCD seven segment data pins***/
/*
 *LOW_NIBBLE
 *HIGH_NIBBLE
 */
#define BCDSevSeg_PORT		LOW_NIBBLE

/***LCD data pins***/
#define BCDSevSeg_PIN_A		0
#define BCDSevSeg_PIN_B		1
#define BCDSevSeg_PIN_C		2
#define BCDSevSeg_PIN_D		3

/***LCD control pins***/
#define BCDSevSeg_EN2	1
#define BCDSevSeg_EN1	2
#define BCDSevSeg_DIP	3

#endif /* BCDSEVSEG_CFG_H_ */