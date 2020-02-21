/* 
 * File:   sensor.h
 * Author: Morgan Diepart
 *
 * Created on 15 f�vrier 2020, 01:21
 */

#ifndef SENSOR_H
#define	SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#define L_EN            0b10000000
#define R_EN            0b01000000
#define XTALK           0b00100000
#define AUTO_INC        0b00010000
#define CONT_MODE       0b00001000
#define CONV            0b00000100
#define CONV_FINISHED   0b00000010
    
#include "Api/inc/core/vl53l0x_api.h"
    
    extern VL53L0X_DEV RightSensor, LeftSensor; /*Sensors handles*/

    /* Config Updated flag */
    extern bool CONFIG_UPDATEDflag;
    
    /*Config low register*/
    extern bool L_ENflag;
    extern bool R_ENflag;
    extern bool XTALKflag;
    extern bool AUTO_INCflag;
    extern bool CONT_MODEflag;
    extern bool CONVflag;
    extern bool CONV_FINISHEDflag;

    /*Config high register*/
    extern uint8_t INT_MODEflags; /* 2 bits */
    extern uint8_t DURATIONval; /* 6 bits */
    
    extern uint8_t I2C_ADDRESSvalue;
    
    /* Distances */
    extern uint8_t leftDist;
    extern uint8_t rightDist;
    extern uint8_t avgDist;
    extern uint8_t *minDist;
    extern uint8_t *maxDist;
    
    void powerOffRightSensor();
    void powerOnRightSensor();
    void powerOffLeftSensor();
    void powerOnLeftSensor();
    
    void setConfigL(uint8_t config_l);
    void setConfigH(uint8_t config_l);
    
    void disableXTalk();
    void enableXTalk();
    
    uint8_t getConfigL();
    uint8_t getConfigH();

    void updateConfig();
#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

