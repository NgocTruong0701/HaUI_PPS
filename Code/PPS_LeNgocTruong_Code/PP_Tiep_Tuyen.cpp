#include <iostream> 
#include <iomanip>
#include <cmath>
#define ep 0.01
using namespace std;

float f(float x){
    return pow(x,3)-(4*x)+2;
}

float df(float x){
    return 3*x*x-4;
}

void calc(float x0){
	float x = x0, e, xn;
	int i = 0; 
	cout << setw(12) << "0" << setw(12) << x << setw(12) << "delta\n";
	do{
		x = x - f(x)/df(x);
		e = fabs(f(x)/df(x)); 
		cout << setw(12) << ++i << setw(12) <<  x << setw(12) << e << endl;
	} while(e > ep);
	cout << "Phuong trinh co nghiem gan dung: " << x << " voi sai so: " << e << endl;
} 

int main(){
    float x0 = 0;
    calc(x0); 
}

