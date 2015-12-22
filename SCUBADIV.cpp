#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define sf second.first
#define ss second.second
#define mk make_pair
#define pii pair<int, pair<int, int> >
#define Inf 70000

pii Cur;
vector<pii> Pesos;
int T, O, N, S, U, V, X, Min, Mem[80][80];

void reset() {
    for(int i=1; i<80; i++) {
        for(int j=1; j<80; j++) Mem[i][j] = -1;
    }
}

int scuba(int U, int V, int X, vector<pii> Pesos) {
    int Val, Aux;
    vector<pii> PAux;
    if(U >= O && V >= N) return X;
    else {
        if(Mem[U][V] != -1) return Mem[U][V];
        else {
            Val = Inf;
            for(int i=0; i<Pesos.size(); i++) {
                PAux = Pesos; PAux.erase(PAux.begin()+i);
                Aux = scuba(U + Pesos[i].sf, V + Pesos[i].ss, X + Pesos[i].first, PAux);
                if(Val > Aux) Val = Aux;
            }
            Mem[U][V] = Val;
            return Val;
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        reset();
        vector<pii> Pesos;
        scanf("%d %d %d", &O, &N, &S);
        for(int i=0; i<S; i++) {
            scanf("%d %d %d", &U, &V, &X);
            Pesos.push_back(mk(X, mk(U, V)));
        }
        Min = Inf;
        vector<pii> PAux;
        for(int i=0; i<S; i++) {
            PAux = Pesos; PAux.erase(PAux.begin()+i);
            Min = min(Min, scuba(Pesos[i].sf, Pesos[i].ss, Pesos[i].first, PAux));
        }
        printf("%d\n", Min);
    }
    return 0;
}
