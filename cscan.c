#include<stdio.h>
#include<stdlib.h>

void main()
{
    int m,n,h,i,j,ch,temp,q[100],f[100],tst=0,l=0;
    printf("Enter the max range of disk:\n");
    scanf("%d",&m);
    printf("Enter the size of queue requests:\n");
    scanf("%d",&n);
    printf("Enter the initial head position:\n");
    scanf("%d",&h);
    printf("Enter the queue requests-->\n");
    for(i=0; i<n; i++)
        scanf("%d",&q[i]);
    printf("Enter direction\n1.Right\n2.Left\n");
    scanf("%d",&ch);
    for(i=0; i<n-1; i++)
        for(j=0; j<n-i-1; j++)
        {
            if(q[j]>q[j+1])
            {
                temp=q[j];
                q[j]=q[j+1];
                q[j+1]=temp;
            }
        }
    f[l++]=h;
    if(ch==1)
    {
        for(i=0; i<n; i++)
        {
            if(h<q[i])
            {
                f[l]=q[i];
                tst+=abs(f[l]-f[l++-1]);
            }
            else
                j=i;
        }
        f[l]=m-1;
        tst+=abs(f[l]-f[l++-1]);
        f[l]=0;
        tst+=abs(f[l]-f[l++-1]);
        for(i=0; i<=j; i++)
        {
            f[l]=q[i];
            tst+=abs(f[l]-f[l++-1]);
        }
    }
    else
    {
        for(i=0; i<n; i++)
            if(h<q[i])
            {
                j=i-1;
                break;
            }
        for(; j>=0; j--)
            if(h>q[j])
            {
                f[l]=q[j];
                tst+=abs(f[l]-f[l++-1]);
            }
        f[l]=0;
        tst+=abs(f[l]-f[l++-1]);
        f[l]=m-1;
        tst+=abs(f[l]-f[l++-1]);
        for(j=n-1; j>=i; j--)
        {
            f[l]=q[j];
            tst+=abs(f[l]-f[l++-1]);
        }
    }
    printf("Requests are fulfilled in the order-->\n");
    for(i=0; i<l; i++)
        printf("%d\t",f[i]);
    printf("\n\nTotal Seek Time= %d\n",tst);
}
