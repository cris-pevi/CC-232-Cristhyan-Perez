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

