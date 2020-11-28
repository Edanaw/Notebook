#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// 1. 
class solution {
    public:
        bool isValid(string s){
            int n = s.size();
            if (n % 2 == 1) {
                return false;
            }

            unordered_map<char, char> pairs = {
                {'}','{'},
                {']','['},
                {')','('}
            };

            stack<char> skt;

            for (char ch : s) {
                /* code */
                if (pairs.count(ch)) {
                    if (skt.empty() || skt.top() != pairs[ch]) {
                        return false;
                    }
                    skt.pop();
                } else {
                    skt.push(ch);
                }
            }
                 
            return skt.empty();
        }
};


// 2.
float arctan2(float x)
{
    double sqr = x * x;
    double e = x;
    double r = 0;
    int i = 1;

    while(e / i > 1e-15) {
        double f = e / i;
        r = (i % 4) ? r + f : r - f;
        e = e * sqr;
        i += 2;
    }

    return r;
}

uint32_t Auint32(float f) {
    union {
        float m;
        uint32_t i;
    } u = {f};

    return u.i;
}

uint64_t Auint64_t(double d) {
    union {
        double d;
        uint64_t i;
    } u = {d};
    return u.i;
}


int main()
{

    float f1 = -0.0;
    float f2 = 0.0;

    uint32_t res1 = Auint32(f1);
    uint32_t res2 = Auint32(f2);

    if (res1 == 0x00000000) {
        cout << "this is -0.0" <<endl; 
    }

    // solution t;
    // string s = "{[]}";

    // bool ret = t.isValid(s);

    // cout << ret << endl;

    // cout << "true: " << true << endl;
    // cout << "false: " << false << endl;

    // int m = 8;
    // int n = m << 2;
    // cout << n <<endl;

    // float m = 3;

    // float res = atan(m);
    // float res1 = arctan2(m);

    // cout << "res: " << res << endl;
    // cout << "res1: " << res1 << endl;

    return 0;
}

