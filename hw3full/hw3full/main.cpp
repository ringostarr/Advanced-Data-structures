#include<cstdio>
#include<cstdlib>
#include <iostream>
#include <fstream>
#include<string>
#include <time.h>
using namespace std;
class BSTNode
{
public:
	int key;
	int data;
	BSTNode *left, *right;
};
BSTNode *newBSTNode(int item, int data)
{
	BSTNode *temp = new BSTNode();
	temp->key = item;
	temp->data = data;
	

	temp->left = temp->right = NULL;
	return temp;
}

BSTNode* inserttobst(BSTNode* n, int key, int data)
{
	if (n == NULL)
		return newBSTNode(key, data);
	if (key <= n->key)
		n->left = inserttobst(n->left, key, data);
	else
		n->right = inserttobst(n->right, key, data);
	return n;
}
BSTNode *deletefromBst(BSTNode *n, int key)
{
	if (!n) return NULL;
	if (n->key<key)
	{
		n->right = deletefromBst(n->right, key);
		return n;
	}
	else if (n->key>key)
	{
		n->left = deletefromBst(n->left, key);
		return n;
	}
	
	else
	{ 
		if (!n->left)
		{
			BSTNode *temp = n->right;
			delete n;
			return temp;
		}
		
		if (!n->right)
		{
			BSTNode *temp = n->left;
			delete n;
			return temp;
		}
		
		BSTNode *temp = n->right;
		while (temp->left) temp = temp->left;
		temp->left = n->left;
		temp = n->right;
		delete n;
		return temp;
	}
}

int kn(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1000;
	else
	{
		return ((kn(n - 1) + kn(n - 2)) / 2);
	}
}
static int i = 0;
void createthefile(BSTNode *x, fstream &out,string filename)
{
	if (x->left != NULL)
		{
			out << "node" << to_string(x->key) + to_string(x->data) << "[label=\"" << x->key << " " << x->data << "\"]" << "\n" << "node" << to_string(x->left->key) + to_string(x->left->data) << "[label=\"" << x->left->key << "|" << x->left->data << "\"]\n";
			out << "node" << to_string(x->key) + to_string(x->data) << "->" << "node" << to_string(x->left->key) + to_string(x->left->data) << "\n";

			createthefile(x->left, out,filename);
		}
	else
	{
		out << "node" << to_string(x->key) + to_string(x->data) << "[label=\"" << x->key << " " << x->data << "\"]" << "\n" << "null" << i << "[style=\"invis\"]\n";
		out << "node" << to_string(x->key) + to_string(x->data) << "->" << "null" << i << "\n";
		i++;

	}
		if (x->right != NULL) {
			out << "node" << to_string(x->key) + to_string(x->data) << "[label=\"" << x->key << " " << x->data << "\"]" << "\n" << "node" << to_string(x->right->key) + to_string(x->right->data) << "[label=\"" << x->right->key << "|" << x->right->data << "\"]\n";
			out << "node" << to_string(x->key) + to_string(x->data) << "->" << "node" << to_string(x->right->key) + to_string(x->right->data) << "\n";

			createthefile(x->right, out, filename);
		}
		else {
			out << "node" << to_string(x->key) + to_string(x->data) << "[label=\"" << x->key << " " << x->data << "\"]" << "\n" << "null" << i << "[style=\"invis\"]\n";
			out << "node" << to_string(x->key) + to_string(x->data) << "->" << "null" << i << "\n";
			i++;
		}
	
		
}

int Height(BSTNode* node)
{
	if (node == NULL)
		return -1;
	else
	{
		
		int lD = Height(node->left);
		int rD = Height(node->right);

		if (lD > rD)
			return(lD + 1);
		else return(rD + 1);
	}
}
 BSTNode* SearchBST( BSTNode* root, int key)
{
	
	if (root == NULL || root->key == key)
		return root;

	
	if (root->key < key)
		return SearchBST(root->right, key);

	
	return SearchBST(root->left, key);
}
 // Copies point p2 to p1
 const int k = 2;


 class KDNode
 {
 public:
	 int key[k];
	 int data;
	 KDNode *left, *right;
 };


 KDNode* CreateKDNode(int arr[], int data)
 {
	 KDNode* temp = new KDNode;

	 for (int i = 0; i<k; i++)
		 temp->key[i] = arr[i];
	 temp->data = data;
	 temp->left = temp->right = NULL;
	 return temp;
 }
 int maxDepth(KDNode* node)
 {
	 if (node == NULL)
		 return -1;
	 else
	 {

		 int lDepth = maxDepth(node->left);
		 int rDepth = maxDepth(node->right);


		 if (lDepth > rDepth)
			 return(lDepth + 1);
		 else return(rDepth + 1);
	 }
 }

 KDNode *insertRec(KDNode *n, int key[], unsigned depth, int d)
 {
	 if (n == NULL)
		 return CreateKDNode(key, d);


	 unsigned curdim = depth % k;


	 if (key[curdim] <= (n->key[curdim]))
		 n->left = insertRec(n->left, key, depth + 1, d);
	 else
		 n->right = insertRec(n->right, key, depth + 1, d);

	 return n;
 }


 KDNode* insert(KDNode *nodex, int key[], int d)
 {
	 return insertRec(nodex, key, 0, d);
 }


 bool arekeysSame(int key1[], int key2[])
 {

	 for (int i = 0; i < k; ++i)
		 if (key1[i] != key2[i])
			 return false;

	 return true;
 }


 bool searchRec(KDNode* root, int key[], unsigned depth)
 {

	 if (root == NULL)
		 return false;
	 if (arekeysSame(root->key, key))
		 return true;


	 unsigned curdim = depth % k;


	 if (key[curdim] < root->key[curdim])
		 return searchRec(root->left, key, depth + 1);

	 return searchRec(root->right, key, depth + 1);
 }


 bool search(KDNode* root, int key[])
 {

	 return searchRec(root, key, 0);
 }
 int xn(int d)
 {
	 if (d == 0)
		 return 0;
	 else if (d == 1)
		 return 500;
	 else
		 return((xn(d - 1) + xn(d - 2)) / 2);
 }
 static int j = 0;
 void createfile(KDNode *x, fstream &out, string filename)
 {



	 if (x->left != NULL)
	 {
		 out << "node" << to_string(x->key[0]) + to_string(x->data) + to_string(x->key[1]) << "[label=\"" << x->key[0] << "|" << x->key[1] << "|" << x->data << "\"]" << "\n" << "node" << to_string(x->left->key[0]) + to_string(x->left->data) + to_string(x->left->key[0]) << "[label=\"" << x->left->key[0] << "|" << x->left->key[1] << "|" << x->left->data << "\"]\n";
		 out << "node" << to_string(x->key[0]) + to_string(x->data) + to_string(x->key[1]) << "->" << "node" << to_string(x->left->key[0]) + to_string(x->left->data) + to_string(x->left->key[0]) << "\n";

		 createfile(x->left, out, filename);
	 }
	 else
	 {
		 out << "node" << to_string(x->key[0]) + to_string(x->data) + to_string(x->key[1]) << "[label=\"" << x->key[0] << "|" << x->key[1] << "|" << x->data << "\"]" << "\n" << "null" << j << "[style=\"invis\"]\n";
		 out << "node" << to_string(x->key[0]) + to_string(x->data) + to_string(x->key[1]) << "->" << "null" << j << "\n";
		 j++;

	 }
	 if (x->right != NULL) {
		 out << "node" << to_string(x->key[0]) + to_string(x->data) + to_string(x->key[1]) << "[label=\"" << x->key[0] << "|" << x->key[1] << "|" << x->data << "\"]" << "\n" << "node" << to_string(x->right->key[0]) + to_string(x->right->data) + to_string(x->right->key[1]) << "[label=\"" << x->right->key[0] << "|" << x->right->key[1] << "|" << x->right->data << "\"]\n";
		 out << "node" << to_string(x->key[0]) + to_string(x->data) + to_string(x->key[1]) << "->" << "node" << to_string(x->right->key[0]) + to_string(x->right->data) + to_string(x->right->key[1]) << "\n";

		 createfile(x->right, out, filename);
	 }
	 else {
		 out << "node" << to_string(x->key[0]) + to_string(x->data) + to_string(x->key[1]) << "[label=\"" << x->key[0] << "|" << x->key[1] << "|" << x->data << "\"]" << "\n" << "null" << j << "[style=\"invis\"]\n";
		 out << "node" << to_string(x->key[0]) + to_string(x->data) + to_string(x->key[1]) << "->" << "null" << j << "\n";
		 j++;
	 }


 }
 int yn(int d)
 {
	 return (500 - xn(d));
 }
 KDNode *minNode(KDNode *x, KDNode *y, KDNode *z, int d)
 {
	 KDNode *res = x;
	 if (y != NULL && y->key[d] < res->key[d])
		 res = y;
	 if (z != NULL && z->key[d] < res->key[d])
		 res = z;
	 return res;
 }
 KDNode *MinNextNode(KDNode* root, int d, unsigned depth)
 {

	 if (root == NULL)
		 return NULL;


	 unsigned curdim = depth % k;


	 if (curdim == d)
	 {
		 if (root->left == NULL)
			 return root;
		 return MinNextNode(root->left, d, depth + 1);
	 }



	 return minNode(root,
		 MinNextNode(root->left, d, depth + 1),
		 MinNextNode(root->right, d, depth + 1), d);
 }

 void copynode(int p1[], int p2[])
 {
	 for (int i = 0; i<k; i++)
		 p1[i] = p2[i];
 }
 KDNode *kddeleteRec(KDNode *nodex, int key[], int depth)
 {

	 if (nodex == NULL)
		 return NULL;


	 int curdim = depth % k;


	 if (arekeysSame(nodex->key, key))
	 {

		 if (nodex->right != NULL)
		 {

			 KDNode *nextmin = MinNextNode(nodex->right, curdim, curdim + 1);


			 copynode(nodex->key, nextmin->key);


			 nodex->right = kddeleteRec(nodex->right, nextmin->key, depth + 1);
		 }
		 else if (nodex->left != NULL)
		 {
			 KDNode *nextmin = MinNextNode(nodex->left, curdim, curdim + 1);
			 copynode(nodex->key, nextmin->key);
			 nodex->right = kddeleteRec(nodex->left, nextmin->key, depth + 1);
			 nodex->left = NULL;
		 }
		 else
		 {
			 delete nodex;
			 return NULL;
		 }
		 return nodex;
	 }


	 if (key[curdim] < nodex->key[curdim])
		 nodex->left = kddeleteRec(nodex->left, key, depth + 1);
	 else
		 nodex->right = kddeleteRec(nodex->right, key, depth + 1);
	 return nodex;
 }



 KDNode* kddelete(KDNode *nodex, int key[])
 {

	 return kddeleteRec(nodex, key, 0);
 }


int main()
{

	BSTNode *root = NULL;

	//TEST CASE 1
	for (int i = 0; i <= 15; i++)
	{
		root = inserttobst(root, kn(i), i);
		//cout << kn(i) << "  " << i << "\n";
	}
	fstream outx1;
	string filename = "t1.dot";
	outx1.open("t1.dot", ios::out);
	outx1 << "digraph t1 { \n";
	createthefile(root, outx1, filename);
	outx1 << "};";
	outx1.close();
	cout << "t1.dot Created \n";
	cout << "---------------------------------------------------------------------------\n";
	//TestCase 2
	KDNode *root2 = NULL;
	int keys[16][k];
	for (int i = 0; i < 16; i++)
	{
		keys[i][0] = xn(i);
		keys[i][1] = yn(i);
	}
	int vals[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int n = sizeof(keys) / sizeof(keys[0]);
	for (int i = 0; i < n; i++) {
		root2 = insert(root2, keys[i], i);
		//cout << i;
	}
	fstream outx;
	 filename = "t2.dot";
	outx.open("t2.dot", ios::out);
	outx << "digraph t1 { \n";
	createfile(root2, outx, filename);
	outx << "};";
	outx.close();
	cout << "t2.dot Created \n";
	cout << "---------------------------------------------------------------------------\n";
	//TEST CASE 3

	BSTNode *root3 = NULL;
	int rn[200];
	bool dup;
	 int MAX=1000; 

	int value[200]; 
	srand(time(NULL));

	for (int i = 0; i<200; i++)
	{
		bool check; 
		int n; 
		do
		{
			n = rand() % MAX;
			
			check = true;
			for (int j = 0; j<i; j++)
				if (n == value[j]) 
				{
					check = false; 
					break; 
				}
		} while (!check); 
		value[i] = n; 
	}
	cout << "\n\n";
	cout << "---------------------------------------------------------------------------------\n";
	cout << "n=Number of nodes in the tree      Height of BST     lgN            rootN\n";
	cout << "---------------------------------------------------------------------------------\n";
	cout << "                          " << 0 << "              " << "nil" << "           " << log(0) << "           " <<  sqrt(0) << "\n";
	for (int i = 1; i <= 200; i++)
	{
		if (i % 20==0)

		{
			int depth = Height(root3);
			cout << "                          " << i << "              "<<depth<<"           "<<log(i)<<"        "<<sqrt(i)<<"\n";
		}
		int num = rand() % 3000;
		root3 = inserttobst(root3, value[i], num);
		
	}
	//TestCase4
	 MAX = 50;
	int max2 = 50;
	int value11[200][2];
	srand(time(NULL));
	KDNode *root4 = NULL;
	for (int i = 0; i<200; i++)
	{
		bool check;
		int n, n2;
		do
		{
			n = rand() % MAX;
			n2 = rand() % max2;
			check = true;
			for (int j = 0; j<i; j++)
				if (n == value11[j][0] && n == value11[j][1])
				{
					check = false;
					break;
				}
		} while (!check);
		value11[i][0] = n;
		value11[i][1] = n2;
		//cout << n << " " << n2 << "\n";
	}
	int dep = 0;
	cout << "\n\n-----------------------------------------------------------------------------------------------------------------\n";
	cout << "n = No. of Nodes in the tree              Height of BST T3               lg n               root n";
	cout << "\n-----------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 200; i++)
	{
		dep = maxDepth(root4);
		if (i % 20 == 0) {
			cout << "                         " << i << "                    " << dep <<"                    "<<log(i)<<"                 "<<sqrt(i)<< "\n";
		}
		int r = rand() % 1000;
		root4 = insert(root4, value11[i], i);
		if (i == 199) {
			cout << "                         " << i + 1 << "                    " << dep << "                    "<<log(i+1)<<"                 "<<sqrt(i+1)<<"\n";
		}
	}
	//TEST CASE 5
	MAX = 15;

	int valuex[10];
	srand(time(NULL));
	BSTNode *root5 = NULL;
	for (int i = 0; i<10; i++)
	{
		bool check;
		int n;
		do
		{
			n = rand() % MAX;

			check = true;
			for (int j = 0; j<i; j++)
				if (n == valuex[j])
				{
					check = false;
					break;
				}
		} while (!check);
		valuex[i] = n;
	}
	for (int i = 0; i < 10; i++)
	{
		root5 = inserttobst(root5, kn(valuex[i]), valuex[i]);
	}
	 outx;
	 filename = "t5-a.dot";
	outx.open("t5-a.dot", ios::out);
	outx << "digraph t1 { \n";
	createthefile(root5,outx,filename);
	outx << "};";
	outx.close();
	cout << "\n------------------------------------------------------------------\n";
	cout << "t5-a.dot Created\n";
root5 =	deletefromBst(root5, valuex[0]);
	filename = "t5-b.dot";
	outx.open("t5-b.dot", ios::out );
	outx << "digraph t1 { \n";
	createthefile(root5, outx,filename);
	outx << "};";
	outx.close();
	cout << "t5-b.dot Created\n";
	cout << "-------------------------------------------------------------------------\n";
	//TestCase 6
	int list[10][2];
	KDNode *root6 = NULL;
	for (int i = 0; i < 10; i++)
	{
		bool check;
		do
		{
			n = rand() % 10;
			//n2 = rand() % max2;
			check = true;
			for (int j = 0; j<i; j++)
				if (list[j][0] == keys[n][0] && list[j][1] == keys[n][1])
				{
					check = false;
					break;
				}
		} while (!check);
		list[i][0] = keys[n][0];
		list[i][1] = keys[n][1];
		//cout << list[i][0] << " " << list[i][1]<<"\n";
		//	cout << "\n";
	}
	int dat = 0;
	for (int i = 0; i < 10; i++)
	{
		dat = xn(i);
		int dat2 = yn(i);
		for (int j = 0; j < 15; j++)
		{
			if (list[j][0] == dat&&list[j][1] == dat2)
			{
				root6 = insert(root6, list[i], j);
				break;
			}
		}
	}
	// outx;
	filename = "t6-a.dot";
	outx.open("t6-a.dot", ios::out);
	outx << "digraph t1 { \n";
	createfile(root6, outx, filename);
	outx << "};";
	outx.close();
	cout << "\n------------------------------------------------------------------\n";
	cout << "t6-a.dot Created\n";
	root6 = kddelete(root6, root6->key);
	filename = "t6-b.dot";
	outx.open("t6-b.dot", ios::out);
	outx << "digraph t1 { \n";
	createfile(root6, outx, filename);
	outx << "};";
	outx.close();
	
	cout << "t6-b.dot Created\n";
	cout << "------------------------------------------------------------------\n";
	BSTNode *searchednode = NULL;
	//TESTCASE 7
	int key = 0;
	BSTNode *root7 = NULL;
	for (int i = 0; i < 10; i++)
	{
		root7=inserttobst(root7, kn(i + 1), i + 1);
	}
	for (int i = 0; i < 10; i++)
	{
		root7=inserttobst(root7, kn(i + 1), i + 11);
		
	}
	
	cout << "\n\n------------------------------------------------------------------------------------------------------------------------";
	cout << "Stage                  data item at root             the root(after deletion                  searchData with key";
	cout << "\n---------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 20; i++)
	{
		cout << i << "                          "<<root7->key<<"  "<<root7->data;
		key = root7->key;
		root7 = deletefromBst(root7, root7->key);
		
		if (root7 == NULL)
		{
			cout << "                             NIL";
		}
		else
		cout << "                         " << root7->key << "  " << root7->data ;
		
		
		searchednode=SearchBST(root7, key);
		if (searchednode != NULL)
			cout << "                           " << searchednode->key << "   " << searchednode->data << "\n";
		else
			cout << "                                nil\n";
		if (i == 10)
		{
			filename = "t7.dot";
			outx.open("t7.dot", ios::out);
			outx << "digraph t1 { \n";
			createthefile(root7, outx, filename);
			outx << "};";
			outx.close();
			cout << "t7.dot Created\n";
		}
		
	}
	
	cout << "------------------------------------------------------------------\n";
	//TestCase8
	int keys8[18][2];
	KDNode *root8 = NULL;
	cout << "\n\n\n\n";
	for (int i = 0; i < 18; i++)
	{
		if (i < 6)
		{
			keys8[i][0] = xn(i + 1);
			keys8[i][1] = yn(i + 1);

		}
		else if (i >= 6 && i < 12)
		{
			keys8[i][0] = xn(i - 5);
			keys8[i][1] = yn(i);

		}
		else
		{
			keys8[i][0] = xn(i - 5);
			keys8[i][1] = yn(i - 12);


		}

	}
	for (int i = 0; i < 18; i++)
	{
		root8 = insert(root8, keys8[i], i + 1);
	}
	int m = 18;
	int keyx[2];
	while (root8 != NULL)
	{
		keyx[0] = root8->key[0];
		keyx[1] = root8->key[1];
		int da = root->data;
		//cout << root8->key[0] << "  " << root8->key[1]<<"  " << root8->data << "\t";
		root8 = kddelete(root8, root8->key);

		bool s = search(root8, keys8[m]);
		if (s == true)
		{
			cout << keys8[m][0] << " " << keys8[m][1] << " " << m << "\n";

		}
		else
		{
			cout << "NIL\n";

		}
		if (m == 13)
		{
			filename = "t8.dot";
			outx.open("t8.dot", ios::out);
			outx << "digraph t1 { \n";
			createfile(root8, outx, filename);
			outx << "};";
			outx.close();
			cout << "\n------------------------------------------------------------------\n";
			cout << "t8.dot Created   :: : : : : : Elements remaining = "<<m-1<<"\n";
			cout << "------------------------------------------------------------------\n";
		}
		m--;
	}
}