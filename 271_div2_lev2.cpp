#include <bits/stdc++.h>
using namespace std;

vector <int> ss(string a){
    istringstream ss(a);
    string token;
    vector<int> p;
    while(std::getline(ss, token, ' ')) {
        p.push_back(stoi(token));
    }
    return p;
}

double dist(string a, string b){
    vector <int> p = ss(a);
    vector <int> q = ss(b);
    double t = sqrt(pow((p[0]-q[0]),2) + pow((p[1]-q[1]),2));
    return t;
}

struct MyStruct
{
    int k;
    string s;
    bool operator > (const MyStruct& str) const
    {
        return (k > str.k);
    }
};

class BlackWhitePlane {
public:
    double area(vector<string> circles) {
        vector<MyStruct> so;
        vector<MyStruct> m;
        double d = 0;
        int c = 1;
        const double pi = 3.14159265358979323846;
        for (int i = 0; i < circles.size(); i++) {
            m.push_back(MyStruct{ss(circles[i])[2], circles[i]});
        }
        sort(m.begin(), m.end(), greater<MyStruct>());
        d = M_PI*m[0].k*m[0].k;
        for (int j = 1; j < m.size(); ++j) {
            c = 1;
            for (int i = j - 1; i >= 0 ; --i) {
                double tt = dist(m[j].s, m[i].s);
                if(tt <= max(m[j].k, m[i].k))
                    c *= -1;
            }
            d += (c*M_PI*m[j].k*m[j].k);
        }
        return d;
    }
};

int main() {
    vector <string> x = {"2549 8482 11", "9175 5927 35", "2747 6177 93", "5512 8791 81", "4487 8456 60",
                         "6899 610 77", "9716 2202 3", "9312 5625 79", "4020 9851 85", "1640 7179 54",
                         "5761 4348 51","5917 3436 88","6547 386 33","182 7676 1","6329 4496 89"};
    BlackWhitePlane b;
    cout << b.area(x);
    return 0;
}