#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <afxres.h>

using namespace std;

bool f(int x, int y)
{
    return x>y;
}

void Vectorfun()
{
    vector<int> a = { 11,2,3,14 };

    cout << a[1] << endl;

    sort(a.begin(), a.end());

    bool present = binary_search(a.begin(), a.end(), 3); //true
    if (present == 1)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    present = binary_search(a.begin(), a.end(), 4); //false
    if (present == 1)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    a.push_back(100);
    present = binary_search(a.begin(), a.end(), 100); //true
    if (present == 1)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

    a.push_back(100);
    a.push_back(100);
    a.push_back(100);
    a.push_back(100);

    a.push_back(123);

    auto it = lower_bound(a.begin(),a.end(), 100);
    auto it2 = upper_bound(a.begin(),a.end(), 100);

    cout<<*it<<" "<<*it2<<endl;
    cout<<it2 - it <<endl;

    sort(a.begin(), a.end(), f);

    for(int &x: a)
    {
        x++;
    }
    for(int &x: a)
    {
        cout<<x<< " ";
    }

}

void setfunction()
{
    set<int> var;
    var.insert(1);
    var.insert(2);
    var.insert(-1);
    var.insert(-10);

        for(int x : var) // wypisz wszystkie wartosci var
            cout<< x<< " ";
    auto it = var.find(-1);
    if(it == var.end())
    {
        cout<<" not present\n";
    }
    else
    {

        cout<<"\npresent\n";
        cout<<*it<<endl;
    }
    auto it2 = var.upper_bound(-1);
    auto it3 = var.upper_bound(0);
    cout<<*it2<<" "<<*it3<<endl;
    auto it4 = var.upper_bound(2);
    if(it4 == var.end())
    {
        cout<<"sorry i cant find smt like that\n";
    }
}

void mapfuncion()
{
    map<int, int> A;
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;
    A[1000032] = 1;

    map<char, int> cnt;
    string x = "rachit jain";

    for(char c :x )
    {
        cnt[c]++;
    }
    cout<<cnt['a']<<" "<<cnt['z']<<endl;

}

void stlfunctions()
{
    vector<int> a = { 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6};

    cout<<"funkcja replace\n";
    Sleep(2000);

    cout<<"vector poczatkowy\n";
    for(int x:a)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    replace(a.begin(), a.end(), 1,4);

    cout<<"vector po metodzie replace dla vectora dla argumentow 1 i 4\n";
    for(int x:a)
    {
        cout<<x<<" ";
    }

    Sleep(3000);
    cout<<"\nwyswietlenie rozmiaru i pojemnosci vectora\n";
    cout<<a.size()<<"- size\n";
    cout<<a.capacity()<<"- capacity\n";
    Sleep(3000);

    a.erase(remove(a.begin(), a.end(), 4), a.end());

    cout<<"funkcja erase i remove dla poprzedniego vectora usuwajaca wszystkie 4\n";
    cout<<"Wyswietlenie vectora po usunieciu, oraz wyswietlenie jego pojemnosci i wielkosci\n";

    Sleep(5000);

    for(int x:a)
    {
        cout<<x<<" ";

    }
    cout<<"\n";
    cout<<a.size()<<"- size\n";
    cout<<a.capacity()<<"- capacity\n";
}
int main() {
    stlfunctions();
    return 0;
}
