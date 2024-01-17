#ifndef __IO_H__
#define __IO_H__

/* Dependencies */
#include <stddef.h>
#include <avr/io.h> /* Memory */

/* Macros */
#define INPUT  (uint8_t)0
#define OUTPUT (uint8_t)1
#define LOW    (uint8_t)0
#define HIGH   (uint8_t)1
#define TOGGLE (uint8_t)2

class __IO__
{
    public:
        __IO__();
        ~__IO__();
        uint8_t setMode(volatile uint8_t* ddr, const uint8_t bit, const uint8_t mode);
        uint8_t setMode(volatile uint8_t* ddr, const uint8_t mode);
        uint8_t write  (volatile uint8_t* dor, const uint8_t bit, const uint8_t state);
        uint8_t write  (volatile uint8_t* dor, const uint8_t state);
        uint8_t read   (volatile uint8_t* dir, const uint8_t bit);
        uint8_t read   (volatile uint8_t* dir);
};
extern __IO__ IO;

#endif
