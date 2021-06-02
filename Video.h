#ifndef Video_h
#define Video_h

#include<iostream>
#include<string>
using namespace std;

class Video{

    public:
        Video() {idVideo=111; titulo="N/A"; genero="N/A"; duracion=1; calificacion=5;};
        Video(string tit, string gen, int id, int dur, int cal) {idVideo=id; titulo=tit; genero=gen; duracion=dur; calificacion=cal;};
        string getTitulo() {return titulo;};
        string getGenero() {return genero;};
        int getIdVideo() {return idVideo;};
        int getDuracion() {return duracion;};
        int getCalificacion() {return calificacion;};
        void setTitulo(string tit) {titulo = tit;};
        void setGenero(string gen) {genero = gen;};
        void setIdVideo(int id) {idVideo = id;};
        void setDuracion(int dur) {duracion = dur;};
        void setCalificacion(int cal) {calificacion=cal;};
        virtual void muestra()=0;

    protected:
        int idVideo, duracion, calificacion;
        string titulo, genero;
};

#endif /* Video_h */