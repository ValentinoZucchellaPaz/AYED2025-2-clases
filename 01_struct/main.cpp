#include <iostream>
#include <string>

struct Item {
  std::string m_nombre;
  int m_cantidad;
};

struct Persona {
    int edad;
    std::string nombre;
};

struct PersonaConst {
    int edad;
    std::string nombre;

    // existe otros contructores x defecto: constructor copia, movimiento y destructor
    PersonaConst() = delete; // elimino constructor default
    PersonaConst(const std::string& n) { // paso string por referencia para evitar copias del string (arr de char)
        edad = 0;
        nombre = n;
    };
    PersonaConst(int e, std::string n) : edad(e), nombre(n) {}; // sintaxis simplificada

    PersonaConst(const PersonaConst&) = delete; // elimino constructor de copia
    PersonaConst& operator=(const PersonaConst&) = delete; // elimino constructor para el operador "=" (sobrecarga de operadores)
};


void inventario ();

int main() {
    Persona p;
    std::cout << p.edad << std::endl;
    std::cout << p.nombre << std::endl;

    Persona p1 = Persona();
    std::cout << p1.edad << std::endl;
    std::cout << p1.nombre << std::endl;

    p1.edad = 22;
    p1.nombre = "pepe";

    Persona p2 = p1;

    p1.edad = 33;
    p1.nombre = "juan";

    Persona p3;
    p3 = p1;

    // PersonaConst pc;
    PersonaConst pc = PersonaConst(11, "hola");
    PersonaConst pc1 = PersonaConst("hola");
    // no puedo usar las siguientes lineas por que como elimine los constructores voy a tener error
    // PersonaConst pc3;
    // pc = pc1;
    // PersonaConst pc2 = pc1;
}

void inventario () {
    int numeroItems;
    std::cout << "Cantidad:" << std::endl;
    std::cin >> numeroItems;

    Item *inventario = new Item[numeroItems];

    for (int i = 0; i < numeroItems; i++) {
        std::cout << "Ingrese Nombre" << std::endl;
        std::cin >> inventario[i].m_nombre;
        std::cout << "Ingrese Cantidad" << std::endl;
        std::cin >> inventario[i].m_cantidad;
    }

    for (int i = 0; i < numeroItems; i++) {
        std::cout << inventario[i].m_nombre << std::endl;
        std::cout << inventario[i].m_cantidad << std::endl;
    }

    for (int i = 0; i < numeroItems; i++) {
        std::cout << (*(inventario+i)).m_nombre << std::endl;
        std::cout << (*(inventario+i)).m_cantidad << std::endl;
    }

    for (int i = 0; i < numeroItems; i++) {
        std::cout << (inventario+i)->m_nombre << std::endl;
        std::cout << (inventario+i)->m_cantidad << std::endl;
    }

    delete[] inventario;
}