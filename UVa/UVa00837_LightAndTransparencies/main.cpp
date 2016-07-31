#include <bits/stdc++.h>

using namespace std;

#define repSTL(iter, c) for(typeof(c.begin()) iter = c.begin(); iter != c.end(); iter++)
#define pb push_back
#define mkp make_pair
typedef pair<double, double> dd;


int main(){/*
    FILE* fp = fopen("input.txt", "w");
    fprintf(fp, "10\n");
    for(int i = 0; i < 10; i++){
    int l = rand()%5;
    fprintf(fp, "\n%d\n", l);
    vector<dd> va;
    for(int j = 0; j < l; j++){
    #define RANGE 100
    double x1 = (rand()%((int)RANGE)) / 10.0  - (RANGE / 10.0 / 2);
    double x2 = (rand()%((int)RANGE)) / 10.0  - (RANGE / 10.0 / 2);
    double r = (rand()%1000) / 1000.0;

    fprintf(fp, "%.1lf %.1lf %.1lf %.1lf %.1lf\n", x1, 1.0, x2, 1.0, r);
    }
    }
    fclose(fp);

    freopen("input.txt", "r", stdin);*/
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        int nl;
        scanf("%d", &nl);

        set<dd> s;
        s.insert(mkp(-INFINITY, 1.0));
        for(int ll = 0; ll < nl; ll++){
            double x1, y1, x2, y2, r;
            scanf("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &r);
            if(x1 > x2) swap(x1, x2);

            stack<dd> st;
            double rf1 = 1.0, rf2 = 1.0;
            repSTL(iter, s){
                if(iter->first < x1){
                    rf1 = iter->second;
                    rf2 = iter->second;
                }
                if(x1 < iter->first && iter->first < x2){
                    rf2 = iter->second;
                    st.push(*iter);
                }
                if(iter->first > x2){
                    break;
                }
            }

            while(!st.empty()){
                dd aux = st.top();
                st.pop();
                s.erase(aux);
                aux.second *= r;
                s.insert(aux);
            }
            s.insert(mkp(x1, rf1*r));
            s.insert(mkp(x2, rf2));

        }

        printf("%d\n", s.size());
        repSTL(iter, s){
            typeof(iter) iter2 = iter;
            iter2++;
            if(iter2 != s.end()){
                if(iter->first == INFINITY){
                    printf("-inf %.3lf %.3lf\n", iter2->first, iter->second);
                }
                printf("%.3lf %.3lf %.3lf\n", iter->first, iter2->first, iter->second);
                }else{
                    printf("%.3lf +inf %.3lf\n", iter->first, iter->second);
                }
        }
        s.clear();
        if(tt != t-1){
            putchar(10);
        }
    }

return 0;
}
