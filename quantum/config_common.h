/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONFIG_DEFINITIONS_H
#define CONFIG_DEFINITIONS_H

/* diode directions */
#define COL2ROW       0
#define ROW2COL       1
#define CUSTOM_MATRIX 2 /* Disables built-in matrix scanning code */

#if defined(__AVR__)
    #include <avr/io.h>

    #define PORT_SHIFTER 4

    #if defined(__AVR_ATmega32U4__)
        #define pin_t uint8_t
        #define ADDRESS_BASE 0x00
        #define PINB_ADDRESS 0x3
        #define PINC_ADDRESS 0x6
        #define PIND_ADDRESS 0x9
        #define PINE_ADDRESS 0xC
        #define PINF_ADDRESS 0xF
    #elif defined(__AVR_ATmega32U2__)
        #define pin_t uint8_t
        #define ADDRESS_BASE 0x00
        #define PINB_ADDRESS 0x3
        #define PINC_ADDRESS 0x6
        #define PIND_ADDRESS 0x9
    #elif defined(__AVR_AT90USB1286__)
        #define pin_t uint8_t
        #define ADDRESS_BASE 0x00
        #define PINA_ADDRESS 0x0
        #define PINB_ADDRESS 0x3
        #define PINC_ADDRESS 0x6
        #define PIND_ADDRESS 0x9
        #define PINE_ADDRESS 0xC
        #define PINF_ADDRESS 0xF
    #elif defined(__AVR_ATmega32a__)
        #define pin_t uint8_t
        #define ADDRESS_BASE 0x10
        #define PIND_ADDRESS 0x0
        #define PINC_ADDRESS 0x3
        #define PINB_ADDRESS 0x6
        #define PINA_ADDRESS 0x9
    #else
        #define pin_t uint16_t
        #define ADDRESS_BASE 0x0
    #endif

    /* I/O pins */
    // #define PINDEF(port, pin) (uint8_t)((((uint16_t)&PIN##port) << 4) + PIN##port##pin)
    //#define PINDEF(port, pin) ((pin_t)(((((uint16_t)&PIN##port) - __SFR_OFFSET)<< 4) + PIN##port##pin))
    #define PINDEF(port, pin) ((PIN##port##_ADDRESS << PORT_SHIFTER) | pin)

    #ifdef PORTA
        #define A0 PINDEF(A, 0)
        #define A1 PINDEF(A, 1)
        #define A2 PINDEF(A, 1)
        #define A3 PINDEF(A, 3)
        #define A4 PINDEF(A, 4)
        #define A5 PINDEF(A, 5)
        #define A6 PINDEF(A, 6)
        #define A7 PINDEF(A, 7)
    #endif
    #ifdef PORTB
        #define B0 PINDEF(B, 0)
        #define B1 PINDEF(B, 1)
        #define B2 PINDEF(B, 2)
        #define B3 PINDEF(B, 3)
        #define B4 PINDEF(B, 4)
        #define B5 PINDEF(B, 5)
        #define B6 PINDEF(B, 6)
        #define B7 PINDEF(B, 7)
    #endif
    #ifdef PORTC
        #define C0 PINDEF(C, 0)
        #define C1 PINDEF(C, 1)
        #define C2 PINDEF(C, 2)
        #define C3 PINDEF(C, 3)
        #define C4 PINDEF(C, 4)
        #define C5 PINDEF(C, 5)
        #define C6 PINDEF(C, 6)
        #define C7 PINDEF(C, 7)
    #endif
    #ifdef PORTD
        #define D0 PINDEF(D, 0)
        #define D1 PINDEF(D, 1)
        #define D2 PINDEF(D, 2)
        #define D3 PINDEF(D, 3)
        #define D4 PINDEF(D, 4)
        #define D5 PINDEF(D, 5)
        #define D6 PINDEF(D, 6)
        #define D7 PINDEF(D, 7)
    #endif
    #ifdef PORTE
        #define E0 PINDEF(E, 0)
        #define E1 PINDEF(E, 1)
        #define E2 PINDEF(E, 2)
        #define E3 PINDEF(E, 3)
        #define E4 PINDEF(E, 4)
        #define E5 PINDEF(E, 5)
        #define E6 PINDEF(E, 6)
        #define E7 PINDEF(E, 7)
    #endif
    #ifdef PORTF
        #define F0 PINDEF(F, 0)
        #define F1 PINDEF(F, 1)
        #define F2 PINDEF(F, 2)
        #define F3 PINDEF(F, 3)
        #define F4 PINDEF(F, 4)
        #define F5 PINDEF(F, 5)
        #define F6 PINDEF(F, 6)
        #define F7 PINDEF(F, 7)
    #endif
#endif

#if defined(PROTOCOL_CHIBIOS)
    #include "hal.h"
    #define pin_t uint64_t

    #ifdef GPIOA
        #define A0 (GPIOA + 0)
        #define A1 (GPIOA + 1)
        #define A2 (GPIOA + 2)
        #define A3 (GPIOA + 3)
        #define A4 (GPIOA + 4)
        #define A5 (GPIOA + 5)
        #define A6 (GPIOA + 6)
        #define A7 (GPIOA + 7)
        #define A8 (GPIOA + 8)
        #define A9 (GPIOA + 9)
        #define A10 (GPIOA + 10)
        #define A11 (GPIOA + 11)
        #define A12 (GPIOA + 12)
        #define A13 (GPIOA + 13)
        #define A14 (GPIOA + 14)
        #define A15 (GPIOA + 15)
    #endif

    #ifdef GPIOB
        #define B0 (GPIOB + 0)
        #define B1 (GPIOB + 1)
        #define B2 (GPIOB + 2)
        #define B3 (GPIOB + 3)
        #define B4 (GPIOB + 4)
        #define B5 (GPIOB + 5)
        #define B6 (GPIOB + 6)
        #define B7 (GPIOB + 7)
        #define B8 (GPIOB + 8)
        #define B9 (GPIOB + 9)
        #define B10 (GPIOB + 10)
        #define B11 (GPIOB + 11)
        #define B12 (GPIOB + 12)
        #define B13 (GPIOB + 13)
        #define B14 (GPIOB + 14)
        #define B15 (GPIOB + 15)
    #endif

    #ifdef GPIOC
        #define C0 (GPIOC + 0)
        #define C1 (GPIOC + 1)
        #define C2 (GPIOC + 2)
        #define C3 (GPIOC + 3)
        #define C4 (GPIOC + 4)
        #define C5 (GPIOC + 5)
        #define C6 (GPIOC + 6)
        #define C7 (GPIOC + 7)
        #define C8 (GPIOC + 8)
        #define C9 (GPIOC + 9)
        #define C10 (GPIOC + 10)
        #define C11 (GPIOC + 11)
        #define C12 (GPIOC + 12)
        #define C13 (GPIOC + 13)
        #define C14 (GPIOC + 14)
        #define C15 (GPIOC + 15)
    #endif

#endif


/* USART configuration */
#ifdef BLUETOOTH_ENABLE
#   ifdef __AVR_ATmega32U4__
#      define SERIAL_UART_BAUD 9600
#      define SERIAL_UART_DATA UDR1
#      define SERIAL_UART_UBRR (F_CPU / (16UL * SERIAL_UART_BAUD) - 1)
#      define SERIAL_UART_RXD_VECT USART1_RX_vect
#      define SERIAL_UART_TXD_READY (UCSR1A & _BV(UDRE1))
#      define SERIAL_UART_INIT() do { \
            /* baud rate */ \
            UBRR1L = SERIAL_UART_UBRR; \
            /* baud rate */ \
            UBRR1H = SERIAL_UART_UBRR >> 8; \
            /* enable TX */ \
            UCSR1B = _BV(TXEN1); \
            /* 8-bit data */ \
            UCSR1C = _BV(UCSZ11) | _BV(UCSZ10); \
            sei(); \
        } while(0)
#   else
#       error "USART configuration is needed."
#   endif
#endif

#define API_SYSEX_MAX_SIZE 32

#include "song_list.h"

#endif
