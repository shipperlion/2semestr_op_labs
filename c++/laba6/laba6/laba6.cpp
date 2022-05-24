#include "tree.h"

int main() {
	cout << "Enter the amount of tree elements: ";
	int n; cin >> n;
	Branch* root1 = NULL;
	int m;
	cout << "Enter the tree elements: ";
	for (int i = 0; i < n; i++) {
		cin >> m;
		AddElement(root1, m);
	}
	print_tree(root1);
	Branch* root2 = NULL;
	cout << "Enter the amount of tree elements: ";
	cin >> n;
	cout << "Enter the tree elements: ";
	for (int i = 0; i < n; i++) {
		cin >> m;
		AddElement(root2, m);
	}
	print_tree(root2);
	vector <int> base;
	pr_obh(root1, base);
	pr_obh(root2, base);
	Branch* root3 = NULL;
	for (const auto& i : base) {
		AddElement(root3, i);
	}
	cout << "Merged tree without duplication of elements: " << endl;
	print_tree(root3);
}