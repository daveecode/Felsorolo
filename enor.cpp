#include "enor.h"
#include <iostream>
#include <cstdlib>

Enor::Enor(const std::string &filename) {

    file.open(filename.c_str());
    if(file.fail()) {
        st = ABNORM;
        throw FILE_ERROR;
        exit(1);
    }

    akt.sorszam = 0;
}

void Enor::Read() {

    std::string str;
    getline(file,str);
    if(!file.fail()) {
        st = NORM;
        line.clear();
        line.str(str);
    }

    else{
        st = ABNORM;
    }
}

int Enor::szavak(std::stringstream &sor) {

    int db = 0;
    std::string tmp;
    sor >> tmp;
    while(!sor.fail()) {
        db = db + 1;
        sor >> tmp;
    }

    return db;
}

void Enor::Next() {

    for(;st==NORM && line.str().size()==0; Read());

    vege = st == ABNORM;
    if(!vege) {
        ++akt.sorszam;
        akt.sor_db = 0;
        akt.szo_db = 0;

        for(;st==NORM && line.str().size()!=0; Read()) {
            ++akt.sor_db;
            akt.szo_db = akt.szo_db + szavak(line);

            //if(Read().fail())
        }
    }

}

void Enor::seged() {

    while(file.eof()) {
        std::cout << "meg nem" << std::endl;
    }
}
