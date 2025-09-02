#include "functions.hpp"
#include <stdexcept> // For std::runtime_error


int sumatoriaIter(int valor) {
    int resultado = 0;
    for (int i = 0; i <= valor; i++){
        resultado += i;
    }
    return resultado;
}

// sumatoria (3);
int sumatoriaRec(int valor) {
    if (valor < 0) {
        throw new std::runtime_error("no se puede calcular sumatoria");
    }
    if (valor == 0) {
        return 0;
    }
    return valor + sumatoriaRec(valor - 1);
}

int fibonacciIter(int valor) {
    if (valor == 0) return 0;
    if (valor == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= valor; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

//                              fibonacciRec (5)
//              fibonacciRec (4)        -           fibonacciRec (3)
//      fibonacciRec(3) - fibonacciRec(2)    fibonacciRec(2)     fibonacciRec(1) 
// fibonacciRec(2)     fibonacciRec(1) 
int fibonacciRec(int valor) {
    if (valor == 1 || valor == 2){
        return 1;
    } 
    return fibonacciRec(valor-1) + fibonacciRec(valor - 2);
}

int fibaux(int y, int a1, int a2, int x){
    if(y == x){
        return a1 + a2;
    }
    return fibaux(y+1, a1 + a2, a1, x);
}

int fibonacciTail(int valor){
    if (valor == 1 || valor == 2){
        return 1;
    }
    return fibaux (3, 1, 1, valor);
}

// revisar metodo recursivo a iterativo
int fibite(int y, int a1, int a2, int x){
    while (y != x){
        int aux = a1;
        y++;
        a1 = a1 + a2;
        a2 = aux;
    }
    return a1 + a2;
}

int fibonacciTailIter(int valor){
    if (valor == 1 || valor == 2){
        return 1;
    }
    return fibite (3, 1, 1, valor);
}
