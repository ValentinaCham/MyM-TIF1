# Trabajo 1: Sistema de Consulta de Datos Estudiantiles

**Universidad Nacional de San Agustín**  
**Facultad de Ingeniería de Producción y Servicios**  
**Escuela Profesional de Ingeniería Electrónica**

| Información | Detalle |
| :--- | :--- |
| **Curso** | Microcontroladores |
| **Docente** | [Nombre del Docente] |
| **Estudiantes** | <ul><li>Chambilla Perca, Valentin Milagros</li><li>Llaja Apaza Aarom</li><li>Mejia Carreño Carlos Daniel</li><li>Olanda Quispe, Kevin Dylan</li><li>Vargas Delgado Gerardo David</li></ul> |
| **Lugar y Fecha** | Arequipa, Perú - 2026 |

---

## 🎯 Planteamiento de la Problemática

En el desarrollo de sistemas embebidos modernos, la optimización de los recursos de hardware es una prioridad crítica, especialmente cuando se trabaja con microcontroladores de arquitectura limitada como el **ATmega328P**. El problema central de este proyecto radica en la necesidad de diseñar e implementar un sistema de consulta de datos estudiantiles que garantice la eficiencia en el uso de la memoria y una comunicación robusta con el usuario.

### Retos Técnicos
1. **Gestión de Memoria:** El ATmega328P cuenta con solo **2 KB de SRAM**, insuficiente para almacenar cadenas de texto extensas sin comprometer la estabilidad. Surge el desafío de utilizar la **memoria Flash (32 KB)** como base de datos interna, requiriendo el dominio de la arquitectura Harvard modificada.
2. **Hibridación de Lenguajes:** 
   - **Lenguaje C:** Facilita la lógica del menú y la configuración del protocolo UART.
   - **Ensamblador (Assembly):** Indispensable para el acceso de bajo nivel mediante direccionamiento indirecto (registro Z).
3. **Validación de Identidad:** Implementación de algoritmos de búsqueda eficientes en tablas de búsqueda (lookup tables) dentro de la memoria de programa mediante el CUI.

---

## 🚀 Desarrollo del Proyecto

El diseño del sistema se basa en una arquitectura modular híbrida que aprovecha la eficiencia de la arquitectura Harvard modificada del ATmega328P. Esta estructura permite la ejecución simultánea de búsqueda de instrucciones y acceso a datos.

### Capas Críticas
- **Capa de Comunicación (C):** Configuración de registros USART0 (`UDR0`, `UCSR0A/B/C` y `UBRR0`). Formato **8N1** (8 bits, sin paridad, 1 bit de parada).
- **Capa de Procesamiento (Assembly):** Rutinas de búsqueda implementadas para maximizar el control. Uso del registro Z (`R31:R30`) para acceder a Flash.
- **Gestión de Memoria:** Almacenamiento en Flash mediante la directiva `.db` y recuperación con la instrucción `LPM`.

### Estructura Modular del Proyecto

| Archivo | Funciones / Operaciones Implementadas |
| :--- | :--- |
| `main.c` | Control del flujo principal, gestión del menú interactivo ('T', 'C', 'O') y llamado a rutinas de validación. |
| `uart.c / .h` | `uart_init` para configuración de baudios, `uart_transmit` y `uart_receive` para intercambio de datos. |
| `procesamiento.S` | Búsqueda del CUI en tablas Flash, algoritmos de comparación y extracción de datos personales. |

---

## 🛠️ Indagación Inicial y Control de Versiones

### Investigación Técnica
Se determinó la importancia de inicializar el **puntero Z** con el desplazamiento correcto de la tabla y usar el bit menos significativo para seleccionar el byte (alto o bajo) de la palabra de memoria.

### Control de Versiones
Se utiliza **GitHub** para:
- **Trazabilidad:** Registro de cambios en archivos `.c`, `.h` y `.S`.
- **Integración:** Unificación controlada de rutinas UART y procesamiento.
- **Respaldo:** Versiones estables listas para simulación en Microchip Studio.

**Enlace al repositorio:** [Colocar enlace aquí]

---

## 📁 Secciones Adicionales

### Elementos del Microcontrolador
*(Espacio para completar según el avance del hardware)*

### Código Fuente
*(Espacio para anexar el código fuente)*

### Evidencias del Funcionamiento
*(Espacio para capturas de pantalla del terminal/simulación)*

---

## 📚 Bibliografía

1. “TRABAJO PRÁCTICO 1.docx.pdf,” documento de pautas del proyecto, 2026.
2. “Technical Analysis of ATmega328P Memory Architecture, Indirect Addressing, and Serial Communication Systems,” análisis técnico sobre arquitectura AVR, 2026.
3. PCBSync, [“ATmega328P Datasheet Explained: Arduino's Brain”](https://pcbsync.com/atmega328p/). [Accedido: 05-may-2026].
4. L. Koepsel, [“Developing in C for the ATmega328: Using PROGMEM”](https://wellys.com/posts/avr_c_progmem/), Wellys Dev, sep. 2022. [Accedido: 05-may-2026].
5. Arxterra, [“#13: AVR Addressing Indirect”](https://www.arxterra.com/13-2-avr-addressing-indirect/). [Accedido: 05-may-2026].
6. RJHcoding, [“AVR Tutorials - Loading Data from Program Memory”](http://www.rjhcoding.com/avr-asm-pm.php). [Accedido: 05-may-2026].
7. Microchip Technology, [“AVR Instruction Set Manual”](https://academy.cba.mit.edu/classes/embedded_programming/doc0856.pdf) [PDF]. [Accedido: 05-may-2026].
8. SiliconWit, [“UART Serial Communication”](https://siliconwit.com/education/embedded-programming-atmega328p/uart-serial-communication/). [Accedido: 05-may-2026].