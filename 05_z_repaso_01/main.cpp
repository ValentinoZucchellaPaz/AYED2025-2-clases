// Estás desarrollando un nuevo videojuego de rol (RPG) y necesitas crear un sistema flexible para manejar
// las habilidades de los personajes. Todas las habilidades tienen un comportamiento básico, pero cada tipo
// de habilidad tiene su propia forma de "activarse". Tu tarea es:
// Crear una clase base abstracta llamada Habilidad con las siguientes características:
// Un constructor que reciba el nombre de la habilidad.
// Un método virtual puro llamado activar() que no retorne nada. Este método será la clave de la polimorfismo.
// Crear dos clases hijas que hereden de Habilidad:
// HechizoDeFuego: Esta habilidad quema al enemigo. Su método activar() debe imprimir un mensaje que diga algo
// como: "Lanzas una bola de fuego, ¡quemando al enemigo!".
// AtaqueFisico: Esta habilidad es un golpe cuerpo a cuerpo. Su método activar() debe imprimir un mensaje como:
// " Asestas un golpe contundente con tu espada, ¡dañando al enemigo!".
// En la función main, crea un puntero a la clase base (Habilidad*) y asigna dinámicamente objetos de las clases
// derivadas. Llama al método activar() a través del puntero para demostrar el comportamiento polimórfico.
// El objetivo es que, sin importar a qué tipo de habilidad apunte el puntero, la llamada a activar()
// ejecute la implementación correcta para esa clase específica. 
#include <iostream>
#include <string>
using namespace std;

class Habilidad
{
    string nombre;

public:
    Habilidad(const string &nombre)
    {
        this->nombre = nombre;
    };
    virtual void activar() const = 0;
    virtual ~Habilidad () {};
};

class HechizoDeFuego : public Habilidad
{
public:
    HechizoDeFuego() : Habilidad("Hechizo de Fuego") {};
    void activar() const override
    {
        cout << "Lanzas una bola de fuego, ¡quemando al enemigo!" << endl;
    };
    ~HechizoDeFuego () {cout << "Destructor Hechizo de fuego"<< endl; };
};

class AtaqueFisico : public Habilidad
{
public:
    AtaqueFisico() : Habilidad("Ataque Fisico") {};
    void activar() const override
    {
        cout << "Asestas un golpe contundente con tu espada, ¡dañando al enemigo!" << endl;
    };
    ~AtaqueFisico () {cout << "Destructor Ataque Fisico"<< endl; };
};

int main()
{
    Habilidad* h1 = new HechizoDeFuego();
    Habilidad* h2 = new AtaqueFisico(); 
    h1->activar();
    h2->activar();
    delete h1;
    delete h2;
    return 0;
}
