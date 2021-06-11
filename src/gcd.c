#include <stdio.h>

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
    if(x == 0) return y;
    return Euclidean_gcd_rec(y % x, x);
}

unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
    while(x){
        unsigned int z = x;
        x = y % x;
        y = z;
    }
    return y;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
    if(x == 0) return y;
    if(y == 0) return x;
    if(x % 2 == 0 && y % 2 == 0) return binary_gcd_rec(x / 2, y / 2) * 2;
    if(x % 2 == 0) return binary_gcd_rec(x / 2, y);
    if(y % 2 == 0) return binary_gcd_rec(x, y / 2);
    if(x < y) return binary_gcd_rec(x, (y - x) / 2);
    return binary_gcd_rec(y, (x - y) / 2);
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y){
    unsigned int shift = 0;
    if((x & -x) > (y & -y)){
        unsigned int z = x;
        x = y;
        y = z;
    }
    if(x == 0) return y;
    while(x % 2 == 0){
        x >>= 1;
        shift++;
    }
    y >>= shift;
    while(y % 2 == 0) y >>= 1;
    while(x != y){
        if(x > y){
            x -= y;
            do x >>= 1; while(x % 2 == 0);
        }
        else{
            y -= x;
            do y >>= 1; while(y % 2 == 0);
        }
    }
    return x << shift;
}


int main(){
    unsigned int i, j, c;


    c = 0;
    for(i = 1; i <= n; i++){
        for(j = i + 1; j <= n; j++){
            if(binary_gcd_itr(i, j) == 1){
                c++;
            }
        }
    }
    c = 2 * c + 1;

    printf("%f\n", (double) c / (n * n));
    return 0;
}
