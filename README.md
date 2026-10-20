# UOCoworking · Código de las prácticas en C

Esta rama `master` contiene los ejercicios y las prácticas de Fundamentos de Programación de la UOC. La [presentación completa del repositorio](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/blob/main/README.md) está en `main`.

## Comprobar la práctica final

Requisitos: GCC con soporte C99 y Python 3. Comprobado en Linux con GCC 13.3.0.

Desde la raíz del repositorio:

```bash
python3 tools/check_pr2.py
```

El script compila `UOCCoworkingPr2` en una carpeta temporal, ejecuta su suite académica y exige el resumen **45 de 45 pruebas superadas**. Devuelve un error si falla la compilación, se agota el tiempo, falla el proceso o el resumen falta o no coincide. Esto evita considerar correcta una ejecución solo porque el programa original devuelve cero.

Si se añaden o eliminan pruebas académicas, hay que revisar explícitamente el contador esperado del script. El código académico no se modifica con esta automatización.

El workflow [C practice validation](https://github.com/Rpfdeveloper/programmingFundamentalsUOC/actions) ejecuta la comprobación en los pushes y pull requests de esta rama. El archivo de workflow está en `master`.

## Alcance

La práctica final supera las 45 pruebas existentes en la revisión local del 20 de octubre de 2026. GCC emite avisos de inicialización de `struct tm` y comparación entre enteros de distinto signo. No se ha validado funcionalmente toda la colección ni el menú interactivo.

Se conservan el material académico y sus atribuciones originales. El script de comprobación y esta documentación se han preparado con asistencia de IA.
