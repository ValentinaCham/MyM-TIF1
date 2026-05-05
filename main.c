/**
 * @file main.c
 * @brief Programa principal para el Sistema de Consulta de Datos Estudiantiles.
 */

#include "uart.h"
#include <stdbool.h>

// Prototipo de la función en ensamblador (se definirá en procesamiento.S)
extern void buscar_estudiante(uint32_t cui);

void mostrar_menu(void) {
    uart_print("\n--- Sistema de Consulta Estudiantil ---\n");
    uart_print("T: Test de comunicación\n");
    uart_print("C: Consultar estudiante por CUI\n");
    uart_print("O: Otras opciones\n");
    uart_print("Seleccione una opcion: ");
}

int main(void) {
    // Inicializar UART a 9600 baudios
    uart_init(9600);
    
    uart_print("Sistema Iniciado...\n");

    while (true) {
        mostrar_menu();
        
        char opcion = uart_receive();
        uart_transmit(opcion); // Echo de la opción seleccionada
        uart_print("\n");

        switch (opcion) {
            case 'T':
            case 't':
                uart_print("Comunicacion UART operativa.\n");
                break;
            
            case 'C':
            case 'c':
                uart_print("Ingrese CUI: ");
                // Aquí se implementará la lógica para leer el CUI y llamar a ASM
                uart_print("[Proximamente: Lectura de CUI y busqueda en Flash]\n");
                break;
                
            case 'O':
            case 'o':
                uart_print("Opcion adicional seleccionada.\n");
                break;

            default:
                uart_print("Opcion no valida.\n");
                break;
        }
    }

    return 0;
}
