#include <bits/stdc++.h>
using namespace std;

int fitcows(vector<int> gaps, int D){
    int cows = 2;
    for(int i : gaps){
        if(i >= D+2){
            return D;
        }
        else if(i == D+1){
            cows--;
        }
    }
    if(cows <= 0){
        return D;
    }
    return fitcows(gaps, D-1);
}

void printvec(vector<bool> v){
    cout << '[';
    for(auto i : v) cout << i << ", ";
    cout << ']' << endl;
}

int main(){
    int N;
    ifstream in("socdist1.in");
    in >> N;

    vector<bool> stalls;
    string k;
    in >> k;

    cout << k << endl;

    for(int i = 0; i < N; i++){
        stalls[i] = k[i];
        cout << k[i];
    }

    printvec(stalls);

    int D = INT_MAX;
    int currcount = 0;
    vector<int> gaps(0);

    for(int i = 0; i < stalls.size(); i++){
        if(!stalls[i]){
            currcount++;
        }
        else if(currcount != 0){
            D = min(currcount, D);
            gaps.push_back(currcount);
            currcount = 0;
        }
    }

    ofstream out("socdist1.out");
    int j = fitcows(gaps, D);
    out << j << endl;

    in.close();
    out.close();
}