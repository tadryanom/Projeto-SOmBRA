#include <drivers/ps2.h>
#include <system.h>
#include <stdio.h>

int ps2_wait(uint8_t w_type)
{
	uint32_t timeout;
	uint32_t status;

	for(timeout = 500000; timeout != 0; timeout--){
		status = inportb(PS2_CTRL);
		/* Efetua o loop at� o controlador(8042) limpar o buffer de entrada. */
		if(w_type && !(status & 0x02))
			return status;

		if (!w_type && (status & 0x01))
			return status;
	}

	return -1;
}

void ps2_write(uint32_t port, uint8_t data)
{
	/* Envia o comando para o teclado. */
	if(ps2_wait(1) != -1)
		outportb(port, data);
	else printf("ps2_write: N�o enviado!\n");
}

uint32_t ps2_read(void)
{
	uint8_t stat = ps2_wait(0);

	if (!(stat & 0xC0))
		return inportb(PS2_PORT);

	printf("ps2_read: N�o recebido!\n");
	return -1;
}

uint8_t ps2_writeack(uint32_t port, uint8_t data)
{
	unsigned int ret_val = 0;

	ps2_write(port, data);
	ret_val = ps2_read();

	if (ret_val != PS2_ACK)
		printf("[Teclado] erro: esperado 0x%x, obtido 0x%x\n", data, ret_val);

	return ret_val;
}

