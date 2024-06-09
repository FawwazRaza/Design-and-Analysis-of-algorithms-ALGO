/*Suppose you are given an array of 3 colors: red, orange and blue. Each color may occur multiple times in
this array. You task is to device an in place O(n) algorithm that sort this array such that first all reds are
placed followed by orange and then green. Here n is the size of the array. Please note that you are not
allowed to count the number of occurrences of these colors. All you can do is just compare the array
elements with red, orange or green.*/

#include<iostream>
using namespace std;
int main()
{
	char arr[10] = { 'r','o','g','o','r','g','o','r','g','r' };
	int size = 10;
	int redloc = 0, orangeloc = (size)/3,greenloc=size-1;
	while (orangeloc <= greenloc)
	{
    if (arr[redloc] == 'r') 
        {
            redloc++;
        }
        else if (arr[greenloc] == 'g') 
        {
            greenloc--;
        }
        else if (arr[orangeloc] == 'o')
        {
            orangeloc++;
        }
        else if (arr[redloc] == 'g' && arr[greenloc] == 'r')
        {
            swap(arr[redloc], arr[greenloc]);
            redloc++;
            greenloc--;
        }
        else if (arr[redloc] == 'o' && arr[orangeloc] == 'r')
        {
            swap(arr[redloc], arr[orangeloc]);
            redloc++;
            orangeloc++;
        }
        else if (arr[greenloc] == 'o' && arr[orangeloc] == 'g') 
        {
            swap(arr[greenloc], arr[orangeloc]);
            greenloc--;
            orangeloc++;
        }
        else if (arr[orangeloc] == 'r')
        {
            swap(arr[redloc], arr[orangeloc]);
            redloc++;
            orangeloc++;
        }
        else if (arr[orangeloc] == 'g') 
        {
            swap(arr[orangeloc], arr[greenloc]);
            greenloc--;
        }
	}
	for (int j = 0; j < size; j++)
	{
		cout << arr[j] << " , ";
	}
    return 0;
}