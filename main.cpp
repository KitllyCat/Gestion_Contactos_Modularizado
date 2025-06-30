#include <iostream>
#include <windows.h>
#include <string>
#include "contactos.h"

using namespace std;

int main(){
	SetConsoleOutputCP(CP_UTF8);
	int opcion;
	do{
		cout<< "-----Gestor de contactos-----"<<endl<<endl;
		cout<<"Elija la opcion que desea realizar en el programa:"<<endl;
		cout<<"1) Agregar un nuevo contacto"<<endl;
		cout<<"2) Eliminar un contacto existente"<<endl;
		cout<<"3) Mostrar todos los contactos guardados"<<endl;
		cout<<"4) Mostrar todos los contactos guardados en orden de correos"<<endl;
		cout<<"5) Salir"<<endl;
		cout<<"Selecione su opcion: ";
		cin>>opcion;
		cout<<endl;
		
		switch(opcion){
			case 1:{
				system("cls");
				agregarContacto();
				break;
			}
			case 2:{
				system("cls");
				eliminarContacto();
				break;
			}
			case 3:{
				system("cls");
				mostrarListadoRegistrados();
				break;
			}
			case 4:{
				system("cls");
				mostrarListadoExistentes();
				break;
			}
			case 5:{
				system("cls");
				cout<<"Saliendo del programa..."<<endl;
				break;
			}
			default:{
				cout<<"Opción invalida!!! Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(opcion!=5);
	return 0;
}