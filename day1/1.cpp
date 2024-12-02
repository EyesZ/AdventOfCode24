#include <stdio.h>
#include <bits/stdc++.h>
#include <ostream>
#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main()
{
    vector<int> vleft , vright;
    int left, right;

    while (cin >> left >> right)
    {
        vleft.push_back(left);
        vright.push_back(right);
    }

    sort(vleft.begin(), vleft.end());
    sort(vright.begin(), vright.end());

    int sum = 0;

    for (int i = 0; i < vleft.size(); i++)
    {
        sum += abs(vleft[i] - vright[i]);
    }

    cout << sum << endl;

    return 0;
}