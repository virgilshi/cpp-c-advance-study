#include <stdio.h>
#include <stdlib.h>
int *ans=NULL;

void merge(int a[],int left,int mid,int right,int ans[]){
	int i=left,j=mid+1;
	int t=0;
	while(i<=mid&&j<=right){
		if(a[i]<=a[j]) ans[t++]=a[i++];
		else ans[t++]=a[j++];
	}
	while(i<=mid) ans[t++]=a[i++];
	while(j<=right) ans[t++]=a[j++];
	t=0;
	while(left<=right){
		a[left++]=ans[t++];
	}
}

void sort(int a[],int left,int right){
	if(left<right){
		int mid=(left+right)/2;
		sort(a,left,mid);
		sort(a,mid+1,right);
		
		merge(a,left,mid,right,ans);
	}
	
}
int main(){
	int a[]={8,4,5,7,1,3,6,2};
	ans=(int*)(malloc(sizeof(int)*8));
	sort(a,0,7);
	for(int i=0;i<8;i++) printf("%d ",a[i]);
	free(ans);
	return 0;
}
