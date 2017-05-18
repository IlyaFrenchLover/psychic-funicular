#include <iostream>
#include <random>
#include <vector>

using namespace std;

/*Даны две непустые очереди. Перемещать элементы из начала первой очереди в конец второй, пока значение первого элемента первой очереди
 * не станет четным. Если в первой очереди нет четных элементов, то полностью переместить элементы первой очереди в конец второй*/

template <typename T>
class Queue// класс очередь
{
private:
    T *QueuePtr; // указатель на очереди
    const int size;  // максимальное количество элементов в очереди
    int start;       // начало очереди
    int end;         // конец очереди
public:
    Queue(int sizeQueue = 10) //конструктор
{

}

    ~Queue() //деструктор
{
  delete [] queuePtr;
};

private:
void enqueue() //функция добавления элемента в очередь
{

}

void dequeue() //функция удаления элемента в очереди
{

}
};

int main(int argc, char *argv[])
{


    return 0;
}
