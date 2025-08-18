//
// Created by Roberto Pablo Gomez on 20/03/2025.
//

#ifndef HERENCIA_ESTUDIANTE_H
#define HERENCIA_ESTUDIANTE_H
#include "Persona.h"

// heredo campos publicos de persona
class Estudiante : public Persona {
public:
    // constructor, llama a constructor default de persona e inicializa la la matricula
    Estudiante (int m) : Persona() , matricula(m) {}
    void mostrarEstudiante ();
private:
    int matricula;
};


#endif //HERENCIA_ESTUDIANTE_H
