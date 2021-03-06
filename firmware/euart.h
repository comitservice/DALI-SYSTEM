#ifndef _EUART_H_
#define _EUART_H_

#include <avr/io.h>

#ifdef __cplusplus
extern "C"
{
#endif

#include "eusart_drv.h"

typedef enum encoding_mode {LEVEL, MANCHESTER} t_encoding;
typedef enum bit_order {MSB_FIRST, LSB_FIRST} t_bit_order;
typedef enum parity_type {PARITY_NONE=0x00,PARITY_EVEN=0x20, PARITY_ODD=0x30} t_parity_type;

#if (defined __C51__)
typedef bit                 Bool;    // Shall be used with _MEM_TYPE_BIT_ to optimize the memory.
#else
typedef unsigned char       Bool;
#endif

#define FALSE   (0==1)
#define TRUE    (1==1)

typedef unsigned char       Uchar;


typedef unsigned char       Uint8;
typedef unsigned int        Uint16;
typedef unsigned long int   Uint32;

typedef char                Int8;
typedef int                 Int16;
typedef long int            Int32;

typedef unsigned char       Byte;
typedef unsigned int        Word;
typedef unsigned long int   DWord;

typedef union
{
  Uint16 w;
  Uint8  b[2];
} Union16;

typedef union
{
  Uint32 dw; // l changed in dw (double word) because l is used for signed long...
  Uint16 w[2];
  Uint8  b[4];
} Union32;

extern Uint8 eusart_rx_error;

Bool euart_init();

Bool euart_enable_rx(Bool enable);

Bool euart_tx_done(void);

Uint16 euart_put(Uint16 uc_wr_byte);

Bool euart_rx_ready(void);

Uint8 euart_get(void);

#ifdef __cplusplus
}
#endif

#endif
