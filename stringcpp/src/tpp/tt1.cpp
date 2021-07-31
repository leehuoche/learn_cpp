

typedef struct BST_ {
	int val;
	struct BST_* left;
	struct BST_* right;
}BST;

BST head;

class Listm {
public:
	Listm(int v) { val = v; }
	int val;
	struct Listm_* prev;
	struct Listm_* next;
};


Listm* Swap(Listm* head,BST* root) {
	if (root==nullptr) {
		head->next =nullptr;
	}

	Listm* cur = Swap(head,root->left);
	cur->next = new Listm(root->val);
	cur = cur->next;
	
	Swap(cur,root->right);
}

Listm* SwapToList(BST* root) {

	Listm* dummy = new Listm(0);
	Swap(dummy,root);

}