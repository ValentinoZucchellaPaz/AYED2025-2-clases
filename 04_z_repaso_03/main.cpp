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
