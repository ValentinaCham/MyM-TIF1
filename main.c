/**
 * @file main.c
 * @brief Programa principal para el Sistema de Consulta de Datos Estudiantiles.
 */

#include "uart.h"
#include <stdbool.h>
#include <stdlib.h>

// Prototipo de la función en ensamblador (se definirá en procesamiento.S)
extern void buscar_estudiante(uint32_t cui);

void mostrar_menu(void) {
    uart_print("\n--- Sistema de Consulta Estudiantil ---\n");
    uart_print("T: Test de comunicacion\n");
    uart_print("C: Consultar estudiante por CUI\n");
    uart_print("O: Otras opciones\n");
    uart_print("Seleccione una opcion: ");
}

int main(void) {
    char cui_buffer[10]; // Buffer para CUI de 8-9 dígitos
    
    // Inicializar UART a 9600 baudios
    uart_init(9600);
    
    uart_print("Sistema Iniciado...\n");

    while (true) {
        mostrar_menu();
        
        char opcion = uart_receive();
        
        // Ignorar saltos de línea y basura del terminal
        if (opcion < 32) continue; 

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
                uart_read_line(cui_buffer, 10);
                uart_print("\nBuscando CUI: ");
                uart_print(cui_buffer);
                uart_print("...\n");
                
                uint32_t cui_val = (uint32_t)atoll(cui_buffer);
                // Aquí se llama a la función de ASM:
                // buscar_estudiante(cui_val);
                
                uart_print("[Resultado: Funcion ASM lista para integracion]\n");
                break;
                
            case 'O':
            case 'o':
                uart_print("Opcion adicional seleccionada.\n");
                break;

            default:
                uart_print("Error: Opcion '");
                uart_transmit(opcion);
                uart_print("' no valida.\n");
                break;
        }
    }

    return 0;
}
