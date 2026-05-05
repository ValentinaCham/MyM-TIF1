--------------------------------------------------------------------------------
Universidad Nacional de San Agustín
Facultad de Ingeniería de Producción y Servicios
Escuela Profesional de Ingeniería Electrónica
Trabajo 1: Sistema de Consulta de Datos Estudiantiles
Curso: Microcontroladores
Docente: [Nombre del Docente]
Estudiantes:
Chambilla Perca, Valentin Milagros
Llaja Apaza Aarom
Mejia Carreño Carlos Daniel
Olanda Quispe, Kevin Dylan
Vargas Delgado Gerardo David
Arequipa – Perú
2026

--------------------------------------------------------------------------------
Planteamiento de la Problemática
En el desarrollo de sistemas embebidos modernos, la optimización de los recursos de hardware es una prioridad crítica, especialmente cuando se trabaja con microcontroladores de arquitectura limitada como el ATmega328P. El problema central de este proyecto radica en la necesidad de diseñar e implementar un sistema de consulta de datos estudiantiles que garantice la eficiencia en el uso de la memoria y una comunicación robusta con el usuario.
Uno de los principales retos técnicos es la gestión de la memoria. El ATmega328P cuenta con solo 2 KB de SRAM, lo cual resulta insuficiente para almacenar cadenas de texto extensas, como correos electrónicos y números telefónicos de múltiples usuarios, sin comprometer la estabilidad del sistema. Por ello, surge el desafío de utilizar la memoria Flash (32 KB) como una base de datos interna, lo cual requiere el dominio de la arquitectura Harvard modificada del dispositivo, donde el espacio de instrucciones y el de datos están separados.
Adicionalmente, la implementación exige una hibridación de lenguajes de programación. Mientras que el lenguaje C facilita la lógica del menú y la configuración del protocolo UART para la comunicación serial, el lenguaje Ensamblador es indispensable para realizar un acceso de bajo nivel a la memoria mediante direccionamiento indirecto y el uso de punteros (específicamente el registro Z). Esta integración es compleja, ya que requiere que el desarrollador gestione manualmente la conversión de direcciones de memoria de palabras (16 bits) a bytes para la recuperación precisa de los datos. Finalmente, el sistema debe resolver la validación de identidad mediante el CUI antes de permitir el acceso a información sensible, lo que implica el diseño de algoritmos de búsqueda eficientes en tablas de búsqueda (lookup tables) dentro de la memoria de programa.

--------------------------------------------------------------------------------
Desarrollo del Proyecto
El diseño del sistema se basa en una arquitectura modular híbrida que aprovecha la eficiencia de la arquitectura Harvard modificada del ATmega328P. Esta estructura permite la ejecución simultánea de búsqueda de instrucciones y acceso a datos, logrando un rendimiento cercano a 1 MIPS por MHz.
La implementación se divide en tres capas críticas:
Capa de Comunicación (C): Se configuran los registros del periférico USART0 (UDR0, UCSR0A/B/C y UBRR0) para establecer una comunicación serial asíncrona. Se utiliza un formato de 8 bits de datos, sin paridad y 1 bit de parada (8N1) para interactuar con el Data Visualizer de Microchip Studio.
Capa de Procesamiento (Ensamblador): Las rutinas de búsqueda se implementan en lenguaje ensamblador para maximizar el control sobre el hardware. Se emplea el direccionamiento indirecto mediante el registro Z (R31:R30) para acceder a la memoria Flash.
Gestión de Memoria: Debido a la limitación de 2 KB de SRAM, el sistema almacena las cadenas de texto en la memoria Flash (32 KB) mediante la directiva .db. El acceso se realiza con la instrucción LPM, convirtiendo la dirección de palabra en dirección de byte multiplicándola por dos.
Estructura Modular del Proyecto
La organización del código garantiza que cada archivo cumpla una función específica, facilitando la depuración y el escalonamiento.
Archivo
Funciones / Operaciones Implementadas
main.c
Control del flujo principal, gestión del menú interactivo ('T', 'C', 'O') y llamado a rutinas de validación.
uart.c / .h
uart_init para configuración de baudios, uart_transmit y uart_receive para el intercambio de datos con el terminal.
procesamiento.S
Búsqueda del CUI en tablas de la Flash, algoritmos de comparación y extracción de datos personales mediante punteros indirectos.
Indagación Inicial y Control de Versiones
La investigación inicial se centró en la gestión de tablas de búsqueda (lookup tables) en memoria de programa. Se determinó que es indispensable inicializar el puntero Z con el desplazamiento correcto de la tabla y usar el bit menos significativo de dicho registro para seleccionar el byte (alto o bajo) de la palabra de memoria.
Para la gestión del desarrollo y la colaboración, se utilizará GitHub como sistema de control de versiones distribuido. Este flujo de trabajo permite:
Trazabilidad: Registrar cada cambio realizado en los archivos .c, .h y .S.
Integración: Unificar las rutinas de comunicación UART con las de procesamiento de forma controlada.
Respaldo: Mantener versiones estables que puedan ser simuladas en Microchip Studio antes de su carga física.
Enlace al repositorio del proyecto:
[Colocar enlace aquí]

--------------------------------------------------------------------------------
Elementos del Microcontrolador empleados en el Proyecto
(Espacio para completar según el avance del hardware)
Código Fuente
(Espacio para anexar el código fuente)
Evidencias del Funcionamiento
(Espacio para capturas de pantalla del terminal/simulación)

--------------------------------------------------------------------------------
BIBLIOGRAFÍA
 “TRABAJO PRÁCTICO 1.docx.pdf,” documento de pautas del proyecto, 2026.
 “Technical Analysis of ATmega328P Memory Architecture, Indirect Addressing, and Serial Communication Systems,” análisis técnico sobre arquitectura AVR, 2026.
 PCBSync, “ATmega328P Datasheet Explained: Arduino's Brain,” [En línea]. Disponible en: https://pcbsync.com/atmega328p/. [Accedido: 05-may-2026].
 L. Koepsel, “Developing in C for the ATmega328: Using PROGMEM,” Wellys Dev, sep. 2022. [En línea]. Disponible en: https://wellys.com/posts/avr_c_progmem/. [Accedido: 05-may-2026].
 Arxterra, “#13: AVR Addressing Indirect,” [En línea]. Disponible en: https://www.arxterra.com/13-2-avr-addressing-indirect/. [Accedido: 05-may-2026].
 RJHcoding, “AVR Tutorials - Loading Data from Program Memory,” [En línea]. Disponible en: http://www.rjhcoding.com/avr-asm-pm.php. [Accedido: 05-may-2026].
 Microchip Technology, “AVR Instruction Set Manual,” [PDF]. Disponible en: https://academy.cba.mit.edu/classes/embedded_programming/doc0856.pdf. [Accedido: 05-may-2026].
 SiliconWit, “UART Serial Communication,” [En línea]. Disponible en: https://siliconwit.com/education/embedded-programming-atmega328p/uart-serial-communication/. [Accedido: 05-may-2026].