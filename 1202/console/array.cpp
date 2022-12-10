#include <iostream>
using namespace std;
int n, stack[0], queue[0];
void sizer()
{
    int size;
    cin >> size;
    int stack[size];
    int queue[size];
}
class stacking
{
private:
    int top = -1;

public:
    void push(int x)
    {
        top++;
        stack[top] = x;
    }
    int pop()
    {
        return stack[top--];
    }
};
class queueing
{
private:
    int front = -1, rear = -1;

public:
    void enqueue(int y)
    {
        if (rear == n - 1)
        {
            printf("Queue is full.\n");
        }
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            queue[rear] = y;
        }
    }
    void dequeue()
    {
        int x, y = 0;
        if (front == -1)
            printf("Queue is empty..\n");
        else
        {
            if (front >= rear)
            {
                y = queue[front];
                front = -1;
                rear = -1;
            }
            else
            {
                x = queue[front];
                front++;
            }
        }
    }
};