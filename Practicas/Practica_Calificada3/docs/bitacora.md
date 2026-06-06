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

