#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back

vector< pair<int, int> > points;
int color[100];
int dist[100][100];

int f(int d){
    //if(dist[i][j] <= d && maxD <= dist[i][j] && !used[i] && !used[j] && color[i] != color[j]){

}

int main(){
    freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    while(n--){
        int p, k;
        scanf("%d%d", &p, &k);

        for(int i = 0; i < p; i++){
            int x, y;
            char str[5];
            scanf("%d %d %s", &x, &y, str);

            points.pb(mkp(x, y));
            color[i] = str[0];
        }


        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                int dx = points[i].first - points[j].first;
                int dy = points[i].second - points[j].second;
                dist[i][j] = dx * dx + dy * dy;
            }
        }

        /*for(int i = 5; i < 9; i++){
            printf("[%d %d]\n\n", i, f(i * i));
        }*/

        int lb = 0;
        int ub = 3000;
        while(lb <= ub){
            int mid = (lb + ub) / 2;
            if(f(mid * mid) < k){
                lb = mid + 1;
            }else{
                ub = mid - 1;
            }
        }

        if(lb == 3000 + 1){
            printf("Impossible\n");
        }else{
            printf("%d\n", lb);
        }

        points.clear();
    }
    return 0;
}
