#include "Forma.h"
#include "Circulo.h"

/**
 * ejemplo de polimorfismo:
 * como le paso f por referencia,
 * si lo que le paso es una subclase de Forma que tiene el metodo llamado dibujar (polimorfismo)
 * entonces imprime Dibujar Circulo cuando le paso un circulo
 * distintos es si saco &: entonces va a hacer una copia de la instancia que le hago, pero una copia Forma (pierdo info)
 * entonces solo encuentra el dibujar de Forma, imprimiendo Dibujar Forma aún cuando le paso un Circulo
 */
void dibujarForma (const Forma& f) {
    f.dibujar();
}

int main() {
    Forma f;
    f.dibujar();
    Circulo c;
    c.dibujar();

    dibujarForma(f);
    dibujarForma(c);
    return 0;
}
