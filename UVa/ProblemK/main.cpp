#include <cstdio>
#include <vector>
#include <algorithm>

#define SET 3
#define PAIR 2
#define NPAIR 1

using namespace std;

struct Hand{
    int va, vb, vc;
    int m, u;
    int t;

    Hand(){va = vb = vc = 0;}
    Hand(int a, int b, int c):va(a), vb(b), vc(c){
        // Sort values
        if( va > vb ) swap(va, vb);
        if( vb > vc ) swap(vb, vc);
        if( va > vb ) swap(va, vb);

        // Classify
        if( va == vb && vb == vc ){
            t = SET;
        }else if( va == vb ){
            t = PAIR;
            m = va;
            u = vc;
        }else if( va == vc ){
            t = PAIR;
            m = va;
            u = vb;
        }else if( vb == vc ){
            t = PAIR;
            m = vb;
            u = va;
        }else{
            t = NPAIR;
        }
    }
    int type() const {return t;}
    int matched() const {return m;}
    int unmatched() const {return u;}
    bool operator<(const Hand& b) const {
        if( type() != b.type() ) return type() < b.type();
        else if( type() == SET ) return va < b.va;
        else if( matched() == b.matched() ) return unmatched() < b.unmatched();
        else return matched() < b.matched();
    }
    bool operator==(const Hand& b) const {
        return va == b.va && vb == b.vb && vc == b.vc;
    }
};

typedef vector<Hand> vh;
vh hh;

void preprocess(){
    hh = vh();
    for( int i = 1; i < 14; i++ ){
        for( int j = 1; j < 14; j++ ){
            hh.push_back(Hand(i, i, j));
        }
    }
    sort( hh.begin(), hh.end() );
    /*for( Hand h: hh ){
        printf("%d %d %d \n", h.va, h.vb, h.vc );
    }*/
}

int main(){
    int a, b, c;

    preprocess();
    while( scanf("%d %d %d", &a, &b, &c) == 3 && a != 0 && b != 0 && c != 0 ){
        Hand h = Hand(a, b, c);
        if( h.type() == PAIR || h.type() == SET ){
            auto next = lower_bound(hh.begin(), hh.end(), h);
            next++;
            if( next == hh.end() ) printf("*\n");
            else printf("%d %d %d\n", next->va, next->vb, next->vc);
        }else{
            printf("1 1 2\n");
        }
    }
    return 0;
}
