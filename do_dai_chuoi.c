#include <stdio.h>

int len(char* pA)
{
    int i = 0;
    while(pA[i] > 0)
    {
      i++;
    }
    return i;
}
int main()
{
    char a[100];
    printf("nhap : ");
    fgets(a, sizeof a, stdin);
    int str = len(a);
    printf("do dai : %d",str - 1);
    return 0;
}
