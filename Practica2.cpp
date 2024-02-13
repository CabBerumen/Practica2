#include <iostream>
#include <string>

using namespace std;

class Usuario{
    protected:
    string nombre;
    string telefono;
    int edad;
    string password;

    public:
    Usuario(string nombreUsuario, string telefonoUsuario, int edadUsuario, string passwordUsuario) : nombre(nombreUsuario), telefono(telefonoUsuario), edad(edadUsuario), password(passwordUsuario){
    }

    bool login (string nombreUsuario, string passwordUsuario){
        return(nombre == nombreUsuario && password == passwordUsuario);

    }

    void logout(){

        cout << nombre << " ha cerrado la sesión" << endl;

    }

    void cambiarpassword(string old, string newPass){
        if(password == old){
            password = newPass;
            cout << nombre << " ha cambiado la contraseña" << endl;

        } else {
            cout << nombre  << " La contraseña no coincide" << endl;
        }

    }


};

class Cliente : public Usuario {
    public:
    Cliente(string nombreUsuario, string telefonoUsuario, int edadUsuario, string passwordUsuario) : Usuario(nombreUsuario, telefonoUsuario, edadUsuario, passwordUsuario){
    }

    void comprar(){
        cout << nombre << " ha hecho una compra" << endl;

    }

    void reclamar(){
         cout << nombre << " ha hecho una reclamación" << endl;

    }

    void devolucion(){
         cout << nombre << " ha hecho una devolución" << endl;

    }
};

class Vendedor : public Usuario{
    public:
    Vendedor(string nombreUsuario, string telefonoUsuario, int edadUsuario, string passwordUsuario) : Usuario(nombreUsuario, telefonoUsuario, edadUsuario, passwordUsuario){
    }

    void vender(){
        cout << nombre << " ha hecho una venta" << endl;
    }

    void actualizar(){
        cout << nombre << " ha hecho una actualización" << endl;

    }
};

int main(){
    Cliente cliente1("Noel Gallagher", "3338301832", 56, "FlyingBirds"); //Ultimo atribulo es la contraseña
    Vendedor vendedor1("Hayley Williams", "3320154618", 35, "Paramore"); //Ultimo atribulo es la contraseña
    
    if (cliente1.login("Noel Gallagher", "FlyingBirds")){
        cout << "Se ha iniciado sesión con un cliente" << endl;
    } 

    if (vendedor1.login("Hayley Williams", "Paramore")){
        cout << "Se ha iniciado sesión con un vendedor" << endl;
    } 

    cliente1.cambiarpassword("FlyingBird", "Oasis123"); // La primera contraseña debe ser igual a la de arriba para que se pueda cambiar, la 2da es la nueva
    vendedor1.cambiarpassword("Paramore", "Paramore1234"); // La primera contraseña debe ser igual a la de arriba para que se pueda cambiar, la 2da es la nueva
    cliente1.comprar();
    cliente1.reclamar();
    cliente1.devolucion();

    vendedor1.vender();
    vendedor1.actualizar();

    cliente1.logout();
    vendedor1.logout();

    return 0;


}