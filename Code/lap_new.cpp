#include<iostream>
#include<bits/stdc++.h>

using namespace std;

float hamlap(float x){
	return (3*pow(x,3) + 5) / 10;
}

void lap(float x0, float q, float e){
	float xn = 0;
	float dental = 0;
	
	do{
		xn = hamlap(x0); 
		dental = (q/(1-q))*(xn - x0);
		x0 = xn;
	}
	while(dental > e);
	cout << "Nghiem cua phuong trinh: " << xn << "+-" << dental;
}

int main(){
	float x0 = 0.5;
	float q = 0.9;
	lap(x0,q,0.01);
	
	return 0;
}
