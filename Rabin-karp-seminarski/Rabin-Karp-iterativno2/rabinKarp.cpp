#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class rabinKarp {
private:
    static const int ASCII = 256;
    int mod = pow(2, 31)-1;
    string tekst, uzorak;
    vector<int> indeksi;

    void rabinKarpPretraga(const vector<char>& uzorak, const vector<char>& tekst) {
        int duljinaUzorka = uzorak.size();
        int duljinaTeksta = tekst.size();
        int hashUzorka = 0;
        int hashTeksta = 0;
        for (int i = 0; i < duljinaUzorka; i++) {
            hashUzorka = (ASCII * hashUzorka + uzorak.at(i)) % mod;
            hashTeksta = (ASCII * hashTeksta + tekst.at(i)) % mod;
        }
        int hashMnozitelj = 1;
        for (int i = 0; i < duljinaUzorka - 1; i++)
            hashMnozitelj = (hashMnozitelj * ASCII) % mod;
        for (int i = 0; i <= duljinaTeksta - duljinaUzorka; i++) {
            if (hashUzorka == hashTeksta) {
                int j;
                for (j = 0; j < duljinaUzorka; j++) {
                    if (tekst.at(i + j) != uzorak.at(j))
                        break;
                }
                if (j == duljinaUzorka) {
                    indeksi.push_back(i);
                }
            }
            if (i < duljinaTeksta - duljinaUzorka) {
                hashTeksta = (ASCII * (hashTeksta - tekst.at(i) * hashMnozitelj) + tekst.at(i + duljinaUzorka)) % mod;
                if (hashTeksta < 0) hashTeksta = (hashTeksta + mod);
            }
        }
    }

    void TekstSaBojanjem(int duljinaUzorka) {
        for (int i = 0; i < tekst.size(); i++) {
            bool jeUzorak = false;
            for (int brojac : indeksi) {
                if (i >= brojac && i < brojac + duljinaUzorka) {
                    jeUzorak = true; break;
                }
            }
            if (jeUzorak) {
                cout << "\033[1;31m" << tekst[i] << "\033[0m";
            } else {
                cout << tekst[i];
            }
        }
        cout << endl;
    }

public:
    void unos() {
        cout << endl;
        cout << "Unesite tekst: ";
        getline(cin, tekst);
        cout << "Unesite uzorak: ";
        getline(cin, uzorak);
    }

    void ispis() {
        rabinKarpPretraga(vector<char>(uzorak.begin(), uzorak.end()), vector<char>(tekst.begin(), tekst.end()));

        if (!indeksi.empty()) {
            cout << "Ukupno pronadjeno uzoraka: " << indeksi.size() << endl;
            TekstSaBojanjem(uzorak.size());
            cout << "Uzorak je pronadjen na indeksima: ";
            for (int brojac : indeksi) {
                cout << brojac << " ";
            }
            cout << endl << endl;
        } else {
            cout << "Uzorak nije pronadjen" << endl;
        }

        indeksi.clear();
    }
};

int main() {
    rabinKarp* objekt = new rabinKarp();
    objekt->unos();
    objekt->ispis();
    delete objekt;
    return 0;
}