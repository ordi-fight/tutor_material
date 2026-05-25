#include "13522.h"

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



