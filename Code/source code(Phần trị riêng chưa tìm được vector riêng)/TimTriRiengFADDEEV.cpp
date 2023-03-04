#include <bits/stdc++.h>
using namespace std;

class Matrix
{
private:
    int r,c;
    double val[51][51];
public:
    Matrix()
    {
        r=1,c=1;
        val[1][1] =0;
    }
    Matrix(int n)
    {
        r = n;
        c = n;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (i==j)
                    val[i][j] = 1;
                else
                    val[i][j] = 0;
            }
        }
    }
    Matrix(int a,int b)
    {
        r = a,c = b;
        for (int i=1;i<=r;i++)
        {
            for (int j=1;j<=c;j++)
                val[i][j] = 0;
        }
    }
    Matrix operator + (Matrix other)
    {
        Matrix res(r,c);
        for (int i=1;i<=r;i++)
        {
            for (int j=1;j<=c;j++)
                res.val[i][j] = val[i][j] + other.val[i][j];
        }
        return res;
    }
    Matrix operator - (Matrix other)
    {
        Matrix res(r,c);
        for (int i=1;i<=r;i++)
        {
            for (int j=1;j<=c;j++)
                res.val[i][j] = val[i][j] - other.val[i][j];
        }
        return res;
    }
    Matrix operator * (Matrix other)
    {
        Matrix res(r,c);
        for (int i=1;i<=res.r;i++)
        {
            for (int j=1;j<=res.c;j++)
            {
                for (int k=1;k<=c;k++)
                    res.val[i][j] = (res.val[i][j]+val[i][k]*other.val[k][j]);
            }
        }
        return res;
    }
    Matrix operator * (double x)
    {
        Matrix res(r,c);
        for (int i=1;i<=res.r;i++)
        {
            for (int j=1;j<=res.c;j++)
               res.val[i][j] = val[i][j]*x;
        }
        return res;
    }
    double trace()
    {
        double res = 0;
        for (int i=1;i<=r;i++)
            res += val[i][i];
        return res;
    }
    friend istream& operator >> (istream &in,Matrix &mat)
    {
        cout << "Nhap lan luot cac phan tu cua ma tran\n";
        for (int i=1;i<=mat.r;i++)
        {
            for (int j=1;j<=mat.c;j++)
                in >> mat.val[i][j];
        }
        return in;
    }
};

double p[50];
main()
{
    int n;
    cout << "Nhap cap cua ma tran vuong: ";
    cin >> n;
    Matrix A(n),I(n);
    cin >> A;
    Matrix Y = I;
    for (int i=1;i<=n;i++)
    {
        // tại i = 1 thì Y = A*I
        Y = A*(Y-I*p[i-1]);
        p[i] = Y.trace()/i;
    }
    cout << "Phuong trinh dac trung can tim la\n";
    printf("x^%d ",n);
    for (int i=1,j=n-1;i<=n;i++,j--)
    {
        if (j==1)
            cout <<" + "<< -p[i]<<"x";
        else if (j==0)
            cout << " + " << -p[i] << "\n";
        else
            cout <<" + "<< -p[i]<<"x^" <<j;
    }
}

