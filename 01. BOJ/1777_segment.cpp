#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> origin_v;
    int input_array[n];
    int input;

    for(int i=0; i<n; i++) 
       cin >> input_array[i];

    for(int i=0; i<n; i++) {
        if(input_array[i] == 0 ){
            origin_v.push_back(i+1);
        }else {
            origin_v.insert((origin_v.end()-input_array[i]), i+1);
        }
    }

    for(int i=0; i<n; i++) {
       cout << origin_v[i] << " ";
    }
    return 0;
}
