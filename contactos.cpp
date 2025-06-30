#include "contactos.h"

contactoEmail conEm[tam];
int cantCont=0;
int indice=0;

void agregarContacto(){
	if(cantCont>=tam){
        cout<<"Ya no se pueden agregar más contactos. Límite alcanzado~!!!";
        Sleep(2000);
        system("cls");
        return;
    }
    contactoEmail aniadir;
    
    cout<<"----- Añadir Contacto -----"<<endl<<endl;
	cout<<"Ingrese el nombre los nombres completos de la persona: ";
	cin.ignore();
	getline(cin, aniadir.nombres);
	do{
    	cout<<endl<<"Ingrese el sexo (M/F): ";
    	getline(cin, aniadir.sexo);
    	if(aniadir.sexo!="M" && aniadir.sexo!="F" && aniadir.sexo!="m" && aniadir.sexo!="f"){
    	    cout<<"Error al momento de guardar dato. Solo se acepta 'M' o 'F' !!!"<<endl;
    	}
	}while(aniadir.sexo!="M" && aniadir.sexo!="F" && aniadir.sexo!="m" && aniadir.sexo!="f");
    int salirE=0;
	do{	
		salirE=1;
		cout<<endl<<"Ingrese la edad: ";
   		cin>>aniadir.edad;
    	cin.ignore();
    	for(char c:aniadir.edad){
	        if(!isdigit(c)){
	            cout<<"La edad tiene que ser solo con números!!!"<<endl;
	            salirE=0;
	            break;
	        }
        }
	}while(salirE!=1);
	int salirT=0;
	do{
		salirT=1;
	    cout<<endl<<"Ingrese el teléfono: ";
    	getline(cin, aniadir.telefono);
		int tamTel=aniadir.telefono.length();
	    if(tamTel!=9){
	        cout<<"El telefono tiene que tener 9 dígitos!!!"<<endl;
	        salirT=0;
	        continue;
	    }
	    for(char c:aniadir.telefono){
        if(!isdigit(c)){
            cout<<"El teléfono solo debe contener números!!!"<<endl;
            salirT=0;
            break;
        }
    }
	}while(salirT!=1);    
    do{
	    cout<<endl<<"Ingrese el Email: ";
    	getline(cin, aniadir.email);
	    if(aniadir.email.find('@')==string::npos){
	        cout<<"Email incorrecto. Debe contener un '@' para ser considerado!!!"<<endl;
	    }
	}while(aniadir.email.find('@')==string::npos);
    cout<<endl<<"Ingrese la nacionalidad: ";
    getline(cin, aniadir.nacionalidad);
	conEm[cantCont]=aniadir;
    cantCont++;
    cout<<endl<<"El contacto se añadio correctamente, regresando al menu..."<<endl;
    Sleep(2000);
    system("cls");
}

void eliminarContacto(){
	if(cantCont==0){
        cout<<"Ya no existen contactos, no se puede eliminar más!!!";
        Sleep(2000);
        system("cls");
        return;
    }
	cout<<"----- Eliminar contacto -----"<<endl<<endl;
	cout<<"Ingrese el numero de orden del contacto a eliminar(Índice): ";
	cin>>indice;
	cin.ignore();
	indice=indice-1;	
	if(indice>=0 && indice<cantCont){
		for(int i=indice;i<cantCont-1;i++){
			conEm[i]=conEm[i+1];
		}
	}else{
		cout<<"El número es incorrecto o inexistente. Regresando al menú..."<<endl;
        Sleep(2000);
        system("cls");
        return;
	}
	cantCont--;
	cout<<"Contacto eliminado correctamente, regresando al menu...";
    Sleep(2000);
    system("cls");
}

void mostrarListadoRegistrados(){
	if(cantCont==0){
        cout<<"No existen contactos que se puedan mostrar!!!";
        Sleep(2000);
        system("cls");
        return;
    }
    cout<<"----- Listado general de contactos -----"<<endl<<endl;
    for(int i=0;i<cantCont;i++){
    	cout<<i+1<<"._ Contacto:"<<endl<<endl;
        cout<<"Nombre: "<<conEm[i].nombres<<endl;
        cout<<"Sexo: "<<conEm[i].sexo<<endl;
        cout<<"Edad: "<<conEm[i].edad<<endl;
        cout<<"Teléfono: "<<conEm[i].telefono<<endl;
        cout<<"Email: "<<conEm[i].email<<endl;
        cout<<"Nacionalidad: "<<conEm[i].nacionalidad<<endl;
        cout<<endl<<"----------------------------------"<<endl<<endl;
	}
	cout<<endl<<"Presione enter para volver al menu principal...";
	cin.ignore();
	cin.get();
	system("cls");
}

string obtDom(const string& email){
    size_t pos=email.find('@');
    if (pos!=string::npos){
        return email.substr(pos+1);
    }
    return "";
}

void mostrarListadoExistentes(){
	if(cantCont==0){
        cout<<"No existen contactos que se puedan mostrar!!!";
        Sleep(2000);
        system("cls");
        return;
    }
    contactoEmail conEm2[tam];
    for(int i=0;i<cantCont;i++){
        conEm2[i]=conEm[i];
    }
    for(int i=0;i<cantCont-1;i++){
        for (int j=0;j<cantCont-i-1;j++){
        	string dom1, dom2;
            dom1=obtDom(conEm2[j].email);
            dom2=obtDom(conEm2[j+1].email);
            if (dom1>dom2){
                contactoEmail aux=conEm2[j];
                conEm2[j]=conEm2[j+1];
                conEm2[j+1]=aux;
            }
        }
    }  
    cout<<"----- Listado general de contactos -----"<<endl<<endl;
    for(int i=0;i<cantCont;i++){
        cout<<i+1<<"._ Contacto:"<<endl<<endl;
        cout<<"Nombre: "<<conEm2[i].nombres<<endl;
        cout<<"Email: "<<conEm2[i].email<<" (Dominio(@): "<<obtDom(conEm2[i].email)<<")"<<endl;
        cout<<endl<<"----------------------------------"<<endl<<endl;
    }
    cout<<endl<<"Presione enter para volver al menu principal...";
	cin.ignore();
	cin.get();
	system("cls");
}