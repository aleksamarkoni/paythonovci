#ifndef _Vojnik_H
#define _Vojnik_H
#include <iostream>
using namespace std;
class Vojnik {
protected:
    int poz;
    bool ziv;
public:
    friend ostream &operator<<( ostream &output, const Vojnik &a );
    Vojnik();
    friend class Josiph;
};
#endif
