#include "net.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

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




    RedSocial_ pruebaRed("NetWorking", usuarios, publicaciones); // objeto de la clase RedSocial el cual se llama pruebaRed al
                                                                 //cual se le da la infrmacion del nombre de la red y los vectores de
                                                                 //los apuntadores de usuarios y publicaciones.

    int option, numeroUsuarios = 4, numerosPublicaciones = 4; //inicializa la variable option que es de tipo entero que guarda la
                                                              //opcion del usuario en el menu
                                                              //inicializa numeroUsuario y numerosPublicaciones que tambien son variables de tipo entero y lo que guardadn es el valor de los usuarios y las publicaciones porsi se agrega algunos o algunas nuevas, las mande al lugar que les corresponden.

    do {
        option = 0;
        cout << "NETWORKING - LA RED EMPRESARIAL MAS GRANDE DEL MUNDO" << endl << endl;
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
                cout << "Ingresa un id para encontrar a empresario" << endl;
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
                            cout << "Ingresa el id para encontrar al empresario" << endl;
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
                cout << "opcion invalida" << endl << endl;
                break;
            }
        }
    } while (option != 0);

    return 0;
}