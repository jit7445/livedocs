#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Function to check if three points form a right triangle
bool check_is_right(pair<int,int> p1, pair<int,int> p2, pair<int,int> p3) {
   
    int a2 = pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
    int b2 = pow(p2.first - p3.first, 2) + pow(p2.second - p3.second, 2);
    int c2 = pow(p3.first - p1.first, 2) + pow(p3.second - p1.second, 2);

    // Check for the Pythagorean theorem
    return (a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2);
}

// Function to find the number of right triangles
int fndright(vector<pair<int,int> >& arr) {
    int right = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (check_is_right(arr[i], arr[j], arr[k])) {
                    right++;
                }
            }
        }
    }
    return right;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int> > arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i] = make_pair(x, y);
        }
        cout << fndright(arr) << endl;
    }
    return 0;
}
