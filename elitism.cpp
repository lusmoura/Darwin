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

double elitism(){
    int ubermensch = 0;
    calc_fitness();
    for(int i = 1; i < pop_size; ++i)
        if(fit_values[i] > fit_values[ubermensch])  ubermensch = i;
    for(int i = 0; i < pop_size; ++i)
        ind[i] = (ind[i] + ind[ubermensch])/2.0;
    
    for(int i = 0; i < pop_size; ++i){
        if(i == ubermensch) continue;
        if((rand()%100) + 1 <= mut_rate)    ind[i] += ((rand()%(MAX*100000) - (MAX*50000))/100000.0);
    }
    return ind[ubermensch];
}


int main(){
    int gen = 100;
    generate();
    srand(time(NULL));
    for(int i = 1; i <= gen; ++i){
        cout << i << " " << fixed << setprecision(6) << elitism() << "\n";
    }


    return 0;
}