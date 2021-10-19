#include <iostream>
#include <vector>
#include <random>


using namespace std;

struct Bektor {
    int x;
    int y;
};

ostream& operator<<(ostream& os, Bektor const v){
    return os << "(" << v.x << "," << v.y << ")";
}

istream& operator>>(istream &in, Bektor &v){
    in >> v.x >> v.y;
    return in;
}

Bektor operator -(Bektor const a, Bektor const b){
    Bektor c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

int operator *(Bektor a, Bektor b){
    return a.x * b.x + a.y * b.y;
}

void sort_bub(vector<Bektor> &v){
    for (int i = 0; i < v.size(); i++){
        for (int j = i+1; j < v.size(); j++){
            if (v[i].x > v[j].x){
                Bektor a;
                a = v[i];
                v[i] = v[j];
                v[j] = a;
            }
            if (v[i].x == v[j].x && v[i].y > v[j].y){
                Bektor a;
                a = v[i];
                v[i] = v[j];
                v[j] = a;
            }
        }
    }

}

int main() {
    random_device rd;

    Bektor Bek;
    cin >> Bek;
    cout << Bek << endl;
    cout << "Vec - Vec:" << endl;
    cout << Bek - Bek << endl;
    cout << "Vec * Vec:" << endl;
    cout << Bek * Bek << endl;
    vector<Bektor> vec;

    for (int i = 0; i < 11 ; i++){
        Bektor c;
        c.x = rd() % 10 - 5;
        c.y = rd() % 10 - 5;
        vec.push_back(c);
    }

    cout << "--------------------" << endl;
    cout << "Mass of Bektors" << endl;
    cout << "--------------------" << endl;

    for (Bektor a : vec){
        cout << a << endl;
    }
    sort_bub(vec);

    cout << "--------------------" << endl;
    cout << "Sorted mass" << endl;
    cout << "--------------------" << endl;

    for (Bektor a : vec){
        cout << a << endl;
    }
    return 0;
}
