#include <bits/stdc++.h>
using namespace std;

int n,l;

int merge(int arr1[],int size1,int arr2[],int size2,int temp[])
{
    int count  = 0;
    int a = 0;
    int b = 0;
    int c = 0;
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

int countInversions(int array[],int size)
{
    if(size > 1 )
    {
    int mid = size / 2;
    int count1 = countInversions(array,mid);
    int count2 = countInversions(array+mid,size-mid);
    int temp[size];
    int count3 = merge(array,mid,array+mid,size-mid,temp);
    for(int x =0;x<size ;x++)
    {
        array[x] = temp[x];
    }
    return count1 + count2 + count3;
    }else{
        return 0;
    }
}

bool cmp1(vector<int> a, vector<int> b){
	int v1, v2;
	if(a[2]==1){
		v1 = l-a[1];
	} else{
		v1 = a[1];
	}
	if(b[2]==1){
		v2 = l-b[1];
	} else {
		v2 = b[1];
	}
	return v1 < v2;
}

bool cmp2(vector<int> a, vector<int> b){
	return a[1] < b[1];
}

bool cmp3(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int main(){
	freopen("meetings.in", "r", stdin);
	freopen("meetings.out", "w", stdout);
	
	cin >> n >> l; //barns 0, l
	vector<vector<int>> arr(n, vector<int>(3));
	int sweight = 0;
	set<pair<int,int>> weights;
	vector<pair<int,int>> pos(n); //i,x
	for(int i=0; i<n; i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2]; //w, x, d;
		sweight += arr[i][0];
		weights.insert({arr[i][1], arr[i][0]}); //x, w
		pos[i] = {0, arr[i][1]};
	}
	sort(begin(arr), end(arr), cmp1);
	
	int cw = 0, ptr = 0, t=0;
	while(cw < sweight/2){
		auto curr = arr[ptr];
		if(curr[2]==1){
			cw+=(*weights.rbegin()).second;
			t=max(t,l-curr[1]);
			weights.erase(*weights.rbegin());
		} else {
			cw+=(*weights.begin()).second;
			weights.erase(*weights.begin());
			t=max(t,curr[1]);
		}
		++ptr;
	}
	
	//cout << t;
	
	sort(begin(arr), end(arr), cmp2); //sort by x
	sort(begin(pos), end(pos)); //sort by x
	for(int i=0; i<n; i++){
		pos[i].first = i;
		pos[i].second += arr[i][2]*t;
	} 
	sort(begin(pos), end(pos), cmp3);
	int invarr[n];
	for(int i=0; i<n; i++) invarr[i] = pos[i].first;
	int ans = 0;
	
	cout << countInversions(invarr, n);
}



