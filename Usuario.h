#ifndef Usuario_h
#define Usuario_h

#include <iostream>
#include "Video.h"
using namespace std;

class Usuario{
    public:
        Usuario();
        Usuario(string nm,string acc, int cntVid);
        int getUnIdMisVideos(int indice);
        Usuario operator+=(int id);
        void setaccount(string acc) { account = acc;};
        string getaccount(){ return account;};
        void setname(string nm) { name = nm;};
        string getname(){ return name;};
        int getContadorVideos() { return contadorVideos;};
    private:
        int misVideos[20];
        int contadorVideos;
        string name;
        string account;

};

Usuario::Usuario(){
    name = "N/A";
    account = "N/A";
    contadorVideos = 20;
    for(int i = 0; i <contadorVideos; i++){ 
        misVideos[i] = 0; 
    }
}

int Usuario::getUnIdMisVideos(int indice){
    for(int i = 0; i < 20; i++){
        if (misVideos[indice] == misVideos[i]){
            return misVideos[i];
        }
    }
}

Usuario Usuario::operator+=(int id){
    
    bool verificacion = false;
    for(int i = 0; i < 20; i++){
        if (misVideos[i] == id || contadorVideos >= 20)
        {
            verificacion = true; 
        }
    }
    if(verificacion == false){
        misVideos[contadorVideos] = id;
        cout << misVideos[contadorVideos];
        contadorVideos++;
    }
}
#endif /* Usuario_h */