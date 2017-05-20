#include <iostream>
#include <random>
#include <vector>

using namespace std;

/*Даны две непустые очереди. Перемещать элементы из начала первой очереди в конец второй, пока значение первого элемента первой очереди
* не станет четным. Если в первой очереди нет четных элементов, то полностью переместить элементы первой очереди в конец второй*/

template <typename T> // создаем шаблон класса
class Queue// класс очередь
{
private:
    T *QueuePtr; // указатель на очередь
    int size;  // максимальное количество элементов в очереди
    int start;       // начало очереди
    int end;         // конец очереди
    int length; // текущее число элементов в очереди
public:

    Queue(int size) //конструктор по умолчанию
    {
        QueuePtr = new T[size];
        for (int i = 0; i < size; i++)
        {
            int n = rand() % 2;
            if (n == 1)
            {
                QueuePtr[i] = rand() % 10;
            }
            else
            {
                QueuePtr[i] = NULL;
            }
        }

    }

    ~Queue() //деструктор
    {
        delete[] QueuePtr;
    }

    void enqueue(T value) //функция добавления элемента в очередь
    {
        QueuePtr[end] = value;
        end = (end + 1) % size;
        length++;
    }

    void enqueueRandom() //функция добавления элемента в очередь
    {
        QueuePtr[end] = rand()%10;
        end = (end + 1) % size;
        length++;
    }

    T dequeue() //функция удаления элемента в очереди
    {
        T n = NULL;
        if (QueuePtr[start] != NULL)
        {
            n = QueuePtr[start];
            QueuePtr[start] = NULL;
            start = (start - 1 + size) % size;
            length--;
        }
        return n;
    }

    void PrintQueue(int size)
    {
        cout << "Queue: ";
        /*if ((end == 0) && (begin == 0))
        {
            cout << "empty\n";
        }
        else*/
        {
            for (int i = 0; i < size; i++)
            {
                if (QueuePtr[i] == NULL)
                {
                    cout << "X ";
                }
                else
                {
                    cout << QueuePtr[i] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    int size = 14;
    int start = 0;
    int end = size - 1;
    Queue<int> myQueue1(size);
    Queue<int> myQueue2(size);
    //myQueue.enqueue();
    myQueue1.PrintQueue(size);
    myQueue2.PrintQueue(size);
    //Queue<int> n = myQueue1.dequeue();
    //cout<<n;
    return 0;
}
