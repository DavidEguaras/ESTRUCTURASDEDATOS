# Estructuras de Datos

| Carpeta | Contenido |
|---|---|
| `apuntes/` | Apuntes de la asignatura (PDF y HTML) |
| `examenes/` | Exámenes de otros años |
| `ejercicios/` | Ejercicios en C; los enunciados están en `ejercicios/ENUNCIADOS.txt` |
| `ejercicios/pruebas/` | Pruebas sueltas que no son de ningún enunciado |

## Compilar

Los ejecutables van siempre a una carpeta `build/` al lado del `.c`, que Git ignora.

- **VS Code** (Linux y Windows): abre el `.c` y pulsa `Ctrl+Shift+B`.
- **Terminal**: desde `ejercicios/`, `make` compila todo, `make ejercicio07` solo uno y `make clean` borra `build/`.
  En Windows hace falta `make` de MSYS2 (`pacman -S make`).
