#ifndef CONTACTOS_H
#define CONTACTOS_H
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

const int tam=99;

struct contactoEmail{
    string nombres;
    string sexo;
    string edad;
    string telefono;
    string email;
    string nacionalidad;
};

extern contactoEmail conEm[tam];
extern int cantCont;
extern int indice;

void agregarContacto();
void eliminarContacto();
void mostrarListadoRegistrados();
void mostrarListadoExistentes();
void exportarContactos();

#endif
