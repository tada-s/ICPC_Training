#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)
#define pb push_back
#define mkp make_pair

double maxFuel;
double milesGal;

vector< pair<double, double> > stations;

int travel(int actualStation, double remainFuel){
    if(actualStation == stations.size() - 1){
        return 0;
    }

    int minCost = INF;
    for(int i = actualStation + 1; i < stations.size(); i++){
        double distanceTraveled = stations[i].first - stations[actualStation].first;
        double fuelNeeded = distanceTraveled / milesGal;
        if(fuelNeeded <= maxFuel){
            if(fuelNeeded > remainFuel){
                int stationCost = (int) round(((maxFuel - remainFuel) * stations[actualStation].second + 200));
                minCost = min(minCost, stationCost + travel(i, maxFuel - fuelNeeded));
            }else{
                if(remainFuel <= maxFuel / 2){
                    int stationCost = (int) round(((maxFuel - remainFuel) * stations[actualStation].second + 200));
                    minCost = min(minCost, stationCost + travel(i, maxFuel - fuelNeeded));
                }
                minCost = min(minCost, travel(i, remainFuel - fuelNeeded));
            }
        }
    }

    return minCost;
}

int main(){
    int dataSet = 1;
    //freopen("input.txt", "r", stdin);
    double dist;
    scanf("%lf", &dist);
    while(dist != -1){
        stations.clear();
        double firstcost;
        int stationssize;
        scanf("%lf %lf %lf %d", &maxFuel, &milesGal, &firstcost, &stationssize);

        stations.pb(mkp(0, 0));
        for(int i = 0; i < stationssize; i++){
            double dist, cost;
            scanf("%lf %lf", &dist, &cost);
            stations.pb(mkp(dist, cost));
        }
        stations.pb(mkp(dist, 0));

        printf("Data Set #%d\n", dataSet++);
        printf("minimum cost = $%.2lf\n", (travel(0, maxFuel)) / 100.0 + firstcost);

        scanf("%lf", &dist);
    }
    return 0;
}
