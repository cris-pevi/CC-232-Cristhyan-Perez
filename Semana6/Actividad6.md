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

