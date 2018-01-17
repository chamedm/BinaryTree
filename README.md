# BinaryTree
Definición, implementación y uso de contenedor Set de números enteros. 

    Setset_create(CompareFunccf: PrintFuncpf); -> Crea  un  ejemplar Set con  memoria  dinámica  y asigna NULL, 0, cf y pfa sus elementos.           Observe que cfes un apuntador a la función comparadoray pfes un apuntador a la función para imprimir un dato.
    
    intset_size(Set); -> Extrae el tamaño del conjunto.boolset_add(Sets, Typet);Agrega  el  valor tal  conjunto  s,  sólo  si saún  no              contiene  a t(esto  sólo  se  puede  saber  usando  la función comparadora referida por el compareFuncde s). Si  se  agregó,                devuelve  TRUE  e  incrementa  el tamaño en uno. Si no, devuelve FALSE.
    
    boolset_contains(Sets, Typet); ->  Devuelve TRUE si el valor t forma parte del conjunto s(use compareFuncal buscar); FALSE en otro              caso. Debe estar implementada de manera iterativa.
    
    voidset_destroy(Sets); .> Elimina  todos  los  nodos  que  constituyen  el  árbol binario, y al conjunto. Se implementa llamando a la           función  recursiva destroy,  que  hace  un  recorrido post-orden.
    
    boolset_remove(Sets, Typet); -> Elimina el valor tdel conjunto s, sólo si s sí contiene a t.  Si  se  eliminó,  devuelve  TRUE  y               disminuye  el tamaño en uno. Si no, devuelve FALSE.Lo primero que hace es buscar si existe un nodo cuyo  dato refiera  al  valor           t(use compareFuncal buscar). Luego, en caso afirmativo y una vez ubicado el  nodo, llama  a  la  función removeBranchpara                   eliminarlo.
    
    voidset_print(Sets); -> Imprime  el  árbol  llamando  a  la  función  recursiva print, pasandocomo   parámetros la   raíz   y   el              printFuncasociado a s.
