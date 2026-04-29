#pragma once
template <class T>

class ThreeWayPartition {
public:
  void Partition(T* arr, int n, T pivot, int& p1, int& p2) {

  p1 = 0, p2 = n-1 ;
  int j = 0;

  while (j <= p2) {
    
	if (arr[j] == pivot){
      swap(arr[j],arr[p2]);
      p2--;
    }

    if (arr[j] < pivot) {
      swap(arr[p1], arr[j]);
      j++;
      p1++;
    }

    if (arr[j] > pivot){
      j++;
    }
  } 
  p2++;
  }
  
void swap(T& x,T& y)
{
     T temp;
     temp=x;
     x=y;
     y=temp;
}
  };