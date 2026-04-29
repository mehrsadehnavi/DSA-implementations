#pragma once
#include <limits.h>
#include "IntegerKey.h"
#include<iostream>

class CountingSort{
public:
	void CountSort(IntegerKey* arr, int n){
		int max = Max(arr, n);
		int min = Min(arr, n);
		int *C;
		int k = max - min + 1;
		C = new int[max - min + 1];
		Count(arr, n, C, k, min, max);
		Sort(arr, n, C, k, min, max);
	}
protected:
	void Count(IntegerKey* arr, int n, int* C, int k, int min, int max){
		for (int i = 0; i < k; i++){
			C[i]=0;
		}
			
		for (int i = 0; i <n; i++) {
			C[arr[i].getKey()-min]++;
		}
		int last=C[0];
		C[0]=0;
		int temp;
		
		for (int i =1; i <k; i++) {
			temp=C[i];
			C[i]=C[i-1]+last;
			last=temp;
		}
		
		
	}
	void Sort(IntegerKey* arr, int n, int* C, int k, int min, int max){
		IntegerKey* B=new IntegerKey[n];
		for (int i =0; i<n ; i++){
			B[C[(arr[i].getKey()-min)]]=arr[i];
			C[arr[i].getKey()-min]++;
		}
		for (int i = 0; i < n; i++)
		{
			arr[i] = B[i];
			
		}
	}
	int Min(IntegerKey* arr, int n) {
		int min = arr[0].getKey();
		for(int i = 1; i < n; i++) 
			if(arr[i].getKey() < min) 
				min = arr[i].getKey();
		return min;
	}
	int Max(IntegerKey* arr, int n){
		int max = arr[0].getKey();
		for(int i = 1; i < n; i++) 
			if(arr[i].getKey() > max)
				max = arr[i].getKey();
		return max;
	}
};
