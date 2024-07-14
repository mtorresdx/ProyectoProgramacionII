#ifndef PROYECTO_ISNUMERIC_H
#define PROYECTO_ISNUMERIC_H

#include <string>
using namespace std;

bool isnumeric(string str){
    for(char ch : str) {
        if(not isdigit(ch)){
            return false;
        }
    }
    return true;
}

#endif //PROYECTO_ISNUMERIC_H
