/**
 * @file uart.h
 * @author [Tu Nombre / Grupo]
 * @brief Definiciones y prototipos para la comunicación serial (UART) en ATmega328P.
 * @date 2026-05-05
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>

/**
 * @brief Inicializa el módulo USART0 con los parámetros 8N1.
 * 
 * @param baud_rate Tasa de baudios deseada (ej. 9600).
 */
void uart_init(uint32_t baud_rate);

/**
 * @brief Transmite un único carácter por el puerto serial.
 * 
 * @param data Carácter a enviar.
 */
void uart_transmit(char data);

/**
 * @brief Recibe un único carácter del puerto serial (bloqueante).
 * 
 * @return char Carácter recibido.
 */
char uart_receive(void);

/**
 * @brief Lee una línea de texto hasta encontrar un Enter (\n o \r).
 * 
 * @param buffer Puntero al arreglo donde se guardará el texto.
 * @param max_len Tamaño máximo del buffer.
 */
void uart_read_line(char* buffer, uint8_t max_len);

/**
 * @brief Transmite una cadena de texto (string) completa.
 * 
 * @param s Puntero a la cadena de texto.
 */
void uart_print(const char* s);

#endif /* UART_H_ */
