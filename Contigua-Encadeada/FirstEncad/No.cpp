#include <iostream>
#include <stdlib.h>

using namespace std;

class No
{
public:
    No() {};
    ~No() {};
    int getInfo() { return info; };
    No* getProx() { return prox; };
    void setInfo(int val) { info = val; };
    void setProx(No* p) { prox = p; };
private:
    int info; // informacao
    No* prox; // ponteiro para o proximo
};