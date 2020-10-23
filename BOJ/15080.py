#include <stdio.h>

int main(){
	int h1, m1, s1, h2, m2, s2;
	scanf("%d : %d : %d", &h1, &m1, &s1);
	scanf("%d : %d : %d", &h2, &m2, &s2);
	if(s1>s2){
		s2+=60;
		m2--;
		if(m1>m2){
			m2+=60;
			h2--;
			if(h1>h2){
				h2+=24;
			}
		}
		else{
			if(h1>h2){
				h2+=24;
			}
		}
	}
	else{
		if(m1>m2){
			m2+=60;
			h2--;
			if(h1>h2){
				h2+=24;
			}
		}
		else{
			if(h1>h2){
				h2+=24;
			}
		}
	}
	printf("%d", (h2-h1)*3600+(m2-m1)*60+(s2-s1));
}
