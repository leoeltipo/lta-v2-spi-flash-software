#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include <sleep.h>
#include <xil_printf.h>
#include "flash.h"
#include "uart.h"


int main() 
{
   Xil_ICacheEnable();
   Xil_DCacheEnable();

   char uartBuffer[UART_BUFFER_LENGTH];
   char cmdBuffer[UART_CMD_LENGTH];

   print("---Entering main---\n\r");

   uart_init(XPAR_AXI_UARTLITE_0_DEVICE_ID);
   flash_init(XPAR_AXI_QUAD_SPI_0_DEVICE_ID);

   // Erase buffers.
   uart_eraseBuffer(uartBuffer, UART_BUFFER_LENGTH);
   uart_eraseBuffer(cmdBuffer, UART_CMD_LENGTH);

   // Main loop.
   unsigned int cmdBufferIdx = 0;
   uart_printMenu();
   while(1)
   {
	   // Read char from serial port.
	   int n = uart_rcv(uartBuffer);
	   for (int i=0; i<n; i++)
	   {
		   // Enter was detected.
		   if (uartBuffer[i] == ASCII_CHAR_CR)
		   {
			   print("\r\n");

			   // Parse command.
			   uart_parseCmd(cmdBuffer);

			   print("\r\n");

			   // Clean command buffer.
			   uart_eraseBuffer(cmdBuffer, UART_CMD_LENGTH);
			   cmdBufferIdx = 0;
		   }
		   // Other chars were detected that delete the command buffer.
		   else if (
				   uartBuffer[i] == ASCII_CHAR_BS 	||
				   uartBuffer[i] == ASCII_CHAR_CAN 	||
				   uartBuffer[i] == ASCII_CHAR_EM 	||
				   uartBuffer[i] == ASCII_CHAR_SUB 	||
				   uartBuffer[i] == ASCII_CHAR_ESC 	||
				   uartBuffer[i] == ASCII_CHAR_FS 	||
				   uartBuffer[i] == ASCII_CHAR_DEL
		   )
		   {
			   // Clean command buffer.
			   uart_eraseBuffer(cmdBuffer, UART_CMD_LENGTH);
			   cmdBufferIdx = 0;

			   print("\33[2K");
			   print("\r\n");
		   }
		   else
		   {
			   //add character to the user vector
			   cmdBuffer[cmdBufferIdx] = uartBuffer[i];
			   cmdBufferIdx++;

			   print((const char*)&uartBuffer[i]);

		   }
	   }
	   //flash_readID();
	   //flash_read(0x3FFFF00, 256);
	   //flash_read(0,16);
	   //flash_write(0x3FFFF00, 256, data);
	   //flash_write(0,16,data);
	   //flash_write(50, 16, COMMAND_4BYTE_PAGE_PROGRAM, data);
	   //flash_resetEnable();
	   //flash_resetMemory();

	   //flash_read(0,0,0);
	   //sleep(5);
   }

   print("---Exiting main---\n\r");
   Xil_DCacheDisable();
   Xil_ICacheDisable();
   return 0;
}
