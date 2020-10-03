#include <bits/stdc++.h>
using namespace std;
 
vector<int> prevSmaller(vector<int> &a) {
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < a.size(); i++) {
        while (!s.empty() && a[i] <= s.top()) {
            s.pop();
        }
        ans.push_back(s.empty() ? -1 : s.top());
        s.push(a[i]);
    }
    return ans;
}
 
/*
Input 1:
    A = [4, 5, 2, 10, 8]
Output 1:
    G = [-1, 4, -1, 2, 2]
Explaination 1:
    index 1: No element less than 4 in left of 4, G[1] = -1
    index 2: A[1] is only element less than A[2], G[2] = A[1]
    index 3: No element less than 2 in left of 2, G[3] = -1
    index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
    index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]
    
Input 2:
    A = [3, 2, 1]
Output 2:
    [-1, -1, -1]
Explaination 2:
    index 1: No element less than 3 in left of 3, G[1] = -1
    index 2: No element less than 2 in left of 2, G[2] = -1
    index 3: No element less than 1 in left of 1, G[3] = -1
*/
int main() {
	vector<int> a{4, 5, 2, 10, 8};
	vector<int> prevSmallerElements = prevSmaller(a);
	cout << "Prev smaller elements: " <<  endl;
	for (int i = 0; i < prevSmallerElements.size(); i++) {
		cout << prevSmallerElements[i] << " ";
	}
	return 0;
}
