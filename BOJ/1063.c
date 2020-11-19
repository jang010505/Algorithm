#include <stdio.h>
#include <string.h>
struct res{
	int x1, y1, x2, y2;
};
int main(){
	struct res t;
	char ks[10], rs[10], x[51][10];
	int n;
	scanf("%s %s %d", ks, rs, &n);
	t.x1=ks[0]-64;
	t.x2=rs[0]-64;
	t.y1=ks[1]-48;
	t.y2=rs[1]-48;
	for(int i=0;i<n;i++) scanf("%s", x[i]);
	for(int i=0;i<n;i++){
		if(strcmp(x[i], "T")==0){
			if(t.x1==t.x2 && t.y2-1==t.y1){
				if(t.y2<8){
					t.y2++;
					t.y1++;
				}
			}
			else if(t.y1<8) t.y1++;
		}
		else if(strcmp(x[i], "L")==0){
			if(t.y1==t.y2 && t.x2+1==t.x1){
				if(t.x2>1){
					t.x2--;
					t.x1--;
				}
			}
			else if(t.x1>1) t.x1--;
		}
		else if(strcmp(x[i], "B")==0){
			if(t.x1==t.x2 && t.y2+1==t.y1){
				if(t.y2>1){
					t.y2--;
					t.y1--;
				}
			}
			else if(t.y1>1) t.y1--;
		}
		else if(strcmp(x[i], "R")==0){
			if(t.y1==t.y2 && t.x2-1==t.x1){
				if(t.x2<8){
					t.x2++;
					t.x1++;
				}
			}
			else if(t.x1<8) t.x1++;
		}
		else if(strcmp(x[i], "RT")==0){
			if(t.y1==t.y2-1 && t.x2-1==t.x1){
				if(t.x2<8 && t.y2<8){
					t.x2++;
					t.x1++;
					t.y1++;
					t.y2++;
				}
			}
			else if(t.x1<8 && t.y1<8){
				t.x1++;
				t.y1++;
			}
		}
		else if(strcmp(x[i], "LT")==0){
			if(t.y1==t.y2-1 && t.x2+1==t.x1){
				if(t.x2>1 && t.y2<8){
					t.x2--;
					t.x1--;
					t.y1++;
					t.y2++;
				}
			}
			else if(t.x1>1 && t.y1<8){
				t.x1--;
				t.y1++;
			}
		}
		else if(strcmp(x[i], "RB")==0){
			if(t.y1==t.y2+1 && t.x2-1==t.x1){
				if(t.x2<8 && t.y2>1){
					t.x2++;
					t.x1++;
					t.y1--;
					t.y2--;
				}
			}
			else if(t.x1<8 && t.y1>1){
				t.x1++;
				t.y1--;
			}
		}
		else if(strcmp(x[i], "LB")==0){
			if(t.y1==t.y2+1 && t.x2+1==t.x1){
				if(t.x2>1 && t.y2>1){
					t.x2--;
					t.x1--;
					t.y1--;
					t.y2--;
				}
			}
			else if(t.x1>1 && t.y1>1){
				t.x1--;
				t.y1--;
			}
		}
	}
	ks[1]=t.y1+48;
	ks[0]=t.x1+64;
	rs[1]=t.y2+48;
	rs[0]=t.x2+64;
	printf("%s\n%s", ks, rs);
}
