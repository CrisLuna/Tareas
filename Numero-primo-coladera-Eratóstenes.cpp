#include <iostream>
using namespace std;

int div(int a);

int main()
{
    int a[1000]{0};

    for(int i=1; i<1000; i++)
    {
        a[i]=1;
    }

    for(int i=1; i<1000; i++)
    {
        a[i]=div(i);
    }

    for(int i=0; i<1000; i++)
    {
        if(a[i]==1)
        {
            cout << i <<" ";
        }
    }
    cout << endl;

    return 0;
}

int div(int a)
{
    int b=0;
    if(a==1)
    {
        return 0;
    }
    else
    {
        for(int i=1; i<=a; i++)
        {
            if(a%i==0)
            {
                b++;
            }
        }
        if(b>2)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
