#ifndef Video_h
#define Video_h

#include<iostream>
#include<string>
using namespace std;

class Video{

    public:
        Video() {};
        virtual void muestra()=0;

    protected:
        int idVideo, duracion, calificacion;
        string titulo, genero;
        

};

#endif /* Video_h */