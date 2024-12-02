#include <stdio.h>
#include <bits/stdc++.h>
#include <ostream>
#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main()
{
    map<int, int> mleft, mrigth;
    int left, right;

    while (cin >> left >> right)
    {
       mleft[left]++;
       mrigth[right]++;
    }


    int sum = 0;

    for (int i = 0; i < mleft.size(); i++)
    {
        sum += abs(i*mrigth[i] * mleft[i]);
    }

    cout << sum << endl;

    return 0;
}