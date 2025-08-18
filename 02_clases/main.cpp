#include <iostream>

class Persona {
public:
    // edad y nombre son campos publicos, su contructor x default tmb
    Persona(): edad(0), nombre(std::string("hola")) {};
    int edad;
    std::string nombre;
};

class PersonaConst {
public:
    // existe otros contructores x defecto: constructor copia, movimiento y destructor

    PersonaConst(): edad(0), nombre(std::string("")) {};
    PersonaConst(int e, std::string n): edad(e), nombre(n) {};
    void mostrar() {
      std::cout << edad << "  " << nombre << std::endl;
    };
private:
    // ahora son campos priv, no puedo acceder a ellos fuera de la clase
    int edad;
    std::string nombre;
};

int main() {
    Persona p;
    std::cout << p.edad << std::endl;
    std::cout << p.nombre << std::endl;
    Persona p1 = Persona();

    Persona *p2 = new Persona(); // al hacer new obtengo puntero al inicio de la clase o estructura
    std::cout << p2->edad << std::endl; // debo usar operador flecha xq es puntero
    std::cout << p2->nombre << std::endl;
    std::cout << (*p2).edad << std::endl; // ó obtener el valor y usar operador punto sobre el valor
    std::cout << (*p2).nombre << std::endl;
    delete p2; // liberar memoria manualmente

    PersonaConst pc = PersonaConst(22, "pepe");
    pc.mostrar();

    PersonaConst *pc1 = new PersonaConst(22, "pepe");
    pc1->mostrar();
    delete pc1;

    PersonaConst pi;
    PersonaConst pi1(22, std::string ("aa"));
    PersonaConst pi2{22, "jj"}; // otra sintaxis para pasar params al constructor

    return 0;
}