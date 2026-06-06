## Bitacora de desarrollo - PC3

### Dia 1: `03/06/2026`
 
Se realizaron las siguientes actividades:

- Lo primero que he hecho ha sido crear el archivo `.gitignore `. He colocado las exclusiones por categoría para así facilitar su lectura. La intención es que el repositorio mantenga solo código fuente, pruebas, documentación y evidencias textuales reproducibles.

- Definí el archivo `CMakeLists.txt` que orquesta la compilación, las pruebas y el benchmark del proyecto. Fijé cmake_minimum_required en la versión 3.17, declaré el proyecto como Practica_Calificada_3 con lenguaje C++17 obligatorio. 

- Contruí el README inicial. Generé el archivo siguiendo la plantilla de la sección 14 de las indicaciones. Completé mis datos y problema asignado (Codeforces 19D, problema 21 del CSV oficial) junto con los enlaces oficiales al juez y al CSV del curso. Las secciones aún están vacíos, pero se completarán conforme avance la implementación en los días siguientes.

Finalmente, las tareas realizadas hoy conforman la base mínima necesaria para iniciar el trabajo técnico de los días siguientes. A partir del día 2 comenzaré con la implementación, empezando por la solución ingenua.

### Día 2: `04/06/2026`

Se repasó el enunciado del problema asignado, Codeforces 19D, para tener claro qué iba a programar. 

El problema plantea un escenario donde un personaje llamado Pete le da órdenes a otro llamado Bob para que marque puntos en un plano cuadriculado donde el origen está en la esquina inferior izquierda y los ejes apuntan a la derecha y hacia arriba.

Las órdenes son de tres tipos:
- `add x y` que marca el punto en esas coordenadas.
- `remove x y` que borra un punto previamente marcado.
- `find x y` que busca todos los puntos marcados que se encuentren estrictamente a la derecha y estrictamente arriba de la consulta, y entre todos esos candidatos selecciona el de menor coordenada x, con desempate por menor coordenada y, devolviendo -1 si no existe ningún candidato válido. 

Las restricciones del problema son hasta 2·10⁵ operaciones en total y coordenadas hasta 10⁹, lo cual descarta inmediatamente cualquier solución cuadrática, aunque usaré esta idea para proponer la solución ingenua.

### Día 3: `05/06/2026`

Este día tuvo como objetivo la implementación de la solución ingenua y para ello se realizaron las siguientes actividades:

- Construí la cabecera `include/solution.h` definiendo un struct Point con dos enteros y una clase PointsIngenua con tres métodos públicos `add`, `remove` y `find`, manteniendo en privado un `std::vector<Point>` llamado pointsAvailable que guarda los puntos activos. La decisión de usar una clase con encapsulamiento responde al concepto de contrato, ya que en los siguientes días se piensa reemplazar la representación interna por un segment tree de Treaps y la idea es que main.cpp no necesite cambiar.

- Implementé el método `add` que agrega un punto al final del vector con push_back. 

```cpp
void PointsIngenua::add(int x, int y) {
    // Point con las coordenadas recibidas
    // agregarlo al final del vector pointsAvailable
}
```

- Implementé el método `remove` que recorre el vector con un iterador, compara campo a campo contra el punto a borrar, y al encontrarlo lo elimina con erase seguido de un return para evitar invalidación del iterador. 

```cpp
void PointsIngenua::remove(int x, int y) {
    // recorrer el vector con un iterador desde begin hasta end
        // si el punto actual coincide en ambas coordenadas con (x, y):
            // borrar ese elemento del vector con erase
            // salir de la funcion inmediatamente con return para no invalidar el iterador
    // (si no se encuentra coincidencia, no hacer nada y terminar)
}
```

- Implementé el método `find` `que recorre todo el vector aplicando dos filtros sucesivos, un primer filtro que descarta los puntos que no están estrictamente arriba y a la derecha de la consulta, y un segundo filtro de comparación contra el mejor candidato actual usando el criterio del problema, menor x con desempate por menor y. Como centinela para el caso sin respuesta uso el valor {-1, -1}, aprovechando que las coordenadas reales del problema son siempre positivas.

```cpp
Point PointsIngenua::find(int x, int y) {
    // valor inicial del "mejor candidato" = centinela {-1, -1}
    // recorrer todos los puntos del vector con un for-iterador
        // si el punto actual es candidato (estrictamente arriba-derecha):
            // si el mejor actual es el centinela O si este punto es mejor que el mejor actual:
                // actualizar el mejor actual con este punto
    // devolver el mejor (que sera el centinela si nunca encontramos candidato)
}
```

Finalmente, la complejidad de esta versión es O(n) por operación `remove` y `find`, dando O(n²) total en el peor caso, lo cual confirma que no es viable para n=2·10⁵ pero sirve comparar con la solución principal, además de verificar correctitud para los tests aleatorios que validarán la versión eficiente.