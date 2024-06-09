/*Suppose you are given an array A with n entries, with each entry holding a distinct number. You are told
that the sequence of values A[1], A[2], ..., A[n] is unimodal. For some index p between 1 and n, the values
in the array entries increase up to position p in A and then decrease the remainder of the way until position
n. You’d like to find the "peak entry" p without having to read the entire array in fact, by reading as few
entries of A as possible. Show how to find the entry p by reading at most O(log n) entries of A.*/


#include <iostream>
using namespace std;


int main()
{
	int arr[11] = { 11,12,13,14,15,18,19,20,24,33,2 }; 
	int size = 11;
	int left = 0, right = size;
	int mid=0;
	for (int i = 0; i < size; i*=2)
	{
		mid = (left + right) / 2;
		if (arr[mid] <= arr[mid + 1])
		{
			left = mid ;
		}
		else if (arr[mid] > arr[mid + 1])
		{
			right = mid +1;
		}
		if (arr[mid - 1] < arr[mid] && arr[mid] >= arr[mid + 1])
		{
			cout <<"Peak entry is : " << arr[mid];
			break;
		}
	}
	return 0;
}