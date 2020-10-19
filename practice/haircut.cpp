#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll merge(ll arr1[],ll size1,ll arr2[],ll size2,ll temp[])
{
    ll count  = 0;
    ll a = 0;
    ll b = 0;
    ll c = 0;
    while(a < size1 && b < size2)
    {
        if(arr1[a] < arr2[b])
        {
            temp[c] = arr1[a];
            c++;
            a++;
        }else{
            temp[c] = arr2[b];
            b++;
            c++;
            count = count + size1 -a;
        }
    }

    while(a < size1)
    {
        temp[c] = arr1[a];
        c++;a++;
    }

	while(b < size2)
    {
        temp[c] = arr2[b];
        c++;b++;
    }

    return count;
}

ll countInversions(ll array[],ll size)
{
    if(size > 1 )
    {
    ll mid = size / 2;
    ll count1 = countInversions(array,mid);
    ll count2 = countInversions(array+mid,size-mid);
    ll temp[size];
    ll count3 = merge(array,mid,array+mid,size-mid,temp);
    for(ll x =0;x<size ;x++)
    {
        array[x] = temp[x];
    }
    return count1 + count2 + count3;
    }else{
        return 0;
    }
}

ll main(){
	//freopen("haircut.in", "r", stdin);
	//freopen("haircut.out", "w", stdout);
	
	int n; cin >> n;
	ll arr[n];
	for(auto& i : arr) cin >> i;
	
}
