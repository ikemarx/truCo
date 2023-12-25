#ifndef CARTAS_H
#define CARTAS_H

class Carta {
private:
    int valor;
    int naipe;
public:
    Carta(int valor, int naipe);
    ~Carta();
    int getValor();
    int getNaipe();
    void setValor(int valor);
    void setNaipe(int naipe);
};

#endif