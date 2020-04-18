// make_shared 2
#include <memory>
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	string name;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x,string _name) : val(x),left(nullptr),right(nullptr),name(_name) {}
};

void foo(shared_ptr<TreeNode> sp) {
	(sp->val)++;
}

int main() {
	// ()括号中的是模板类的类型的初始化函数
	auto sp = make_shared<TreeNode>(12,"good");
	auto ptr = sp;
	cout << ptr.use_count() << endl;
	auto p = ptr.get();
	cout << p->val << " " << p->name << endl;
	cout << ptr.use_count() << endl;
	foo(sp);
	cout << sp->val << endl;
	return 0;
}

