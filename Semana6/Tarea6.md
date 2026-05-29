# A ctividad 6

2. Explica `getMax`, `insert`, `delMax`, `percolateUp`, `percolateDown` y `heapify`.

`getMax` lo que hace es devolver el elemento que está en la cima de un max-heap, ya que por propiedad sabemos que el elemento más grande siempre está en la raíz. Su complejidad es O(1).

`insert` se refiere a insertar un elemento nuevo. Se agrega al final del heap, en la última posición del arreglo. Probablemente rompa la propiedad de heap, porque el elemento recién agregado puede ser más grande que su padre y aquí entra el `percolateUp` para arreglarlo, subiendo por medio de rotaciones el nuevo elemento hasta su lugar correcto. La complejidad total de insertar es O(log n) porque en el peor caso tienes que subir desde la última hoja hasta la raíz, y la altura de un heap binario completo es logarítmica.

`delMax` se encarga de eliminar el máximo, es decir, la raíz en un max-heap. Sin embargo, no se puede borrar la raíz y dejar un hueco arriba, eso destruiría la estructura del árbol. Lo que se hace es tomar el último elemento del heap (la última hoja del último nivel), moverlo a la raíz, y reducir el tamaño del heap en uno. Y como probablemente se rompa la propiedad de heap, ahora se llama a `percolateDown` desde la raíz para hundirlo hasta su posición correcta. También cuesta O(log n) porque en el peor caso baja por toda la altura del árbol.

`percolateUp`, es la operación que sube un elemento hacia la raíz. Se empieza en el índice del elemento y se entra en un bucle donde se compara el elemento con su padre, y si el elemento es mayor que el padre (en el caso de max-heap), se intercambia y subimos el índice al del padre. Esto, se repites mientras el elemento siga siendo mayor que su nuevo padre, o hasta que llegues a la raíz, que ya no tiene padre con quien compararse.

`percolateDown`, hunde un elemento desde donde esté hacia las hojas. Como cada nodo tiene dos hijos, en cada paso miramos ambos hijos y elegimos el mayor de los dos. Si ese hijo mayor es más grande que el elemento actual, los intercambias y bajas tu índice al de ese hijo. Si el elemento ya es mayor que ambos hijos, paras porque ya cumple la propiedad. También paras cuando llegas a una hoja, que no tiene hijos. 



Finalmente heapify, en el sentido de la función que construye un heap completo a partir de un arreglo desordenado. La forma ingenua sería ir insertando elemento por elemento, lo cual te daría O(n log n). Pero existe una forma más inteligente, llamada construcción de Floyd, que parte del arreglo ya colocado y aplica percolateDown empezando desde el último nodo no-hoja hacia atrás, hasta llegar al índice cero. El último nodo no-hoja está en la posición n/2 - 1 aproximadamente, porque todos los nodos en la segunda mitad del arreglo son hojas y las hojas ya son heaps válidos por sí mismas (son árboles de un solo nodo). Lo sorprendente es que aunque parezca que esto debería costar O(n log n), un análisis más fino te demuestra que cuesta O(n), porque la mayoría de los nodos están cerca de las hojas y solo se hunden poquitos niveles, y los pocos nodos cercanos a la raíz que sí pueden hundirse mucho son contados. Esta construcción lineal es una de las cosas más bonitas de los heaps.
