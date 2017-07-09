#include <iostream>
#include<queue>

using namespace std;



struct BstNode{
int data;
BstNode* left;
BstNode* right;

};

BstNode* GetnewNode(int data){
BstNode* newNode= new BstNode();
newNode->data=data;
newNode->left=0;
newNode->right=0;

return newNode;

}

BstNode* insert(BstNode* root,int data){

if (root ==0){
    root=GetnewNode(data);

}
else if (data<=root->data){
    root->left=insert(root->left,data);
}
else{
    root->right=insert(root->right,data);
}
return root;
}

bool search(int data, BstNode* root){
if (root==0){
        return false;
}
else if(root->data==data){
    return true;

}
else if(data <=root->data){
     return search(data, root->left);
}
else
     return search(data,root->right);
}

int findmin(BstNode* root){
if (root==0){
    cout<<"Error the tree is empty";
    return -1;
}
else if(root->left==0){
    return root->data;

}

return findmin(root->left);

}


int FindHeight (BstNode* root){

if(root==0){
    return -1;
}
int leftheight=FindHeight(root->left);
int rightheight=FindHeight(root->right);
return max(leftheight,rightheight)+1;
}

void preorder_traversal(BstNode* root){
if (root==0){
    return;
}
cout<<root->data;
preorder_traversal(root->left);
preorder_traversal(root->right);

}
void inorder_traversal(BstNode* root){
if (root==0){
    return;
}
inorder_traversal(root->left);
cout<<root->data;
inorder_traversal(root->right);
}
void postorder_traversal(BstNode* root){
if (root==0){

    return;
}
postorder_traversal(root->left);

postorder_traversal(root->right);
cout<<root->data;

}

void LevelOrder_traversal(BstNode* root){
    if (root==0){
        return;
    }

    queue<BstNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        BstNode* current=Q.front();
        cout<<current->data<<" ";
        if (current->left!=0){
            Q.push(current->left);

        }
        if (current->right!=0){
            Q.push(current->right);
        }

        Q.pop();
    }
}
//bool IsSubtreeLesser(BstNode* root,int value){
//    if (root==0)
//        return true;
//    if ((root->data<=value) && (IsSubtreeLesser(root->left,value)) && (IsSubtreeLesser(root->right,value)))
//        return true;
//
//
//    else
//        return false;
//
//}
//bool IsSubtreeGreater(BstNode* root, int value){
//    if (root==0)
//        return true;
//    if ((root->data>value) && (IsSubtreeGreater(root->left,value)) && (IsSubtreeGreater(root->right,value)))
//        return true;
//
//      else
//        return false;
//}

bool IsBinarySearchTree(BstNode* root, int minValue, int maxValue){
    if (root==0)
        return true;
//    if (IsSubtreeLesser(root->left,root->data) &&
//        IsSubtreeGreater(root->right,root->data)&&
      if (root->data>minValue &&
          root->data<maxValue&&
          IsBinarySearchTree(root->left,minValue,root->data) &&
          IsBinarySearchTree(root->right,root->data,maxValue))
        return true;

    else
        return false;


    }
    BstNode* BST_FindMin(BstNode* root) {
 while (root->left != 0)
    root = root->left;
 return root;
}

BstNode* Delete(BstNode* root, int data){

    if (root==0)
        return root;

    else if (data<root->data)
        root->left=Delete(root->left,data);

    else if (data>root->data)
        root->right=Delete(root->right,data);
    else{

        //case 0:no child
        if (root->right==0 && root->left==0){
            delete root;
            root=0;

        }
        //case 1: 1 child

        else if(root->left==0){
            BstNode* temp=root;
            root=root->right;
            delete temp;


        }
        else if(root->right==0){

            BstNode* temp=root;
            root=root->left;
            delete temp;

        }

        //case 2: 2 children

        else{

            BstNode* temp=BST_FindMin(root);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);

        }

    }
    return root;


}

void Merge_order(int* L,int L_count,int* R,int R_count,int* A){

 int i=0;
 int j=0;
 int k=0;
 while(i<L_count && j<R_count){

    if (L[i]<=R[j]){
        A[k]=L[i];
        i=i+1;
    }
    else {
        A[k]=R[j];
        j=j+1;
    }
    k=k+1;
 }
 while(i<L_count){
    A[k]=L[i];
    k=k+1;
    i=i+1;

 }
 while(j<R_count){

    A[k]=R[j];
    k=k+1;
    j=j+1;
 }



}

void MergeSort(int *A,int N){

    if (N<2)
        return;
    int mid=N/2;
    int* Left=new int(mid);
    int* Right=new int(N-mid);
    for (int i=0;i<mid;i++)
        Left[i]=A[i];
    for (int i=mid;i<N;i++)
        Right[i-mid]=A[i];

    MergeSort(Left,mid);
    MergeSort(Right,N-mid);
    Merge_order(Left,mid,Right,N-mid,A);
    delete(Left);
    delete(Right);



}




int main()

{
    BstNode* root=0;
    root=insert(root,10);
    root=insert(root,15);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,9);
    root=insert(root,5);
    if (search(20,root)==true)
        cout<<"found"<<endl;
    else
        cout<<"not found"<<endl;

    cout<<findmin(root)<<endl;
    cout<<"THe height of this tree is "<<FindHeight(root)<<endl;
    preorder_traversal(root);
    cout<<endl;
    inorder_traversal(root);
    cout<<endl;
    postorder_traversal(root);
    cout<<endl;
    LevelOrder_traversal(root);
    cout<<endl;
    cout<<IsBinarySearchTree(root,-15,100);
    cout<<endl;
    cout<<"Deleted "<<Delete(root,20);
    cout<<endl;
    LevelOrder_traversal(root);
    cout<<endl;
    int A[]={1,4,2,6,8,5,3,9,10,11,12,7};


    int N = sizeof(A)/sizeof(A[0]);
    MergeSort(A,N);
    for(int i = 0;i <N;i++)
        cout<<A[i];

    return 0;
}
