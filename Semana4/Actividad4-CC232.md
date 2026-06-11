## Actividad 4 - Semana 4

`Nombre`: Cristhyan Manuel Perez Villegas

`Codigo`: 20231066A

## Bloque 1 — Núcleo conceptual de la semana

### 1. Explica con tus palabras la diferencia entre acceso `LIFO` y acceso `FIFO`.

LIFO es el principio de la pila (`Stack`) en donde el último en entrar es el primero en salir. Mientras que FIFO es el principio de la cola (`Queue`) en donde el primero en entrar es el primero en salir. 

La diferencia es en qué extremo se retiran los elementos. En la pila se retira por la cima (donde se insertó), y en la cola se retira por el frente (el extremo opuesto a donde se insertó).

### 2. Explica por qué `Stack` resuelve naturalmente problemas donde importa "lo último pendiente".

Porque una pila garantiza que la cima siempre contenga la decisión o el trabajo más reciente y aún no resuelto. Esto se alinea con problemas donde hay que procesar la tarea abierta más reciente antes de volver a las anteriores. 

Por ejemplo, en la verificación de paréntesis, el último delimitador abierto debe cerrarse antes que cualquier delimitador abierto anteriormente. La pila guarda exactamente esa apertura pendiente más reciente.

### 3. Explica por qué `Queue` modela naturalmente procesos de espera y atención.

Porque una cola preserva el orden de llegada, donde el primer elemento en entrar es el primero en salir. Esto modela directamente cualquier sistema donde la equidad de servicio está basada en el tiempo de llegada.

Por ejemplo en `BankSimulation.h`, cada ventanilla tiene una `Queue<Customer>`. Cuando un cliente llega, se hace `enqueue` al fondo. Cuando la ventanilla atiende, se hace `dequeue` desde el frente: el cliente que lleva más tiempo esperando es el siguiente en ser atendido.

### 4. Explica qué significa reemplazar recursión implícita por una estructura explícita.

Es básicamente por el control, porque cuando un algoritmo es recursivo, el call stack del sistema guarda automáticamente en cada llamada, los parámetros locales, las variables locales y la dirección de retorno. Aquí el programador como tal no ve ni controla esa pila. Sin embargo al reemplazarlo por una pila explícita, el programador toma ese control y decide exactamente qué información guardar en la pila, cuándo empujar y cuándo hacer pop. 

### 5. Explica qué información mínima debe guardarse para que una pila permita reconstruir una solución parcial.

Debe guardarse lo necesario para saber qué decisión se tomó en cada nivel y desde dónde reanudar la exploración si hay que retroceder.

Por ejemplo en N-Reinas, la pila `Stack<Queen>` guarda objetos `Queen(x, y)`, donde `x` es la fila y `y` es la columna. Con eso basta para saber cuántas reinas se han colocado y dónde está cada una. Al retroceder, se hace pop y se incrementa `y` para probar la siguiente columna en esa fila.

### 6. Compara la conversión de base recursiva e iterativa: ¿qué comparten y qué cambia en el control del proceso?

Comparten la misma idea matemática de dividir sucesivamente el número por la base y juntar los residuos. En este caso la misma estructura auxiliar, un `Stack<char>` que acumula los dígitos.Además de la la misma salida para los mismos inputs.

Y se diferencian en que en la recursiva, la secuencia de llamadas es gestionada por el call stack del sistema. Además, el residuo se apila antes de la llamada recursiva, y la profundidad de recursión es igual al número de dígitos del resultado. Mientras que en la iterativa, un bucle while (n > 0) controla el proceso. Cada iteración apila un residuo y divide n por la base. Aqui no hay llamadas anidadas.

### 7. Explica por qué la verificación iterativa de paréntesis necesita almacenar aperturas pendientes.

Al recorrer una cadena de izquierda a derecha, cuando encontramos un cierre (`)`, `]` o `}`), debemos verificar que el último delimitador abierto sin cerrar sea del tipo correcto. Sin almacenar las aperturas, esa verificación es imposible.

La pila en parenIterative de `Parentheses.h` mantiene el invariante que en la cima es siempre la apertura más reciente que aún no ha sido cerrada. Al encontrar un cierre, se hace pop y se verifica la coincidencia.

### 8. Explica por qué el evaluador de expresiones necesita dos pilas y no una sola.

Se mantienen dos pilas:

- `Stack<double> operands` que guarda los valores numéricos esperando ser operados.

- `Stack<char> operators` que guarda los operadores pendientes cuya aplicación se difiere hasta que aparece un operador de menor o igual prioridad.

La lógica de evaluación compara operators.top() con el símbolo actual para decidir si aplicar el operador pendiente o diferirlo. Esa decisión requiere acceso independiente a cada pila.

Si se usara una sola pila, no se podría distinguir entre un número y un operador sin tipo adicional, y la lógica de prioridad no podría funcionar porque necesita comparar el tipo del tope de operadores con el símbolo actual. 

Las dos pilas son estructuralmente necesarias porque los tipos de datos son diferentes y su ciclo de vida (cuándo empujar, cuándo hacer pop) obedece a reglas distintas.

### 9. Explica por qué N-Reinas y laberinto son ejemplos naturales de backtracking.

Porque ambos problemas comparten la estructura de construcción incremental de una solución con retroceso:

Primero se toma una decisión parcial (colocar una reina en cierta columna, avanzar a una celda vecina).

Segundo, se verifica si esa decisión es válida (¿entra en conflicto con otra reina?, ¿está la celda disponible?).

Tercero, si es válida, se avanza al siguiente nivel.

Cuarto, si no se puede avanzar en ninguna dirección, se deshace la última decisión y se prueba la siguiente alternativa.

Y por último, si no quedan alternativas en un nivel, se sube otro nivel y se deshace esa decisión también.

### 10. Explica por qué la simulación bancaria no se modela bien con pila, pero sí con colas.

La simulación bancaria modela una fila de espera justa donde el primer cliente en llegar debe ser el primero en ser atendido. Este principio FIFO es exactamente lo que implementa `Queue`.

Una pila invertiría el orden de atención donde el último cliente en llegar sería el primero atendido, lo que contradice la semántica del sistema modelado.

### 11. Explica qué relación hay entre estructura auxiliar, estado parcial y correctitud.

La estructura auxiliar es el contenedor que guarda el estado parcial durante la computación, básicamente lo que el algoritmo ha procesado hasta ahora y lo que queda pendiente.

Si la estructura guarda datos incorrectos (orden equivocado, tipo incorrecto, información insuficiente), el algoritmo produce resultados incorrectos aunque su lógica general sea razonable. La correctitud es inseparable del mantenimiento del invariante de la estructura auxiliar en cada paso.

### 12. Explica qué diferencia conceptual hay entre "resolver un problema" y "simular un proceso".

En la resolución hay un estado final que es correcto o incorrecto; en la simulación hay una trayectoria de estados cuya validez depende de que el modelo sea fiel al sistema real, no de un valor esperado único. La aleatoriedad y el tiempo discreto son parte del modelo, no del problema a resolver.

## Bloque 2 - Demostración y trazado guiado

| Archivo | Salida u observable importante | Estructura o técnica central | Qué concepto permite defender |
|---|---|---|---|
| `demo_stack_queue.cpp` | Tope=9, Pop=9 / Frente=10, Dequeue=10 | `Stack<int>` y `Queue<int>` | LIFO - FIFO |
| `demo_base_conversion.cpp` | Recursivo: "30071" / Iterativo: "30071" | `Stack<char>` con residuos apilados | Recursiva e iterativa producen la misma representación |
| `demo_paren_rpn.cpp` | Balanceados=true / RPN completa / Valor=2012 | `Stack<double>` + `Stack<char>` para evaluar | Paréntesis -> RPN sin ambigüedad -> valor correcto |
| `demo_nqueens.cpp` | N=4, soluciones=2, verificaciones=X | `Stack<Queen>`, backtracking con pila explícita | Respuestas ≠ checks (trabajo realizado) |
| `demo_maze.cpp` | Medida del camino + secuencia de coordenadas | `Stack<Cell*>`, backtracking con marcado de estado | La pila reconstruye el camino |
| `demo_bank.cpp` | Llegadas=N, atendidos=M, estado de colas en cada t | `vector<Queue<Customer>>`, política FIFO | La cola modela espera justa y permite ver la congestión temporal |
| `demo_capitulo4_panorama.cpp` | "Semana 4 cargada correctamente" y todos los resultados en pantalla | Integración de Stack, Queue y todas las aplicaciones | Una sola semana une estructuras lineales y algoritmos avanzados |

### 1. En `demo_stack_queue.cpp`, ¿qué parte de la salida deja más clara la diferencia entre tope y frente?

La parte más ilustrativa es la comparación directa:

```bash
Tope de la pila = 9       <- el último en insertarse (LIFO)
Frente de la cola = 10    <- el primero en insertarse (FIFO)
```

### 2. En `demo_base_conversion.cpp`, ¿qué observable permite afirmar que las versiones recursiva e iterativa producen la misma representación?

Ambas líneas imprimen exactamente `"30071"`. Tanto en recursivo como en iterativo.

Esto evidencia que aunque el control del proceso difiere, el resultado de apilar los residuos en el mismo orden y luego extraerlos con `popAll` es idéntico. La pila normaliza el orden de los dígitos de la misma manera en ambas versiones.

### 3. En `demo_paren_rpn.cpp`, ¿qué relación observas entre paréntesis balanceados, RPN y valor final?

La expresión `(0!+1)*2^(3!+4)-(5!-67-(8+9))` tiene paréntesis balanceados (resultado `true`). Eso es condición necesaria para que el algoritmo de evaluación pueda procesar correctamente la prioridad de operadores. Como los paréntesis están bien formados, el evaluador genera una RPN sin ambigüedad y aplica las operaciones en el orden correcto, obteniendo el valor exacto 2012. Si los paréntesis estuvieran mal formados, el evaluador lanzaría un error antes de producir RPN o valor.

### 4. En `demo_nqueens.cpp`, ¿qué significan `solutions` y `checks`, y por qué no miden lo mismo?

No miden lo mismo porque `checks` contabiliza todas las comparaciones hechas en caminos que no llevan a solución, además de los que sí llevan. Para n=4, el algoritmo puede verificar decenas de conflictos para encontrar solo 2 soluciones. `checks` crece mucho más rápido que `solutions` conforme n aumenta.

### 5. En `demo_maze.cpp`, ¿qué muestra la secuencia de coordenadas sobre el camino encontrado?

Demuestra que el backtracking funcionó. El algoritmo exploró y descartó caminos erróneos, y la pila al final contiene únicamente el camino exitoso como una secuencia ordenada de coordenadas.

### 6. En `demo_bank.cpp`, ¿qué representa cada lista impresa en cada instante `t`?

En cada instante `t`, se imprimen las colas de las 3 ventanillas. Cada lista muestra el tiempo restante de atención de cada cliente en esa ventanilla, en orden FIFO. El primer valor es el cliente siendo atendido ahora, y los siguientes son los que esperan. Por ejemplo, `[15, 42]` significa que el cliente al frente tiene 15 unidades restantes y el siguiente tiene 42. Permite ver en tiempo real cómo se llenan, se vacían y se redistribuyen los clientes entre ventanillas.

### 7. En `demo_capitulo4_panorama.cpp`, ¿qué salida resume mejor la idea de que una misma semana reúne estructuras y aplicaciones?

La línea `"Semana 4 cargada correctamente"` seguida de todos los resultados impresos en secuencia en un único programa es el mejor resumen. Demuestra que `Stack` y `Queue` no son estructuras aisladas sino la base común de aplicaciones tan diferentes como evaluar expresiones aritméticas, soluciones con backtracking y simular sistemas de servicio.

## Bloque 3 - Pruebas públicas, pruebas internas y correctitud

### 1. ¿Qué operaciones mínimas valida la prueba pública para `Stack`?

La prueba pública `test_public_week4.cpp` valida cuatro operaciones (empty, push, top, pop) que cubren el ciclo completo de vida de la pila

- `empty()` retorna true cuando la pila está recién creada.
- `push(5)` y `push(9)` agregan elementos; `top()` retorna el último insertado.
- `pop()` retorna el elemento del tope en orden LIFO.
- `empty()` retorna `true` después de extraer todos los elementos.

### 2. ¿Qué operaciones mínimas valida la prueba pública para `Queue`?

- `empty()` retorna true inicialmente.
- `enqueue(1)`, `enqueue(2)`, `enqueue(3)` agregan elementos.
- `front()` retorna el primer insertado sin sacarlo.
- `dequeue()` extrae en orden FIFO.
- `empty()` retorna true al final.

### 3. ¿Qué valida la prueba pública sobre conversión de base?

La prueba pública valida que ambas implementaciones son equivalentes para este caso concreto y que la representación octal de 12345 es "30071".

### 4. ¿Qué valida la prueba pública sobre paréntesis balanceados?

La prueba pública valida tres casos:
- `parenRecursive("a+(b*(c+d))")` -> `true`: paréntesis correctamente anidados.
- `parenIterative("a+(b*[c-{d/e}])")` -> `true`: múltiples tipos de delimitadores correctamente anidados.
- `parenIterative("([)]")` -> `false`: cruce incorrecto entre tipos de delimitadores.

### 5. ¿Qué valida la prueba pública sobre evaluación de expresiones y RPN?

La prueba pública valida para la expresión `(0!+1)*2^(3!+4)-(5!-67-(8+9))`:
- La RPN generada sea exactamente `"0 ! 1 + 2 3 ! 4 + ^ * 5 ! 67 - 8 9 + - -"`
- El valor calculado es `2012.0`

Entonces, valida tanto la correctitud de la conversión a notación postfija (RPN) como la correctitud del cálculo aritmético.

### 6. ¿Qué valida la prueba pública sobre `NQueens`?

La prueba pública valida para n=4:
- `queens.solutions == 2`: el tablero 4×4 tiene exactamente 2 soluciones al problema de las 4 reinas.
- `queens.placements.size() == 2`: se almacenaron ambas configuraciones cuando `collectPlacements = true`.

### 7. ¿Qué valida la prueba pública sobre `Maze`?

La prueba pública valida:
- `!path.empty()`: existe un camino, es decir, el laberinto tiene solución.
- `path.front() == {1, 1}`: el primer elemento del camino es la celda de inicio.
- `path.back() == {3, 3}`: el último elemento es la celda destino.

### 8. ¿Qué valida la prueba pública sobre `bestWindow` en la simulación bancaria?

La prueba pública configura:
- `windows[0]`: 2 clientes
- `windows[1]`: 1 cliente
- `windows[2]`: vacía

Y verifica que `bestWindow(windows) == 2`, es decir, retorna el índice de la cola más corta, la vacía. Esto valida la política de "menor cola" y el comportamiento cuando hay una ventanilla sin clientes.

### 9. ¿Qué casos adicionales cubre la prueba interna y no aparecen de forma explícita en la pública?

 La prueba interna `test_internal_week4.cpp` agrega:

**Conversión de base:**
- `toBaseRecursive(0, 2) == "0"`: caso borde del número cero, que debe retornar "0" sin entrar al bucle ni a la recursión.
- `toBaseIterative(255, 16) == "FF"`: conversión hexadecimal con dígitos alfabéticos.

**Paréntesis:**
- `parenRecursive("sin parentesis")` -> `true`: cadena sin ningún delimitador debe considerarse balanceada.
- `parenIterative("{[(])}")` -> `false`: cruce con tres tipos de delimitadores.

**Evaluador:**
- `"3+4*2"`: prioridad de operadores sin paréntesis; RPN `"3 4 2 * +"`, valor 11.
- `"5!+2^3"`: combinación de factorial y potencia; RPN `"5 ! 2 3 ^ +"`, valor 128.
- `"-3+5"`: signo menos unario; valor 2.

**N-Reinas:**
- `placeQueens(1)`: caso mínimo con exactamente una solución; la reina única está en la columna 0.

### 10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, estado y complejidad?

Las pruebas solo verifican que el código produce el resultado correcto para un conjunto finito y específico de casos. No demuestran Corrección general, que se entiende como el algoritmo funcione para todos los inputs posibles, no solo los probados. 

Un algoritmo puede pasar todas las pruebas escritas y aun así ser incorrecto para inputs no probados. La explicación de invariantes es la forma de demostrar corrección sin enumeración exhaustiva.

### 11. Da un ejemplo de un error conceptual que podría sobrevivir si solo se ejecutaran los casos mínimos.


Supongamos que `parenIterative` ignora el **tipo** de delimitador al cerrar y solo verifica que la pila no esté vacía:

```cpp
case ')': case ']': case '}':
    if (stack.empty()) return false;
    stack.pop();
    break;
```

Esta implementación errónea pasaría todos los casos mínimos que solo usan paréntesis redondos, como `"a+(b*(c+d))"`. Pero fallaría para `"([)]"` (cruce de tipos). Si la prueba pública no incluyera el caso `"([)]"`, ese error conceptual nunca se detectaría, y el código parecería correcto.

