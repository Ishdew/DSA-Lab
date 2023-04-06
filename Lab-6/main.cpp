#include <iostream>
using namespace std;

#include <chrono>
using namespace std::chrono;



class Stack {
    private:
        int top;        
        int *arr;
        int max_size;
    
    public:
        Stack(int size) {
            top = -1;
            max_size = size;
            arr = new int[max_size];
        }
        
        bool isEmpty() {
            return (top == -1);
        }
        
        bool isFull() {
            return (top == max_size - 1);
        }
        
        void push(int item) {
            if (isFull()) {
                cout << "Stack overflow!" << endl;
                return;
            }
            
            arr[++top] = item;
        }
        
        int pop() {
            if (isEmpty()) {
                cout << "Stack underflow!" << endl;
                return -1;
            }
            
            return arr[top--];
        }
        
        int StackTop() {
            if (isEmpty()) {
                cout << "Stack underflow!" << endl;
                return -1;
            }
            
            return arr[top];
        }


        void display() {
            if (isEmpty()) {
                cout << "Stack is empty!" << endl;
                return;
            }
            
            cout << "Stack contents: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {

    auto start = high_resolution_clock::now();
    int size=100;

    Stack s(size);


    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display(); 

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "time taken in micro seconds for Array Stack "<<duration.count() << endl;

    
    
    return 0;
}