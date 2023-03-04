#include <iostream>
#include <bits/stdc++.h>

using namespace std;



/*void SuLy(float x, float dental)
{
    while(dental <= 0.5 * );
}
*/

/*bool CheckThapPhan(float x)
{
    if(x - floor(x) == 0) // so do tru di phan nguyen cua so do, neu = 0 thi k co phan thap phan
        return false;
    return true;
}
*/
void SuLy(float x,float dental)
{
    // kiem tra xem so do co phai so thap phan
    if((x - floor(x) == 0))
    {
        cout << x << " la mot so nguyen, luon co nghia" << endl;
    }
    else
    {
        float x1 = x; // tranh lam thay doi so ban dau
        int PhanTP;
        int dem = 0;
        int dem2 = 0;
        float PhanTPGhep;
        // lay so luong chu so phan thap phan cua so do
        while((x1- floor(x1)) != 0)
        {

            // nhan vs 10 de khi so thap phan ay tru di so nguyen cua so tp ay se dan dan = nhau, nghia la dau tien la 0.12
            // dem se = 1 sau do * 10 la 0.1 dem = 2 sau do la 0 luc nay 0 - 0 = 0 se dung vong lap
            x1 *= 10;
            dem++;
        }


        // lay so thap phan kia dang so nguyen, nhan voi 10^dem la dc vi no dang o dang 0.xyz..

        PhanTP = (x - floor(x)) * pow(10,dem);

        int i = -1;
        while(dental <= 0.5 * pow(10,i))
        {

            i -= 1;
            dem2++;
        }

        if(dem2 == 0)
        {
            cout << "So dang tin va co nghia cua " << x << " voi dental: " << dental << " la: " << floor(x) << "+-" << dental << endl;
        }
        else
        {
            for(i = 0; i < dem-dem2; i++)
            {
                PhanTP /= 10;
            }

            PhanTPGhep = PhanTP;
            for(i = 0; i < dem2;i++)
            {
                PhanTPGhep /=10;
            }

            float x2 = floor(x) + PhanTPGhep;

            cout << "So dang tin va co nghia cua " << x << " voi dental: " << dental << " la: " << x2 << "+-" << dental << endl;
        }
    }

}

int main()
{
    float x,dental;
    cout << "Nhap so x: "; cin >> x;
    cout << endl << "Nhap dental: "; cin >> dental;
    cout << endl;


    SuLy(x,dental);
    return 0;
}
