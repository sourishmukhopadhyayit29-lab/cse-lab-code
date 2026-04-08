#include <stdio.h>
int main(){
 int a[20],n,i,pos,val,ch;
 scanf("%d",&n);
 for(i=0;i<n;i++) scanf("%d",&a[i]);

 scanf("%d",&ch);

 if(ch==1){
  scanf("%d%d",&pos,&val);
  for(i=n;i>=pos;i--) a[i]=a[i-1];
  a[pos-1]=val; n++;
 }
 else{
  scanf("%d",&pos);
  for(i=pos-1;i<n-1;i++) a[i]=a[i+1];
  n--;
 }
  

 for(i=0;i<n;i++) printf("%d ",a[i]);
 return 0;
}
