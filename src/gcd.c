#include <stdio.h>

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
	if(x == 0) return y;
	return Euclidean_gcd_rec(y % x, x);
}


unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
  while(x != 0){
    unsigned int z = x;
    x = y % x;
    y = z;
  }
  return y;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
  if(x == 0) return y;
  else if(y == 0) return x;
  else if(((x | y) & 1) == 0) return 2 * binary_gcd_rec(x / 2, y / 2);
  else if((x & 1) == 0) return  binary_gcd_rec(x / 2, y);
  else if((y & 1) == 0) return  binary_gcd_rec(x, y / 2);
  else if(y >= x) return binary_gcd_rec(x, (y - x) / 2);
  else return binary_gcd_rec((x - y) / 2, y); 
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y){
  unsigned int exp = 0;
  while(x != 0 && y != 0){
    if(((x | y) & 1) == 0)  x = x >> 1, y = y >> 1, exp++;
    else if((x & 1) == 0) x = x >> 1;
    else if((y & 1) == 0) y = y >> 1;
    else if(y >= x) y = (y - x) >> 1;
    else  x = (x - y) >> 1;
  }
    return x == 0? y << exp : x << exp;
}



int main(){
  unsigned int i, j, c, d, e;


  c = 0;
  d = 0;
  e = 0;
  for(i = 1; i <= n; i++){
    for(j = i + 1; j <= n; j++){
      if(Euclidean_gcd_itr(i, j) == 1){
        c++;
      }
      if(binary_gcd_rec(i, j) == 1){
        d++;
      }
      if(binary_gcd_itr(i, j) == 1){
        e++;
      } 
    }
  }
  c = 2 * c + 1;
  d = 2 * d + 1;
  e = 2 * e + 1;
  printf("%f\n", (double) c / (n * n));
  printf("%f\n", (double) d / (n * n));
  printf("%f\n", (double) e / (n * n));
  return 0;
}
