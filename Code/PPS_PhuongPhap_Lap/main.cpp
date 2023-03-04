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

double Max(double a, double b)
{
    if(a > b)
        return a;
    else if(a < b)
        return b;
    else
        return a;
}

void PPLap(double hs[], int n, double left, double right, double ep)
{
    if(checkKhoangLN(hs,n,left,right))
    {
        double x0 = (left + right)/2;
        double maxDH = Max(DaoHam(hs,n,left),DaoHam(hs,n,right));
        double x1;
        if(DaoHam(hs,n,left) > 0 && DaoHam(hs,n,right) > 0)
        {
            x1 = x0 - (F(hs,n,x0)/maxDH);
            cout << x0 << "," << x1 << endl;
            while(fabs(x1-ep) > (maxDH/(1-maxDH))*fabs(x1 - x0))
            {
                x0 = x1;
                x1 = x0 - (F(hs,n,x0)/maxDH);
                cout << x0 << "," << x1 << endl;
            }
        }
        if(DaoHam(hs,n,left) < 0 && DaoHam(hs,n,right) < 0)
        {
            x1 = x0 + (F(hs,n,x0)/maxDH);
            cout << x0 << "," << x1 << endl;
            while(fabs(x1-ep) > (maxDH/(1-maxDH))*fabs(x1 - x0))
            {
                x0 = x1;
                x1 = x0 + (F(hs,n,x0)/maxDH);
                cout << x0 << "," << x1 << endl;
            }
        }

        cout << "Nghiem cua phuong trinh tren khoang ly nghiem [" << left << "," << right << "] la: " << x1 << "+/-" << (maxDH/(1-maxDH))*fabs(x1 - x0) << endl;
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
    PPLap(hs,n,left,right, ep);
    return 0;
}
