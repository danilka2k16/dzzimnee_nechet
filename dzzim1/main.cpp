#include <iostream>
#include <math.h>
using namespace std;
bool is_palindrom(int num)
{
    int a, b = 0;
    for ( a = num; a>0; a /= 10 )
        b = b * 10 + a % 10;
    return b == num;
}
void print_palindrom(int n)
{
    int lim= pow (10,n);//max
    if (n==2)
   {
        cout<<99;
        return ;//stop
   }
    if (n==1)
    {
        cout<<9;
        return ;//stop
    }
        int first=0;
    if (n%2==0)
        first= pow (10,n-1)+1+88*(pow (10,n/2-1));//1881 108801 10088001
    else
        first=pow (10,n-1)+1+7*(pow (10,n/2));//171 10701 1007001
    for (first; first<lim;first+=9)
        if (is_palindrom(first)==true)
        cout<<first<<" ";
}
int main()
{
   int n;
   cin>>n;
   print_palindrom (n);
}
