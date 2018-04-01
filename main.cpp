#include <iostream>
#include "enor.h"
#include <math.h>
#include <cstdlib>

using namespace std;

int main()
{
    Enor t("in.txt");

  /* for(t.First(); !t.end(); t.Next()) {
    Bekezdes e = t.Current();
    cout << "Sorszam: " << e.sorszam << endl;
    cout << "Sorok: " << e.sor_db << endl;
    cout << "Szavak: " << e.szo_db << endl;
   }*/

   Eredmeny x;
   x.hanyados = 0;
   x.sorszam = 0;
   bool l = false;
   for(t.First(); !t.end(); t.Next()) {
        Bekezdes e = t.Current();
        float tmp = (float)e.szo_db/ (float)e.sor_db;
        if(e.sor_db < 3);
        else{cout << tmp << endl;
        if(tmp > x.hanyados) {

                x.hanyados = tmp;
                x.sorszam = e.sorszam;

        }
        }
   }

   cout << x.sorszam << ":\t" << x.hanyados << endl;




    return 0;





}
