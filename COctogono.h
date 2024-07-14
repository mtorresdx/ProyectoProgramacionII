#ifndef PROYECTO_COCTOGONO_H
#define PROYECTO_COCTOGONO_H

#include <iostream>
#include <string>
using namespace std;

class COctogono{
private:
    string id;
    string alto;
public:
    COctogono(){};
    COctogono(string i, string a){
        id = i;
        alto = a;
    };
    ~COctogono(){};
    void setId(string  id_oct){
        id = id_oct;
    }
    void setAlto(string alto_en){
        alto = alto_en;
    }
    string getId(){
        return id;
    }
    string getAlto(){
        return alto;
    }
    void imprimirOct(){
        cout << "         ID Octogono: " << id << endl;
        cout << "            Alto en: " << alto << endl;
    }
};

#endif //PROYECTO_COCTOGONO_H
