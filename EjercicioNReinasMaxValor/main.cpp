#include <iostream>

using namespace std;

const int N = 4;

void nReinas(int solucion[], int valores[][N], int k, int n, int coste, int &maxCoste);
bool esValida(int solucion[], int k);
void tratarSolucion(int solucion[], int n, int const &maxCoste);
void nReinas(int n);

int main(int argc, const char * argv[])
{
    
    nReinas(4);
   
    return 0;
}
void nReinas(int n) {
    int solucion[n];
    int valores[][N] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
    int maxcoste = 0;
    
    nReinas(solucion, valores, 0, n, 0, maxcoste);
}

void nReinas(int solucion[], int valores[][N], int k, int n, int coste, int &maxCoste) {
    
    for(int i = 0; i < n; i++) {
        solucion[k] = i;
        coste += valores[k][i];
        
        if (esValida(solucion, k)) {
            if(k == n - 1) {
                if (coste >= maxCoste) {
                    
                    maxCoste = coste;
                
                    tratarSolucion(solucion, n, maxCoste);
                }
                
            } else {
                nReinas(solucion, valores, k + 1, n, coste, maxCoste);
            }
        }
        coste -= valores[k][i];
    }
}

bool esValida(int solucion[], int k) {
    bool correcto = true;
    int i = 0;
    while (i < k && correcto) {
        if(solucion[i] == solucion[k] || abs(solucion[k] - solucion[i]) == k - i)
            correcto = false;
        
        i++;
    }
    return correcto;
}

void tratarSolucion(int solucion[], int n, int const &maxCoste) {
    cout << "Solucion: ";
    for(int i = 0; i < n; i++)
        cout << solucion[i] << " ";
    
    cout << "Coste: " << maxCoste << endl;
    cout << endl;
}