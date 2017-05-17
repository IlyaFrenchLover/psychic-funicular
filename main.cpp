#include <iostream>
#include <random>
#include <vector>

using namespace std;

/*Даны две непустые очереди. Перемещать элементы из начала первой очереди в конец второй, пока значение первого элемента первой очереди
 * не станет четным. Если в первой очереди нет четных элементов, то полностью переместить элементы первой очереди в конец второй*/

int main(int argc, char *argv[])
{
//std:<int>vector MyVector[] = { , };
    //const int n = 6;
    int m1[12];
    int m2[12];
    int start = 6;
    int end = 0;
    //vector<int> MyVector1(6);
    //vector<int> MyVector2(6);

    for(int i = 0; i<start; i++)
    {
        m1[i] = rand()%10;
        cout<<m1[i]<<" ";
    }

    cout<<endl;

    for(int i = 0; i<start; i++)
    {
        m2[i] = rand()%10;
        cout<<m2[i]<<" ";
    }

    cout<<endl;
    cout<<endl;

    for(int i = 0; i<start; i++)
    {
        if(m1[i] % 2 != 0)
        {
            start = start + i;
            m2[start] = m1[i];
            end = end +1;
        }
        else break;
    }

    for(int i = 0; i<=start; i++)
    {
        cout<<m2[i]<<" ";
    }

    cout<<endl;

    for(int i = end; i<6; i++)
    {
        cout<<m1[i]<<" ";
    }

    cout<<endl;

    return 0;
}
