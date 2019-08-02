/*
 * comm.h
 *
 * Created: 26.4.2019. 20.00.51
 *  Author: Kovacevic
 */ 


#ifndef COMM_H_
#define COMM_H_

#define  F_CPU 16000000UL
#define  SET_BIT(REGx, PINx)	REGx|=(1<<PINx)		//nisu testirana ova dva makroa
#define  RESET_BIT(REGx, PINx)	REGx&=~(1<<PINx)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <inttypes.h>
#include <stdio.h>
#include <avr/pgmspace.h>


#endif /* COMM_H_ */