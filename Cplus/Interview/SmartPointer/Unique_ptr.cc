// use of unique_ptr 

// make_shared 2
#include <memory>
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	string name;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x, string _name) : val(x), left(nullptr), right(nullptr), name(_name) {}
};
/* 注意，unique_ptr作为函数参数的时候只能使用引用传递 */
void foos(unique_ptr<TreeNode> &sp) {
	(sp->val)++;
}

int main() {
	// ()括号中的是模板类的类型的初始化函数
	//auto sp = make_unique<TreeNode>(12, "good"); c++11没有make_unique函数
	unique_ptr<TreeNode> sp(new TreeNode(12, "good"));
	foos(sp);

    // std::move,因为unique_ptr只能有一个，所以move之后原指针就没有了
    auto ptr = move(sp);
    cout<<"is sp still exist? : "<<(sp?1:0)<<endl;
	cout << ptr->val << endl;
	return 0;
}

