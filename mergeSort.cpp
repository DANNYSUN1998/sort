#include<iostream>
#include<vector>

using namespace std;

void mergeSort(vector<int>& array,int start,int end)
{
    if(start == end)
        return;
    int mid = (start + end) / 2;
    mergeSort(array,start,mid);
    mergeSort(array,mid + 1,end);

    vector<int> tmp;
    int i = start,j = mid + 1;
    while(i <=mid && j <= end)
    {
        if(array[i] <= array[j])
        {
            tmp.push_back(array[i]);
            i++;
        }
        else
        {
            tmp.push_back(array[j]);
            j++;
        }
    }
    while(i <= mid)
    {
        tmp.push_back(array[i]);
        i++;
    }
    while(j <= end)
    {
        tmp.push_back(array[j]);
        j++;
    }
    
    for(int m = start;m<=end;m++)
    {
        array[m] = tmp[m - start];
    }
}


int main()
{
    vector<int> array;
    for(int i = 100; i >= 1; i--)
        array.push_back(i);
   mergeSort(array,0,array.size()-1);
    for(auto u:array)
        cout<<u<<endl;
        return 0;
}