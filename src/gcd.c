#include <stdio.h>

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
	if (x == 0) return y;
	return Euclidean_gcd_rec(y % x, x);
}


unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
	while (x != 0) {
		unsigned int z = x;
		x = y % x;
		y = z;
	}
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
	if (x == 0) 
		return y;
	if (y == 0)
		return x;
	if (((x | y) & 1) == 0)
		return binary_gcd_rec(x >> 1, y >> 1) << 1;
	if ((x & 1) == 0) //上でx,yがともに偶数の場合ははじかれるのでok
		return binary_gcd_rec(x >> 1, y);
	if ((y & 1) == 0) //同上
		return binary_gcd_rec(x, y >> 1);
	if (y >= x)
		return binary_gcd_rec(x, (y - x) >> 1);
	else
		return binary_gcd_rec((x - y) >> 1, y);
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y){
	unsigned int cof = 0; //倍率 xとyがともに偶数の時に生じる係数を保存する
	while (x != 0 && y != 0) {
		if (((x | y) & 1) == 0)
			x >>= 1, y >>= 1, cof++;
		else if ((x & 1) == 0)
			x >>= 1;
		else if ((y & 1) == 0)
			y >>= 1;
		else if (y >= x)
			y = (y - x) >> 1;
		else
			x = (x - y) >> 1;
	}
	return (x != 0 ? x : y) << cof;
}

void test() {
	bool euc_itr = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			euc_itr &= Euclidean_gcd_rec(i,j) == Euclidean_gcd_itr(i,j);
	printf("Euclidean_gcd_itr: %s\n", euc_itr ? "正しい" : "正しくない");

	bool bin_rec = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			bin_rec &= Euclidean_gcd_rec(i,j) == binary_gcd_rec(i,j);
	printf("binary_gcd_rec: %s\n", bin_rec ? "正しい" : "正しくない");

	bool bin_itr = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			bin_itr &=  Euclidean_gcd_rec(i,j) == binary_gcd_itr(i,j);
	printf("binary_gcd_itr: %s\n", bin_itr ? "正しい" : "正しくない");
}

int main(){
  //test();
  unsigned int i, j, c;


  c = 0;
  for(i = 1; i <= n; i++){
    for(j = i + 1; j <= n; j++){
      if(Euclidean_gcd_rec(i, j) == 1){
        c++;
      }
    }
  }
  c = 2 * c + 1;

  printf("%f\n", (double) c / (n * n));
  return 0;
}
