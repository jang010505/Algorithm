#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int dp[2][2000], rock[3]={1, 3, 4};
	dp[0][1]=dp[0][3]=dp[0][4]=1;
   dp[1][1]=dp[1][3]=dp[1][4]=1;
   for (int i=2;i<=n;i++){
      if(dp[0][i])
			continue;
      for(int j=0;j<2;j++){
         int chk=0;
         for(int k=0;k<3;k++){
            int idx=i-rock[k];
            if(idx<0)continue;
            if(dp[1-j][idx]==0){
               chk=1;
               break;
            }
         }
         dp[j][i]=chk;
      }
   }
   if(dp[0][n])
   	printf("SK");
   else
   	printf("CY");
}
