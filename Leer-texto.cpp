#include <iostream>
#include <string.h>
using namespace std;

int buscarprimerletra(char texto[], char palabra[]);
int compararpalabra(char texto[], char palabra[]);
int compararletras(char texto[], char palabra[], int tamano, int posicion);

int main(){

    char texto[200]="Mi mision es matar el tiempo y la de este matarme a su vez. Se esta bien entre asesinos.";
    char palabra[20];
    int posicion=0;
    //int coincidencias=0;

    cout << texto << endl << endl;
    cout <<"Escribe la palabra que deseas buscar en el texto: ";
    cin >> palabra;
    cout << endl;

    //coincidencias=buscarprimerletra(texto, palabra);
    posicion=compararpalabra(texto, palabra);
    if(posicion>0){
        cout <<"La palabra se encontro en la posicion " << posicion+1 <<" del texto." << endl;
    }else{
        cout <<"No se encontro la palabra en el texto" << endl;
    }
    //cout << coincidencias << endl;

    return 0;
}

int buscarprimerletra(char texto[], char palabra[]){
    int contador=0;
    for(int i=0; texto[i]; i++){
        if(texto[i]==palabra[0]){
            contador++;
        }
    }
    return contador;
}

int compararpalabra(char texto[], char palabra[]){
    int tamano=strlen(palabra);
    int cont=0;
    int posicion=0, lugar=0;
    for(int i=0; texto[i]; i++){
        if(texto[i]==palabra[0]){
            posicion=i;
            cont=compararletras(texto, palabra, tamano, posicion);
            if(cont==tamano){
                lugar=posicion;
                break;
            }
        }
    }
    return lugar;
}

int compararletras(char texto[], char palabra[], int tamano, int posicion){
    int cont=0;
    for(int i=posicion, j=0; j<tamano; i++, j++){
        if(texto[i]==palabra[j]){
            cont++;
        }
    }
    if(texto[posicion+tamano]==32 || texto[posicion+tamano]==44 || texto[posicion+tamano]==46){
        return cont;
    }else{
        return 0;
    }
}
