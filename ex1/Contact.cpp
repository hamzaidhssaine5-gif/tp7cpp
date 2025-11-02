#include <iostream>
#include <string>

class Contact {
private:
    std::string nom;
    std::string telephone;
    std::string email;

public:
    Contact(const std::string& n) : nom(n), telephone("Non renseigné"), email("Non renseigné") {}
    Contact(const std::string& n, const std::string& tel) : nom(n), telephone(tel), email("Non renseigné") {}
    Contact(const std::string& n, const std::string& tel, const std::string& mail) : nom(n), telephone(tel), email(mail) {}

    void afficher() const {
        std::cout << "Nom: " << nom << std::endl;
        std::cout << "Téléphone: " << telephone << std::endl;
        std::cout << "Email: " << email << std::endl;
    }
};

int main() {
    Contact c1("Hamza");
    Contact c2("Amina", "0600000000");
    Contact c3("Karim", "0611111111", "karim@example.com");

    c1.afficher();
    std::cout << "-----" << std::endl;
    c2.afficher();
    std::cout << "-----" << std::endl;
    c3.afficher();

    return 0;
}
