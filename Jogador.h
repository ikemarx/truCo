class Jogador {
public:
    Jogador(std::string nome) : nome(nome) {}

    // Método para adicionar uma carta à mão do jogador
    void receberCarta(const Carta& carta) {
        mao.push_back(carta);
    }

    // Método para exibir as cartas na mão do jogador
    void exibirMao() const {
        std::cout << nome << " tem as seguintes cartas na mão:\n";
        for (const auto& carta : mao) {
            std::cout << "  " << carta.toString() << "\n";
        }
    }

private:
    std::string nome;  // Nome do jogador
    std::vector<Carta> mao;  // Cartas na mão do jogador
};