#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    Tree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(2);
    tree.insert(5);
    cout << tree.order_of_key(3) << endl;

}