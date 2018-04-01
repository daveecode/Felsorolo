#pragma once
#include <string>
#include <fstream>
#include <sstream>

struct Bekezdes{
    int sorszam, sor_db, szo_db;

};

struct Eredmeny{

    double hanyados;
    int sorszam;
};

class Enor {

enum Status {NORM, ABNORM};
enum Exceptions {FILE_ERROR};

private:
    std::ifstream file;
    std::stringstream line;
    Bekezdes akt;
    Status st;
    bool vege;
    void Read();

public:
    Enor(const std::string &filename);
    void First() {Read(); Next(); }
    void Next();
    Bekezdes Current() const {return akt; }
    bool end() const {return vege; }
    int szavak(std::stringstream &sor);
    void seged();
    ~Enor() {file.close(); }

};
