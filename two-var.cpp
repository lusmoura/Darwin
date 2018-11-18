#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<double, double> ind;

vector<ind> pop, fit, tmp;
static int pop_size = 50, MAX = 10, mut_rate = 5;


ind rando(){
    double x, y;
    x = (rand()%(MAX*100000))/100000.0;
    y = (rand()%(MAX*100000))/100000.0;
    return ind(x, y);
}

void initialize(){
    pop.resize(pop_size), fit.resize(pop_size), tmp.resize(pop_size);
    for(int i = 0; i < pop_size(); ++i)
        pop[i] = rando();
}

double fitness(ind x){
    return exp(-(x.ff - 3)*(x.ff - 3) - (x.ss - 4)*(x.ss - 4));
}

void evaluate(){
    for(int i = 0; i < pop_size(); ++i) fit[i] = fitness(pop[i]);
}

double tournament(){
    evaluate();
    int ind1, ind2, aux1, aux2, mut;
    for(int i = 1; i < pop_size; ++i){
        if(fit[i] > fit[0]){
            swap(fit[i], fit[0]);
            swap(pop[i], pop[0]);
        }
    }
    
    for(int i = 1; i < pop_size; ++i){
        aux1 = rand()%pop_size;
        aux2 = rand()%pop_size;
        ind1 = (fit[aux1] > fit[aux2])?aux1:aux2;

        aux1 = rand()%pop_size;
        aux2 = rand()%pop_size;
        ind2 = (fit[aux1] > fit[aux2])?aux1:aux2;

        tmp[i] = ind((ind1.ff + ind2.ff), (ind1.ss + ind2.ss));
        
        mut = (rand()%100) + 1;
        if(mut > mut_rate)  tmp[i].ff + rand()
    }

}

int main(){




}