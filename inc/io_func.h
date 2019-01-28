/*
 * stdio_func.h
 *
 *  Created on: Sep 11, 2018
 *      Author: lstefana
 *
 *      Support functions for printing.
 */

#include <stdint.h>

#ifndef SRC_IO_FUNC_H_
#define SRC_IO_FUNC_H_

void io_sprintf(char *str, char *fmt, ...);
void io_int2str(int32_t n, char *str);
void io_uint2str(uint32_t n, char *str);
void io_float2str(float n, char *str);

#endif /* SRC_IO_FUNC_H_ */
