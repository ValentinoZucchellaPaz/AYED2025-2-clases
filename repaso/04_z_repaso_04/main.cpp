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
#include <string>

enum class TipoItem
{
    Arma,
    Armadura,
    Pocion,
    Gema
};

std::string tipoItemToString(TipoItem tipo)
{
    switch (tipo)
    {
    case TipoItem::Arma:
        return "Arma";
    case TipoItem::Armadura:
        return "Armadura";
    case TipoItem::Pocion:
        return "Pocion";
    case TipoItem::Gema:
        return "Gema";
    default:
        return "Desconocido";
    }
}

class Item
{
protected:
    std::string nombre;
    double precio;
    TipoItem tipo;

public:
    Item(const std::string &nombre, double precio, TipoItem tipo) : nombre(nombre), precio(precio), tipo(tipo) {}
    virtual ~Item() {}

    virtual void mostrarInformacion()
    {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Precio: " << precio << std::endl;
    }
};

class Arma : public Item
{
private:
    int dano;

public:
    Arma(const std::string &nombre, double precio, int dano)
        : Item(nombre, precio, TipoItem::Arma), dano(dano) {}
    void mostrarInformacion() override
    {
        Item::mostrarInformacion();
        std::cout << "Tipo: " << tipoItemToString(this->tipo) << std::endl;
        std::cout << "Daño: " << dano << "\n"
                  << std::endl;
    }
};

class Pocion : public Item
{
private:
    int curacion;

public:
    Pocion(const std::string &nombre, double precio, int curacion)
        : Item(nombre, precio, TipoItem::Pocion), curacion(curacion) {}
    void mostrarInformacion() override
    {
        Item::mostrarInformacion();
        std::cout << "Tipo: " << tipoItemToString(this->tipo) << std::endl;
        std::cout << "Curación: " << curacion << "\n"
                  << std::endl;
    }
};

int main()
{
    Item *inventario[5]; // Array de punteros a Item
    for (int i = 0; i < 5; ++i)
    {
        if (i % 2 == 0)
        {
            inventario[i] = new Arma("Espada " + std::to_string(i), 100.0 + i * 10, 20 + i);
        }
        else
        {
            inventario[i] = new Pocion("Poción " + std::to_string(i), 50.0 + i * 5, 10 + i);
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        inventario[i]->mostrarInformacion();
    }

    for (int i = 0; i < 5; ++i)
    {
        delete inventario[i];    // Liberar memoria
        inventario[i] = nullptr; // Evitar dangling pointers
    }

    // Verificación de memoria liberada
    std::cout << "Memoria liberada correctamente." << std::endl;

    return 0;
}
