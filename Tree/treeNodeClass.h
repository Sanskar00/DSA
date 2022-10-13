#include <vector>
using namespace std;

template <typename T>

class TreeNode {
    public:
    T data;
    vector<TreeNode*> chilren;

    TreeNode(T data){
        this->data=data;
    }

    ~TreeNode(){
        for(int i=0;i<this->chilren.size();i++){
            delete chilren[i];
        }
    }
};