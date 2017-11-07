#include <iostream>
#include <cstdlib>
using namespace std;

void comandos();
void tortugaarriba(char matriz[][20], int &x, int y, bool pluma, int avance);
void tortugaderecha(char matriz[][20], int x, int &y, bool pluma, int avance);
void tortugaizquierda(char matriz[][20], int x, int &y, bool pluma, int avance);
void tortugaabajo(char matriz[][20], int &x, int y, bool pluma, int avance);

int main(){

    char matriz[20][20];
    int op=0;

    //coordenadas: (x=renglones, y=columnas)
    int x=0, y=0;
    //direccion: (0=derecha, 1=abajo, 2=izquierda, 3=arriba)
    int dir=0;
    //posicion de la pluma: (0=arriba, 1=abajo)
    bool pluma=0;
    //cantidad de avance de casillas:
    int avance=0;

    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            matriz[i][j]='°';
        }
    }

    do{
        system("cls");
        comandos();
        cin >> op;

        switch(op){
        case 1:
            {
                pluma=0;
                cout <<"Pluma arriba" << endl;
                system("pause");
                break;
            }
        case 2:
            {
                pluma=1;
                cout <<"Pluma abajo" << endl;
                system("pause");
                break;
            }
        case 3:
            {
                if(dir==3){
                    dir=0;
                }
                else{
                    dir++;
                }
                cout <<"Giro derecha" << endl;
                system("pause");
                break;
            }
        case 4:
            {
                if(dir==0){
                    dir=3;
                }
                else{
                    dir--;
                }
                cout <<"Giro izquierda" << endl;
                system("pause");
                break;
            }
        case 5:
            {
                cout <<"Escribe cuanto deseas avanzar: ";
                cin >> avance;
                if(dir==0){
                    tortugaderecha(matriz, x, y, pluma, avance);
                }else{
                    if(dir==1){
                        tortugaabajo(matriz, x, y, pluma, avance);
                    }else{
                        if(dir==2){
                            tortugaizquierda(matriz, x, y, pluma, avance);
                        }else{
                            tortugaarriba(matriz, x, y, pluma, avance);
                        }
                    }
                }
                cout <<"Avanzando" << endl;
                system("pause");
                break;
            }
        case 6:
            {
                for(int i=0; i<20; i++){
                    for(int j=0; j<20; j++){
                        cout << matriz[i][j] <<" ";
                    }
                    cout << endl;
                }
                cout << endl;
                system("pause");
                break;
            }
        }
    }while(op!=0);

}

void comandos(){

    cout <<"1.- Pluma hacia arriba" << endl;
    cout <<"2.- Pluma hacia abajo" << endl;
    cout <<"3.- Gira a la derecha" << endl;
    cout <<"4.- Gira a la izquierda" << endl;
    cout <<"5.- Avanzar" << endl;
    cout <<"6.- Imprime matriz" << endl;
    cout <<"0.- Fin de datos" << endl;
}

//La distancia real positiva o negativa se aplicará en los casos en que el avance supere la proporcion del tablero en ambas coordenadas y en las 4 direcciones.

void tortugaarriba(char matriz[][20], int &x, int y, bool pluma, int avance){
    int disrealnegx=x-avance;
    if(disrealnegx<0){
        disrealnegx=0;
    }
    for(int i=x; i>=disrealnegx; i--){
        if(pluma==1){
            matriz[i][y]='*';
        }
    }
    x=disrealnegx;
}

void tortugaderecha(char matriz[][20], int x, int &y, bool pluma, int avance){
    int disrealposy=y+avance;
    if(disrealposy>19){
        disrealposy=19;
    }
    for(int i=y; i<=disrealposy; i++){
        if(pluma==1){
            matriz[x][i]='*';
        }
    }
    y=disrealposy;
}

void tortugaizquierda(char matriz[][20], int x, int &y, bool pluma, int avance){
    int disrealnegy=y-avance;
    if(disrealnegy<0){
        disrealnegy=0;
    }
    for(int i=y; i>=disrealnegy; i--){
        if(pluma==1){
            matriz[x][i]='*';
        }
    }
    y=disrealnegy;
}

void tortugaabajo(char matriz[][20], int &x, int y, bool pluma, int avance){
    int disrealposx=x+avance;
    if(disrealposx>19){
        disrealposx=19;
    }
    for(int i=x; i<=disrealposx; i++){
        if(pluma==1){
            matriz[i][y]='*';
        }
    }
    x=disrealposx;
}
