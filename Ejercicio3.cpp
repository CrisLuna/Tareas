#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int opc, num, ind, fact, numcal;
    float cali, sum;

    do
    {
        cout <<"1.-Numero primo" << endl;
        cout <<"2.-Factorial de un numero" << endl;
        cout <<"3.-Promedio de calificaciones" << endl;
        cout <<"0.-Salir" << endl;
        cin >> opc;

        switch(opc)
        {
        case 1:
            {
                ind=0;
                cout <<"Introduzca el numero: ";
                cin >> num;
                for(int i=1; i<=num; i++)
                {
                    if(num%i==0)
                    {
                        ind++;
                    }
                }
                if(ind==2)
                    {
                        cout <<"El numero es primo" << endl;
                    }
                    else
                    {
                        cout <<"El numero no es primo" << endl;
                    }
                system("pause");
                system("cls");
                break;
            }
        case 2:
            {
                fact=1;
                cout <<"Introduzca el numero: ";
                cin >> num;
                for(int i=1; i<=num; i++)
                {
                    fact*=i;
                }
                cout <<"Factorial de " << num <<" = " << fact << endl;
                system("pause");
                system("cls");
                break;
            }
        case 3:
            {
                numcal=1;
                sum=0;
                cout <<"Escriba una serie de calificaciones a promediar, cuando termine introduzca -1" << endl;
                do
                {
                    cout <<"Introduzca la calificacion " << numcal <<": ";
                    cin >> cali;
                    if(cali>0)
                    {
                        sum+=cali;
                        numcal++;
                    }
                }while(cali!=-1);
                cout <<"El promedio de las calificaciones es: " << sum/(numcal-1) << endl;
                system("pause");
                system("cls");
                break;
            }
        }
    }while(opc!=0);
    return 0;
}
