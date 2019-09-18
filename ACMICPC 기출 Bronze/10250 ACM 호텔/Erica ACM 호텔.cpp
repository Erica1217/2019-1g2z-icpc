#include <cstdio>
int main()
{
    int n;
    int floor, room, client;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d %d",&floor, &room, &client);
        int dong = client%floor==0 ? floor : client%floor;
        int ho = ((client-1)/floor)+1;
        printf("%d%02d\n",dong,ho);
    }
}
