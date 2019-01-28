#include<iostream>
#include<string>
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

	binary_tree* getRoot(){
		return root;
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
	int space=0;
	void printTree(){
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

	vector<T> getBfs(){
		queue<binary_tree*> storeNodes;
		storeNodes.push(root);
		vector<T> bfs;
		while(!storeNodes.empty()){
			binary_tree* currentNode=storeNodes.front();
			if(currentNode!=NULL){
				bfs.push_back(currentNode->data);
				if(currentNode->left!=NULL){
					storeNodes.push(currentNode->left);
				}
				if(currentNode->right!=NULL){
					storeNodes.push(currentNode->right);
				}
			}
			storeNodes.pop();
		}		
		return bfs;
	}

	vector<T> getBfs(binary_tree* root){
		queue<binary_tree*> storeNodes;
		storeNodes.push(root);
		vector<T> bfs;
		while(!storeNodes.empty()){
			binary_tree* currentNode=storeNodes.front();
			if(currentNode!=NULL){
				bfs.push_back(currentNode->data);
				if(currentNode->left!=NULL){
					storeNodes.push(currentNode->left);
				}
				if(currentNode->right!=NULL){
					storeNodes.push(currentNode->right);
				}
			}
			storeNodes.pop();
		}		
		return bfs;
	}

	vector<T> getElementsLevelWise(binary_tree* root,int level=0){
		queue<binary_tree*> storeNodes;
		vector<T> levelWiseNodes;
		storeNodes.push(root);
		for(int i=0;i<level;i++){
			queue<binary_tree*> tempStoreNodes;
			while(!storeNodes.empty()){
				binary_tree* currentNode=storeNodes.front();
				if(currentNode->left!=NULL){
					tempStoreNodes.push(currentNode->left);
				}
				if(currentNode->right!=NULL){
					tempStoreNodes.push(currentNode->right);
				}
				storeNodes.pop();
			}
			storeNodes=tempStoreNodes;
		}
		while(!storeNodes.empty()){
			levelWiseNodes.push_back(storeNodes.front()->data);
			storeNodes.pop();
		}
		return levelWiseNodes;
	}

	vector<T> getElementsLevelWise(int level=0){
		queue<binary_tree*> storeNodes;
		vector<T> levelWiseNodes;
		storeNodes.push(root);
		for(int i=0;i<level;i++){
			queue<binary_tree*> tempStoreNodes;
			while(!storeNodes.empty()){
				binary_tree* currentNode=storeNodes.front();
				if(currentNode->left!=NULL){
					tempStoreNodes.push(currentNode->left);
				}
				if(currentNode->right!=NULL){
					tempStoreNodes.push(currentNode->right);
				}
				storeNodes.pop();
			}
			storeNodes=tempStoreNodes;
		}
		while(!storeNodes.empty()){
			levelWiseNodes.push_back(storeNodes.front()->data);
			storeNodes.pop();
		}
		return levelWiseNodes;
	}
};


int main(){
	binary_tree<string> intTree;
	
	intTree.restricatedData="=";
	intTree.levelWiseInput();//Taking input in levelWise Manner. If there is no node than put restricatedData there to indicate that there is no node.
	intTree.printTree();
	cout<<endl<<endl<<endl;
	binary_tree<string> *root=intTree.getRoot();
	intTree.printTree(root->left);
	vector<string> levelAns=intTree.getElementsLevelWise(2);

	for(int i=0;i<levelAns.size();i++){
		cout<<levelAns[i]<<" ";
	}

	cout<<endl;
}