/*
 * I2C_Scanner.c
 *
 * Created: 2.8.2019. 16.12.20
 * Author : Kovacevic
 */ 

#include "comm.h"
#include "uart.h"
#include "i2cmaster.h"

int main(void)
{
   char buffer[100];
   int i;
   int nDevices = 0;
   
   uart_init(9600);
   i2c_init();

   
   sei();
   
    while (1) 
    {
		uart_send_str("Scanning... \n");
		
		nDevices = 0;
		
		for(i = 1; i<127; i++)
		{
			
			if (	i2c_start( (i<<1)+I2C_WRITE ) == 0		)
			{
				//device accessible
				nDevices++;
				
				//i2c_write(0x00);	//dummy write, zato sto je i2cStart + i2cStop invalid u samom protokolu (valjda)
				
				sprintf(buffer, "Device found at address: 0x%02x ! \n", i);
				uart_send_str(buffer);
				
			}
			//sprintf(buffer, "Loop %d \n", i);
			//uart_send_str(buffer);
			
		}
		
		if (nDevices == 0)
			uart_send_str("No devices found ! \n");
		else
		{
			sprintf(buffer, "========= Number of devices found: %d ! ========= \n", nDevices);
			uart_send_str(buffer);
		}
		
			

		uart_send_str("Done. \n\n");
		
		_delay_ms(5000);
		
    }
}

