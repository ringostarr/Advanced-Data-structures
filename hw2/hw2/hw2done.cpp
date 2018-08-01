#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define N 10000 
class node
{
public:
	int key;
	
	vector<int> a;
};
node n1[N];
node n3[N];
node n4[N];
node n5[N];
node n6[N];
int Hsize = 0;
int parent(int i)
{
	return ceil(i / 2.0 - 1);
}

void displayv(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\t";
}
void decreaseKey(int i, node n,node n2[])
{
	if (n.key > n2[i].key)
	{
		cout << "err\n";
		return;
	}
	n2[i] = n;
	while (i > 0 && n2[parent(i)].key > n2[i].key)
	{
		std::swap(n2[i], n2[parent(i)]);
		i = parent(i);
		/*if (n.key == n2[i].key)
		{
			n2[i].a.push_back(n.data);
		}*/
	}
}

int searchindex(node n, node n2[])
{
	for(int i=0;i<Hsize;i++)
{
		if (find(n2[i].a.begin(),n2[i].a.end(),n.a[0])!=n2[i].a.end())//n2[i].data == n.data)
			return i;
}
	return Hsize;
}


void heapify(int i, node n2[])
{
	int max;
	int l = 2 * i + 1;

	if (l < Hsize && n2[l].key < n2[i].key)
		max = l;
	else
		max = i;
	int r = 2 * i + 2;

	if (r < Hsize && n2[r].key < n2[max].key)
		max = r;

	if (max != i)
	{
		std::swap(n2[i], n2[max]);
		heapify(max,n2);
	}
}

node retminimum(node n2[])
{
	return n2[0];
}

void InToHeap(node n, node n2[])
{
		++Hsize;
		n2[Hsize - 1].key = INT_MAX;
		decreaseKey(Hsize - 1, n,n2);
}

void extractallmin(node n2[])
{
	if (Hsize <= 0)
	{
		cout << "all extracted\n";
		return;
	}

	node min = n2[0];
	n2[0] = n2[Hsize - 1];
	--Hsize;		
	heapify(0,n2);
	cout << "Extracted :" << min.key << "    " ;
	displayv(min.a);
	if (n2[0].key == min.key)
		extractallmin(n2);
	
	//return min;
}
void displayPQ(node n2[])
{
	cout << "\n\n\nPrio Queue:\n";
	for (int i = 0; i < Hsize; i++)
	{
		cout << n2[i].key << "----";
		displayv(n2[i].a);
		cout << endl;
	}
	//heapify(0);
	/*while (Hsize)
	{
		node extracted = extractallmin();
		cout << extracted.key << "-----" << extracted.a[0]<<endl;

	}*/
}
void allminimum(node n2[])
{
	if (Hsize == 0) {
		cout << "Underflow" << endl;
		//continue;
	}
	else
		cout << "All Minimum:" << n2[0].key << "-----" << n2[0].a[0] << endl;
}
void decreasekeyax(int keyx, int data, node a[], node n2[])
{
	
	for (int i = 0; i < Hsize; i++)
	{
		if (Hsize == 0)
		{
			cout << "No Items in PQ" << endl;
			break;
		}
		vector<int>::iterator it = find(a[i].a.begin(), a[i].a.end(), data);
		if (it != a[i].a.end())
		{
			a[i].key = keyx;
			heapify(i,n2);
		}
	}

}


int countx;
vector<int> leonardonums;
typedef pair < int, int > pair_input;
int chck = 0;
//stack<pair_input> stack_input;
temp1late <class T>
class Stack {
private:
	vector<T> elems;     // elements 

public:
	void push(T const&);  // push element 
	void pop();               // pop element 
	T top() const;            // return top element 
	bool empty() const {       // return true if empty.
		return elems.empty();

	}
	int size();
};

temp1late <class T>
void Stack<T>::push(T const& elem) {
	// append copy of passed element 
	elems.push_back(elem);
}

temp1late <class T>
void Stack<T>::pop() {
	if (elems.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}

	// remove last element 
	elems.pop_back();
}

temp1late <class T>
T Stack<T>::top() const {
	if (elems.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}

	// return copy of last element 
	return elems.back();
}
temp1late <class T>
int Stack<T>::size() {



	return elems.size();
}
//IntStack stack_input(10000000);
//vector<IntStack> stack_input;
Stack<pair_input> stack_input;
void insertintoheap(int initial, int part_int, int part_out, vector<int> &inputarray)
{
	int left_out, right_out, left_in, right_in;
	left_out = part_out - 1;
	right_out = part_out - 2;
	//countx++;
	//countx++;
	if (left_out >= 0 && right_out >= 0)
	{
		left_in = part_int - leonardonums[right_out] - 1;
		right_in = part_int - 1;

		while (part_int != initial && part_int != initial + 1)
		{
			//countx++;
			if (inputarray[left_in] > inputarray[right_in])
			{
				//countx++;
				if (inputarray[left_in] > inputarray[part_int])
				{
					int temp1 = inputarray[part_int];
					inputarray[part_int] = inputarray[left_in];
					inputarray[left_in] = temp1;
					//countx++;
					if (initial != left_in)
						insertintoheap(initial, left_in, left_out, inputarray);
				}
			}
			else if (inputarray[right_in] > inputarray[part_int])
			{
				//countx++;
				int temp1 = inputarray[part_int];
				inputarray[part_int] = inputarray[right_in];
				inputarray[right_in] = temp1;
				//countx++;
				if (initial + 1 != right_in)
					insertintoheap(left_in + 1, right_in, right_out, inputarray);
			}
			break;
		}
	}
}

void sort_root(vector<int> &v)
{
	vector<pair_input> inputarray, temp1;
	vector<pair_input>::iterator it;
	pair_input pop;
	while (stack_input.size() != 0)
	{
		//countx++;
		pop = stack_input.top();
		temp1.push_back(pop);
		stack_input.pop();
	}
	while (temp1.size() != 0)
	{
		//countx++;
		inputarray.push_back(temp1[temp1.size() - 1]);
		temp1.pop_back();
	}
	size_t min = 0;
	for (int i = 0; i < inputarray.size() - 1; i++)
	{
		//countx++;
		min = i;
		for (int j = i + 1; j < inputarray.size(); ++j)
		{


			if (v[inputarray[j].second] < v[inputarray[min].second])
			{
				//countx++;
				chck = 1;
				min = j;
			}
		}
		int idx = inputarray[min].second;
		int temp1 = v[idx];
		int idx1 = inputarray[i].second;
		int temp11 = v[idx1];
		v[inputarray[i].second] = temp1;
		v[inputarray[min].second] = temp11;
	}
	for (int i = 0; i < inputarray.size(); i++)
	{
		stack_input.push(inputarray[i]);
	}
}


void insert(vector<int> &value)
{
	int len = value.size();
	int count = 0, cond = 2;

	//default
	if (value.size() == 0 || value.size() == 1)
	{
		return;
	}

	while (count < len)
	{

		int lchildo = -1, rchildo = -1, lchildi = -1, rchildi = -1;
		pair_input pop1, pop2;
		pop1.first = -1;
		pop1.second = -1;
		pop2.first = -1;
		pop2.second = -1;

		//0.0

		if (stack_input.size() != 0 && lchildo == -1)
		{

			pop1 = stack_input.top(); stack_input.pop();

			if (stack_input.size() != 0)
			{
				pop2 = stack_input.top(); stack_input.pop();

				if (abs(pop1.first - pop2.first) == 1)
				{
					rchildo = pop1.first;
					rchildi = pop1.second;

					lchildo = pop2.first;
					lchildi = pop2.second;
				}
				else
				{
					stack_input.push(pop2);
					lchildo = pop1.first;
					lchildi = pop1.second;
				}
			}
			else
			{
				lchildo = pop1.first;
				lchildi = pop1.second;
			}
		}
		//1.1  1.2

		if (lchildo >= 0 && rchildo >= 0)
		{
			//++;
			if ((lchildo - rchildo) == 1)
			{
				insertintoheap((count + 1) - leonardonums[lchildo + 1], count, lchildo + 1, value);


				//END
				pair_input temp1(++lchildo, count);
				stack_input.push(temp1);
				lchildo = -1; rchildo = -1;
				lchildi = -1; rchildi = -1;
				cond = 1;
			}
			//1.3
			else
			{
				stack_input.push(make_pair(lchildo, lchildi));
				lchildo = rchildo; lchildi = rchildi;
				rchildo = -1; rchildi = -1;
				cond = 2;
			}
		}
		//2.1

		else if (cond == 2)
		{
			//++;
			if (lchildo == -1)
			{
				lchildo = 1;
				lchildi = count;
				stack_input.push(make_pair(lchildo, lchildi));
			}
			else
			{
				//++;
				if (lchildo != 1)
				{
					rchildo = 1;
				}
				else
				{
					rchildo = 0;
				}
				rchildi = count;

				stack_input.push(make_pair(lchildo, lchildi));
				stack_input.push(make_pair(rchildo, rchildi));
			}
		}

		//3.0
		do
		{
			//++;
			chck = 0;
			vector<pair_input> pairs;
			sort_root(value); // yes = cond_test = 1;
							  //++;
			if (chck == 1)
			{
				while (stack_input.size() != 0)
				{
					pairs.push_back(stack_input.top());
					stack_input.pop();
				}
				for (int i = 1; i < pairs.size(); i++)
				{
					insertintoheap((pairs[i].second + 1) - leonardonums[pairs[i].first], pairs[i].second, pairs[i].first, value);
				}

				for (int i = pairs.size() - 1; i >= 0; i--)
				{
					stack_input.push(pairs[i]);
				}
			}

		} while (chck == 1);
		cond = 2;
		count++;
	}
}

void dequeue(vector<int> &value)
{
	size_t count = value.size();
	vector<pair_input> store;
	pair_input pop1;
	int left_out, right_out, left_in, right_in;

	while (count != 0)
	{

		pop1 = stack_input.top();
		stack_input.pop();
		if (pop1.first == 1 || pop1.first == 0)
		{
			count--;
		}
		else
		{
			left_out = pop1.first - 1;
			right_out = pop1.first - 2;

			left_in = pop1.second - leonardonums[right_out] - 1;
			right_in = pop1.second - 1;

			stack_input.push(make_pair(left_out, left_in));
			stack_input.push(make_pair(right_out, right_in));

			do
			{
				//++;
				chck = 0;
				vector<pair_input> pairs;
				sort_root(value); // yes = cond_test = 1;
				if (chck == 1)
				{
					while (stack_input.size() != 0)
					{
						pairs.push_back(stack_input.top());
						stack_input.pop();
					}
					for (int i = 1; i < pairs.size(); i++)
					{
						insertintoheap((pairs[i].second + 1) - leonardonums[pairs[i].first], pairs[i].second, pairs[i].first, value);
					}

					for (int i = pairs.size() - 1; i >= 0; i--)
					{
						stack_input.push(pairs[i]);
					}
				}

			} while (chck == 1);
			count--;
		}
	}
}


int main()
{
	
	node n;
	int i = 0;
	int j = 1, k = 100;
	cout << "TESTCASE 1 " << endl;
	for (i = 0; i <100; i++)
	{
		
		n1[i].key =k;
		n1[i].a.push_back(j);// = j;
		j++;
		k--;
		//cout << n2[i].key;
		InToHeap(n1[i],n1);
	}
	extractallmin(n1);
	n.key = 1;
	n.a.push_back(0);
	InToHeap(n,n1);
	extractallmin(n1);
	//TESTCASE 1 END
	//deleteall();
	cout << "TESTCASE 2" << endl;
	j = 1000, k = 1;
	Hsize = 0;
	for (i = 0; i < 1000; i++)
	{
		n3[i].key = j;
		n3[i].a.push_back(k);
		InToHeap(n3[i],n3);
		j--;
		k++;

	}
	//displayPQ();
	allminimum(n3);
	for (int x = 0; x < 30; x++)
	{
		n3[i].key = 1;
		n3[i].a.push_back(x + 1);
		InToHeap(n3[i],n3);
		i++;

	}
	extractallmin(n3);
	//displayPQ();
	allminimum(n3);
	//TESTCASE 2 END
	
	cout << "TESTCASE 3 " << endl;
	for (i = 0; i < 500;i++)
	{
		int k = rand() % 1000;
		int p = rand() % 1000;
		if (k >= 10 && p >= 10 && k <= 1000 && j <= 1000)
		{
			n4[i].key = p;
			n4[i].a.push_back(k);
			InToHeap(n4[i],n4);
			
		}
		else
		{
			
		}
	
	}
	//displayPQ();
	extractallmin(n4);
	extractallmin(n4);
	extractallmin(n4);
	extractallmin(n4);
	extractallmin(n4);
	int r = rand() % 500;
	cout << "decreasekey:" << n4[r].key<<" to "<<n4[r].key-5 << endl;
	decreaseKey(searchindex(n4[r], n4), { n4[r].key - 5,n4[r].a }, n4);
	allminimum(n4);
	//TESTCASE 3 END
	//deleteall();
	//Hsize = 0;
	//TEstCASE 4 initial
	Hsize = 0;
	for (i = 0; i < 500;)
	{
		int k = rand() % 1000;
		int p = rand() % 1000;
		if (k >= 10 && p >= 10 && k <= 1000 && j <= 1000)
		{
			n5[i].key = p;
			n5[i].a.push_back(k);
			InToHeap(n5[i],n5);
			i++;
		}

	}
	for (int l = 0; l < 10; l++)
	{
		int r = rand() % 500;
		int np = rand() % 9;
	//	cout << "decreasekey:" << n2[r].key << endl;
		cout << "decreasing key : " << n5[r].key<<"----";
			displayv(n5[r].a);
			cout << "  to   " << np << "-------";
			displayv(n5[r].a);
			cout<< endl;
		//decreasekeyax(np, n2[r].a[0],n2);
		decreaseKey(searchindex(n5[r],n5), { np,n5[r].a },n5);

	}
	//extractallmin(n2);
	for (int l = 0; l < 10; l++)
	{
		extractallmin(n5);
		//decreaseKey(np, n2[r]);
	}
	//TESTCASE 4 END
	//deleteall();
	//TESTCASE 5 initial
	cout << "TESTCASE5" << endl;
	Hsize = 0;
	
	for (i = 0; i < 100; i++)
	{
		cout << endl << endl;
		cout << "operation number:" << i+1;
		int m = rand() % 4;
		
		if (m == 0) {

			k = rand() % 1000;
			int p = rand() % 1000;
			if (k >= 10 && p >= 10 && k <= 1000 && j <= 1000)
			{
				cout << "---->Inserting to PriorityQueue : ";
				;
				n6[i].key = p;
				n6[i].a.push_back(k);
				cout << n6[i].key;
				cout << "----" << k;
				InToHeap(n6[i],n6);
				cout << endl;
			}
			else
			{
				i--;
			}
		}
			
		else if (m == 1) {
			if (Hsize == 0)
				cout << "Nothing to extract" << endl;
			else
			{
				cout << "--->Extracting all min" << endl;
				extractallmin(n6);
			}
			
			//break;
		}
		else if (m == 2) {
			cout << "-->AllMin" << endl;
			allminimum(n6);
		
		}
		else if(m==3)
		{
			if (Hsize == 0)
			{
				cout << "empty PQ , Underflow" << endl;
				//break;
			}
			else {
				int r = rand() % Hsize;
				int np = rand() % 9;
				//	cout << "decreasekey:" << n2[r].key << endl;
				cout << "---->decreasing key : " << n6[r].key << "  to   " << np << endl;
				//decreasekeyax(np, n2[r].a[0],n2);
				decreaseKey(searchindex(n6[r], n6), { np,n6[r].a }, n6);
			}
		}
		if (i == 19 || i == 39 || i == 59 || i == 79 || i == 99)
			displayPQ(n6);
	}
	leonardonums.push_back(1);
	leonardonums.push_back(1);

	countx = 0;
	int fir = 1, sec = 1, sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (i <= 1)
			sum = i;
		else
		{
			sum = fir + sec + 1;
			fir = sec;
			//cout << sum;
			leonardonums.push_back(sum);
			sec = sum;
		}
	}
	vector<int> inputarray;

	for (int i = 1000; i >= 1; i--)
	{
		inputarray.push_back(i);

	}
	insert(inputarray);
	dequeue(inputarray);

	for (int i = 0; i < inputarray.size(); i++)
	{
		if (i % 20 == 0)
			cout << inputarray[i] << "   ";
	}
	cout << endl;
	inputarray.clear();
	cout << "comparisions" << countx << endl;;
	countx = 0;




	//cout << countx << endl;
	//TESTCASE 7
	for (int i = 0; i < 2000; i++)
	{
		inputarray.push_back(i + 1);
	}
	//int arr[19];
	int temp1;
	for (int i = 0; i < 20; i++)
	{
		int x = rand() % 2000;
		int y = rand() % 2000;
		if (x != y && x != 0 && y != 0)
		{
			temp1 = inputarray[x];
			inputarray[x] = inputarray[y];
			inputarray[y] = temp1;
			i++;
		}
		else
		{
			i--;
		}
	}
	insert(inputarray);
	dequeue(inputarray);
	for (int i = 0; i < inputarray.size(); i++)
	{
		if (i % 20 == 0)
			cout << inputarray[i] << "   ";

	}
	cout << endl;
	cout << "comparisons:" << countx << endl;;
	inputarray.clear();
	countx = 0;
	//TESTCASE 8
	for (int i = 1; i <= 2000; i++)
	{
		inputarray.push_back(i);
	}
	int arr[60];
	for (int i = 0; i < 60; i++)
	{
		int x = rand() % 2000;
		int y = rand() % 2000;
		int z = rand() % 2000;
		int temp1;
		for (int i = 0; i < 60; i++)
		{
			if (arr[i] == inputarray[x] || arr[i + 1] == inputarray[y] || arr[i + 2] == inputarray[z])
				i = i - 2;
			else
			{
				if (x != y &&y != z)
				{
					arr[i] = inputarray[x];
					arr[i + 1] = inputarray[y];
					arr[i + 2] = inputarray[z];
					i++; i++;
				}
				else
				{
					i--;
				}
				temp1 = inputarray[x];
				inputarray[x] = inputarray[y];
				inputarray[y] = temp1;

			}
		}

	}
	insert(inputarray);
	dequeue(inputarray);
	for (int i = 0; i < inputarray.size(); i++)
	{
		if (i % 20 == 0)
			cout << inputarray[i] << "   ";

	}
	inputarray.clear();
	cout << "comparisons:" << countx << endl;;
	countx = 0;
	//TEST CASE 9
	for (int i = 0; i < 3193; i++)
	{
		inputarray.push_back(rand() % 10000);
	}
	insert(inputarray);
	dequeue(inputarray);
	for (int i = 0; i < inputarray.size(); i++)
	{
		if (i % 20 == 0)
			cout << inputarray[i] << "   ";

	}
	cout << endl;
	cout << "comparisons:" << countx << endl;;
	inputarray.clear();
	countx = 0;
	//TESTCASE10
	for (int i = 0; i < 5166; i++)
	{
		inputarray.push_back(rand() % 10000);
	}
	insert(inputarray);
	dequeue(inputarray);
	for (int i = 0; i < inputarray.size(); i++)
	{
		if (i % 20 == 0)
			cout << inputarray[i] << "   ";

	}
	cout << endl;
	cout << "comparisons:" << countx << endl;;
	inputarray.clear();
	
}
