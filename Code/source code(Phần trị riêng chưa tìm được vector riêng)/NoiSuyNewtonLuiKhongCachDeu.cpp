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
double f[M][M],x[M],y[M];
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
    // Tính tỉ số sai phân
    for (int i=0;i<n;i++)
        f[i][i] = y[i];
    for (int len = 2;len<=n;len++)
    {
        for (int i=0;i+len-1<n;i++)
        {
            int j = i+len-1;
            f[i][j] = (f[i+1][j] - f[i][j-1])/(x[j]-x[i]);
        }
    }
    dt ans(n-1,0),cur(0,1);
    n--;
    for (int i=0;i<=n;i++)
    {
        ans = ans + cur*f[n-i][n];
        cur = cur*poly[n-i];
    }
    cout << "Da thuc noi suy Newton lui la:\n";
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
