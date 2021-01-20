#include <stdio.h>
void nhap(int *pA, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("mang %d :",i+1);
        scanf("%d",&pA[i]);
    }
}
void xuat(int *pA, int n)
{
    int i;
    for(i = 0; i < n;i++)
    {
        printf("gia trị của mang %d = %d \n",i + 1,pA[i]);
    }
}
int main()
{
    int a[100],n;
    printf("nhap so mang : ");
    scanf("%d",&n);
    nhap(a,n);
    xuat(a,n);
    return 0;
}
