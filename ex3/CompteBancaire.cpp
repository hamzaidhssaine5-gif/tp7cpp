#include <iostream>
#include <string>

class CompteBancaire {
private:
    double solde;
    std::string codeSecurite;

public:
    CompteBancaire() : solde(0), codeSecurite("1234") {}
    CompteBancaire(double montantInitial) : solde(montantInitial), codeSecurite("1234") {}

    void afficherSolde() const {
        std::cout << "Solde actuel : " << solde << " €" << std::endl;
    }

    bool retrait(double montant) {
        if (montant <= 0) {
            std::cout << "Montant invalide pour retrait." << std::endl;
            return false;
        }
        if (montant > solde) {
            std::cout << "Solde insuffisant." << std::endl;
            return false;
        }
        solde -= montant;
        std::cout << "Retrait de " << montant << " € effectué." << std::endl;
        return true;
    }

    bool retrait(double montant, const std::string& code) {
        if (code != codeSecurite) {
            std::cout << "Code de sécurité incorrect." << std::endl;
            return false;
        }
        return retrait(montant);
    }
};

int main() {
    CompteBancaire compte1;
    CompteBancaire compte2(1000);

    compte1.afficherSolde();
    compte2.afficherSolde();

    compte2.retrait(200);
    compte2.afficherSolde();

    compte2.retrait(500, "0000");
    compte2.retrait(500, "1234");
    compte2.afficherSolde();

    return 0;
}
