#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>

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

int main() {
    Usuario_ usuario1(1, "Llados", 32); //usuario1 es un objeto de la clase Usuario, que representan los usuarios de la red social,
                                          // se crean utilizando el constructor de usuarios para llenar toda la informacion del usuario 
                                          //como su id, nombre etc.

    Usuario_ usuario2(2, "Mark Zuckemberg", 38);
    Usuario_ usuario3(3, "Warren Buffet", 73, "Canadiense");

    //post1 es un objeto de la clase Publicacion, que representan las publicaciones de los usuarios en la red social, y a este se le da 
    //el puntero hacia el id del usuario que realizo la publicacion y la fecha y el contenido de la publicacion.


    Publicacion_ post1(1, &usuario1, "09/abr/2024", "Maquinas estoy en el porfirios, volteo a la derecha panza volteo a la izquierda mileurista, aqui no puedo estar, eso esta claro.");
    Publicacion_ post2(2, &usuario2, "9/abr/2024", "Ahora invierte en Meta y te estare triplicando tu dinero, ven las oficinas y estaré explicandote");
    Publicacion_ post3(3, &usuario3, "9/abr/2024", "Este año habrá una crisis económica, unanse a la conferencia que daré mañana a las 6 pm");
    
    //al usuario 1 se le agrega el post1
    //usuario 2 post2
    //usuario 3 post3

    usuario1.agregarPublicacion(&post1);
    usuario2.agregarPublicacion(&post2);
    usuario3.agregarPublicacion(&post3);

//hacemos vector llamado usuarios que apuntan a los apuntadores de los usuarioa
//hacemos vector llamado publicaciones que apunta a los apuntadores de las publicaciones 

//basicamente de esta manera tenemos todos los apuntadores de los usuarios en un vector 

//y tambien tenemos todos los apuntadores de las publicaciones en un vector 

    vector<Usuario_*> usuarios;
    vector<Publicacion_*> publicaciones;

//y pues ya aqui le pasamos los apuntadores del usuario o publicaciones a vector 

    usuarios.push_back(&usuario1);
    usuarios.push_back(&usuario2);
    usuarios.push_back(&usuario3);

    publicaciones.push_back(&post1);
    publicaciones.push_back(&post2);
    publicaciones.push_back(&post3);

   


    RedSocial_ pruebaRed("NetWorking", usuarios, publicaciones);
    int option, numeroUsuarios = 4, numerosPublicaciones = 4;
    do {
        option = 0;
        cout << ".menu" << endl << endl;
        cout << "0- Salir" << endl;
        cout << "1- Lista de empresarios" << endl;
        cout << "2- Lista de oportunidades potenciales" << endl;
        cout << "3- investigar empresario" << endl;
        cout << "4- Agregar empresario" << endl;
        cin >> option;
        switch (option) {
            case 0: {
                break;
            }
            case 1: {
                pruebaRed.mostrarUsuarios();
                break;
            }
            case 2: {
                pruebaRed.mostrarPublicaciones();
                break;
            }
            case 3: {
                int idUsuario, elMenu = 1, idUsuarioAmigo;
                bool forAmigo;
                Usuario_* usuarioExplorado;
                Usuario_* usuarioExploradoNewAmigo;
                cout << "Ingresa un id para encontrar a alguien" << endl;
                cin >> idUsuario;
            exploreAmigo:
                forAmigo = false;
                usuarioExplorado = pruebaRed.getUsuario(idUsuario);
                if (usuarioExplorado != nullptr) {
                Elmenu:
                    while (elMenu != 0) {
                        cout << "menu: " << pruebaRed.getUsuario(idUsuario)->nombre_ << endl << endl;
                        if (elMenu == 1) {
                            cout << endl;
                            cout << "info del usuario: " << endl;
                            cout << "nombre: " << pruebaRed.getUsuario(idUsuario)->nombre_ << endl;
                            cout << "edad: " << pruebaRed.getUsuario(idUsuario)->edad_ << endl;
                            cout << "nacionalidad: " << pruebaRed.getUsuario(idUsuario)->nacionalidad_ << endl;
                            cout << endl << endl;
                        }
                        cout << "0- Salir" << endl << "1- Ver info del empresario " << endl << "2- Ver a mis contactos empresarios" << endl << "3- Ver publicaciones de empresarios" << endl << "4- Crear publicacion empresarial" << endl << "5. ver empresario" << endl << "6. Agregar nuevo empresario" << endl;
                        cin >> elMenu;
                        if (elMenu == 1) {
                             cout << "Información del usuario: " << endl;
                             cout << "Nombre: " << pruebaRed.getUsuario(idUsuario)->nombre_ << endl;
                             cout << "Edad: " << pruebaRed.getUsuario(idUsuario)->edad_ << endl;
                             cout << "Nacionalidad: " << pruebaRed.getUsuario(idUsuario)->nacionalidad_ << endl;
                             cout << "ID: " << pruebaRed.getUsuario(idUsuario)->getId2() << endl;
                        }
                        if (elMenu == 2) {
                            cout << "Amigos: " << endl;
                            pruebaRed.getUsuario(idUsuario)->mostrarAmigos();
                            cout << endl;
                        }
                        if (elMenu == 3) {
                            cout << ".publicaciones del empresario" << endl;
                            pruebaRed.getUsuario(idUsuario)->mostrarPublicaciones();
                            cout << endl;
                            goto Elmenu;
                        }
                        if (elMenu == 4) {
                            pruebaRed.agregarPublicacion(pruebaRed.getUsuario(idUsuario)->crearPublicacion(numerosPublicaciones));
                            cout << " My NetWork, your NetWork" << endl;
                            goto exploreAmigo;
                        }
                        if (elMenu == 5) {
                            cout << "Ingresa el id para encontrar al empresario" << endl << endl << "--> ";
                            cin >> idUsuarioAmigo;
                            for (int i = 0; i < pruebaRed.getUsuario(idUsuario)->amigos_.size(); i++) {
                                if (idUsuarioAmigo == pruebaRed.getUsuario(idUsuario)->amigos_[i]->getId2()) {
                                    forAmigo = true;
                                }
                            }
                            if (forAmigo) {
                                goto exploreAmigo;
                            } else {
                                cout << "Aun no lo agregas a tus networking de empresario" << endl;
                            }
                        }
                        if (elMenu == 6) {
                            pruebaRed.mostrarUsuarios();
                            cin >> idUsuarioAmigo;
                            if (idUsuarioAmigo != idUsuario) {
                                usuarioExploradoNewAmigo = pruebaRed.getUsuario(idUsuarioAmigo);
                                pruebaRed.getUsuario(idUsuario)->agregarAmigos(usuarioExploradoNewAmigo);
                            } else {
                                cout << "Error" << endl;
                            }
                        }
                    }
                } else {
                    cout << "No esta dado de alta en Networking ese empresario" << endl;
                }
                break;
            }
            case 4: {
                string name, nationality;
                int age;
                cout << "Ingresa el nombre del empresario" << endl;
                cin >> name;
                cout << "Ingresa la edad del empresario" << endl;
                cin >> age;
                cout << "Ingrese la nacionalidad del empresario" << endl;
                cin >> nationality;
                Usuario_ newusuario(numeroUsuarios, name, age, nationality); 
        /*numerodeUsuarios esta definido arriba en 4 debido a los 3 usuarios default aqui se añade como el id y 
        luego se incrementa para la siguiente vez que creas un usuario*/
                numeroUsuarios++;
                pruebaRed.agregarUsuario(&newusuario);
                break;
            }
            default: {
                cout << "Inserte una opcion valida" << endl << endl;
                break;
            }
        }
    } while (option != 0);
    
    return 0;
}
