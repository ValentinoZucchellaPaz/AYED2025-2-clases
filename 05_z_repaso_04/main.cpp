// Eres el programador de un sistema de gestión de inventario para una tienda de videojuegos. Tu tarea es diseñar un módulo
//  que pueda manejar un array de objetos de tipo Item, cada uno representando un producto en el inventario.
// Reutiliza las clases Item, Arma y Pocion del ejercicio anterior. No necesitas reescribirlas, solo asegúrate de tener el 
// código a mano.
// En la función main, crea un array de punteros a la clase base Item con un tamaño fijo (por ejemplo, 4 o 5). 🖥️
// Utiliza un bucle para inicializar cada elemento del array. Dentro del bucle, usa new para instanciar objetos de las
//  clases derivadas (Arma, Pocion) y asignarlos a cada posición del array. Intenta que la mitad sean armas y la otra
//   mitad pociones.
// Luego, recorre el array con otro bucle. Para cada elemento, llama al método mostrarInformacion() a través del puntero. 
// Esto demostrará que puedes gestionar una colección de objetos de diferentes tipos de forma polimórfica.
// Muy importante: Utiliza un tercer bucle para liberar la memoria de cada objeto creado con new. Esto es crucial para
//  evitar memory leaks.

#include <iostream>

enum class TipoItem {
    Arma,
    Armadura,
    Pocion,
    Gema
};

std::string tipoItemToString (TipoItem tipoItem) {
    switch (tipoItem) {
        case TipoItem::Arma:
            return "Arma";
        case TipoItem::Armadura:
            return "Armadura";
        case TipoItem::Pocion:
            return "Pocion";
        case TipoItem::Gema:
            return "Gema";
        default:
            return "Tipo de item desconocido";
    }
}

class Item {
protected:
    std::string nombre;
    double precio;
    TipoItem tipo;

public:
    Item () : nombre(""), precio(0.0), tipo(TipoItem::Arma){};
    Item(const std::string& nombre, double precio, TipoItem tipo) : nombre(nombre), precio(precio), tipo(tipo) {}
    virtual ~Item() {}

    virtual void mostrarInformacion() {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Precio: " << precio << std::endl;
// Como hacemos para mostrar el nombre del valor del enumerado ? 
        std::cout << "Tipo item: " << static_cast<int>(tipo) << std::endl;
        std::cout << "Tipo item: " << tipoItemToString(tipo) << std::endl;
    }
};

class Arma : public Item {
    int danio;
public:
    Arma(const std::string& nombre, double precio, int danio) : Item(nombre, precio, TipoItem::Arma), danio(danio) {}
    void mostrarInformacion() override {
        // Como hacemos para mostrar también los datos de los campos de la superclase? 
        Item::mostrarInformacion();
        std::cout << "Danio: " << danio << std::endl;
    }
};

class Pocion : public Item {
    int curacion;
public:
    Pocion(const std::string& nombre, double precio, int curacion) : Item(nombre, precio, TipoItem::Pocion), curacion(curacion) {}
    void mostrarInformacion() override {
        // Como hacemos para mostrar también los datos de los campos de la superclase? 
        Item::mostrarInformacion();
        std::cout << "Curacion: " << curacion << std::endl;
    }
};

int main() {
    const int TAMANIO = 5;
    //Item items [5]; // array de items - todo en el stack
    //Item* items [5]; // stack : items [ p1 (heap), p2 (heap),p3 (heap),p4 ,p5 ]
    Item** items = new Item*[TAMANIO]; // heap : items  [ p1 (heap), p2 (heap),p3 (heap),p4 ,p5 ]

    items[0] = new Arma("Espada de Acero", 150.0, 50);  // Heap : item 
    items[1] = new Pocion("Poción de Salud", 25.5, 20); // Heap : item 
    items[2] = new Arma("Arco y Flecha", 120.0, 40);    // Heap : item 
    items[3] = new Pocion("Poción de Mana", 30.0, 15);  // Heap : item 
    items[4] = new Pocion("Poción de Mana", 30.0, 15);  // Heap : item 

    std::cout << "--- Contenido del Inventario ---" << std::endl;
    for (int i = 0; i < TAMANIO; ++i) {
        std::cout << "\n--------------------------" << std::endl;
        items[i]->mostrarInformacion();
    }

    for (int i = 0; i < TAMANIO; ++i) {
        delete items[i];
    }
    delete[] items;

    return 0;
}
