 #include<stdio.h>
 #include<algorithm>
 using namespace std;
 struct m
 {
     int l,w,z;
 };
 bool cmp(struct m  x,struct m  y)
 {
     if(x.l<y.l)
     return true;
     else if(x.l==y.l)
     {
         if(x.w<y.w)
         return true;
         else
         return false;
     }
     else
     return false;
 }
 
 int main()
 {
     int t,n,i,c,j,l,w;
     struct m b[5001];
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d",&n);
         for(i=0;i<n;i++){
             scanf("%d%d",&b[i].l,&b[i].w);
             b[i].z=0;//均初始化为0，表示未加工过 
         }
         sort(b,b+n,cmp);//按长度排好序
        // for(i=0;i<n;i++)
         for(c=0,i=0;i<n;i++)
         {
             if(b[i].z==0) //直接跳过z为0的，从z为1的再次往后遍历
             {
                 b[i].z=1;
                 c++;//c代表所需时间
                 l=b[i].l;
                 w=b[i].w;
                 for(j=0;j<n;j++)
                {
                     if(b[j].z==0&&b[j].l>=l&&b[j].w>=w) //先遍历出所有l、w都比前一个值更大的值
                     {
                         b[j].z=1;
                         l=b[j].l;
                         w=b[j].w;    
                     }
                 }
             }
         }
         printf("%d\n",c);
     }
    return 0;
 }