#ifndef net_h
#define net_h


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Declaración de clases
class Usuario_;
class Publicacion_;
class RedSocial_;

// Definición de la clase Usuario_
class Usuario_ {
private:
    int id_;

public:
    string nombre_;
    int edad_;
    string nacionalidad_;
    vector<Usuario_*> amigos_;
    vector<Publicacion_*> publicaciones_;

    // Métodos
    int getId2() {
        return id_;
    }

    void mostrar();
    void mostrarAmigos();
    void mostrarPublicaciones();
    void agregarAmigos(Usuario_* nuevoAmigo);
    void agregarPublicacion(Publicacion_* NuevaPublicacion);
    Publicacion_* crearPublicacion(int id2);
    Usuario_* getAmigo(int id2);

    // Constructores
    Usuario_(int id2, string nombre);
    Usuario_(int id2, string nombre, int edad);
    Usuario_(int id2, string nombre, int edad, string nacionalidad);
};

// Definición de la clase Publicacion_
class Publicacion_ {
private:
    int id_;

public:
    string fecha_;
    string contenido_;
    Usuario_* usuario_;

    // Métodos
    int getId2();
    void mostrarPublicacion();

    // Constructor
    Publicacion_(int id2, Usuario_* usuario, string fecha, string contenido);
};

// Definición de la clase RedSocial_
class RedSocial_ {
private:
    vector<Usuario_*> usuarios_;
    vector<Publicacion_*> publicaciones_;

public:
    string nombre_;

    // Métodos
    void agregarUsuario(Usuario_* usuario);
    void mostrarUsuarios();
    void agregarPublicacion(Publicacion_* publicacion);
    void mostrarPublicaciones();
    Usuario_* getUsuario(int id2);

    // Constructores
    RedSocial_(string nombre);
    RedSocial_(string nombre, vector<Usuario_*> usuarios);
    RedSocial_(string nombre, vector<Usuario_*> usuarios, vector<Publicacion_*> publicaciones);
};

// Implementación de métodos de la clase Usuario_
Usuario_::Usuario_(int id2, string nombre) {
    this->id_ = id2;
    this->nombre_ = nombre;
}

Usuario_::Usuario_(int id2, string nombre, int edad) {
    this->id_ = id2;
    this->nombre_ = nombre;
    this->edad_ = edad;
}

Usuario_::Usuario_(int id2, string nombre, int edad, string nacionalidad) {
    this->id_ = id2;
    this->nombre_ = nombre;
    this->edad_ = edad;
    this->nacionalidad_ = nacionalidad;
}

void Usuario_::mostrar() {
    cout << "Nombre: " << nombre_ << endl;
    cout << "Edad: " << edad_ << endl;
    cout << "Nacionalidad: " << nacionalidad_ << endl;
    cout << "Id: " << id_ << endl;
}

void Usuario_::mostrarAmigos() {
    cout << "Nombre: " << nombre_ << endl;
    for (int i = 0; i < amigos_.size(); i++) {
        Usuario_* amigo = amigos_[i];
        cout << "Nombre: " << amigo->nombre_ << endl;
        cout << "Edad: " << amigo->edad_ << endl;
        cout << "Nacionalidad: " << amigo->nacionalidad_ << endl;
        cout << "Id: " << amigo->getId2() << endl;
    }
}

void Usuario_::mostrarPublicaciones() {
    cout << "Nombre: " << nombre_ << endl;
    for (int i = 0; i < publicaciones_.size(); i++) {
        Publicacion_* publicacion = publicaciones_[i];
        publicacion->mostrarPublicacion();
    }
}

void Usuario_::agregarAmigos(Usuario_* nuevoAmigo) {
    this->amigos_.push_back(nuevoAmigo);
    nuevoAmigo->amigos_.push_back(this);
}

Publicacion_* Usuario_::crearPublicacion(int id2) {
    string fecha, contenido;
    cout << "Ingrese la fecha de hoy: ";
    cin >> fecha;
    cout << "Ingrese el contenido: ";
    cin >> contenido;
    Publicacion_* nueva = new Publicacion_(id2, this, fecha, contenido);
    publicaciones_.push_back(nueva);
    return nueva;
}

Usuario_* Usuario_::getAmigo(int id2) {
    for (int i = 0; i < amigos_.size(); i++) {
        if (id2 == amigos_[i]->getId2()) {
            return amigos_[i];
        }
    }
    return nullptr;
}

void Usuario_::agregarPublicacion(Publicacion_* NuevaPublicacion) {
    this->publicaciones_.push_back(NuevaPublicacion);
}

// Implementación de métodos de la clase Publicacion_
int Publicacion_::getId2() {
    return id_;
}

void Publicacion_::mostrarPublicacion() {
    cout << endl;
    cout << "Fecha: " << fecha_ << endl;
    cout << "Contenido: " << contenido_ << endl;
    cout << "Nombre del Usuario: " << usuario_->nombre_ << endl;
    cout << "Id del usuario: " << usuario_->getId2() << endl;
}

Publicacion_::Publicacion_(int id2, Usuario_* usuario, string fecha, string contenido) {
    this->id_ = id2;
    this->usuario_ = usuario;
    this->fecha_ = fecha;
    this->contenido_ = contenido;
}

// Implementación de métodos de la clase RedSocial_
void RedSocial_::agregarUsuario(Usuario_* usuario) {
    this->usuarios_.push_back(usuario);
}

void RedSocial_::mostrarUsuarios() {
    for (int i = 0; i < usuarios_.size(); i++) {
        usuarios_[i]->mostrar();
        cout << endl;
    }
}

void RedSocial_::agregarPublicacion(Publicacion_* publicacion) {
    this->publicaciones_.push_back(publicacion);
}

void RedSocial_::mostrarPublicaciones() {
    for (int i = 0; i < publicaciones_.size(); i++) {
        publicaciones_[i]->mostrarPublicacion();
    }
}

Usuario_* RedSocial_::getUsuario(int id2) {
    for (int i = 0; i < usuarios_.size(); i++) {
        if (id2 == usuarios_[i]->getId2()) {
            return usuarios_[i];
        }
    }
    return nullptr;
}

RedSocial_::RedSocial_(string nombre) {
    this->nombre_ = nombre;
}

RedSocial_::RedSocial_(string nombre, vector<Usuario_*> usuarios) {
    this->nombre_ = nombre;
    this->usuarios_ = usuarios;
}

RedSocial_::RedSocial_(string nombre, vector<Usuario_*> usuarios, vector<Publicacion_*> publicaciones) {
    this->nombre_ = nombre;
    this->usuarios_ = usuarios;
    this->publicaciones_ = publicaciones;
}

#endif