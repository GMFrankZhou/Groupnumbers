#include <iostream>
#include <fstream>
using namespace std;   

bool cangroup(int *sp,int n,int f);
int main() 
{
//read the integers to array s and calculate the sum
    int n=0,tmp,i=0,sum=0;
    ifstream fin("input.in"); 
    while (fin>>tmp) 
        n++;
    fin.clear();
    fin.seekg(0);
    int s[n];
    while (i<n)
    {
        fin>>s[i];
        sum+=s[i++];
    }
    fin.close();

    cout <<"Input: \n";
    for (i=0;i<n;i++)
        cout << s[i]<<" ";
    cout <<"\n\n";
//main loop
    int f1=1;
    bool found=false;
    while ((f1<=sum/2) && !found)
    {
        if ((sum%f1)==0) found=cangroup(s,n,f1);
        if (!found) f1++;
    }
//output the results
    if (!found) 
        cout <<"Just 1 block of "<<sum<<".\n";
    else
    {
        cout <<sum/f1<<" blocks of "<<f1<<":\n";
        int psum=0;
        for (i=0;i<n;i++)
        {
            psum+=s[i];
            cout <<s[i]<<" ";
            if (psum==f1 && i!=n-1 && s[i+1]!=0)
            {
                cout <<"| ";
                psum=0;
            }
        }
        cout <<"\n";
    }
}
//using the factor f to test the array sp which contains nn integers
bool cangroup(int *sp,int nn,int f)
{
    if (nn==0) return true;
    if (sp[0]==0) return cangroup(sp+1,nn-1,f);
    int i=0,t=0;
    while (i<nn)
    {
        t+=sp[i++];
        if (t>f) return false;
        if (t==f) return cangroup(sp+i,nn-i,f);
    }
    return false;
}