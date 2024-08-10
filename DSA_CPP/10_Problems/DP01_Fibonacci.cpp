#include <iostream>
using namespace std;

/*
This is regular program using recursion with
T = O(2^n)
S = O(2^n)
*/

class Solution1 {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};

/*
Solution using Memoization method (DP method)
T = O(n)
S = O(n)
*/
class Solution2 {
public:
    int fib(int n) {
        int cache[1024] = {0};      // use vector to get rid of array size
        return mem_fib(n, cache);
    }

    int mem_fib(int n, int cache[]) {
        if (n <= 1) {
            return n;
        }
        if (cache[n] > 0) {
            return cache[n];
        }
        cache[n] = mem_fib(n-1, cache) + mem_fib(n-2, cache);
        return cache[n];
    }
};

/*
Solution using Tabulation method (DP method)
T = O(n)
S = O(n)
*/
class Solution3 {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int res[n+1];
        int i;

        res[0] = 0;
        res[1] = 1;
        for (i=2; i<=n; i++) {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n];
    }
};

/*
Solution using Tabulation method (DP method)
T = O(n)
S = O(1) Optimized space
*/
class Solution4 {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        int sum = 0;
        int first = 0;
        int second = 1;
        for (int i = 2; i <= n; i++) {
            sum = first + second;
            first = second;
            second = sum;
        }
        return sum;
    }
};

int main() {
    Solution1 s1;
    int ret = s1.fib(8);
    cout << "result 1 : " << ret << endl;

    Solution2 s2;
    ret = s2.fib(8);
    cout << "result 2 : " << ret << endl;

    Solution3 s3;
    ret = s3.fib(8);
    cout << "result 3 : " << ret << endl;

    Solution4 s4;
    ret = s4.fib(8);
    cout << "result 3 : " << ret << endl;

    return 0;
}