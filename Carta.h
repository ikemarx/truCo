#ifndef CARTAS_H
#define CARTAS_H

class Carta {
private:
    int valor;
    int naipe;
    bool isCoringa;
public:
    Carta(int valor, int naipe);
    ~Carta();
    int getValor();
    void setValor(int valor);
    void setIsCoringa(bool isCoringa);
    bool getIsCoringa();
};

#endif