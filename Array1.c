#include <stdio.h>
#include <math.h>
int main(){
 int a[20],n,i,ch,max,min; float s=0,avg,sd=0;
 scanf("%d",&n);
 for(i=0;i<n;i++){scanf("%d",&a[i]); s+=a[i];}
 avg=s/n;
 for(i=0;i<n;i++) sd+=(a[i]-avg)*(a[i]-avg);
 sd=sqrt(sd/n);

 do{
  scanf("%d",&ch);
  if(ch==1){max=a[0]; for(i=1;i<n;i++) if(a[i]>max) max=a[i]; printf("%d",max);}
  else if(ch==2){min=a[0]; for(i=1;i<n;i++) if(a[i]<min) min=a[i]; printf("%d",min);}
  else if(ch==3) printf("%.2f",avg);
  else if(ch==4) printf("%.2f",sd);
 }while(ch!=5);

 return 0;
}
