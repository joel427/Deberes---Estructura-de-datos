# Árbol BST Empresarial en C++

## Descripción
Implementación de un Árbol Binario de Búsqueda (BST) en C++ para organizar
empleados de una empresa usando su código como clave de ordenamiento.

## Integrantes
- [Nombre 1] — Estructura Nodo e inserción
- [Nombre 1] — Búsqueda y recorridos
- [Nombre 1] — Altura, raíz y hojas
- [Nombre 1] — README, capturas y documentación

## Objetivo
Implementar un árbol binario de búsqueda en C++ para organizar empleados
de una empresa y aplicar los conceptos de raíz, nodo interno, hoja,
nivel y altura.

## Funcionalidades
- Insertar empleados (código, nombre, cargo)
- Buscar empleado por código
- Mostrar nodo raíz
- Recorrido inorden (orden ascendente por código)
- Recorrido preorden
- Recorrido postorden
- Calcular altura del árbol
- Mostrar nodos hoja


## Compilación y ejecución
### Linux / macOS
```bash
g++ src/main.cpp -o arbol
./arbol
```
### Windows
```bash
g++ src/main.cpp -o arbol.exe
arbol.exe
```

## Datos de prueba
| Código | Nombre          | Cargo           |
|--------|-----------------|-----------------|
| 50     | Empresa UTA     | Raíz            |
| 30     | Gerente Ventas  | Nodo interno    |
| 70     | Gerente Finanzas| Nodo interno    |
| 20     | Emp 1           | Hoja            |
| 40     | Emp 2           | Hoja            |
| 60     | Emp 3           | Hoja            |
| 80     | Emp 4           | Hoja            |


## Capturas
*(Agregar capturas de pantalla de cada funcionalidad)*

## Conclusión
El árbol BST permite organizar información jerárquica de manera eficiente.
Las búsquedas tienen complejidad O(log n) en árboles balanceados, lo que
lo convierte en una estructura ideal para directorios y organigramas.
