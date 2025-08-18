//
// Created by Roberto Pablo Gomez on 20/03/2025.
//

#ifndef VIRTUAL_FORMA_H
#define VIRTUAL_FORMA_H

#include <iostream>

class Forma {
public:
    // sintaxis metodo abstracto (virtual): indica que se va a re escribir metodo en subclases
    /**
     * Virtual:
     * indica que subclase debe sobre escribir ese metodo para instanciarse,
     * pero no evita que lo instance dentro de la clase actual (problematico, es muy abstracto una forma para dibujarse)
     * para lograr esto ultimo existen los metodos virtuales puros
     */
    virtual void dibujar () const;
};


#endif //VIRTUAL_FORMA_H
