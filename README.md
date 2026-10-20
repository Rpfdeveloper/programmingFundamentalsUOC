# UOCoworking · Fundamentos de programación en C

**Prácticas académicas de la UOC sobre programación estructurada y gestión de centros de coworking.**

[Explorar el código](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/tree/master) · [Práctica final](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/tree/master/UOCCoworkingPr2) · [Pruebas académicas](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/blob/master/UOCCoworkingPr2/src/test.c)

> **Dónde está el código:** la rama predeterminada `main` contiene esta presentación. Los ejercicios y las prácticas están en **[`master`](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/tree/master)**.

## De qué trata

Colección de ejercicios y prácticas de Fundamentos de Programación del Grado en Ingeniería Informática de la Universitat Oberta de Catalunya (UOC). La progresión abarca entrada y salida de datos, condiciones, bucles, funciones, estructuras y módulos en C.

Las prácticas UOCoworking trabajan con coworkers y centros de coworking. La segunda práctica incorpora reservas, listas, colas y procesos de entrada y salida.

## Recorrido por el repositorio

| Carpeta en `master` | Contenido |
| --- | --- |
| `PEC1Code` a `PEC8Code` | Ejercicios progresivos de la asignatura. |
| [`UOCCoworkingPr1/UOCCoworking`](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/tree/master/UOCCoworkingPr1/UOCCoworking) | Primera práctica con código modular y pruebas académicas. |
| [`UOCCoworkingPr2`](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/tree/master/UOCCoworkingPr2) | Práctica final con reservas, listas, colas y movimientos. |

Para una revisión técnica rápida, empieza por estos archivos de la práctica final:

| Archivo | Qué permite revisar |
| --- | --- |
| [`include/data.h`](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/blob/master/UOCCoworkingPr2/include/data.h) | Tipos y estructuras de datos. |
| [`src/api.c`](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/blob/master/UOCCoworkingPr2/src/api.c) | Operaciones de la aplicación. |
| [`src/list.c`](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/blob/master/UOCCoworkingPr2/src/list.c) | Operaciones sobre listas de reservas. |
| [`src/queue.c`](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/blob/master/UOCCoworkingPr2/src/queue.c) | Gestión de colas. |
| [`src/test.c`](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/blob/master/UOCCoworkingPr2/src/test.c) | Casos de prueba incluidos en la práctica. |

## Compilar y ejecutar las pruebas

Requisitos: Git y GCC con soporte C99. Comandos comprobados en Linux con GCC 13.3.0:

```bash
git clone --branch master --single-branch https://github.com/Rpfdeveloper/programmingFundamentalsUOC.git
cd programmingFundamentalsUOC/UOCCoworkingPr2
mkdir -p build
gcc -std=c99 -Wall -Wextra -Iinclude src/*.c -lm -o build/uocoworking
./build/uocoworking -t
```

Resultado de la revisión del **20 de octubre de 2026**:

```text
PR1: Passed 26 of 26 [100.00%]
PR2: Passed 19 of 19 [100.00%]
Total: Passed 45 of 45 [100.00%]
```

La suite imprime el resumen; el programa devuelve cero incluso si algún caso falla. Para evaluar el resultado hay que comprobar los contadores, no solo el código de salida.

Para abrir el menú interactivo, ejecuta `./build/uocoworking` desde `UOCCoworkingPr2`, donde se encuentran los archivos de datos.

## Comprobación automática del resultado

La rama `master` incluye [`tools/check_pr2.py`](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/blob/master/tools/check_pr2.py). Desde la raíz de la copia de esa rama, con Python 3 y GCC:

```bash
python3 tools/check_pr2.py
```

Compila la práctica final en una carpeta temporal y exige un único resumen con **45 de 45 pruebas superadas**. Si falla la compilación, la ejecución o el resumen, devuelve un código de error. Así evita que el código cero del programa académico oculte un test fallido. El workflow [C practice validation](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/actions), incluido en `master`, automatiza esta comprobación.

## Estado y límites

- La práctica final compila y supera sus **45 pruebas académicas existentes** en el entorno descrito.
- GCC emite avisos sobre inicialización de `struct tm` y comparaciones entre enteros con y sin signo. Esta revisión documenta el código original; no corrige esos avisos.
- No se ha validado funcionalmente toda la colección ni el menú interactivo.
- Los Makefiles generados por CodeLite contienen rutas absolutas del entorno original. Los comandos anteriores permiten compilar la práctica final sin depender de esas rutas.

## Contexto académico y atribución

Este repositorio documenta mi aprendizaje de C durante la asignatura. Incluye material y estructura de prácticas académicas de la UOC; se conservan las atribuciones existentes. No se atribuye la autoría íntegra del material docente al titular del repositorio.

La presentación y la comprobación reciente de compilación y pruebas se han realizado con asistencia de IA.
