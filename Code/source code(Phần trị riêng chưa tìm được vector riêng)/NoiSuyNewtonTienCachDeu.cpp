#include<bits/stdc++.h>
using namespace std;
const int M = 20;
class dt
{
private:
	vector <double> val;
	int n;
	public:
		double calc(double x)
		{
			double res = 0;
			for (int i=0;i<=n;i++)
				res += val[i]*pow(x,i);
			return res;
		}
		dt()
		{
			n = 0;
			vector <double> v;
			val = v;
		}
        dt(int deg,double init)
        {
            n = deg;
            vector<double> v(deg+1,init);
            val = v;
        }
		void print()
		{
			for (int i=n;i>=0;i--)
            {
                if (i==1)
                    cout << val[1] << "x"<< " + ";
                else if (i==0)
                    cout << val[0];
                else
                cout << val[i] << "x^" << i << " + ";
            }
            cout << "\n";
		}
        dt operator +(dt other)
        {
            dt res(max(n,other.n),0);
            for (int i=0;i<=res.n;i++)
            {
                if (i<=n)
                    res.val[i] += val[i];
                if (i<=other.n)
                    res.val[i] += other.val[i];
            }
            return res;
		}
		dt operator -(dt other)
        {
            dt res(max(n,other.n),0);
            for (int i=0;i<=res.n;i++)
            {
                if (i<=n)
                    res.val[i] += val[i];
                if (i<=other.n)
                    res.val[i] -= other.val[i];
            }
            return res;
		}
		dt operator *(dt other)
		{
		    dt res(n+other.n,0);
            for (int i=0;i<=n;i++)
            {
                for (int j=0;j<=other.n;j++)
                    res.val[i+j] += val[i]*other.val[j];
            }
            return res;
		}
		dt operator * (double x)
		{
		    dt res(n,0);
		    for (int i=0;i<=n;i++)
                res.val[i] = val[i]*x;
            return res;
		}
};
// biến toàn cục
double d[M][M],x[M],y[M];
bool isCalc[M][M];
unsigned long long frac[M];
double tinh_delta(int i,int p)
{
    if (isCalc[i][p])
        return d[i][p];
    if (p==0)
    {
        isCalc[i][p] = 1;
        return d[i][p] = y[i];
    }
    d[i][p] = tinh_delta(i+1,p-1) - tinh_delta(i,p-1);
    isCalc[i][p] = 1;
    return d[i][p];
}


main()
{
    int n;
    frac[0] = 1;
    for (int i=1;i<=20;i++)
        frac[i] = frac[i-1]*i;
    cout << "Nhap so gia tri: ";
    cin >> n;
    cout << "Nhap lan luot x[i],y[i]\n";
    for (int i=0;i<n;i++)
        cin >> x[i] >> y[i];
    double h = x[1] - x[0];

    n--;
    d[0][n] = tinh_delta(0,n);
    dt ans(n,0),q(1,1), iden(0,1),cur = iden;
    q = q + iden*(-x[0]-1);
    q = q*(1/h);
    for (int i=0;i<=n;i++)
    {
        cout << "i = " << i << endl;
        ans = ans+ cur*(d[0][i]/frac[i]);
        cur.print();
        cur = cur*q;
        q = q-iden;
    }
    cout << "Da thuc noi suy Newton tien la:\n";
    ans.print();
    double k;
    char tt;
    while (1)
    {
        cout << "Nhap gia tri can noi suy\n";
        cin >> k;
        printf("N(%lf) = %.6lf\n",k,ans.calc(k));
        cout << "Tiep tuc?(Y/N)";
        cin >> tt;
        if (tt=='N'||tt=='n')
            return 0;
    }
}

