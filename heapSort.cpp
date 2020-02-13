#include<iostream>
#include<vector>

using namespace std;

void adjust(vector<int> & array,int length,int index)//index是第一个非叶子节点的坐标，length是待排数组的长度
{
    int left = 2 * index,right = 2 * index + 1;
    int maxIndex = index;
    if(left < length && array[maxIndex] < array[left])
        maxIndex = left;
    if(right < length && array[maxIndex] < array[right])
        maxIndex = right;
    if(maxIndex != index)
    {
        int tmp = array[index];
        array[index] = array[maxIndex];
        array[maxIndex] = tmp;
        adjust(array,length,maxIndex);
    }
}

    void heapSort(vector<int> & array, int size)
    {
        for(int i = size / 2 - 1; i >= 0; i--)
        {
            adjust(array,size,i);
        }
        for(int i = size - 1; i >= 1;i --)
        {
            int tmp = array[0];
            array[0] = array[i];
            array[i] = tmp;
            adjust(array,i,0);
        }
    }

    int main()
    {
        vector<int> array;
        for(int i = 100; i>=1; i--)
            array.push_back(i);
        heapSort(array,array.size());
        for(auto u:array)
            cout<<u<<endl;
        return 0;
    }
