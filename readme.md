# Resumenes por unidad AYED 2025

**Valentino Zucchella Paz**

**Facultad**: FCEFyN (UNC)
**Carrera**: Ing. en Computación.
**Materia**: Algoritmos y Estructuras de Datos.

Este documento es para estudio de la materia, basado en mis notas (y la ayuda de ChatGPT y navegador para investigar y sacarme dudas).
Como esto es un apunte informal no habrá links o referencias de bibliografia, pero si hay algo que no te cierra podes buscarlo o preguntarlo a tu agente de IA fav.
Se verán estructuras de datos y algoritmos usando C++.

## Índice
1. [Memoria](#memoria)
2. [Punteros](#punteros)
3. [Estructuras y Clases](#estructuras-y-clases)

## Introducción.

Considero útil primero hablar un poco de **C++ como lenguaje y como trabaja la memoria de este.**  

La intención de su creación fue **extender al lenguaje de programación C** y añadir mecanismos que permiten la manipulación de objetos. Se dice que C++ es un lenguaje híbrido, además multiparadigma (en la primera parte del curso veremos Programación Orientada a Objetos, uno de estos paradigmas).  

Es un lenguaje **tipado** y **compilado**, osea que hay tipos definidos (que determinan la cantidad de bytes en memoria que usan) y además, antes de ejecutarse se debe compilar (un proceso por el cual se transcribe del lenguaje C++ a lenguaje maquina, haciendo un ejecutable que se pueda correr en la computadora)  

Aunque controvencial, se lo considera una **lenguaje de bajo nivel**, esto es porque tiene la capacidad de interactuar directamente con el hardware, permitir el manejo manual de memoria, utilizar punteros y realizar optimizaciones de rendimiento extremas.

En base a esto último, es que comprender qué es la memoria y a que se hace referencia cuando se habla de esta es escencial para afrontar el resto de temas con una mejor representación mental de qué está pasando por detrás del código.

---

## 1. Memoria {#memoria}

La memoria en C++ se organiza como un conjunto de celdas, típicamente de tamaño 1 byte, cada una con una dirección asociada que permite acceder a su ubicación.  

Esta memoria se utiliza para almacenar los valores generados al ejecutar un programa, y el espacio necesario para almacenar un valor depende del tipo de dato; por ejemplo, un char ocupa 1 byte, un int 4 y un double 8.

Todo esto sucede en la memoria *RAM*, que es la memoria de acceso aleatorio donde se almacenan temporalmente el programa y sus variables durante la ejecución, aquí estarán las variables y funciones del programa.
El nombre de una variable actúa como una etiqueta que permite acceder a su ubicación en memoria sin conocer su dirección exacta.

En C++ (y en general en lenguajes de bajo nivel como C), la memoria donde se almacenan las variables y objetos puede dividirse en varias **áreas principales**: memoria **estática**, **dinámica**, **stack** (pila) y **heap** (montículo). Comprender estas diferencias es clave para escribir programas seguros y eficientes.

---

### 1.1 Memoria Estática (spoiler, no es el Stack)
- Se reserva en **tiempo de compilación**.
- Incluye:
    - **Variables globales**.
    - **Variables `static`** dentro de funciones o clases.
    - Constantes (`const` y `constexpr`).
- Su espacio de memoria se mantiene durante **toda la ejecución del programa**.

¿Qué? ¿Osea que **no se libera hasta que el programa finaliza**? Esto significa que:
- Es ideal para valores que **deben persistir entre llamadas a funciones**.
- Puede generar problemas si se usa excesivamente (alto consumo de memoria fija) → CUIDADO CON LOS STATIC.

---

### 1.2 Memoria Automática (este sí es Stack)

- Usada para variables locales dentro de funciones.
- Se reserva en el stack frame al entrar en la función y se libera automáticamente al salir.
- Muy rápida de asignar y liberar.
- Limitada en tamaño (overflow si hay demasiadas variables locales o recursión profunda).
- No requiere `delete` ni `free`.

---

### 1.3 Memoria Dinámica (Heap)

- Se reserva en tiempo de ejecución (runtime) usando `new` ó `malloc` (cuando se llega a la linea con esas instrucciones se reserva).
- Permite crear estructuras de tamaño variable o que sobrevivan más allá del ámbito de la función.
- Flexible, el tamaño puede decidirse en runtime.
- Necesita liberación manual (`delete` o `delete[]`), si no → **memory leaks**.
- Más lenta que la memoria de pila.
- Usada para estructuras grandes (listas, árboles, vectores dinámicos, etc.).

**Ejemplo**:
```cpp
int* ptr = new int(42);   // reserva en heap
delete ptr;               // liberación manual
```

---

### 1.4 Comparación
| Tipo de Memoria | Momento de Asignación | Momento de Liberación | Ejemplo                      |
| --------------- | --------------------- | --------------------- | ---------------------------- |
| **Estática**    | Compilación           | Fin del programa      | Variables globales, `static` |
| **Stack**       | Entrada a función     | Salida de función     | Variables locales            |
| **Heap**        | Ejecución (`new`)     | Manual (`delete`)     | Objetos dinámicos            |

### 1.5 Casos de Uso
- Estática → contadores, configuraciones globales, valores que no cambian.
- Stack → variables temporales, funciones recursivas, parámetros por valor.
- Heap → estructuras de datos grandes o dinámicas, objetos que deben persistir entre funciones.


### 1.6 Memory Leaks

Se denomina así a cuando, se reserva (y o guarda) memoria dinamica (heap) pero no se libera cuando ya no se necesita más, osea que lo que grabe en esa memoria seguirá hasta que termine la ejecución del programa.

Esto puede deverse a muchos factores pero es escencial tenerlo en cuenta porque, como dije antes, C++ usa un manejo manual de la memoria. En Java o Python me puedo olvidar porque existe un Recolector de Basura que lo hace de forma automática, pero aquí debe ser manual.

Para poner un poco de contexto, si tenemos un programa con memory leaks y lo corremos en nuestra computadora no va a crashear, es raro incluso si usamos un programa muy grande. Pero imagina que se programa un microcontrolador (poca memoria) que mueve una antena en la punta del Cerro Uritorco, no va a ser conveniente ir hasta alla a resetearlo si crashea porque se quedó sin memoria.

--- 

## 2. Punteros {#punteros}

Cuando hablamos de memoria dije que esta se organiza en celdas de 1 byte, que tienen una dirección y además pueden almacenar un valor (de 1 byte). Los punteros son esa dirección.

Un **puntero** es una variable cuyo valor es una **dirección de memoria**.  
En vez de guardar un valor directamente, guarda *la ubicación* donde ese valor está almacenado.
*Se debe tener en cuenta que al ser una variable, también se guarda en memoria, por lo que tiene un puntero, pero eso no es importante ahora.*

Cuando se asigna un puntero, se debe especificar el tipo de la variable a la que apunta, con esto C++ podrá hacer operaciones con punteros.

Ejemplo:
```cpp
int x = 42;
int* p = &x; // p guarda la dirección de memoria de x
```
Aquí:
- `x` → contiene el valor `42`.
- `&x` → es la dirección en memoria de `x`.
- `p` → es un puntero a `int` que guarda esa dirección.

---

### 2.1 Operadores

| Operador | Símbolo | Significado |
|----------|---------|-------------|
| **Dirección** | `&` | Devuelve la dirección de una variable. |
| **Desreferencia** | `*` | Accede al valor contenido en la dirección que guarda el puntero. |
| **Acceso miembro (puntero)** | `->` | Accede a un miembro de un objeto/struct/clase a través de un puntero. |

Ejemplos:
```cpp
int x = 10;
int* p = &x;     // & → obtener dirección
*p = 20;         // * → modificar valor apuntado
std::cout << x;  // imprime 20
```

Para estructuras:
```cpp
struct Punto { int x, y; };
Punto pt = {3, 4};
Punto* ptr = &pt; // o new Punto{...}

std::cout << ptr->x; // equivalente a (*ptr).x
```

---

### 2.2. Aritmética de punteros
En C++ **sumar o restar enteros a un puntero** no suma bytes, sino posiciones de elementos del tipo al que apunta.

Como cada puntero al inicializarse se dice a que tipo apunta, las operaciones se harán operando según los bytes de ese tipo.

Ejemplo:
```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* p = arr;        // p apunta a arr[0]

std::cout << *p;     // 10
p = p + 2;           // avanza 2 elementos, ahora apunta a arr[2]
std::cout << *p;     // 30
```

📌 Si `p` es `int*`, y un `int` ocupa 4 bytes, `p + 1` **mueve 4 bytes en memoria** (1 entero).  
📌 De igual manera al **trabajar con clases**, si sumo 1 a un puntero de una clase/struct, se moverá 1 unidad de esa clase. Imagina que cada clase tiene 120 bytes, entonces:
```cpp
*(punteroClase+1)
```
va a retornar el valor de lo que hay 120 bytes más adelante en memoria (a partir del inicio de una clase).  

---

#### Operaciones válidas:
- `p + n` → puntero a la posición `n` elementos adelante.
- `p - n` → puntero a la posición `n` elementos atrás.
- `p2 - p1` → número de elementos entre dos punteros (misma zona de memoria).
- Comparaciones (`<`, `>`, `==`, etc.) → posibles si apuntan al mismo arreglo/bloque.

---

#### Ejemplo visual de aritmética:
Supongamos:
```cpp
int arr[3] = {5, 6, 7};
int* p = arr;
```

Memoria (cada celda 4 bytes):
```
Dirección   Valor
0x1000      5   <- p
0x1004      6
0x1008      7
```
- `p + 1` apunta a `0x1004`.
- `*(p + 1)` → 6.

---

### 2.3 Punteros y arreglos (importante)
- El **nombre de arreglo** es un puntero a su primer elemento.
- Por eso `arr` y `&arr[0]` son equivalentes al usarlos como puntero.

```cpp
int arr[3] = {1, 2, 3};
int* p = arr; // p == &arr[0]
```

---

### 2.4 CONST y punteros

#### Antes de eso, **¿Qué es const?**

const significa constante: el valor no puede ser modificado después de ser inicializado.

Sirve para:  
- Proteger datos de modificaciones.
- Mejorar legibilidad (intención clara).
- Optimización (el compilador puede hacer chequeos extra).

```cpp
const int a = 10;
// a = 20  ❌ No se puede reasignar una var const
int x = 1, y = 2;
const int* p1 = &x; // puntero a constante (no puedo modificar valor, *p1, pero si puedo modficar a donde apunta el puntero)
int* const p2 = &x; // puntero constante (no puedo cambiar a dónde apunta, si su valor)
const int * const p3 = &x // puntero constante a constante (no se puede cambiar ni valor ni a donde apunta puntero)
```

#### Otros casos de CONST
- **En params de funciones** (haciendo que sus params sean inmutables, útil cuando se trabaja con params por referencia)
- **Después de funciones** (indica que el metodo no modifica atributos de la clase o struct, **da error al compilar sino**)

```cpp
void f (const int & x) {...}

class Persona {
    string nombre;
public:
    string getNombre() const {
        return nombre
    }
}
```
---

### 2.5 Parámetros de funciones: punteros vs referencias

En C++ hay **tres formas principales** de pasar parámetros a funciones:

1. **Por valor** (copia del argumento)
```cpp
void f(int x) {
    x = 10; // solo afecta a la copia
}

int main() {
    int a = 5;
    f(a);
    // a sigue valiendo 5
}
```

- Se crea una copia en memoria.
- El valor original no se modifica.
- Más seguro, pero puede ser costoso si el objeto es grande.

2. **Por puntero** ( * )
```cpp
void f(int* x) { // se recibe un puntero
    *x = 10; // modifica el contenido de la dirección a la que apunta
}

int main() {
    int a = 5;
    f(&a);
    // a ahora vale 10
}
```
- La función recibe una dirección de memoria.
- Dentro de la función, al usar *x, accedemos al valor real.
- Hay que pasar &a explícitamente.
- Permite que el parámetro sea nullptr (si no se valida, error seguro).
- Se puede cambiar qué dirección apunta el puntero dentro de la función (pero eso no afecta al puntero original, porque el puntero mismo se pasa por valor).

Ejemplo de confusión:
```cpp
void g(int* x) {
    int b = 20;
    x = &b; // solo cambia la copia local del puntero
}

int main() {
    int a = 5;
    g(&a);
    // a sigue siendo 5, el puntero original no cambió
}
```
3. **Por referencia** (&)
```cpp
void f(int& x) {
    x = 10; // modifica directamente a
}

int main() {
    int a = 5;
    f(a);
    // a ahora vale 10
}
```

- La función recibe un alias directo del objeto original.
- No hay necesidad de usar &a al llamar ni * dentro de la función.
- Siempre es válido, nunca nullptr.
- No se puede hacer que la referencia "apunte" a otra variable después de creada.

#### Comparativa
| Característica                | Puntero (`*`)            | Referencia (`&`)                |
| ----------------------------- | ------------------------ | ------------------------------- |
| Necesita `&` en llamada       | ✅ Sí                     | ❌ No                            |
| Se usa `*` para acceder valor | ✅ Sí                     | ❌ No (se usa directo)           |
| Puede ser `nullptr`           | ✅ Sí                     | ❌ No                            |
| Puede cambiar de objetivo     | ✅ Sí (puede reasignarse) | ❌ No (fijo tras inicializar)    |
| Más usado en                  | APIs C, arrays dinámicos | C++ moderno, parámetros por ref |

>`Ejercicio:` Al igual que en las clases, es útil implementar y ver la ejecución de 3 funciones `swap(a, b)` la cual tome 2 enteros y los cambie. Para esto probar con las 3 formas anteriores y ver como se mueve y cambia la memoria usando [python tutor](https://pythontutor.com/cpp.html#mode=edit), podrás correr codigo y ver como se agregar variables al Stack y Heap

---

### 2.6 Pero... ¿Qué cambia entre puntero y referencia?

- Cuando pasamos por valor, se crea una copia en memoria (stack).
- Cuando pasamos por puntero, lo que viaja es la dirección (un valor de 4 u 8 bytes según la arquitectura). El objeto real sigue en la memoria original.
- Cuando pasamos por referencia, el compilador usualmente lo traduce a un puntero “oculto”, pero con sintaxis más amigable.

Ejemplo ilustrado:
```cpp
void f(int& x) { x = 10; }  // referencia
void g(int* x) { *x = 20; } // puntero

int main() {
    int a = 5;

    f(a);  // mueve "referencia implícita" -> a = 10
    g(&a); // mueve dirección explícita   -> a = 20
}
```

#### Efecto en memoria (simplificado):

| Variable   | Dirección     | Valor                |
| ---------- | ------------- | -------------------- |
| `a`        | 0x100         | 20                   |
| `x` (en f) | alias → 0x100 | —                    |
| `x` (en g) | 0x200 (stack) | 0x100 (apunta a `a`) |

#### Cuándo usar cada uno

✅ Referencia (&)
- Cuando querés modificar el valor de un parámetro.
- Cuando querés evitar copias en objetos pesados (ej: `const T&`).
- Cuando querés sintaxis limpia y segura.

✅ Puntero (*)
- Cuando trabajás con arrays, memoria dinámica (`new`, `malloc`), o APIs C.
- Cuando necesitás que un parámetro pueda ser "nulo".
- Cuando querés cambiar a qué objeto apunta (ej: función que reasigna).

#### 👉 En resumen:

- Usa **referencias** para la mayoría de los casos en C++.
- Usa **punteros** cuando tenés que trabajar con memoria dinámica o "opcionalidad" (null).


---

### 2.7 Errores comunes y advertencias
- **Puntero colgante (dangling pointer):** usar un puntero después de liberar o perder su memoria.
- **Desreferenciar punteros nulos:** siempre inicializar punteros y verificar que no sean `nullptr`.
- **Moverse fuera de los límites** del arreglo: comportamiento indefinido.

---

### 2.8 Mini resumen rápido
- Operadores y Artimetica:
    - `&` → dirección de.
    - `*` → desreferencia.
    - `->` → acceso a miembro vía puntero.
    - `p + n` → mueve el puntero `n` elementos (no bytes).
- El **nombre del array** es equivalente puntero al primer elemento.
- Siempre **inicializar** punteros (`nullptr` si no tienen valor aún).
- **Const** evita que se re asigne esa var, util para punteros y funciones
- Pasar props por **referencia** generalmente, con **punteros** cuando es memoria dinámica o hay que usar null.


## 3. Estructuras y Clases {#estructuras-y-clases}
