#include <bits/stdc++.h>
#define pop_size 100

using namespace std;

static long long int MAX = 2, mut_rate = 10; 

double ind[pop_size], fit_values[pop_size], temp_ind[pop_size];

void generate(){
    for(int i = 0; i < pop_size; ++i)
        ind[i] = (rand()%(MAX*100000))/100000.0;
    return;
}

void calc_fitness(){
    for(int i = 0; i < pop_size; ++i)
        fit_values[i] = sin(ind[i]);
}

double tournanment(){
    int aux1, aux2, idx1, idx2, ubermensch = 0;
    calc_fitness();
    for(int i = 1; i < pop_size; ++i)
        if(fit_values[i] > fit_values[ubermensch])  ubermensch = i;
    for(int i = 0; i < pop_size; ++i){
        aux1 = rand()%pop_size;
        aux2 = rand()%pop_size;

        if(fit_values[aux1] > fit_values[aux2]) idx1 = aux1;
        else    idx1 = aux2;

        aux1 = rand()%pop_size;
        aux2 = rand()%pop_size;

        if(fit_values[aux1] > fit_values[aux2]) idx2 = aux1;
        else    idx2 = aux2;

        temp_ind[i] = (ind[idx1] + ind[idx2])/2.0;
    }
    
    for(int i = 0; i < pop_size; ++i) ind[i] = temp_ind[i];

    for(int i = 0; i < pop_size; ++i){
        if((rand()%100) + 1 <= mut_rate)    ind[i] += ((rand()%(MAX*10000) - (MAX*5000.0))/10000.0);
    }
    return ind[ubermensch];

}

int main(){
    int gen = 100;
    generate();
    srand(time(NULL));
    for(int i = 1; i <= gen; ++i){
        cout << i << " " << fixed << setprecision(6) << tournanment() << "\n";
    }


    return 0;
}