#include <iostream>
#include "Persona.h"
#include "Estudiante.h"

int main() {
    // sintaxis para inicializar una clase
    Persona p {33, "pp"};
    p.mostrar();

    Estudiante e (22);
    e.mostrarEstudiante();

    Persona p1 = e; // asigno un Estudiante a una var Persona
    // (subclase puede asignarse a clase padre, perdiendo info agregada pero es posible, al revés no)
    p1.mostrar();
    //p1.mostrarEstudiante(); // no puede exe metodo de subclase, perdio esa info

    return 0;
}
