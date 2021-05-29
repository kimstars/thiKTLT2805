#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void quickSort(int Data[], int l, int r)
{
    if (l <= r)
    {
        int key = Data[(l + r) / 2];
        int i = l;
        int j = r;
        while (i <= j)
        {
            while (Data[i] < key)
                i++;
            while (Data[j] > key)
                j--;
            if (i <= j)
            {
                swap(Data[i], Data[j]);
                i++;
                j--;
            }
        }
        if (l < j)
            quickSort(Data, l, j);
        if (r > i)
            quickSort(Data, i, r);
    }
}

void phanA(int arr[], int n){
    ofstream fileOutput("output21.txt");
    cout << endl;
    quickSort(arr, 0, n-1);

    for (int j = 0; j < n; j++)
    {
        fileOutput << arr[j] << " ";
    }

    fileOutput.close();
}


//--------------------PHẦN B-------------------

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}* Node;

int leftof(Node root, int data){
    return data < root->data;
}

int rightof(Node root, int data){
    return data > root->data;
}

Node createNode(int data){  
    Node temp = (Node)malloc(sizeof(struct node));
    temp->data = data;
    temp->left =  temp->right = NULL;
    return temp;
}


Node insertNode(Node root, int data){
    if(root == NULL){
        return createNode(data);
    }else{
        if(leftof(root,data)){
            root->left = insertNode(root->left,data);
        }else{
            root->right = insertNode(root->right,data);
        }
        return root;
    }
}

FILE* fileOut2 = fopen("output22.txt", "w");



Node PreOrder(Node t){ 
    if(t != NULL){
        fprintf(fileOut2, "%d ", t->data);
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void phanB(int arr[], int n){

    Node root = NULL;
    Node p = root;
    for(int i = 0; i < n; i++){
        p = insertNode(p,arr[i]);
    }
    PreOrder(p);

}



int main()
{
    int n;
    int arr[100];
    ifstream fileInput("input2.txt");
    n =0;
    int i = 0;
    if (fileInput.fail())
    {
        cout << "Failed to open this file!" << endl;
    }
    while (!fileInput.eof())
    {   
        n++;
        fileInput >> arr[i++];
    }

    phanA(arr,n);

    phanB(arr,n);


    return 0;
}