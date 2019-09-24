#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int data[11000]={0,};
    for(int i=0; i<n ; i++)
    {
        cin>>data[i];
    }
    sort(data,data+n);
    
    int right2=1;
    int left2=1;
    for(int i=0 ; i<2 ; i++)
    {
        right2*=data[i];
        left2*=data[n-i-1];
    }
    int right3=right2*data[2];
    int left3=left2*data[n-3];
    
    int result = max(max(right2,left2),max(right3,left3));
    int lr = right2*data[n-1];
    int rl = left2*data[0];
    int result2 = max(lr,rl);
    cout<< max(result2,result);
}
