#include <bits/stdc++.h> 

using namespace std;

map<int, int> mp;
map<pair<pair<int, int>, int>, int> triplet_mp;
int arr[5005];
int n, x;


int main () {
    cin >> n >> x;

    for (int i = 1 ; i <= n ; i++) {
        cin >> arr[i];

        mp[arr[i]]++;
    }

    for (int i = 1 ; i <= n ; i++) {
        mp[arr[i]]--;
        for (int j = i ; j <= n ; j++) {
            mp[arr[j]]--;

            if (mp.find(x - arr[i] - arr[j]) != mp.end()) {
                vector<int> v = {arr[i], arr[j], x - arr[i] - arr[j]};
                sort(v.begin(), v.end());
                triplet_mp[{{v[0], v[1]}, v[2]}] = 1;
            }
            mp[arr[j]]++;
        }    
        mp[arr[i]]++;
    }

    cout << triplet_mp.size() << endl;
}
