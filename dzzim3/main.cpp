#include <iostream>
using namespace std;

void incredible_sort(int N,int K)
{
    int*counter=new int [K];
    for (int i=0; i<K;i++ )
        counter [i]=0;
    for (int i=0; i<N; i++)
  {
      int temp = 0;
      cin>>temp;
      counter [temp-1]++;
  }
  for (int i=K-1; i>=0; i--)
    for (int j=0; j<counter[i]; j++)
        cout<<i+1<<" ";
}
int main ()
{
    int N,K;
    cin>>N;
    cin>>K;
    incredible_sort (N,K);
}
