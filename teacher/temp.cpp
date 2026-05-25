#include <bits/stdc++.h>

class Darray {
    public:
        Darray() {
            capacity = 100;
            size = 0;
            data = new int[capacity];
        };
        ~Darray();
        int& operator[](int);
        void pushback(int x);
        void popback(void);
        void clear(void);
        int length(void);
    private:
        void resize(void); // double the capacity
        int *data;
        int capacity;
        int size;
};

int& Darray :: operator[](int index) {
    
    return data[index];

}

void Darray :: pushback(int x){
    if (size == capacity) {
        resize();
    }
    data[size] = x;
    size++;
}
void Darray :: popback(void){
    if(size > 0)
        size -= 1;
}
void Darray :: clear(void){
    size = 0;
}
int  Darray ::length(void){
    return size;
}

void  Darray ::resize(void){
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}
Darray :: ~Darray(){
    delete[] data;
}


int main(void){
    Darray a;
    Darray b = a;
    b.pushback(3);

    printf("a.size = %d, a[0] = %d\n", a.length(), a[0]);
    printf("b.size = %d, b[0] = %d\n", b.length(), b[0]);

    Darray c;
    Darray& d = c;
    d.pushback(3);

    printf("c.size = %d, c[0] = %d\n", c.length(), c[0]);
    printf("d.size = %d, d[0] = %d\n", d.length(), d[0]);
}