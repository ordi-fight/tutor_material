#include <bits/stdc++.h>
#include "13523.h"

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

void INT::operator+=(INT& num){
    int overTen = 0;
    int maxLen = std::max(data.length(), num.data.length());
    
    for(int i = 0; i < maxLen || overTen; i++){
        int a = (i < data.length()) ? data[i] : 0;
        int b = (i < num.data.length()) ? num.data[i] : 0;
        int sum = a + b + overTen;
        
        if(i < data.length()){
            data[i] = sum % 10;
        } else {
            data.pushback(sum % 10);
        }
        overTen = sum / 10;
    }
}

std::istream &operator>>(std::istream & os, INT & num){
    Darray& arr = num.data;
    arr.clear();
    std::string input;
    os >> input;
    for(int i = input.size() - 1;i >= 0;i--){
        arr.pushback(input[i] - '0');
    }
    return os;
}

std::ostream &operator<<(std::ostream & os, INT & num){
    Darray& arr = num.data;
    for(int i = arr.length() - 1;i >= 0;i--){
        os << arr[i];
    }
    return os;
}
