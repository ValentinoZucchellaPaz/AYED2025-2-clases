// Estás trabajando en un videojuego de aventura y necesitas un sistema de inventario que pueda manejar diferentes
// tipos de objetos. Para asegurar que los datos estén bien organizados y evitar errores, usarás un enum para
// clasificar los ítems. Tu tarea es:
// Crear una enum llamada TipoItem que defina las siguientes categorías de ítems: Arma, Armadura, Pocion, y Gema. 💎
// Crear una clase base llamada Item que contenga un nombre (std::string), un precio (double), y el TipoItem del
// objeto.
// Implementar dos clases hijas que hereden de Item:
// - Arma: Un arma tiene un daño (int). Su constructor debe inicializar el tipo de ítem a TipoItem::Arma.
// - Pocion: Una poción tiene una cantidad de curación (int). Su constructor debe inicializar el tipo de ítem a
// TipoItem::Pocion.
// Crea un método virtual en la clase base Item llamado mostrarInformacion() que imprima los datos básicos del
// ítem (nombre, precio y tipo).
// Sobrescribe este método en las clases hijas para que impriman su información específica (el daño en Arma o
// la curación en Pocion) además de la información básica.
// En main, utiliza punteros a la clase base para instanciar objetos de las clases derivadas y luego llama
// al método mostrarInformacion() a través de los punteros para demostrar el polimorfismo.
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
    Item *i1 = new Item("nomrbre", 1.23, TipoItem::Gema);
    Item *arma = new Arma("Espada", 150.0, 50);
    Item *pocion = new Pocion("Poción de Vida", 30.0, 20);

    arma->mostrarInformacion();
    pocion->mostrarInformacion();

    return 0;
}
