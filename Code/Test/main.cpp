#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
float daThuc(float heSo[], int bac , float x)
{
    float res = 0;
    for(int i = 0 ; i < bac + 1 ; ++i)
        res = res*x + heSo[i];
    return res;
}
void nghiem(float heSo[], int bac, float l, float r, float e)
{
    float m = (l+r)/2;
    while (abs(r-l)/2 >e)
    {
        if (daThuc(heSo, bac, m)==0)
        {
            cout<<"Nghiem gan dung la: "<<m<<" +/- "<<abs(r-l)/2<<endl;
            return;
        }
        else
        {
            if (daThuc(heSo, bac, l)*daThuc(heSo, bac, m)<0) r=m;
            else if (daThuc(heSo, bac, m)*daThuc(heSo, bac, r)<0) l=m;
        }
        m = (l+r)/2;
    }
    cout<<"Nghiem gan dung la: "<<m<<" +/- "<<abs(r-l)/2<<endl;
}
int main()
{
    int bac;      cout<<"Nhap bac da thuc: ";      cin>>bac;
    float heSo[bac+1];
    for(int i = 0; i< bac+1 ; i++)
    {
        cout<<"Nhap he so x mu "<<(bac-i)<<" : ";
        cin>>heSo[i];
    }

    float saiSo;   cout<<"Nhap sai so: ";      cin>>saiSo;
    float canDuoi; cout<<"Nhap can duoi: ";    cin>>canDuoi;
    float canTren; cout<<"Nhap can tren: ";    cin>>canTren;

    nghiem(heSo, bac, canDuoi, canTren, saiSo);
}


