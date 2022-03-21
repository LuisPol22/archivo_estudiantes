#include <iostream>
#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>

using namespace std;

const char *nombre_archivo = "archivo.dat";
int a;

struct estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	char direccion[50];
	int telefono;
};

void ingresar_estudiante();
void abrir_estudiante();
void modificar_estudiante();
void eliminar_estudiante();
void buscar_codigo();



int main(){

	cout<<"INGRESE UNA OPCION"<<endl;
	cout<<"1. Ingresar Nuevo Estudiante: "<<endl;
	cout<<"2. Modificar Estudiante: "<<endl;
	cout<<"3. Mostrar Datos de Estudiantes: "<<endl;
	cout<<"4. Buscar Codigo: "<<endl;
	cin>>a;
	
	switch (a) {
		abrir_estudiante();
	case 1:
		ingresar_estudiante();
		break;
		
	case 2:
		abrir_estudiante();
		modificar_estudiante();
		break;
	case 3:
		abrir_estudiante();
		break;
	case 4:
		buscar_codigo();
		break;
	default:
		cout << "OPCION INVALIDA" << endl;
	}
	
	
	
	
	return 0;

}



void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombre_archivo, "w+b");
	}
	estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(estudiante), 1, archivo );
	cout<<"____________________________________________________________________________________________"<<endl;
	cout << "id" <<" | "<< "CODIGO" <<" | "<< "NOMBRE"<<" | "<<"APELLIDO"<<" | "<<"DIRECCION"<<" | "<<"TELEFONO"<<" "<<endl;	
		do{
		cout<<"___________________________________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre<<" | "<<estudiante.apellido<<" | "<<estudiante.direccion<<" | "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombre_archivo, "ab");

	
		estudiante estudiante;
		 string nombre,apellido,direccion;
		do{
			
			fflush(stdin);
				system ("cls"); 
	
		cout<<"DATOS DEL ESTUDIANTE "<<endl;	
		
		cout<<"Ingrese el Codigo......";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre......";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido....";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 

		cout<<"Ingrese la Direccion...";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str()); 
				
		cout<<"Ingrese el Telefono....";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_estudiante();

}
void modificar_estudiante(){
	
	FILE* archivo = fopen(nombre_archivo, "r+b");
	
		int id;
		string nombre,apellido,direccion;	
    	estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(estudiante), SEEK_SET );  
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
	
		cout<<"Ingrese el Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(estudiante), 1, archivo );
		
	fclose(archivo);
	abrir_estudiante();
		system("PAUSE");
}
void buscar_codigo(){
		FILE* archivo = fopen(nombre_archivo,"rb");	
	int pos=0,indice=0,cod=0;
	cout<<"Que codigo desea ver: ";
	cin>>cod;
	
	estudiante estudiante;
	fread(&estudiante,sizeof(estudiante),1,archivo);	
	do{
	   if(estudiante.codigo == cod)	{
	   	cout<<"Codigo: "<<estudiante.codigo<<endl;
	   	cout<<"Nombres: "<<estudiante.nombre<<endl;
	   	cout<<"Apellidos: "<<estudiante.apellido<<endl;
	   	cout<<"Telefono: "<<estudiante.telefono<<endl;
	   	
	   }
	   
	   fread(&estudiante,sizeof(estudiante),1,archivo);	
	} while(feof(archivo)==0);
	

	fclose(archivo);
}
