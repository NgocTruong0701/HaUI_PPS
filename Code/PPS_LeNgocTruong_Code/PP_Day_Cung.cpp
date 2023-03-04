#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void input(double hs[], int &n, double &left, double &right, double &ep)
{
    cout << "nhap bac cua da thuc: ";
    cin >> n;
    cout << "nhap he so:" << endl;
    for(int i = n ;i >= 0;i--)
    {
        cout << "he so cua bac thu " << i << " la: ";
        cin >> hs[i];
    }
    cout << "Nhap khoang dau phan ly: ";
    cin >> left;
    cout << "Nhap khoang cuoi phan ly: ";
    cin >> right;

    cout << "Nhap sai so tuyet doi EP: ";
    cin >> ep;
}

double DaoHam(double hs[], int n, double gt)
{
    double hsdh[100];
    int m = n-1;
    for(int i = n; i >= 0;i--)
    {
        hsdh[i-1] = hs[i]*i;
    }

    double kq = 0;
    for(int i = m; i >=0;i--)
    {
        kq += hsdh[i]*pow(gt,i);
    }

    return kq;
}

double F(double hs[], int n, double gt)
{
    double kq = 0;
    for(int i = n; i >=0; i--)
    {
        kq += hs[i]*pow(gt,i);
    }
    return kq;
}

bool checkKhoangLN(double hs[], int n, double left, double right)
{
    double kqLeft = F(hs, n, left);
    double kqRight = F(hs, n, right);
    double dhLeft = DaoHam(hs, n, left);
    double dhRight = DaoHam(hs, n, right);

    if(kqLeft * kqRight > 0)
        return false;
    else{
        if(dhLeft * dhRight < 0)
            return false;
        return true;
    }
}

// pp day cung
void DayCung(double hs[], int n, double left, double right, double ep)
{
    if(checkKhoangLN(hs,n,left,right))
    {
        double l = left;
        double r = right;
        double x = left - (right - left)*F(hs,n,left)/(F(hs,n,right) - F(hs,n, left));
        if(F(hs,n,x) * F(hs,n,left) < 0)
        {
            while(fabs(x - right) > ep)
            {
                right = x;
                x = left - (((right - left)*F(hs,n,left)) / (F(hs,n,right) - F(hs,n, left)));
            }
        }
        if(F(hs,n,x) * F(hs,n,right) < 0)
        {
            while(fabs(x - left) > ep)
            {
                left = x;
                x = left - (((right - left)*F(hs,n,left)) / (F(hs,n,right) - F(hs,n, left)));
            }
        }

        cout << "Nghiem cua phuong trinh tren khoang ly nghiem [" << l << "," << r << "] la: " << x << "+/-" << fabs(x - left) << endl;
    }
    else
    {
        cout << "Day khong phai khoang ly nghiem" << endl;
    }
}

int main()
{
    double hs[100];
    int n;
    double left, right, ep;

    input(hs,n,left,right,ep);
    DayCung(hs,n,left,right, ep);

    return 0;
}
