#include<iostream>
#include<string>
#include<fstream>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Usuario.h"
using namespace std;
int main(){
    Video *arrVideos[50];
    Usuario user1;
    string nombreAr;
    char opcion,tV,TipoV[50];
    string acc, nm,tit,gen, ser,genes,nomtemp,acctemp;
    int contV, misV[50],id, dur, cal,ep,temp,cc,cales,idint;
    cout << "Ingresar el nombre del Archivo: "<<endl;
    cin >> nombreAr;
    ifstream ArchivoVideos(nombreAr);
    while(ArchivoVideos >> tV){
            if(tV == 'e'){
                ArchivoVideos >> id >> tit >> gen >> dur >> cal >> ser >> ep >> temp;
                arrVideos[cc] = new Episodio(tit, gen,ser,ep,temp,id,dur,cal);
                TipoV[cc] = 'e';
                cc++;
            } else if(tV=='p'){
                ArchivoVideos >> id >> tit >> gen >> dur >> cal;
                arrVideos[cc] = new Pelicula(tit, gen,id,dur,cal);
                TipoV[cc] = 'p';
                cc++;
            }
        }
        contV = cc;
    do {
        cout << "Menu de opciones " << endl;
        cout << endl;
        cout << "a) Consultar la lista de videos disponibles " << endl;
        cout << "b) Consultar la lista de Videos con cierta calificación " << endl;
        cout << "c) Consultar la lista de Videos por género " << endl;
        cout << "d) Ver datos del usuario " << endl;
        cout << "e) Modificar el perfil del usuario " << endl;
        cout << "f) Agregar video a la lista del usuario " << endl;
        cout << "g) terminar " << endl;
        cout << "opcion ->";
        cin >> opcion;
        
        switch (opcion) {
            case 'a': {
                for(int i=0; i <contV; i++){
                    if (TipoV[i]=='e')
                    {
                        cout << "Episodio "<<endl;
                        arrVideos[i]->muestra();
                    } else {
                        cout << "Pelicula "<<endl;
                        arrVideos[i]->muestra();
                    }
                }
                break;
            }
        
            case 'b': {
                cin >> cales;
                if (cales < 0 || cales > 5)
                {
                    cout << "Error Ingresar una Calificación Valida!" << endl;
                    cout << endl;
                } else {
                    for(int i=0; i <contV; i++){
                        if (arrVideos[i]->getCalificacion()==cales){
                            arrVideos[i]->muestra();
                        }
                    }
                }    
                break;
            }
                
            case 'c':  {
                cin >> genes;
                for(int i=0; i <contV; i++){
                    if (arrVideos[i]->getGenero()==genes){
                        arrVideos[i]->muestra();
                    }
                }                   
                break;
            }

            case 'd': {
                cout << "Nombre :" <<user1.getname()<< endl;
                cout << "Usuario: "<<user1.getaccount() << endl;
                cout << endl;
                for(int i=0; i<contV;i++){
                    for(int v=0; v<user1.getContadorVideos();v++){
                        if(arrVideos[i]->getIdVideo()==user1.getUnIdMisVideos(v)){
                            arrVideos[i]->muestra();
                        }
                    }
                }
                break;
            }
                
            case 'e':  {
                cin >> nomtemp;
                cin >> acctemp;
                if(nomtemp == user1.getname() && acctemp == user1.getaccount()){
                    string nombren,accn;
                    cout << "Ingrese El Nuevo Nombre :"<<endl;
                    cin >> nombren;
                    cout << endl;
                    cout << "Ingrese El Nuevo Usuario :"<< endl;
                    cin >> accn;
                    cout << endl;
                    user1.setname(nombren);
                    user1.setaccount(accn);
                } else{
                    cout << "Error Esas Credenciales no se encuentran en nuestro Sistema...";
                    cout << endl;
                }                
                break;
            }

            case 'f':  {
                bool uwu=false;
                while(uwu==false){
                cin >> idint;
                    for (int i=0;i<contV;i++){
                        if(arrVideos[i]->getIdVideo()==idint){
                            user1 += idint;
                            uwu = true;
                        }
                    }   
                }              
                break;
            }
        }
        
    } while (opcion != 'g');
    return 0;
}