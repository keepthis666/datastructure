#include<stdio.h>
#include<stdlib.h>
#define max 13
typedef struct node {
	int data;
	struct node* next;
}node;
int H(int key)
{
	return key % max;
}
int inserthashline(int hash[], int key)//线性探测，key为关键字，pos为哈希表的下标，addr为初始线性的pos
{
	int addr = H(key);
	for (int i = 0; i < max; i++)
	{
		int pos = (addr + i) % max;
		if (hash[pos] == -1)//位置空不空
		{
			hash[pos] = key;
			return pos;
		}
		if (hash[pos] == key)//存不存重复
		{
			printf("关键字已存入，请勿重复存入");
			return pos;
		}
	}
	return -1;

}
void insertlinked(int key,node* hash[])//链地址
{
	int pos = H(key);
	
	node* p = (node*)malloc(sizeof(node));
	p->data = key;
	p->next = hash[pos];
	hash[pos] = p;

}
int main()
{
	node* hash[max];
	int arr[max];
	for (int i = 0; i < max; i++)
	{
		arr[i] = -1;
	}
	printf("%d\n", inserthashline(arr, 44));
	printf("%d", inserthashline(arr, 57));
	return 0;
}