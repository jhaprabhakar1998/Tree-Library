#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class binary_tree{
public:
	T data;
	T restricatedData;
	
	binary_tree *left,*right,*root;
	binary_tree(){
		root=NULL;
		restricatedData=-1;	
	}

	binary_tree(T data){
		this->data=data;
		left=NULL;
		right=NULL;
		root=NULL;
	}


	void levelWiseInput(){
		T data;
		cin>>data;
		if(data==restricatedData)return;
		binary_tree* root=new binary_tree(data);
		queue<binary_tree*> storeNodes;

		storeNodes.push(root);
		while(!storeNodes.empty()){
			binary_tree* topNode=storeNodes.front();
			storeNodes.pop();	
			T leftVal,rightVal;
			cin>>leftVal>>rightVal;
			if(leftVal!=restricatedData){
				binary_tree* leftNode=new binary_tree(leftVal);
				topNode->left=leftNode;
				storeNodes.push(leftNode);
			}
			if(rightVal!=restricatedData){
				binary_tree* rightNode=new binary_tree(rightVal);
				topNode->right=rightNode;
				storeNodes.push(rightNode);
			}
		}
		this->root=root;
		return;
	}

	void printTree(binary_tree *root, int space=0){  
	    if (root == NULL) 
	        return; 
	    space += 10; 
	    printTree(root->right, space); 
	    cout<<endl;
	    for (int i = 10; i < space; i++) 
	        cout<<" "; 
	    cout<<root->data<<endl; 
	    printTree(root->left, space); 
	}	
	void printTree(){
		if (root == NULL) 
	        return; 
	    int space=0;
	    space += 10; 
	    printTree(root->right, space); 
	    cout<<endl;
	    for (int i = 10; i < space; i++) 
	        cout<<" "; 
	    cout<<root->data<<endl; 
	    printTree(root->left, space);
	}
};


int main(){
	binary_tree<int> intTree;
	intTree.levelWiseInput();
	intTree.printTree();
	cout<<endl<<endl<<endl;
	intTree.printTree(intTree.root);
}