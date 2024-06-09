
/*Suppose each member of the national assembly of banana republic wants to pass his/her resolution. The
constitution of banana republic pass only those resolutions that are supported by more than half members
of the assembly. None of the members of the assembly wants to disclose its resolution until it is passed
by the assembly. Now assume that they have a device that can tell whether two members have same
resolution or not. Your task is to device an algorithm that uses this device no more than O(nlgn) time and
find out whether there is some resolution that this assembly can pass or not. Here n is the number of
members in the national assembly.*/

#include <iostream>
using namespace std;
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int p, int q, int r) 
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = new int[n1];
    int* M = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i++];
          
        }
        else 
        {
            arr[k] = M[j++];
            
        }
        k++;
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2) 
    {
        arr[k++] = M[j++];
    }

    delete[] L;
    delete[] M;
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}



int main() {
    //1= 1st member
    //0= 2nd member
    int arr[] = {1, 0, 0, 0, 0, 1} ;
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    int mid = (size) / 2;
    if (arr[0]==arr[mid]|| arr[size-1] == arr[mid-1])
    {
       
        cout << "resolution passed\n";
    }
    else
    {
        cout << "resolution isn't passed\n";

    }
    return 0;
}
