#include<iostream>
#include<vector>

int partition(std::vector<int> & array,int start,int end)
{
    int key = array[start];
    while(start < end)
    {
        while(start < end && array[end] > key)
        {
            end--;
        }
        array[start] = array[end];
        while(start < end && array[start] < key)
        {
            start++;
        }
        array[end] = array[start];
    }
    array[start] = key;
    return start;
}


void quickSort(std::vector<int> & array,int start,int end)
{
    if(start > end)
        return;
    int pivot = partition(array,start,end);
    quickSort(array,start,pivot-1);
    quickSort(array,pivot+1,end);
}


int main()
{
    std::vector<int> array;
    for(int i = 100; i >= 1; i--)
        array.push_back(i);
    quickSort(array,0,array.size()-1);
    for(auto u:array)
        std::cout<<u<<std::endl;
    return 0;
}