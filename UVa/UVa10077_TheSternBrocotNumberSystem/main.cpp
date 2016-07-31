#include <iostream>
#include <stdio.h>

using namespace std;

class Frac{
    friend ostream &operator<<(ostream &, const Frac &);
public:
    long int a,b;
    Frac(){this->a = 0; this->b = 0;}
    Frac(int a, int b){this->a = a; this->b = b;}
    bool operator<(const Frac &f) const{
        return (0 > this->a * f.b - this->b * f.a);
    }
    bool operator>(const Frac &f) const{
        return (0 < this->a * f.b - this->b * f.a);
    }
    bool operator==(const Frac &f) const{
        return (this->a == f.a && this->b == f.b);
    }
    Frac& operator=(Frac rhs)
    {
      this->a = rhs.a;
      this->b = rhs.b;
      return *this;
    }

};

Frac operator+(const Frac& lhs, const Frac& rhs){
    Frac f;
    f.a = rhs.a + lhs.a;
    f.b = rhs.b + lhs.b;
    return f;
}

int main()
{
    Frac f1, f2, f3;
    Frac fB;
    int a,b;

    scanf("%d%d",&a,&b);
    while(!(a == 1 && b == 1)){
        fB.a = a; fB.b = b;
        f1.a = 0; f1.b = 1;
        f2.a = 1; f2.b = 1;
        f3.a = 1; f3.b = 0;
        while(!(f2 == fB)){
            if(f2 > fB){
                f3 = f2;
                f2 = f1+f3;
                putchar('L');
            }else if(f2 < fB){
                f1 = f2;
                f2 = f1+f3;
                putchar('R');
            }
        }
        putchar(10);
        scanf("%d%d",&a,&b);
    }

    return 0;
}

