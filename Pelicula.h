#ifndef Pelicula_h
#define Pelicula_h

#include<iostream>
#include<string>
#include "Video.h"
using namespace std;

class Pelicula : public Video{

    public:
        Pelicula();
        Pelicula(string tit, string gen, int id, int dur, int cal);
        void muestra();
};

Pelicula :: Pelicula() : Video(){
    idVideo=111; 
    titulo="N/A"; 
    genero="N/A";
    duracion=1; 
    calificacion=5;
}
Pelicula :: Pelicula(string tit, string gen, int id, int dur, int cal) : Video(tit, gen, id, dur, cal){
    idVideo=id; 
    titulo=tit; 
    genero=gen; 
    duracion=dur; 
    calificacion=cal;
}
void Pelicula::muestra(){
    cout << "Titulo: " << titulo << endl;
    cout << "Genero: " << genero << endl;
    cout << "Ïd de Película: "<< idVideo << endl;
    cout << "Duración : " << duracion << endl;
    cout << "Calificación: " << calificacion * '*' << endl;

}

#endif /* Pelicula_h */