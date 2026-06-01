### Actividad 6 - CC232 

Nombre: Cristhyan Manuel Perez Villegas

#### Objetivo

Consolidar lo trabajado en la Semana 6 a partir de lectura cercana, modificación controlada de código, ejecución de demostraciones, ampliación de pruebas y defensa escrita breve.

#### Bloque 1 - Diagnóstico inicial de la Semana 6

1. ¿Qué targets de demostraciones o pruebas aparecen para Semana 6?

Aquí, apaarecen:

**Demostraciones**

```bash
sem6_demo_pq_complheap_basico
sem6_demo_heapify_floyd
sem6_demo_heapsort
sem6_demo_left_heap_merge
sem6_demo_huffman`
sem6_demo_compare_with_semana5
sem6_demo_bst_rotations` 
sem6_demo_treap_basico
sem6_demo_capitulo6_panorama
```

**Pruebas**
Target:

```bash
sem6_test_public
sem6_test_internal
```

2. ¿Qué archivos se incluyen desde `Capitulo6.h`?

Incluye 16 archivos:

```bash
PQ.h
PQ_ComplHeap_macro.h
PQ_ComplHeap.h
PQ_ComplHeap_getMax.h
PQ_ComplHeap_insert.h
PQ_ComplHeap_percolateUp.h
PQ_ComplHeap_delMax.h
PQ_ComplHeap_percolateDown.h
PQ_ComplHeap_heapifyFloyd.h
PQ_LeftHeap.h
PQ_LeftHeap_merge.h
PQ_LeftHeap_insert.h
PQ_LeftHeap_delMax.h
vector_heapSort.h
Huffman_PQ.h
Treap.h
```

3. ¿Qué diferencia práctica hay entre `Capitulo6.h` y `Capitulo10.h`?

Bueno aquí, podemos decir que sobre la práctica, el código fuente puede usar cualquiera de los dos como punto de entrada ya que ambos exponen exactamente las mismas definiciones. Sin embargo, `Capitulo10.h` permite que un código escrito siguiendo la numeración del libro compile sin necesidad de conocer la organización por semanas del repositorio.

4. ¿Qué partes de Semana 6 dependen conceptualmente de Semana 5?

Para empezar podemos decir que `BinaryTree` ya que es la base estructural de `Treap`, `Huffman_PQ`, porque son árboles binarios. Además `BinarySearchTree` es usado en los archivos demo_compare_with_semana5.cpp y demo_bst_rotations.cpp para comparar BST con Treap. También, `BinaryHeap` que se usa en PQ_ComplHeap.

Entonces podemos decir que la Semana6, como ya es sabido, aquí podemos comprobarlo que es una extensión de la semana 5, el heap binario completo de Semana 6  es una versión más completa que el BinaryHeap. Además, el `Treap` de Semana 6 reutiliza BST de Semana 5 y agrega la dimensión de prioridad.

5. ¿Qué estructura se usa para prioridad pura?


6. ¿Qué estructura se usa para búsqueda ordenada?


7. ¿Qué estructura mezcla búsqueda ordenada con prioridad?


8. ¿Qué evidencia inicial obtuviste al ejecutar las pruebas sin modificar nada?.

A partir de la Semana6 correr lo siguiente:
cmake --test-dir build-debug -R semana6 --output-on-failure


#### Bloque 2 - Modificación de utilidades de heap completo

`PQ_ComplHeap_macro.h` ya contiene seis funciones `constexpr` que encapsulan la aritmética de índices del heap binario completo:

* `pqParent(i)` -> Índice del padre de `i`
* `pqLeftChild(i)` -> Índice del hijo izquierdo de `i`
* `pqRightChild(i)` -> Índice del hijo derecho de `i`
* `pqInHeap(i, n)` -> ¿El índice `i` está dentro del heap?
* `pqHasParent(i)` -> ¿El nodo `i` tiene padre?
* `pqLastInternal(n)` -> Último nodo interno del heap

Lo que falta es poder preguntar directamente si un nodo concreto tiene hijo izquierdo, si tiene hijo derecho, si es hoja, o es interno, sin exponer la aritmética en cada punto de uso.

1. ¿Por qué conviene expresar `parent`, `left`, `right` y pruebas de frontera como funciones pequeñas?

Una de las razónes es por el nombre por contrato por ejemplo en `pqHasLeftChild(i, n)` dice directamente "qué" se pregunta. Mientras que, `pqInHeap(pqLeftChild(i), n)` dice *cómo* se computa.

Otra de las razones es por tener un punto único de definición dado que si la representación cambiara, por ejemplo a un heap 1-indexado donde `pqLeftChild(i) = 2*i` solo se modifican `pqLeftChild` y `pqRightChild`.
Aquí las funciones de más alto nivel como `pqHasLeftChild` y `pqIsLeaf` se actualizan automáticamente por herencia.

Además, otra de las razones es que los Test son independientes ya que se puede verifivar en una prueba unitaria que `pqIsLeaf(3, 4)` devuelve `true` (nodo 3 en heap de 4 elementos, sin hijos) antes de integrar `percolateDown`.

2. ¿Qué ventaja tiene `constexpr` frente a macros?


3. ¿Qué caso borde aparece cuando el nodo tiene solo hijo izquierdo?

El caso borde ocurre cuando el heap tiene un número par de elementos. El último elemento del arreglo es el hijo izquierdo del último nodo interno, y ese nodo interno no tiene hijo derecho.

Por ejemplo con n = 6, con índices del o al 5:

```bash
        0
      |   |
     1     2
    | |   |
    3 4   5
```

El nodo en índice 2 tiene hijo izquierdo (índice 5) pero no hijo derecho.

Si `percolateDown` llega al nodo 2, el bucle continúa porque `pqHasLeftChild(2, 6)` es verdadero (2*2+1 = 5 < 6). Dentro del bucle, `c` se inicializa en 5. Luego se evalúa `pqHasRightChild(2, 6)`: 2*2+2 = 6, y 6 < 6 es falso, así que la rama del `if` no se toma y `c` permanece en 5.

El peligro que el código debe evitar es intentar acceder a a[6] como si el hijo derecho existiera. En la versión original, r = pqRightChild(i) se calcula siempre, pero `pqInHeap(r, n)` lo descarta antes del acceso a a[r]. En la versión modificada, `pqHasRightChild(i, n)` encapsula exactamente esa comprobación, haciendo más difícil equivocarse si se reescribe la lógica internamente.

4. ¿Qué condición identifica una hoja en la representación implícita?


5. ¿Qué cambió en `percolateDown` después de usar las funciones auxiliares?


## Bloque 4 - Modificación de `percolateDown`: elección del hijo dominante

1. ¿Por qué después de `delMax` se mueve el último elemento a la raíz?


2. ¿Por qué la reparación baja y no sube?


3. ¿Cómo se decide entre hijo izquierdo e hijo derecho?


4. ¿Qué pasa si el nodo actual tiene un solo hijo?


5. ¿Por qué `delMax` tiene costo `O(log n)`?.

Bueno, `delMax` hace dos cosas. Primero, intercambiar el primer y último elemento y reducir el tamaño, esto es O(1). Y, segundo, llamar `complHeapPercolateDown` desde la raíz.

Aqui, `percolateDown` sigue un camino desde la raíz hacia abajo. En cada iteración del bucle, i va a pasar a uno de sus hijos, es decir, baja un nivel. Un heap binario completo de n elementos tiene altura `h = ⌊log n⌋`. Por tanto el bucle ejecuta a lo sumo h iteraciones. Cada iteración realiza O(1) trabajo (dos comparaciones, a lo sumo un swap). Por lo tanto, el costo total es O(log n).