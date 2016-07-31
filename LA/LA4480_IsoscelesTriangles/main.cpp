#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>


using namespace std;

struct point{
int x,y;
};

struct rect{
long long a,b,c;
};

int main(){
    int n, isoc;
    point p;
    rect r;
    vector<point> points;
    vector<rect> med;
    scanf("%d",&n);
    while(n != 0){
        isoc = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d",&p.x,&p.y);
            for(int j = 0; j < med.size(); j++){
                if(med[j].a * p.x + med[j].b * p.y + med[j].c == 0){
                    isoc++;
                }
            }
            for(int j = 0; j < i; j++){
                r.a = 2*(p.x-points[j].x);
                r.b = 2*(p.y-points[j].y);
                r.c = p.x*p.x+p.y*p.y-points[j].x*points[j].x+points[j].y*points[j].y;
                med.push_back(r);
            }
            points.push_back(p);
        }
        scanf("%d",&n);
    }
    return 0;
}

/*
long long sqdist(point p1, point p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int main(){
    map<long long, int> distC;
    map<long long, int> :: iterator iter;
    vector<point> points;
    point p;
    int n,k;
    int isoc;
    //freopen("input.txt","r",stdin);
    scanf("%d", &n);
    while(n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d %d", &p.x, &p.y);
            points.push_back(p);
        }
        isoc = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                distC[sqdist(points[i], points[j])]++;
            }
            for(iter = distC.begin(); iter != distC.end(); iter++){
                k = iter->second;
                isoc += (k*k-k)/2;
            }
            distC.clear();
        }
        points.clear();
        printf("%d\n",isoc);
        scanf("%d", &n);
    }
    return 0;
}
*/

/*
struct point{
int x, y;
};
struct edge{
long double x1, y1, x2, y2;
long double sqdist;
};



bool edge_cmp(edge e1, edge e2){
    return e1.sqdist < e2.sqdist;
}

long double sqdist(edge e){
    return sqrtl((e.x1-e.x2)*(e.x1-e.x2) + (e.y1-e.y2)*(e.y1-e.y2));
}

int main()
{
    int n, x, y;
    int isoc;

    point p;
    edge e;
    vector<point> v;
    vector<edge> d;


    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    while(n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d %d",&x, &y);
            p.x = x;
            p.y = y;
            v.push_back(p);
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                e.x1 = v[i].x;
                e.y1 = v[i].y;
                e.x2 = v[j].x;
                e.y2 = v[j].y;
                e.sqdist = sqdist(e);
                d.push_back(e);
            }
        }
        sort(d.begin(), d.end(), edge_cmp);
        isoc = 0;
        for(int i = 0; i < d.size(); i++){
            printf("(");
            cout << d[i].x1;
            printf(",");
            cout << d[i].y1;
            printf(")(");
            cout << d[i].x2;
            printf(",");
            cout << d[i].y2;
            printf(") | ");
            cout << d[i].sqdist;
            printf("\n");
        }
        int i;
        for(i = 0; d[i].sqdist == 0; i++);
        for(; i < d.size(); i++){
            for(int j = i+1; j < d.size() && d[i].sqdist == d[j].sqdist; j++){
                if((d[i].x1 == d[j].x1 && d[i].y1 == d[j].y1) ||
                    (d[i].x1 == d[j].x2 && d[i].y1 == d[j].y2) ||
                    (d[i].x2 == d[j].x1 && d[i].y2 == d[j].y1) ||
                    (d[i].x2 == d[j].x2 && d[i].y2 == d[j].y2)){
                    isoc++;
                }
            }
        }
        printf("%d\n",isoc);
        v.clear();
        d.clear();
        scanf("%d",&n);
    }
    return 0;
}
*/
