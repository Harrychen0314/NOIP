#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int *result;
int top=0;
int *top_result;
int choose(int stamp[], int stamp_num, int stamp_max,int money) {
	int chose = 0;
	int i=0;
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
void judge(int n,int k,int stamp[]){
	int i;
	stamp[n]=0;
	n++;
	result=(int*)calloc(n*k+1,sizeof(int));
	printf("get data\n");
	for(i=0;i<n;i++){
		printf("%d ",stamp[i]);
	}
	printf("\n");
    for(i=0;i<=n*k;i++){
        result[i]=0;
    }
	choose(stamp, n, k,0);
	for(i=1;i<=n*k;i++){
        if(result[i]!=1){
            break;
        }
    }
	printf("judge result=%d\n",i-1);
	if(i-1>top){
		top=i-1;
		for(i=0;i<n;i++){
			top_result[i]=stamp[i];
		}
	}
}
int generate(int n,const int k,int stamp_sub,int output[]){
	int i=0;
	int stamp_value=0;
	if(stamp_sub < n){
		output[stamp_sub]=stamp_value;
		//printf("chose %d\n",stamp_value);
		for (i = 0; i <= n+1; i++){
			output[stamp_sub]=stamp_value;
			//printf("chose %d\n",stamp_value);
			generate(n,k,stamp_sub+1,output);
			stamp_value++;
		}
	}else{
		judge(n,k,output);
		return 0;
	}
}
int main(void) {
	int n, k;
	int i;
	scanf("%d", &k);
	scanf("%d", &n);
	int *stamp = (int*)calloc(k+1, sizeof(int));
	top_result=(int*)calloc(n,sizeof(int));
	generate(n,k,0,stamp);
	for(i=0;i<n;i++){
		printf("%d ",top_result[i]);
	} 
	printf("\nMAX=%d\n",top);
	system("pause");
	return (0);
}