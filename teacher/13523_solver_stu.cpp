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

void INT :: operator+=(INT& right){

    int ll = data.length() - 1,rl =  right.data.length() - 1,  b = 0;
    if ( ll == rl && rl == -1){
        return;
    }
    int buffer[std::max(data.length(), right.data.length()) + 1];
    if (data.length() <= right.data.length()) {
        while(rl >= 0){
            
            if (ll < 0){
                buffer[rl + 1] = right.data[rl] + b;
                if (buffer[rl + 1] >= 10) {
                    buffer[rl + 1] -= 10;
                    b = 1;}
                else b = 0;
            }
            else{
                buffer[rl + 1] = data[ll] + right.data[rl] + b;
                if (buffer[rl + 1] >= 10) {
                    buffer[rl + 1] -= 10;
                    b = 1;}
                else b = 0;
            }
            rl--;ll--;
        }

    }else if (data.length() > right.data.length()){
        while(ll >= 0){
            if (rl < 0){
                buffer[ll + 1] = data[ll] + b;
                if (buffer[ll + 1] >= 10) {
                    buffer[ll + 1] -= 10;
                    b = 1;}
                else b = 0;
            }
            else{
                buffer[ll + 1] = data[ll] + right.data[rl] + b;
                if (buffer[ll + 1] >= 10) {
                    buffer[ll + 1] -= 10;
                    b = 1;}
                else b = 0;
            }
            rl--;ll--;
        }
    }
    if (b == 1)  buffer[0] = 1;
    else buffer[0] = 0;
    int buffer_len = std::max(data.length(), right.data.length()) + 1;
    data.clear();
    for (int i = 1 - b; i < buffer_len; i++) {
        data.pushback(buffer[i]);
    }
}

std::istream &operator>>(std::istream & os, INT & num){
    Darray& arr = num.data;
    arr.clear();
    std::string input;
    os >> input;
    for(char s : input){
        arr.pushback(s - '0');
    }
    return os;
}

std::ostream &operator<<(std::ostream & os, INT & num){
    Darray& arr = num.data;
    for(int i = 0;i < arr.length();i++){
        os << arr[i];
    }
    return os;
}
