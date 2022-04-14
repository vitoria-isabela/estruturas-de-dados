class MatrizAmpulheta
{
private:
    int n;
    float* vet;
    bool verifica(int i, int j);

public:
    ///interface
    MatrizAmpulheta(int ordem);
    ~MatrizAmpulheta();
    float get(int i, int j);
    void set(int i, int j, float valor);
};

