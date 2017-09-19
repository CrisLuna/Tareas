#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int dado();
int menu();

int main()
{
    srand(time(NULL));
    int op, lanz, lanz2, reg1[6]{0}, reg2[11]{0};

    do
    {
        op=menu();

        switch(op)
        {
        case 1:
            {
                lanz=0;
                for(int z=0; z<6; z++)
                {
                    reg1[z]=0;
                }

                for(int i=1; i<=100; i++)
                {
                    lanz=dado();
                    for(int j=1; j<=6; j++)
                    {
                        if(j==lanz)
                        {
                            reg1[j-1]++;
                        }
                    }
                }

                for(int i=0; i<6; i++)
                {
                    cout <<"Cara " << i+1 <<": " << reg1[i] <<" ";
                    for(int j=1; j<=reg1[i]; j++)
                    {
                        cout <<"* ";
                    }
                    cout << endl;
                }
                system("pause");
                system("cls");
                break;
            }
        case 2:
            {
                lanz=0;
                lanz2=0;
                for(int z=0; z<12; z++)
                {
                    reg2[z]=0;
                }

                for(int i=1; i<=100; i++)
                {
                    lanz=dado();
                    lanz2=dado();
                    for(int j=1; j<=6; j++)
                    {
                        if(j==lanz)
                        {
                            for(int z=1; z<=6; z++)
                            {
                                if(z==lanz2)
                                {
                                    reg2[j+z-2]++;
                                }
                            }
                        }
                    }
                }

                for(int i=1; i<=11; i++)
                {
                    cout <<"Cuando ambos sumaron " << i+1 <<": " << reg2[i-1] <<" ";
                    for(int z=1; z<=reg2[i-1]; z++)
                    {
                        cout <<"* ";
                    }
                    cout << endl;
                }
                system("pause");
                system("cls");
                break;
            }
        }
    }while(op!=0);

    return 0;
}

int dado()
{
    int a=1+rand()%6;
    return a;
}

int menu()
{
    int a;
    cout <<"MENU" << endl;
    cout <<"1.- Un lanzamiento" << endl;
    cout <<"2.- Dos lanzamientos" << endl;
    cout <<"0.- Salir" << endl;
    cin >> a;
    cout << endl;
    return a;
}
