#ifndef POLINOMIO_H
#define POLINOMIO_H


class Polinomio
{
public:
    Polinomio() {};
    Polinomio(int n);
    Polinomio(int nn, float coef[]);
    ~Polinomio();

    float avalia(float);
    Polinomio* soma(Polinomio* p);
    Polinomio* derivada(Polinomio* p);  ///fazer
    float integral();  ///fazer

    void set(int nn, float coef[]);
private:
    int n;
    float* vet;
};

#endif // POLINOMIO_H
