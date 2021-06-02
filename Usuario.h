#ifndef Usuario_h
#define Usuario_h

#include <iostream>
#include "Video.h"
using namespace std;

class Usuario{
    private:
        int misVideos[20];
        int contadorVideos;
        string name;
        string account;

    public:
        Usuario();
        int getUnIdMisVideos(int indice);
        int operator+(int id);
        void setaccount(string acc) { account = acc;};
        string getaccount(){ return account;};
        void setname(string nm) { name = nm;};
        string getname(){ return name;};
        int getContadorVideos() { return contadorVideos;};
};

Usuario::Usuario(){
    name = "default";
    account = "default";
    contadorVideos = 0;
    for(int i = 0; i < 20; i++){ misVideos[i] = 0; }
}

int Usuario::getUnIdMisVideos(int indice){
    for(int i = 0; i < 20; i++){
        if (indice == misVideos[i]){
            return misVideos[i];
        }
    }
}

int Usuario::operator+(int id){
    bool verificacion = false;
    for(int i = 0; i < 20; i++){
        if (misVideos[i] == id || contadorVideos >= 20)
        {
            verificacion = true; 
        }
    }
    if(verificacion == false){
        misVideos[contadorVideos] = id;
        contadorVideos++;
    }
    verificacion = false; 
}
#endif /* Usuario_h */