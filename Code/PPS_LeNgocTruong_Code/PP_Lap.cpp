#include <iostream>
#include <iomanip>
#include <cmath>
#define ep 0.01

using namespace std;

//declare function
float f(float x){
    return (5*pow(x,3)+3)/20;
}

void calc(float x0, float q){
	float xn, x = x0, e;
	int i = 0;
	cout << setw(12) << "0" << setw(12) << x << setw(12) << "delta\n";
	do{
		xn = x; 
		x = f(x);
		cout << setw(12) << ++i << setw(12) <<  x;
		e = (q/(1-q))*fabs(x-xn);
		cout << setw(12) << e << endl;
	} while(e > ep);
	cout << "Phuong trinh co nghiem gan dung: " << x << " voi sai so: " << e << endl;
}

int main(){
	float q = 15*1.0/20, x0 = 0.5;
	calc(x0,q);
}
