#ifndef Episodio_h
#define Episodio_h

#include<iostream>
#include<string>
#include "Video.h"
using namespace std;

class Episodio : public Video{

    public:
        Episodio();
        Episodio(string tit, string gen, string ser, int numEp, int numTemp, int id, int dur, int cal);
        string getSerie() {return serie;};
        int getNumeroEpisodio() {return numeroEpisodio;}; 
        int getNumeroTemporada() {return numeroTemporada;};
        void setSerie(string ser) {serie = ser;};
        void setNumeroEpisodio(int numEp) {numeroEpisodio = numEp;};
        void setNumeroTemporada(int numTemp) {numeroTemporada = numTemp;};
        void muestra();
    private:
        string serie;
        int numeroEpisodio, numeroTemporada;
};

Episodio :: Episodio() : Video(){
    serie="N/A";
    numeroEpisodio=1;
    numeroTemporada=1;
}
Episodio :: Episodio(string tit, string gen, string ser, int numEp, int numTemp, int id, int dur, int cal) : Video(tit, gen, id, dur, cal){
    serie=ser;
    numeroEpisodio=numEp;
    numeroTemporada=numTemp;
}
void Episodio::muestra(){
    cout << "Titulo: " << titulo << endl;
    cout << "| Temporada " << numeroTemporada << " | Episodio " << numeroEpisodio << " |"<< endl;
    cout << "Genero: " << genero << endl;
    cout << "Duración : " << duracion << " min"<< endl;
    cout << "Ïd de Episodio: "<< idVideo << endl;
    cout << "Calificación: " << calificacion << " Estrellas" << endl;
    cout << endl;
}

#endif /* Episodio_h */