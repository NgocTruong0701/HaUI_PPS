#include<iostream>
#include<bits/stdc++.h>

using namespace std;

float f(float x){
	return 3*pow(x,3) - 10*x + 5;
}

float fdaoham1(float x){
	return 9*pow(x,2) - 10;
}

float fdaoham2(float x){
	return 18*x;
}

void daycung(float a, float b, float e){
	float x0 = 0;
	float d = 0;
	float x = 0;
	
	if(f(a)*fdaoham2(a) >= 0 && f(a)*fdaoham2(b) >= 0){
		d = a;
		x0 = b;
	}
	else{
		d = b;
		x0 = a;
	}
	
	do{
		x = x0 - ((f(x0)*(x0 - d)) / (f(x0) - f(d)));
		x0 = x;
	}
	while(fabs(f(x)) / fabs(fdaoham1(x)) > e);
	
	cout << "Nghiem cua phuong trinh la: " << x << "+-" << fabs(f(x)) / fabs(fdaoham1(x));
}

int main(){
	daycung(0,1,0.01);
	return 0;
}
