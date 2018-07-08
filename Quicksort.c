#include<stdio.h>

void SWAP(int* a, int* b); // ���� ���ִ� �Լ� 
void quicksort(int A[], int p, int r); // ����Ʈ 
int partition(int A[], int p, int r); // X�� ���Ͽ� ���ĸ�! 


int main(void)
{
	int i, A[100]; // ���� �־��� A �迭 100�� ���� 
	for (i=0; i < 100;  i++ )
   	 if (i%2) 
		A[i] = (100-i)*3+1;
   	 else A[i] = i * 2 + 1;
    
    quicksort(A,0,99); // ����Ʈ �Լ� ȣ�� 
    
    for(i=0; i<100; i++)
    	printf("%d ",A[i]); // ��� 
    	
    printf("\n");
    return 0;
}
void quicksort(int A[], int p, int r) // ����Ʈ 
{
	int q; // ���� ���������� �� ���� 
	if(p<r)
	{
		q = partition(A,p,r); // ������ ����. q�� ���ĸ� 
		quicksort(A,p,q-1); // ���� part1 �ٽ� ���� 
		quicksort(A,q+1,r);	 // ������ part2 �ٽ� ���� 
	}
}

int partition(int A[], int p, int r) // ����. x�� �������� ���ĸ� 
{
	int i=p-1, x=A[r]; // �������� i�� �� ���� ���� x���� 
	int j;
	
	for(j=p; j<r; j++)
		if(A[j]<=x)  // A[j] �� x���� �۰ų� ���� �� ���� �ٲ��� 
			SWAP(&A[++i], &A[j]); // x���� ū���� �ڷ� �������� ������ 
			
	SWAP(&A[++i], &A[r]); // �� �������� X���� A[r]�� �߰����� ���ܿ��� 
	
	return i; // �߰����� ��������. 
}

void SWAP(int* a, int* b)  // ������ ���� �Լ� 
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
