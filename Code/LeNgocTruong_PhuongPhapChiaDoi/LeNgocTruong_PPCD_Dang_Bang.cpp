#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//define the function
float f(float x){
	return exp(-x) - sin(x);
}

void Input(double *hs, int &n, double &d, double &c, double &ep)
{
    cout << "Nhap so bac cua da thuc: ";
    cin >> n;
    cout << "Nhap he so: " << endl;
    for(int i = n ;i >= 0;i--)
    {
        cout << "he so cua bac " << i << " la: ";
        cin >> hs[i];
    }
    cout << "Nhap khoang dau phan ly: ";
    cin >> d;
    cout << "Nhap khoang cuoi phan ly: ";
    cin >> c;

    cout << "Nhap sai so tuyet doi EP: ";
    cin >> ep;
}

double F(double *hs, int n, double gt)
{
    double kq = 0;
    for(int i = n ;i >=0;i--)
    {
        kq += hs[i]*pow(gt,i);
    }
    return kq;
}

bool checkKPL(double *hs, int n, double d, double c)
{
    double kqd = F(hs,n,d);
    double kqc = F(hs,n,c);
    if(kqd*kqc >= 0)
        return false;
    return true;
}

//draw table lines
void draw(){
	cout << "+";
	for(int i = 0; i < 5; i++){
		for(int i = 0; i < 16; i++)
			cout << "-";
		cout << "+";
	}
	cout << endl;
}

//print table data
void row(float a, float b, float c, float d, float e){
	cout << "| " << setw(13) << a;
	cout << "| " << setw(13) << b;
	cout << "| " << setw(13) << c;
	if(d > 0)
		cout << "| " << setw(13) << d; // <<"+"
	else
		cout << "| " << setw(13) << d; //<< "-"
	cout << "| " << setw(13) << e << "|" << endl;
}


//Chia doi
void bisect(double *hs, int n, double d, double c, double ep){
    if(checkKPL(hs,n,d,c) == true)
    {
        draw();
        cout << "| a            | b            | m            | f(m)         | e = (b-a)/2  |\n";
        draw();
        double m = (d + c) / 2;
        while (fabs((c-d)/2) > ep)
        {
            if(F(hs,n,m) == 0)
            {
            cout << "Nghiem can tim la: " << m << endl;
            return;
            }
            else
            {
                row(d,c,m,F(hs,n,m),fabs(c - d)/2);
                if(F(hs,n,d) * F(hs,n,m) < 0)
                {
                    c = m;
                }
                else if(F(hs,n,m) * F(hs,n,c) < 0)
                {
                    d = m;
                }
            }
            m = (d + c) / 2;
        }
        row(d,c,m,F(hs,n,m),fabs((d-c)/2));
        draw();
        cout << "Nghiem m gan dung can tim la: " << m << " +- " << fabs((c-d)/2) << endl;
    }
    else{
        cout << "Day khong phai khoang phan ly nghiem" << endl;
    }
}

int main(){
    double *hs = new double[100];
    int n;
    double d,c;
    double ep;
	Input(hs,n,d,c,ep);
	bisect(hs,n,d,c,ep);
	return 0;
}
