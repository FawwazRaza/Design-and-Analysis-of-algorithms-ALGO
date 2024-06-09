/*Suppose a coin is tossed n number of times and the result of tosses is stored in an array such that all
occurrences of heads are followed by all occurrences of tail. Your task is to device an algorithm that finds
the number of occurrences of tail in O(lgn) time.*/

#include<iostream>
using namespace std;

int main() {
    char a[7] = { 'h', 'h', 'h', 't', 't', 't', 't' };
    int size = 7;
    int left = 0, right = size - 1;
    int mid=0;

    while (left < right)
    {
        mid = (left + right) / 2;
        if (a[mid] == 'h')
        {
            left = mid + 1;
        }
        else
        { 
            right = mid;
        }
    }

    int count = abs(size - left);
    cout << "Tails count is :  " << count << endl;

    return 0;
}
