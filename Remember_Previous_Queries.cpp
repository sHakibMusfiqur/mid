#include <bits/stdc++.h>
using namespace std;

void print_left_to_right(list<int> &l)
{
    cout << "L ->";
    for(int val : l)
    {
        cout << " " << val;
    }
    cout << endl;
}

void print_right_to_left(list<int> &l)
{
    cout << "R ->";
    for(auto it = l.rbegin(); it != l.rend(); it++)
    {
        cout << " " << *it;
    }
    cout << endl;
}

int main()
{
    int q;
    cin >> q;

    list<int> l;

    while (q--)
    {
        int x, v;
        cin >> x >> v;

        if(x == 0)
        {
            l.push_front(v) ;
        }
        else if(x == 1)
        {
            l.push_back(v);
        }
        else if(x == 2)
        {
            if(v >= 0 && v < l.size())
            {
                auto it = l.begin();
                advance(it, v);
                l.erase(it);
            }
        }

        print_left_to_right(l);
        print_right_to_left(l);
    }

    return 0;
}
