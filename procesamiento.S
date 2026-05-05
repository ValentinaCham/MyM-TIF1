/**
 * @file procesamiento.S
 * @brief Rutinas en lenguaje ensamblador para búsqueda en memoria Flash.
 */

#include <avr/io.h>

.section .text

/**
 * @brief Rutina para buscar un estudiante en la tabla de la Flash.
 * @param R25:R22 CUI del estudiante (32 bits, ejemplo)
 * 
 * Uso del registro Z:
 * El registro Z (R31:R30) se utiliza como puntero a la memoria de programa.
 * Para acceder a una dirección de byte (LPM), se debe cargar la dirección de palabra
 * multiplicada por 2.
 */
.global buscar_estudiante
buscar_estudiante:
    ; --- Inicio de rutina ---
    ; 1. Cargar dirección de la tabla en registro Z
    ; ldi zh, high(tabla_estudiantes << 1)
    ; ldi zl, low(tabla_estudiantes << 1)
    
    ; 2. Ciclo de búsqueda
    ; lpm r16, Z+   ; Cargar byte de la flash y auto-incrementar
    
    ; 3. Comparación y retorno
    ret

; --- Sección de Datos en Memoria de Programa (Flash) ---
.section .progmem.data
tabla_estudiantes:
    .db "20260001", "Chambilla Perca, Valentin", 0, 0 ; Ejemplo de estructura
    .db "20260002", "Llaja Apaza, Aarom", 0, 0
    ; ... más datos ...
