#include <iostream>
#include <cstring>
using namespace std;

#define velicinaASCII 256

bool provjera = false;

int racunanjeHashVrijednosti(const char str[], int M, int trenutniHash = 0, int i = 0)
{
    int prostiBroj =  2147483647;
    if (i == M)
        return trenutniHash;

    return racunanjeHashVrijednosti(str, M, (velicinaASCII * trenutniHash + str[i]) % prostiBroj, i + 1);
}

void rabinKarpPretragaRekurzivno(const char uzorak[], const char znakovniNiz[], int M, int N, int h, int i = 0){
    int prostiBroj =  2147483647;
    if (i > N - M)
        return;

    int uzorakHash = racunanjeHashVrijednosti(uzorak, M, prostiBroj);
    int hashNiza = racunanjeHashVrijednosti(znakovniNiz+ i, M, prostiBroj);

    if (uzorakHash == hashNiza) {
        int j;
        for (j = 0; j < M; j++) {
            if (znakovniNiz[i + j] != uzorak[j]) {
                break;
            }
        }

        if (j == M){
            cout << "Uzorak je pronadjen na indeksu: (" << i << ")" << endl;
            provjera = true;
        }
    }

    if (i < N - M) {
        hashNiza = (velicinaASCII * (hashNiza - znakovniNiz[i] * h) + znakovniNiz[i + M]) % prostiBroj;

        if (hashNiza < 0)
            hashNiza = (hashNiza + prostiBroj);

        rabinKarpPretragaRekurzivno(uzorak, znakovniNiz, M, N, h, i + 1);
    }
}

void rabinKarpPretraga(const char uzorak[], const char znakovniNiz[]){
    int prostiBroj =  2147483647;
    int M = strlen(uzorak);
    int N = strlen(znakovniNiz);
    int h = 1;
    if(M > N){
        cout << "Uzorak koji pokusavate pronaci je duzi od niza u kojem ga zelite pronaci!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < M - 1; i++)
        h = (h * velicinaASCII) % prostiBroj;

    rabinKarpPretragaRekurzivno(uzorak, znakovniNiz, M, N, h);
    
    if(!provjera)
        cout << "Uzorak nije pronadjen!" << endl;
}

int main()
{
    char znakovniNiz[] = "Prehladjen sam jer je hladno.";
    char uzorak[] = "je";
    

    rabinKarpPretraga(uzorak, znakovniNiz);
    return 0;
}
