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

class Item {
protected:
    std::string nombre;
    double precio;
    TipoItem tipo;

public:
    Item(const std::string& nombre, double precio, TipoItem tipo) : nombre(nombre), precio(precio), tipo(tipo) {}
    virtual ~Item() {}

    virtual void mostrarInformacion() {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Precio: " << precio << std::endl;

    }
};

int main() {
    Item *i1 = new Item("nomrbre", 1.23, TipoItem::Gema);
    std::cout << "hello" ;
    return 0;
}
