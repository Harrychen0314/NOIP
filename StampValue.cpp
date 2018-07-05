#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int *result;
int tmp=0;
int count=0;
int choose(int stamp[], int stamp_num, int stamp_max,int money) {
	int chose = 0;
	int i=0;
    count++;
	if (stamp_max > 0) {
		for (i = 0; i < stamp_num; i++) {
			choose(stamp, stamp_num, stamp_max-1, money + stamp[chose]);
            chose++;
		}
	}else {
		result[money]=1;
        money=0;
	}
    return 0;
}
int judge(int n,int k,int stamp[],int num){
	int i;
	stamp[num+1]=0;
    n++;
	result=(int*)calloc(n*k+1,sizeof(int));
    for(i=0;i<=n*k;i++){
        result[i]=0;
    }
	choose(stamp, n, k,0);
	for(i=1;i<=n*k;i++){
        if(result[i]!=1){
            break;
        }
    }
	return (i-1);
}
int main(void) {
	int n, k;
	int i;
	int target;
	scanf("%d", &n);
	scanf("%d", &k);
	int *stamp = (int*)calloc(k+1, sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &stamp[i]);
	}
    printf("%d\n",judge(n,k,stamp,i));
	system("pause");
	return (0);
}