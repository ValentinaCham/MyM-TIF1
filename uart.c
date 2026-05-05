/**
 * @file uart.c
 * @brief Implementación de la comunicación serial.
 */

#include "uart.h"

#ifdef __AVR__
    #include <avr/io.h>
    #define F_CPU 16000000UL // Frecuencia de reloj por defecto (16MHz)
#else
    #include <stdio.h>
#endif

void uart_init(uint32_t baud_rate) {
#ifdef __AVR__
    // Cálculo del registro UBRR
    uint16_t ubrr_val = (uint16_t)(F_CPU / (16 * baud_rate) - 1);
    
    UBRR0H = (uint8_t)(ubrr_val >> 8);
    UBRR0L = (uint8_t)ubrr_val;

    // Habilitar transmisor y receptor
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    // Configurar formato: 8 datos, 1 bit parada (8N1)
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
#else
    printf("[MOCK] UART Inicializada a %u baudios\n", (unsigned int)baud_rate);
#endif
}

void uart_transmit(char data) {
#ifdef __AVR__
    // Esperar a que el buffer de transmisión esté vacío
    while (!(UCSR0A & (1 << UDRE0)));
    // Poner el dato en el registro
    UDR0 = data;
#else
    putchar(data);
#endif
}

char uart_receive(void) {
#ifdef __AVR__
    // Esperar a que el dato sea recibido
    while (!(UCSR0A & (1 << RXC0)));
    // Retornar el dato del registro
    return UDR0;
#else
    return (char)getchar();
#endif
}

void uart_read_line(char* buffer, uint8_t max_len) {
    uint8_t i = 0;
    char c;
    while (i < max_len - 1) {
        c = uart_receive();
        if (c == '\r' || c == '\n') break; // Enter
        
        if (c == '\b' || c == 127) { // Backspace
            if (i > 0) {
                i--;
                uart_print("\b \b"); // Borrar de la terminal
            }
        } else {
            buffer[i++] = c;
            uart_transmit(c); // Eco
        }
    }
    buffer[i] = '\0'; // Fin de cadena
}

void uart_print(const char* s) {
    while (*s) {
        uart_transmit(*s++);
    }
}
