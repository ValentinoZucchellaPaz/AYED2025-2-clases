# Resumenes por unidad AYED 2025

**Valentino Zucchella Paz**  

**Facultad**: FCEFyN (UNC)  
**Carrera**: Ing. en Computación.  
**Materia**: Algoritmos y Estructuras de Datos.  

Se verán estructuras de datos y algoritmos usando C++.

El código es sobre las clases prácticas del docente Pablo Gomez, sobre el cual hago comentarios segun creo conveniente.
Este documento es para estudio de la materia, basado en mis notas de las clases, en conjunto con la ayuda de ChatGPT y web para investigar y sacarme dudas.
Esto es un apunte informal no habrá links o referencias de bibliografia, pero si hay algo que no te cierra podes buscarlo o preguntarlo a tu agente de IA fav.
**Si encontrás un error en conceptos o código o simplemente quieras dejar tu feedback, no dudes en hablarme [vzucchellapaz@mi.unc.edu.ar](mailto::vzucchellapaz@mi.unc.edu.ar)**

<mark>DISCLAIMER</mark>: No se busca reemplazar ni socavar las enseñanzas de la cátedra, si acá leen A y en la clase les dicen B, sigan B. Esto son MIS notas.

---

## Índice
1. [Memoria](#1-memoria)
    1. [Python Tutor](#python-tutor)
    2. [Tipos](#tipos)
    3. [Comparación](#comparación)
    4. [Casos de uso](#casos-de-uso)
    5. [Memory Leaks](#memory-leaks)
    6. [Static](#static)
2. [Punteros](#2-punteros)
    1. [Operadores](#21-operadores)
    2. [Aritmetica de punteros](#22-aritmética-de-punteros)
    3. [Punteros y Arreglos](#23-punteros-y-arreglos-importante)
    4. [Punteros vs Referencia](#25-punteros-vs-referencias)
    5. [Resumen de unidad](#26-resumen-de-unidad)
3. [Estructuras y Clases](#3-estructuras-y-clases)
    1. [Bases](#31-bases)
    2. [Inicialización](#32-inicialización)
    3. [Constructores y Destructores](#33-constructores-y-destructores)
    4. [Sobrecarga de Operadores](#34-sobrecarga-de-operadores)
    5. [Herencia](#35-herencia)
    6. [Polimorfismo](#36-polimorfismo)
    7. [Clases Abstractas (Interfaces)](#37-clases-abstractas-interfaces)

---

## Introducción.

Considero útil primero hablar un poco de **C++ como lenguaje y como trabaja la memoria de este.**  

La intención de su creación fue **extender al lenguaje de programación C** y añadir mecanismos que permiten la manipulación de objetos. Se dice que C++ es un lenguaje híbrido, además multiparadigma (en la primera parte del curso veremos Programación Orientada a Objetos, uno de estos paradigmas).  

Es un lenguaje **tipado** y **compilado**, osea que hay tipos definidos (que determinan la cantidad de bytes en memoria que usan) y además, antes de ejecutarse se debe compilar (un proceso por el cual se transcribe del lenguaje C++ a lenguaje maquina, haciendo un ejecutable que se pueda correr en la computadora)  

Aunque controvencial, se lo considera una **lenguaje de bajo nivel**, esto es porque tiene la capacidad de interactuar directamente con el hardware, permitir el manejo manual de memoria, utilizar punteros y realizar optimizaciones de rendimiento extremas.

En base a esto último, es que comprender qué es la memoria y a que se hace referencia cuando se habla de esta es escencial para afrontar el resto de temas con una mejor representación mental de qué está pasando por detrás del código.

---

## 1. Memoria

La memoria en C++ se organiza como un conjunto de **celdas de 1 byte, cada una con una dirección asociada que permite acceder a su ubicación**. Todo el programa y la "memoria" de este se guarda en la *RAM*.

Esta memoria se utiliza para almacenar los valores y variables del programa, y el espacio necesario para almacenar un valor depende del tipo de dato; por ejemplo, un char ocupa 1 byte, un int 4 y un double 8.

El nombre de una variable actúa como una etiqueta que permite acceder a su ubicación en memoria sin conocer su dirección exacta.
Los punteros, por otro lado, son variables que contienen la dirección de memoria misma.

### Python Tutor
[Python Tutor](https://pythontutor.com/cpp.html#mode=edit) es una herramienta para ver la ejecución, el movimiento de las variables y punteros a través de la memoria a medida que se ejecuta el código.
Pero esto tiene un problema, originalmente se hizo para Python y luego tuvo el soporte para C++, por lo que hay cosas que generan inconsistencias con lo que van a leer sobre la memoria.
Aquí verán solo Stack y Heap, lo cual **esta bien para los fines del curso**. No tienen que saber como compila C++ para este curso, pero tampoco hace mal.
En el futuro desarrollaré más sobre las diferencias y distintas diferencias de Python Tutor con la compilación real de C++.

### Tipos

Se organiza en bloques que determinan el tiempo de vida y el ámbito de las variables. Los principales tipos de memoria son la stack (pila) y el heap (montón).

- **Stack**: almacena variables locales y gestionar llamadas a funciones, con un tamaño limitado y una destrucción automática cuando se abandona el ámbito de una función. La *gestiona automáticamente el sistema*. Generalmente se almacenan las variables conjuntamente, una al lado de la otra.

- **Heap**: memoria dinámica, cuyo tamaño está limitado únicamente por la cantidad de RAM disponible, y requiere una *gestión manual* (`new` y `delete`). Su reserva y liberación ocurre en tiempo de ejecución, lo que es esencial (y peligroso) cuando el tamaño de los datos no se conoce de antemano.

- **Memoria estática (Data Segment)**. similar al stack pero en esta se guardan objetos con duración estática, como variables globales o variables locales declaradas con `static`, que se crean antes de que el programa comience a ejecutarse y se destruyen al finalizar.

Aunque a veces se asocia erróneamente la memoria estática con el stack, en realidad las variables con duración automática (locales no estáticas) son las que residen en el stack.


### Comparación
| Tipo de Memoria | Momento de Asignación | Momento de Liberación | Ejemplo                      |
| --------------- | --------------------- | --------------------- | ---------------------------- |
| **Estática**    | Compilación           | Fin del programa      | Variables globales, `static` |
| **Stack**       | Entrada a función     | Salida de función     | Variables locales            |
| **Heap**        | Ejecución (`new`)     | Manual (`delete`)     | Objetos dinámicos            |

### Casos de Uso
- Estática → contadores, configuraciones globales, valores que no cambian.
- Stack → variables temporales, funciones recursivas, parámetros por valor.
- Heap → estructuras de datos grandes o dinámicas, objetos que deben persistir entre funciones.


### Memory Leaks

Se denomina así cuando se reserva (y o guarda) memoria dinamica (heap) y no se libera cuando ya no se necesita, osea que lo que grabe en esa memoria seguirá hasta que termine la ejecución del programa.

Esto puede deverse a muchos factores pero es escencial tenerlo en cuenta porque, como dije antes, C++ usa un manejo manual de la memoria. En Java o Python me puedo olvidar porque existe un Recolector de Basura que lo hace de forma automática, pero aquí debe ser manual.

Para poner un poco de contexto, si tenemos un programa con memory leaks y lo corremos en nuestra computadora no va a crashear, es raro incluso si usamos un programa muy grande. Pero imagina que se programa un microcontrolador (poca memoria) que mueve una antena en la punta del Cerro Uritorco, no va a ser conveniente ir hasta alla a resetearlo si crashea porque se quedó sin memoria.

### Static

`static` puede usarse para declarar variables y funciones en el ámbito global, el ámbito de espacio de nombres y el ámbito de clase. También se pueden declarar variables estáticas en el ámbito local.
Es un modificador de almacenamiento y **su función depende de dónde y cómo se use**.

*Duración estática significa que el objeto o la variable se asignan cuando se inicia el programa y se desasignan cuando finaliza el programa.*

*Vinculación externa* significa que el nombre de la variable puede verse desde fuera del archivo en el que se declara la variable. A la inversa, la *vinculación interna* significa que el nombre no es visible fuera del archivo en el que se declara la variable.

**Casos de uso**
1. Variables locales (dentro de funciones)
    - Se crea solo una vez, y su valor persiste entre llamadas sucesivas a la función (vive durante toda la exe del programa).
    - No se destruye al salir del bloque, como ocurre con una variable normal.
    - Ambito local, no es accesible de fuera de la función.
```cpp
void contador() {
    static int x = 0; // se inicializa solo la primera vez
    x++;
    cout << "x vale: " << x << endl;
}

int main() {
    contador(); // x = 1
    contador(); // x = 2
    contador(); // x = 3
}
```

2. Variables globales
    - Una variable global estática solo es visible en el archivo donde fue declarada (tiene linkage interno).
    - Sirve para ocultar variables globales y evitar conflictos de nombres entre archivos. Por ejemplo si tengo `static int contador` en archivo1.cpp no puedo acceder desde otro archivo con `extern int contador`

3. Miembros de clases
    - Pertenece a la clase en sí, no a un objeto en particular. 👉 Significa que todos los objetos comparten ese mismo miembro.
    - Pueden ser variables o funciones de la clase.

```cpp
class Persona {
public:
    static int poblacion;
    static void imprimir() {
        cout << "Soy una función estática" << endl;
    }
    Persona() { poblacion++; }
};

int Persona.poblacion = 0; // Definición fuera de la clase

int main() {
    Persona.imprimir(); // Llamo a f antes de inicializar
    Persona p1, p2, p3;
    cout << "Población: " << Persona::poblacion << endl; // 3

}
```

--- 

## 2. Punteros

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


#### Operaciones válidas:
- `p + n` → puntero a la posición `n` elementos adelante.
- `p - n` → puntero a la posición `n` elementos atrás.
- `p2 - p1` → número de elementos entre dos punteros (misma zona de memoria).
- Comparaciones (`<`, `>`, `==`, etc.) → posibles si apuntan al mismo arreglo/bloque.


### 2.3 Punteros y arreglos (importante)
- El **nombre de arreglo** es un puntero a su primer elemento.
- Por eso `arr` y `&arr[0]` son equivalentes al usarlos como puntero.

```cpp
int arr[3] = {1, 2, 3};
int* p = arr; // p == &arr[0]
```


### 2.4 CONST y punteros

#### Antes de eso, **¿Qué es const?**

const significa constante: el valor no puede ser modificado después de ser inicializado.

Sirve para:  
- Proteger datos de modificaciones.
- Mejorar legibilidad (intención clara).
- Optimización (el compilador puede hacer chequeos extra).

**Ejemplos con casos de punteros**

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

### 2.5 Punteros vs referencias

En C++ hay tres formas principales de **pasar parámetros a funciones**:

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
- Más seguro, pero puede ser costoso si el objeto es grande (arrays).

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
- La función recibe una dirección de memoria y se accede al valor real.
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

>`Ejercicio:` Al igual que en las clases, es útil implementar y ver la ejecución de 3 funciones `swap(a, b)` la cual tome 2 enteros y los cambie. Para esto probar con las 3 formas anteriores y ver como se mueve y cambia la memoria usando [python tutor](https://pythontutor.com/cpp.html#mode=edit), podrás correr codigo y ver como se agregar variables al Stack y Heap


#### Cuándo usar cada uno

✅ Referencia (&)
- Cuando querés modificar el valor de un parámetro.
- Cuando querés evitar copias en objetos pesados (ej: `const T&`).
- Cuando querés sintaxis limpia y segura.

✅ Puntero (*)
- Cuando trabajás con arrays, memoria dinámica (`new`, `malloc`), o APIs C.
- Cuando necesitás que un parámetro pueda ser "nulo".
- Cuando querés cambiar a qué objeto apunta (ej: función que reasigna).

#### Notas finales

- Cuando pasamos por valor, se crea una copia en memoria (stack).
- Cuando pasamos por puntero, lo que viaja es la dirección (un valor de 4 u 8 bytes según la arquitectura). El objeto real sigue en la memoria original.
- Cuando pasamos por referencia, el compilador usualmente lo traduce a un puntero “oculto”, pero con sintaxis más amigable.

### 2.6 Resumen de unidad
- Operadores y Artimetica:
    - `&` → dirección de.
    - `*` → desreferencia.
    - `->` → acceso a miembro vía puntero.
    - `p + n` → mueve el puntero `n` elementos (no bytes).
- El **nombre del array** es equivalente puntero al primer elemento.
- Siempre **inicializar** punteros (`nullptr` si no tienen valor aún).
- **Const** evita que se re asigne esa var, útil para punteros y funciones
- En funciones pasar props por **referencia** cuando se deba modificar dentro de f (evita copias de objeto), con **punteros** cuando es un array o hay que usar null. Por valor crea una copia.

---

## 3. Estructuras y Clases

Ya existe una materia que estudia a fondo la Programación Orientada a Objetos, pero debido a cambio de planes algunos no la tuvieron por lo que pueden estar confundidos con algunos conceptos. [Este es un blog interesante sobre POO](https://coderslink.com/talento/blog/que-es-la-programacion-orientada-a-objetos-poo-y-cuales-son-sus-principios-fundamentales/)

*Luego de las bases se hablará de clases pero se debe tener en mente que todo es aplicable a estructuras, su única diferencia es que struct tiene miembros públicos por defecto, y en class privados.*

### 3.1 Bases
Si ya viste algo de POO y clases pasa a la prox.

En programación orientada a objetos, una **clase** es un molde o
plantilla que define cómo serán los objetos.  
Dentro de una clase podemos tener:
- **Atributos (datos/variables de instancia):** representan el estado del objeto.
- **Métodos (funciones):** representan el comportamiento del objeto.

Por otro lado, los **struct** son originarios de C y extendidos en C++ con comportamientos similares a clases, pero con una diferencia fundamental en los **modificadores de acceso**.
Son **idénticos a las clases**, salvo que por defecto sus miembros son **públicos**.

📌 **Puntos clave sobre las clases en C++:**
- Permiten **encapsulamiento** (ocultar la implementación interna).
- Pueden tener **constructores y destructores**.
- Soportan **herencia** y **polimorfismo**.
- Por defecto, los miembros de una clase son **privados**.
- Por defecto, los miembros de una estructura son **públicos**.
- Las estructuras se usan para **datos simples agrupados** o cuando no es necesario ocultar información. Mientras que las clases para **representar entidades lógicas completas**.


#### Diferencias entre Clase y Struct en C++

Aunque hoy en día se pueden usar casi igual, hay diferencias de estilo y semántica:

| Característica          | `class`                                                              | `struct`                                                          |
| ----------------------- | -------------------------------------------------------------------- | ----------------------------------------------------------------- |
| **Acceso por defecto**  | `private`                                                            | `public`                                                          |
| **Encapsulación**       | Usada típicamente para OOP con atributos privados y métodos públicos | Usado más para agrupar datos simples                              |
| **Estilo / Convención** | Representa **objetos complejos**, entidades con lógica               | Representa **datos livianos** o registros de datos                |
| **Herencia**            | Privada por defecto                                                  | Pública por defecto                                               |
| **Uso típico**          | Modelar entidades del dominio (ej: Usuario, Pedido, Cuenta)          | Modelar estructuras de datos (ej: Punto, Vector3D, Configuración) |


#### Ejemplo Comparativo

``` cpp
class Coche { // definición no es instancia
private: // Acceso restringido: solo se puede acceder desde dentro de la clase (encapsulamiento).
    std::string marca;
    int velocidad;

public: // Acceso público: las instancias pueden llamar a lo que hay aquí dentro
    // Constructor
    Coche(std::string m, int v) : marca(m), velocidad(v) {}

    // Método
    void acelerar() {
        velocidad += 10;
        std::cout << marca << " va a " << velocidad << " km/h" << std::endl;
    }

    // Método a implementar antes de main
    void groovy()
};

void Coche::groovy(){
    std::cout << "groovy\n";
}

struct Coordenada {
    int x;
    int y;
};
```

Para crear instancias (objetos) se inicializan usando el constructor (dentro de main):

``` cpp
Coche c1("Toyota", 100);
c1.acelerar(); // Métodos, encapsulación

Coordenada punto {5, 7};
std::cout << "X: " << punto.x << ", Y: " << punto.y << std::endl; // Datos simples
```

### 3.2 Inicialización
```cpp
// stack allocation
Persona p1;              // Llama al constructor por defecto
Persona p2(20, "Juan");  // Llama al constructor con parámetros
Persona p3{30, "Ana"};   // Inicialización con llaves (uniform initialization)
Persona p4 = Persona(25, "Carlos"); // Inicialización por copia (equivalente a directa en C++ moderno)

// heap allocation
Persona * p5 = new Persona(25, "Carlos");

// static allocation
static Persona p6 (50, "Marta")
```
#### Inicialización automática (stack allocation)
- Se guarda en la stack (pila).
- Se destruye automáticamente al salir del ámbito.
- Muy eficiente porque el stack tiene gestión automática.
- Sintaxis y diferencias:
    - () → inicialización directa.
    - {} → inicialización uniforme (C++11+). Previene narrowing conversions (por ej., int x{3.14}; da error).
    - = → inicialización por copia (aunque es identica a directa en C++ moderno porque el compilador lo optimiza).

#### Inicialización dinámica (heap allocation)
Se usa `new` cuando se llama al constructor, tiene las siguientes caracteristicas:
- El objeto vive en el heap (montículo).
- Devuelve un puntero (a su dirección en el heap)
- No se destruye automáticamente → debes liberar con delete.

#### Inicialización estática
- Si es global o static, vive toda la ejecución del programa.
- Solo se crea una vez, no se destruye al salir del ámbito.
- Muy usado en singletons o constantes globales.

#### Resumen
| Forma                       | Dónde se guarda                    | Vida útil                  |
| --------------------------- | ---------------------------------- | -------------------------- |
| `Persona p;`                | **Stack**                          | Hasta que termina el scope |
| `new Persona();`            | **Heap**                           | Hasta `delete`             |
| `static Persona p;`         | **Data segment** (global estática) | Todo el programa           |
| `Persona p = Persona(...);` | Stack (igual que directa)          | Scope                      |


### 3.3 Constructores y Destructores

Un **constructor** es una función miembro especial que se llama automáticamente cuando se crea un objeto.
- Tiene el mismo nombre que la clase/struct.
- No tiene tipo de retorno (ni void).
- Se usa para inicializar datos miembros.

####  Tipos

1. **Por defecto**
Se invoca cuando no se pasan parámetros al crear un objeto.
Si no lo definimos, C++ genera uno implícito (que inicializa los miembros con valores por defecto o indeterminados en tipos primitivos).
2. **Parametrizado**
Permite inicializar los miembros con valores específicos.
3. **Copia**
Se invoca cuando se crea un objeto a partir de otro del mismo tipo.
Por defecto, C++ genera uno que copia miembro a miembro,<mark>esta copia es SUPERFICIAL, si hay un miembro que es un puntero (por ejemplo un array), copiará el puntero y dos objetos copiados compartirán el mismo array. </mark>
4. **Movimiento**
Se usa cuando el objeto se inicializa a partir de un temporal o un recurso que se puede "mover".
Evita copias innecesarias, optimizando el rendimiento.

#### Destructor
Un **destructor** es una método especial que se llama automáticamente cuando un objeto de esa clase es destruido.
Se usa principalmente para liberar recursos que el objeto pudo haber adquirido durante su vida (memoria dinámica, archivos abiertos, conexiones de red, etc.)

**Caracteristicas:**
- Se llama igual que la clase pero con una virgulilla ~ delante.
- No devuelve nada (void implícito).
- No recibe parámetros.
- No se puede sobrecargar (solo hay uno por clase).

**¿Cuándo se llama al destructor?**
- Objeto local (en stack) → al salir de su ámbito.
- Objeto dinámico (heap) con new → cuando usamos delete.
- Objetos globales o estáticos → al finalizar el programa.

**Destructor por Defecto**
Si no se declara uno, el compilador designa uno default, el cual llama al destructor de cada miembor (si tienen). <mark>Esto no libera memoria dinamica (heap)</mark>, si se tienen arrays se debe implementar un destructor en la clase para liberar los recursos.

**Importancia**
Si no liberas lo que reservaste en el constructor (o métodos), tendrás memory leaks.
Si tu clase gestiona recursos, probablemente necesites definir:
- Destructor
- Constructor de copia
- Operador de asignación



#### Ejemplos
**Constructores y destructor**
```cpp
struct Punto {
    int x, y;
    int [] recurso;

    // Constructor Parametizado
    Punto(int xVal, int yVal) : x(xVal), y(yVal) { 
        recurso = new int[5];
    }
    // Constructor de Copia Custom (deep copy)
    Punto(const Punto& otro) : x(otro.x), y(otro.y) {
        recurso = new int[5];
        for(int i = 0; i< 5; i++) recurso[i] = otro.recurso[i];
    }
    // Destructor Custom
    ~Punto() {
        std::cout << "Destructor llamado\n";
        delete[] recurso; // liberamos memoria
        // primitivos (int) se borran automaticamente al salir del stack
        // "se dejan morir"
    }
    // Constructor por defecto (existe aunque no lo escriba)
    Punto() : x(0), y(0) {}
};

int main() {
    Punto p1(5, 10);
    Punto p2 = p1; // Copia los valores de p1
    delete p1; // se llama destructor
}
```
Con esta implementación se evita que se comparta un mismo array al hacer copias y memory leaks al borrar el objeto.

**Ejemplo constructor de movimiento**
```cpp
struct Vector {
    vector<int> datos; // <- tipo de c++, se hace #include <vector>

    Vector(vector<int>&& v) : datos(move(v)) { // operador de copia (&&) y move es f de c++
        cout << "Constructor de movimiento\n";
    }
};

int main() {
    Vector v(move(vector<int>{1, 2, 3})); // Se mueve el temporal
}
```

### 3.4 Sobrecarga de operadores
La sobrecarga de operadores permite redefinir el comportamiento de operadores como +, -, =, ==, etc.

- Operadores que sí se pueden sobrecargar
    - Aritméticos: +, -, *, /, %
    - Relacionales: ==, !=, <, >, <=, >=
    - Asignación: =, +=, -=, etc.
    - Otros: [], (), ->, ++, --

- Operadores que NO se pueden sobrecargar
    - . (acceso a miembro)
    - .* (puntero a miembro)
    - :: (resolución de ámbito)
    - sizeof
    - typeid

**Ejemplo de sobrecarga operador + y ==**
```cpp
struct Punto {
    int x, y;
    Punto(int xVal, int yVal) : x(xVal), y(yVal) {}

    // Sobrecarga del operador +
    Punto operator+(const Punto& otro) const {
        return Punto(x + otro.x, y + otro.y);
    }

    // Sobrecarga del operador ==
    bool operator==(const Punto& otro) const {
        return (x == otro.x && y == otro.y);
    }
};

int main() {
    Punto p1(5, 10), p2(5, 10);
    if (p1 == p2) cout << "Son iguales\n";
    
    Punto p3 = p1 + p2; // Usa la sobrecarga
    cout << p3.x << ", " << p3.y << endl; // 10, 20
}
```

### 3.5 Herencia
La herencia es un mecanismo de la Programación Orientada a Objetos (POO) que permite a una clase (clase hijo) reutilizar atributos y métodos de otra clase (clase padre).
**Esto favorece la reutilización de código y el diseño jerárquico.**

*Siempre tener en cuenta que se va a heredar lo público y protegido, los campos privados no pasarán a la clase hijo*

*Resulta conveniente leer sobre los cuidados con los [destructores de clase padre](#-destrucción-virtual-importante)*

**Tipos de herencia:**
- `public`: lo público en el padre sigue siendo público en el hijo (la más común).
- `protected`: lo público/protegido en el padre pasa a ser protegido en el hijo.
- `private`: lo público/protegido en el padre pasa a ser privado en el hijo.

**Multiple**
C++ permite herencia múltiple, esto es que una clase hijo herede de muchas clases padres, pudiendo generar estructuras lógicas mejor segregadas.

Imagina un `Venteveo`, es un pájaro volador, pero si pongo un método `volar()` en la clase padre `Pajaro`, estaría haciendo voladores a pájaros que no vuelan como `Pinguino` o `Kiwi`.
Es por esto que `Venteveo` va a heredar de `Pajaro` (sin el método volar) y `Volador` (con el método)

**Ejemplo**
```cpp
class Base {
public:
    void metodoBase() {
        std::cout << "Soy un método de la clase Base\n";
    }
};

class Derivada : public Base {  // "public" define el tipo de herencia
public:
    void metodoDerivado() {
        std::cout << "Soy un método de la clase Derivada\n";
    }
};
```

### 3.6 Polimorfismo
El polimorfismo significa "muchas formas". En C++, permite que una misma interfaz (ej. un método) tenga distintas implementaciones dependiendo del objeto.

Existen dos tipos:
1. Polimorfismo en tiempo de compilación (sobrecarga de funciones y operadores).
2. Polimorfismo en tiempo de ejecución (funciones virtuales y herencia).

**En tiempo de compilación**
La sobrecarga de funciones es definir una arriba de otra funciones que toman distintos tipos, haciendo que se acceda primero a la superior y vaya bajando la jerarquía.
La sobrecarga de operadores ya fue cubierta en [Constructores](#33-sobrecarga-de-operadores).

```cpp
class Calculadora {
public:
    int suma(int a, int b) {
        return a + b;
    }

    double suma(double a, double b) {
        return a + b;
    }
};
```

#### Método Virtual
El polimorfismo en tiempo de ejecución aparece cuando trabajamos con punteros o referencias a clases padre.

Ejemplo intuitivo:
- Tienes una clase padre `Animal` con un método `hablar()`.
- Varias clases hijas (`Perro`, `Gato`, etc.) sobrescriben ese método.
- Si tienes un puntero de tipo `Animal*` que apunta a un Perro, ¿qué `hablar()` debe llamar?
👉 Aquí entra el despacho dinámico: la **decisión se hace en tiempo de ejecución**.

Una **función virtual** es una función que se declara con la palabra clave `virtual` en la clase padre, y que puede ser sobrescrita en las clases hijas.

>**Conceptos detrás del mecanismo (dato de color)**
>
>Cuando declaras una función como virtual:
>1. El compilador genera una tabla de funciones virtuales (vtable) para la clase.
>    - Esta tabla contiene punteros a las implementaciones de las funciones virtuales.
>2. Cada objeto que tiene métodos virtuales guarda un puntero oculto a su vtable (llamado vptr).
>3. Cuando llamas a una función virtual a través de un puntero o referencia a base:
>    - El programa mira el vptr del objeto en tiempo de ejecución.
>    - Usa la vtable para encontrar la función correcta.
>    - Llama a la implementación adecuada de la clase derivada.
>
>👉 Esto se conoce como despacho dinámico o dynamic dispatch.

#### 🚨 Destrucción virtual (Importante)
Cuando trabajamos con herencia y punteros, el destructor de la clase padre debe ser virtual, o puedes tener fugas de memoria.

Al eliminar una clase hija a partir de un puntero de la clase padre:
- Destructor no virtual: se ejecutaría el destructor del padre solamente y no del hijo.
- Destructor virtual: se ejecutaría el destructor del padre y recursivamente el de los hijos.


#### Método Virtual Puro

Un **método virtual puro** es un método que se declara en la clase padre sin implementación obligatoria. Se indica con = 0.

La principal diferencia con `virtual` normal es que este permite una implementación por defecto y luego ser sobreescrito.
`virtual puro` no tiene implementación obligatoria en la clase base; fuerza a la clase hija a implementarlo.. Si no lo hace, la clase derivada también será abstracta.

#### Ejemplo completo

```cpp
class Figura {
public:
    virtual void dibujar() const = 0;   // método puro virtual
    virtual ~Figura() = default;        // destructor virtual para evitar fugas
    // virtual ~Figura() { cout << "elimnando padre\n"; }
};

class Circulo : public Figura {
public:
    // ~Circulo() { cout << "eliminando hija\n"; }
    void dibujar() const override {
        cout << "Dibujando un círculo" << endl;
    }
};

class Rectangulo : public Figura {
public:
    void dibujar() const override {
        cout << "Dibujando un rectángulo" << endl;
    }
};

int main() {
    vector<Figura*> figuras;
    figuras.push_back(new Circulo());
    figuras.push_back(new Rectangulo());

    for (auto f : figuras) {
        f->dibujar(); // Polimorfismo en acción
    }

    for (auto f : figuras) delete f; // liberar memoria
}
```

Como el destructor de padre es virtual se evitan memory leaks.
Si no borrara los destructores con salida por cout, vería los dos eliminando padre e hijo.
Pero si no pusiera el virtual tendría solo eliminando padre.
Esto es una memory leak, se elimina la clase padre y no la hija

### 3.7 Clases Abstractas (Interfaces)

En C++, una clase abstracta es una clase que no puede ser instanciada directamente (no puedes hacer Clase c;) y está pensada para servir como padre para otras clases.

Se utiliza cuando queremos definir una interfaz común para un conjunto de clases hijas, pero dejando la implementación de ciertos métodos a esas clases hijas.

Se puede simular una `Interfaz` (como en Java por ejemplo) haciendo una clase que: 
- Sólo tiene [métodos virtuales puros](#método-virtual-puro).
- No contiene implementación (salvo quizá un destructor virtual).

**La clase Figura del [Ejemplo completo de Polimorfismo](#ejemplo-completo) es una clase abstracta**
Notar que se trabajan con punteros y no valores de Figura.

#### Cuidados a tener
- Destructor virtual obligatorio:
Si vas a heredar de una clase abstracta y destruir objetos por punteros base, siempre define un destructor virtual en la clase abstracta.
De lo contrario → Undefined Behavior y memory leaks.
- Clases derivadas pueden ser abstractas:
Si una clase hija no implementa todos los métodos puros virtuales de la base, también será abstracta.
- Herencia múltiple y conflictos:
C++ permite herencia múltiple, pero si implementas varias interfaces (clases abstractas) que tengan el mismo método, puede generar ambigüedad → se resuelve con `override` explícito.

### 3.8 Funciones amigas
Una función amiga (`friend`) es una función que no pertenece a una clase, pero que tiene acceso a los miembros privados y protegidos de esa clase.

Normalmente, los miembros privados solo pueden accederse desde la propia clase o desde sus métodos.
La función amiga rompe esa restricción de acceso, permitiendo acceder directamente a los datos privados.

También es posible declarar una clase amiga completa, la cual tiene acceso a miembros privados/protected también.

**Cuidado: rompe encapsulamiento**

#### Características
- No es miembro de la clase:
- No se llama con obj.func(), sino como función global (func(obj)).
- Puede acceder a privados y protegidos de la clase.
- Se declara dentro de la clase con la palabra clave friend, pero se define fuera.

##### Ejemplo:

```cpp
class Caja {
private:
    int contenido;

public:
    Caja(int c) : contenido(c) {}

    // Declaración de función amiga
    friend void mostrarContenido(const Caja& c);
};

// Definición fuera de la clase
void mostrarContenido(const Caja& c) {
    std::cout << "Contenido: " << c.contenido << std::endl;
}

int main() {
    Caja c(42);
    mostrarContenido(c); // Función amiga puede acceder al miembro privado
}
```