#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("life.txt");
    int nr=0,i,j,m,n,v,x;
    char s=219;
    bool a[28][122];
    for(i=0;i<28;i++)
        for(j=0;j<112;j++)
    {
        f>>a[i][j];
        if(a[i][j])
            cout<<s;
        else
            cout<<" ";
        nr++;
        if(nr%112==0&&nr!=3136) cout<<endl;
    }
    while(true)
    {
        int b[28][122]={0};
        x=nr=0;
        for(i=0;i<28;i++)
            for(j=0;j<112;j++)
            if(i==0||j==0||i==27||j==111)
                b[i][j]=0;
            else
            {
                v=0;
                for(m=i-1;m<=i+1;m++)
                    for(n=j-1;n<=j+1;n++)
                    if(m!=i||n!=j) v=v+a[m][n];
                if(a[i][j]&&(v==2||v==3)) b[i][j]=1;
                else if(a[i][j]==0&&v==3) b[i][j]=1;
                else b[i][j]==0;
            }
        for(i=0;i<28;i++)
            for(j=0;j<112;j++)
        {
            a[i][j]=b[i][j];
            if(b[i][j])
                cout<<s;
            else
                cout<<" ";
            nr++;
            if(nr%112==0&&nr!=3136) cout<<endl;
        }
        while(x<1500000000)
            x++;
    }
}
