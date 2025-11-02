#include <iostream>
#include <vector>
#include <string>

class Facture {
private:
    struct Article {
        std::string nom;
        double prixUnitaire;
        int quantite;
        double tva;
        
        Article(const std::string& n, double p, int q = 1, double t = 0.0)
            : nom(n), prixUnitaire(p), quantite(q), tva(t) {}
    };
    
    std::vector<Article> articles;

public:
    void ajouterArticle(const std::string& nom, double prixUnitaire) {
        articles.emplace_back(nom, prixUnitaire);
    }

    void ajouterArticle(const std::string& nom, double prixUnitaire, int quantite) {
        articles.emplace_back(nom, prixUnitaire, quantite);
    }

    void ajouterArticle(const std::string& nom, double prixUnitaire, int quantite, double tva) {
        articles.emplace_back(nom, prixUnitaire, quantite, tva);
    }

    void afficherTotal() const {
        double total = 0.0;
        for (const auto& article : articles) {
            double prixTTC = article.prixUnitaire * article.quantite * (1 + article.tva / 100.0);
            total += prixTTC;
            std::cout << article.nom << ": " << prixTTC << " € ("
                      << article.quantite << " x " << article.prixUnitaire << " € + TVA " << article.tva << "%)\n";
        }
        std::cout << "Total à payer : " << total << " €" << std::endl;
    }
};

int main() {
    Facture facture;
    facture.ajouterArticle("Stylo", 1.5);
    facture.ajouterArticle("Cahier", 2.0, 3);
    facture.ajouterArticle("Sac à dos", 50.0, 1, 20.0);

    facture.afficherTotal();

    return 0;
}
