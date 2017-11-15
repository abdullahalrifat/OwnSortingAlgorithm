#include "NSort.h"

#include <iostream>
#include<vector>
#include<climits>
#include<cstdlib>
#include<ctime>
using namespace std;
vector<int>arr;
vector<int>negarr;
vector<int>vt;
vector<int>neg;
vector<int>negcnt;
vector<int>cnt;
void nsortpos(int limit,int n)
{
    int counts=0;
    for(int i=0;i<limit;)
    {
        if(vt[i]==-1)
        {
            i++;
            continue;
        }
        else
        {
            if(cnt[vt[i]]!=0)
            {
                arr.push_back(vt[i]);
                cnt[vt[i]]--;
                counts++;
            }
            else
            {
                arr.push_back(vt[i]);
                counts++;
                i++;
            }

        }
        if(counts==n)
        {
            break;
        }
    }
}
void nsortneg(int limit,int n)
{
    int counts=0;
    for(int i=0;i<limit;)
    {
        if(neg[i]==-1)
        {
            i++;
            continue;
        }
        else
        {
            if(negcnt[neg[i]]!=0)
            {
                negarr.push_back(neg[i]);
                negcnt[neg[i]]--;
                counts++;
            }
            else
            {
                negarr.push_back(neg[i]);
                counts++;
                i++;
            }

        }
        if(counts==n)
        {
            break;
        }
    }
}

void sortn::sorts(int n,int *array) {

    for(int i=0;i<10000010;i++)
    {
        vt.push_back(-1);
        cnt.push_back(-1);
        neg.push_back(-1);
        negcnt.push_back(-1);
    }
    neg.clear();
    arr.clear();
    negarr.clear();
    vt.clear();
    cnt.clear();
    negcnt.clear();
    for(int i=0;i<n;i++)
    {
       int temp=array[i];
        // cin>>num;
        if(temp<0)
        {
            temp*=-1;
            neg[temp]=temp;
            negcnt[temp]++;
        }
        else{

            vt[temp]=temp;
            cnt[temp]++;
        }
    }

    nsortpos(10000000,n);
    nsortneg(10000000,n);

    for(int i=0;i<negarr.size();i++)
    {
        array[i]=negarr[i];
    }
    for(int i=0;i<arr.size();i++)
    {
        array[i]=arr[i];
    }
}
/*
 * just for custome test
using namespace std;
int main()
{
    int arr[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sortn::sorts(n,arr);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
 */