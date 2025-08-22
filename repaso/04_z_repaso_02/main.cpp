// Eres el ingeniero de software principal en 'TechSolutions'. Tu tarea es desarrollar un módulo para gestionar
// la información de los empleados. La empresa te ha pedido que uses punteros para optimizar el acceso a los
// datos y la memoria. Necesitas:

// Crear una struct llamada Empleado que contenga el nombre (std::string), el ID (int) y el salario (double).
// Implementar una función que, utilizando punteros, actualice el salario de un empleado basándose en su ID.
// Esto simula un aumento de sueldo. 💰
// Implementar una segunda función que imprima los datos de un empleado, también usando punteros.
#include <iostream>
#include <string>
using namespace std;

struct Empleado
{
    string nombre;
    int id;

    Empleado(string nombre, int id, double salario) : nombre(nombre), id(id), _salario(salario) {}
    void mostrarDatos()
    {
        cout << "Nombre: " << nombre << ", ID: " << id << ", Salario: " << _salario << endl;
    }
    double *getPtrSalario()
    {
        return &_salario;
    }

private:
    double _salario;
};

int main()
{
    Empleado juancito = Empleado("Juan Perez", 12345, 50000.0);

    double *ptrSalario = juancito.getPtrSalario();
    cout << "Salario actual: " << *ptrSalario << endl;
    *ptrSalario = 55000.0; // Aumento de sueldo
    cout << "Salario actualizado: " << *ptrSalario << endl;
    juancito.mostrarDatos();

    return 0;
}
