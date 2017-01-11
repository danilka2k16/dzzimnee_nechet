#include <iostream>

using namespace std;

struct item // ������� ������ ��������
{
    int W; // �����
    int c; //���� ������ ������
    double price; //�������� ���� ("���������")
    int number; // ����� �� �������, ��� ������
    double part; // ����� , ������� �� �������� � ������
};
item *allitems;

void quickSort_price(int l, int r)//�� ����
{
    int x = allitems[l + (r - l) / 2].price;
    int i = l;
    int j = r;
    while(i <= j)
    {
        while(allitems[i].price < x) i++;
        while(allitems[j].price > x) j--;
        if(i <= j)
        {
            swap(allitems[i], allitems[j]);
            i++;
            j--;
        }
    }
    if (i<r)
        quickSort_price(i, r);

    if (l<j)
        quickSort_price(l, j);
}

void quickSort_number(int l, int r)//�� ������/�������
{
    int x = allitems[l + (r - l) / 2].number;
    int i = l;
    int j = r;
    while(i <= j)
    {
        while(allitems[i].number < x) i++;
        while(allitems[j].number > x) j--;
        if(i <= j)
        {
            swap(allitems[i], allitems[j]);
            i++;
            j--;
        }
    }
    if (i<r)
        quickSort_number(i, r);

    if (l<j)
        quickSort_number(l, j);
}

void Continuous_knapsack(int W,int n)
{
    allitems= new item [n];
    double sum=0;
    for (int i=0; i<n;i++)
    {
         cin>>allitems[i].W>>allitems[i].c;
         allitems[i].price=allitems [i].c/allitems [i].W;
         allitems[i].number=i+1;
         allitems[i].part=0;
    }
    cout<<endl;
    quickSort_price(0, n-1);//������������� �� ���� �� ����
    for (int i=n-1; i>=0;i--) {
        //������
        if (W >= allitems[i].W) {   //���� ���������� - �����
            allitems[i].part=1;
            sum+=allitems[i].c;
            W -= allitems[i].W;
        }
        else {// ����� ����� ������� ����� � �������
            allitems[i].part+= W / (allitems[i].W*1.0);
            sum+=W / (allitems[i].W*1.0) * allitems[i].c;
            break;
        }
    }

    quickSort_number(0, n-1); //������������� �� ������� �����

    cout<<sum<<endl;
    for (int i=0; i<n;i++)

    cout<<allitems[i].part<<" "; //����� ����������


    delete[]allitems;
}

int main()
{
  int W,n;
  cin>>W>>n;

  Continuous_knapsack(W,n);
}
