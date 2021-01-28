/*
 * macros.h
 *
 *  Created on: Nov 20, 2020
 *      Author: Vangard Vangard
 */

#ifndef MACROS_H_
#define MACROS_H_

#define setbit(port,pin)  (port |= (1<<pin))
#define clearbit(port,pin)  (port &= ~(1<<pin))
#define togglebit(port,pin)  (port ^= (1<<pin))
#define readbit(port,pin) (port&(1<<pin))

#endif /* MACROS_H_ */
