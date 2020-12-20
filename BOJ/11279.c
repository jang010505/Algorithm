#include <stdio.h>
int h[100001],t=0, n;

int push(int x){
   h[++t]=x;
   for(int i=t;i>1;i/=2){
      if(h[i]>h[i/2]){
      	int tmp=h[i];
         h[i]=h[i/2];
         h[i/2]=tmp;
		}
      else break;
   }
   return 0;
}
int pop(){
   int top=h[1];
   h[1]=h[t];
   h[t--]=0;   
   int i=1;
   while(i*2<=t){   
      if(h[i]>h[i*2] && h[i]>h[i*2+1]) break;
      else if (h[i*2]>h[i*2+1]){
         int tmp=h[i];
         h[i]=h[i*2];
         h[i*2]=tmp;
			i=i*2;
      } 
      else{
         int tmp=h[i];
         h[i]=h[i*2+1];
         h[i*2+1]=tmp;
			i=i*2+1;
      }
   }
   return top;
}
int main(){
   scanf("%d", &n);
   for(int i=0;i<n;i++){
   	int x;
   	scanf("%d", &x);
      if(x==0){
         if(t==0) printf("0\n");
         else printf("%d\n", pop());
      }
      else push(x);    
   }
   return 0;
}
