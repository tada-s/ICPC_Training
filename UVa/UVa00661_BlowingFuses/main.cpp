#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int counter = 1;
    int n,m,c,maxAmpere;
    int device;
    int ampere;
    int deviceAmpere[20];
    bool deviceIsOn[20];
    bool fuseBlown;
    int i;

    scanf("%d %d %d",&n,&m,&c);

    while(!(n == 0 && c == 0 && m == 0)){
        printf("Sequence %d\n",counter);
        counter++;
        for(i = 0; i < n; i++){
            scanf("%d",&deviceAmpere[i]);
            deviceIsOn[i] = false;
        }
        ampere = 0;
        maxAmpere = 0;
        fuseBlown = false;
        for(i = 0; i < m; i++){
            scanf("%d",&device);
            if(deviceIsOn[device-1]){
                ampere = ampere - deviceAmpere[device-1];
                deviceIsOn[device-1] = false;
            }else{
                ampere = ampere + deviceAmpere[device-1];
                if(ampere > c){
                    printf("Fuse was blown.\n");
                    fuseBlown = true;
                    for(int j = i+1; j < m; j++) scanf("%d",&device);
                    break;
                }
                if(ampere > maxAmpere) maxAmpere = ampere;
                deviceIsOn[device-1] = true;
            }
        }
        if(!fuseBlown)printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n",maxAmpere);
        putchar('\n');
        scanf("%d %d %d",&n,&m,&c);
    }
    return 0;
}
