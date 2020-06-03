#include<stdio.h>

int main()
{
	int m,n,i,j,k,t=0,q=0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);

	printf("Enter the number of resource type: ");
	scanf("%d",&m);

	int available[m],remaining[n],order[n], allocation[n][m],need[n][m],max[n][m];

	printf("Enter values of allocated matrix : \n");
	
	for(int i = 0 ; i < n ; i++) {
		for(int j=0;j<m;j++) {
			scanf("%d",&allocation[i][j]);
		}
	}

	printf("Enter values of Maximum Resource matrix : \n");
	
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			scanf("%d",&max[i][j]);
		}
	}
	
	printf("Enter available: ");

	for(i = 0 ; i < m ; i++) {
		scanf("%d",&available[i]);
	}

	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			need[i][j] = max[i][j]-allocation[i][j];
		}
	}

	int r, request[m];
	printf("Enter the process which requests: ");
	scanf("%d",&r);

	printf("Enter the request: ");
	
	for(i=0;i<m;i++) {
		scanf("%d",&request[i]);
	}

	for(i = 0 ; i < m ; i++) {
		if(request[i] < need[r][i]) {
			if(request[i] < available[i]) {
				available[i] = available[i] - request[i];
				need[r][i] = need[r][i] - request[i];
				allocation[r][i] = allocation[r][i] + request[i];
			}
		}
	}

	int flag=1;

	for(i = 0 ; i < n ; i++) {

		flag=1;
		
		for(j = 0 ; j < m ; j++) {
			if(need[i][j]>available[j]) {
				flag=0;
			}
		}

		if(flag==1) {

			order[t++] = i;
			for(k = 0 ; k < m ; k++) {
				available[k]=available[k]+allocation[i][k];
			}
		} else {
			remaining[q++] = i;
		}
	}

	for(i=0;i<t;i++) {
		printf("%d ",order[i]);
	}
	
	for(i=0;i<q;i++) {
		printf("%d",remaining[i]);
	}
	printf("\n");
	return 0;
}
