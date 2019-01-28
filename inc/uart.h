#ifndef UART_H_
#define UART_H_

#include <stdint.h>

// ASCII Characters.
#define ASCII_CHAR_BS 	8	// Back space.
#define ASCII_CHAR_CR 	13 	// Carriage return.
#define ASCII_CHAR_CAN 	24 	// Cancel.
#define ASCII_CHAR_EM 	25 	// End of Medium.
#define ASCII_CHAR_SUB 	26 	// Substitute.
#define ASCII_CHAR_ESC 	27 	// Escape.
#define ASCII_CHAR_FS 	28 	// File Separator.
#define ASCII_CHAR_DEL 	127 // Delete.

#define UART_BUFFER_LENGTH 50
#define UART_CMD_LENGTH 100
#define UART_WORD_LENGTH 50
#define UART_NWORDS 5

#define NO_WORD 0
#define ONE_WORD 1
#define TWO_WORD 2
#define THREE_WORDS 3
#define FOUR_WORDS 4

typedef struct {
	char word[UART_WORD_LENGTH];
} user_words_t;

int uart_init(uint16_t device_id);

void uart_eraseBuffer(char *buf, unsigned int n);
unsigned int uart_rcv(char *buf);

void uart_parseCmd(char *buf);
void uart_printMenu();

void uart_cmdReset();
void uart_cmdBoardInfo();
void uart_cmdRead(char *addr, char *nBytes);
void uart_cmdReadByte(char *addr);
void uart_cmdReadWord(char *addr);
void uart_cmdReadQWord(char *addr);
void uart_cmdReadPage(char *addr);
void uart_cmdWrite(char *type, char *addr, char *val);
void uart_cmdErase(char *addr);

uint32_t str2num(char *str);
uint32_t convertToDecimal(char *str);

#endif
