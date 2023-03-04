#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// dinh nghia ham
float f(float x){
	return 3*pow(x,3) - 10*x + 5;
}

float fdaoham(float x){
	return 9*pow(x,2) - 10;
}

void chiadoi(float a, float b, float e){
	float m = 0;
	
	while(fabs((b - a) / 2) > e ){
		m = (a + b) / 2;
		if(f(m) == 0)
		{
			cout << "Nghiem cua phuong trinh la : " << m;
			return;
		}
		else{
			if(f(a) * f(m) < 0)
			{
				b = m;
			}
			else
			{
				a = m;
			}
		}
	}
	
	cout << "Nghiem cua phuong trinh la: " << m << "+/-" << fabs((b-a)/2);
}

int main()
{
	chiadoi(0,1,0.01);
	return 0;
}
 
