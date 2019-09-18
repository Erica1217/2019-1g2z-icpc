#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int data[1010]={0,};
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&data[i]);
    }
    sort(data,data+n);
    
    int dap=0;
    for(int i=1 ; i<data[n-1] ; i++)
    {
        int cnt=0;
        for(int j=0 ; j<n ; j++)
        {
            if(i <= data[j])
            {
                cnt++;
            }
        }
        if(cnt>=i)
        {
            dap=i;
        }
    }
    printf("%d",dap);
    
}
