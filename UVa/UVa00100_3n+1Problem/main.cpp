#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

map<unsigned long ,unsigned long > m;

unsigned long longitud(unsigned long );

int main()
{
    unsigned long cotaInferior, cotaSuperior, l, maxLongitud;

    while(scanf("%lu %lu",&cotaInferior, &cotaSuperior)!= EOF){
        printf("%lu %lu ",cotaInferior,cotaSuperior);
        if(cotaInferior > cotaSuperior){
            l = cotaInferior;
            cotaInferior = cotaSuperior;
            cotaSuperior = l;
        }
        maxLongitud = 0;
        for(unsigned long c = cotaInferior; c <= cotaSuperior; c++){
            l = longitud(c);
            if(l > maxLongitud) maxLongitud = l;
        }
        printf("%lu\n",maxLongitud);
    }
    return 0;
}

unsigned long longitud(unsigned long n){
    if(n == 1) return 1;
    map<unsigned long ,unsigned long >::const_iterator i;
    i = m.find(n);
    if(i != m.end()){
        return i->second;
    }else{
        unsigned long l;
        if(n%2 == 0){
            l = longitud(n/2) + 1;
        }else{
            l = longitud(3*n+1) + 1;
        }
        m[n] = l;
        return l;
    }
}

