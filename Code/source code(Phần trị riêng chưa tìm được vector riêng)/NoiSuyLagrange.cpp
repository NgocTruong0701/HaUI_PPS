#include<bits/stdc++.h>
using namespace std;
const int M = 2e3;
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
		friend void init(dt poly[],int n);
};
// biến toàn cục
double x[M],y[M];
// Các nhị thức X - Xi
dt poly[M];
void init(dt poly[],int n)
{
    for (int i=0;i<n;i++)
    {
        poly[i].n = 1;
        poly[i].val.push_back(-x[i]);
        poly[i].val.push_back(1);
    }
}

main()
{
    int n;
    cout << "Nhap so gia tri: ";
    cin >> n;
    cout << "Nhap lan luot x[i],y[i]\n";
    for (int i=0;i<n;i++)
        cin >> x[i] >> y[i];
    init(poly,n);
    dt ans(n-1,0);
    n--;
    for (int i=0;i<=n;i++)
    {
        dt cur(0,1);
        double m = 1;
        for (int j=0;j<=n;j++)
        {
            if (j==i)
                continue;
            cur = cur*poly[j];
            m *= x[i]-x[j];
        }
        ans = ans + cur*(y[i]/m);
    }
    cout << "Da thuc noi suy Lagrange la:\n";
    ans.print();
    double k;
    char tt;
    while (1)
    {
        cout << "Nhap gia tri can noi suy\n";
        cin >> k;
        printf("N(%lf) = %.6lf\n",k,ans.calc(k));
        cout << "Tiep tuc?(Y/N)\n";
        cin >> tt;
        if (tt=='N'||tt=='n')
            return 0;
    }
}

