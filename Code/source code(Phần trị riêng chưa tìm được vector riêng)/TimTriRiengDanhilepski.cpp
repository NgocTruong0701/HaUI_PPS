#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    int r,c;
    double val[51][51];
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

Matrix init(vector<double> lst,int row,int m)
    {
        Matrix res(m);
        for (int i=1;i<=m;i++)
            res.val[row][i] = lst[i];
        return res;
    }

main()
{
    int n;
    cout << "Nhap cap cua ma tran vuong: ";
    cin >> n;
    Matrix A(n);
    cin >> A;
    for (int i=n-1;i>=1;i--)
    {
        vector<double> lst;
        lst.push_back(0);
        for (int j=1;j<=n;j++)
        {
            if (j==i)
                lst.push_back(1);
            else
                lst.push_back(A.val[i+1][j]);
        }
        Matrix M1 = init(lst,i,n);
        for (int j=1;j<=n;j++)
            lst[j] /= -A.val[i+1][i];
        lst[i] *= -1;
        Matrix M = init(lst,i,n);
        A = M1*A*M;
    }
    cout << "Phuong trinh dac trung can tim la\n";
    printf("x^%d ",n);
    for (int i=1,j=n-1;i<=n;i++,j--)
    {
        if (j==1)
            cout <<" + "<< -A.val[1][i]<<"x";
        else if (j==0)
            cout << " + " << -A.val[1][i] << "\n";
        else
            cout <<" + "<< -A.val[1][i]<<"x^" <<j;
    }
}

