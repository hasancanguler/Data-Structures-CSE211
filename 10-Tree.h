#include <vector>

using namespace std;

template<class T>
bool Tree<T>::findTuple(TreeNode<T>* root, T diff, vector<T>&set) {

    if (root == NULL)
        return false;

    findTuple(root->left,diff,set);
    set.push_back(root->data);
    findTuple(root->right, diff, set);

    for (int index = 0; index < set.size(); index++)
    {
        //it must be possitive for diff control
        int control = set[index] - root->data;
        if (control < 0)
            control *= -1;

        if (control == diff )
        {
            cout << "(" << root->data << "," << set[index] << ") ";
        }
    }
    return true;
}

template<class T>
bool Tree<T>::findTuple(T diff, vector<T>&set) {
    return findTuple(root, diff, set);
}
