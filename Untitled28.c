#include <stdio.h>
void knapsack(int n,float weight[],float profit[],float capacity)
{
	float x[10],A =0;
	int i,j,u;
	u= capacity;
	for(i=0;i<n;i++)
	{
		x[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(weight[i]>u)
			break;
		else
		{
			x[i]=1.00;
			A=A+profit[i];
			u=u-weight[i];
		}
	}
	if(i<n)
	x[i]=u/weight[i];
	A=A+(x[i]*profit[i]);
	printf("\n =");
	printf("\n the maximum profit is = %f\n",A);
}
int main()
{
	float weight[7],profit[7],capacity;
	int num = 7, i , j;
	float ratio[7], temp;
	printf("\n enter the weight an dprofit of the objects");
	for(i=0;i<num;i++){
		scanf("%f %f",&weight[i],&profit[i]);
	}
	printf("\n enter the capacity of kanapsack = ");
	scanf("%f",&capacity);
	for(i=0;i<num;i++)
	{
		ratio[i]=profit[i]/weight[i];
	}
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;
				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
			}
		}
	}
	knapsack(num,weight,profit,capacity);
	return(0);
}
