#include <iostream> 
#include <string>

using namespace std;

class Node
{
    public:
        Node* right;
        Node* left;
        string name;
        double weight;

};

class BST
{
    public:
        Node* BinaryTree(string ,double,Node*);
        Node* getNode(string ,double);
        void preOrder(Node*);
        void inOrder(Node*);
        void postOrder(Node*);
        int findHeight(Node*);
        int getHeight(Node*);
        void printLeaf(Node*);
        void numLeaf();
        void search(Node*,string);
        double lowestWeight(Node*,double);
        void firstName(Node*, string);

    private:
        int numLeaves = 0;

};


//creates new nodes for BinaryTree
Node* BST::getNode(string refName, double refWeight)
{
    Node* newNode = new Node();
    newNode -> name = refName;
    newNode -> weight = refWeight;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

//Creating BinarySearchTree
Node* BST::BinaryTree(string refName, double refWeight, Node* leaf)
{
    if(leaf == NULL)
    {
        leaf = BST::getNode(refName, refWeight);
        return leaf;
    }
    if(refName.compare(leaf -> name) <= 0 )
    {
        leaf -> left = BST::BinaryTree(refName, refWeight, leaf->left);
    }
    if(refName.compare(leaf -> name) >= 0)
    {
        leaf -> right = BST::BinaryTree(refName, refWeight, leaf->right);
    }
    return leaf;
}


void BST::preOrder(Node* refTree)
{
    if(refTree == NULL)
    {
        return;
    }
    cout << refTree -> name << ": " << refTree -> weight << endl;
    BST::preOrder(refTree -> left);
    BST::preOrder(refTree -> right);
}

void BST::inOrder(Node* refTree)
{
    if(refTree == NULL)
    {
        return;
    }
    BST::inOrder(refTree -> left);
    cout << refTree -> name << ": " << refTree -> weight << endl;
    BST::inOrder(refTree -> right);
}

void BST::postOrder(Node* refTree)
{
    if(refTree == NULL)
    {
        return;
    }
    BST::postOrder(refTree -> left);
    BST::postOrder(refTree -> right);
    cout << refTree -> name << ": " << refTree -> weight << endl;
}

//gets height from tree
int BST::getHeight(Node* refTree) 
{
    int height = findHeight(refTree);
    if(height <= 0)
        return height;
    else
        return height - 1;
}

//finding height of tree
int BST::findHeight(Node* refTree) 
{
    if (refTree == NULL) 
    {
        return 0;
    }
    else 
    {
        int leftHeight = findHeight(refTree->left);
        int rightHeight = findHeight(refTree->right);
        if (leftHeight >= rightHeight)
            return leftHeight + 1;
        else 
            return rightHeight + 1;
    }
}

void BST::printLeaf(Node* refTree)
{
    if(refTree == NULL)
    {
        return;
    }
    BST::printLeaf(refTree -> left);
    BST::printLeaf(refTree -> right);
    if(refTree -> left == NULL && refTree -> right == NULL)
    {
        numLeaves++;
        cout << refTree->name << ": " << refTree->weight << endl;
    }

}

void BST::numLeaf()
{
    cout << "Number of Leaves: " << numLeaves << endl;
}

void BST::search(Node* refTree, string name1)
{
    while(refTree != NULL)
    {
        if(name1.compare(refTree -> name) == 0)
        {
            cout << "Weight: " << refTree -> weight << endl;
            return;
        }
        else if(name1.compare(refTree -> name) < 0)
        {
            refTree = refTree -> left;
        }
        else if(name1.compare(refTree -> name) > 0)
        {
            refTree = refTree -> right;
        }
    }
    cout << "Name does not exist." << endl;  
}

double BST::lowestWeight(Node* refTree, double Lweight)
{
    if(refTree == NULL)
    {
        return Lweight;
    }
    if(refTree -> weight < Lweight) // Lweight is initializes as the root
    {
        Lweight = refTree -> weight;
    }
    Lweight = BST::lowestWeight(refTree->left, Lweight);
    Lweight = BST::lowestWeight(refTree -> right, Lweight);
    return Lweight;
}

void BST::firstName(Node* refTree, string Fname)
{
    while(refTree != NULL)
    {
        if(Fname.compare(refTree -> name) >= 0)
        {
            Fname = refTree -> name;
        }
        refTree = refTree -> left; // no point in searching the right because lower values will always be in left most leaf
    }
    cout << "First name Alphabeticaly: " << Fname;
}

int main()
{
    BST myTree;
    Node* Tree = NULL; //Binary Search Tree
    string tempName; // holds the name temp
    double tempWeight; // holds weight temp
    string temp; // used to help get weight inputs

    //Inputs
    cout << "Enter names with a weight on their own separtate lines, enter empty line to quit: " << endl;
    do
    {
        getline(cin,tempName);
        if(tempName == "")
            break;
        getline(cin,temp);
        tempWeight = stoi(temp);
        if(tempWeight < 0)
        {
        cout << "Invalid weight";
        exit(1);
        }
        Tree = myTree.BinaryTree(tempName, tempWeight, Tree); // puts name and weight into tree
    } while (true);

    //outputs
    cout << "\n____Pre-Order____" << endl;
    myTree.preOrder(Tree);

    cout << "\n____In-Order____" << endl;
    myTree.inOrder(Tree);

    cout << "\n____Post-Order____" << endl;
    myTree.postOrder(Tree);

    cout << "\n____Height____" << endl;
    cout << "Height of Tree: " <<  myTree.getHeight(Tree) << endl;

    cout << "\n____Leaves____" << endl;
    myTree.printLeaf(Tree); // prints the leaves
    myTree.numLeaf(); // prints number of leaves

    cout << "\n____Search____" << endl;
    cout << "Enter a name to search for individual's weight: " << endl;
    cin >> tempName;
    myTree.search(Tree,tempName);

    cout << "\n____Lowest Weight____" << endl;
    cout << "Lowest Weight: " << myTree.lowestWeight(Tree, Tree -> weight) << endl;

    cout << "\n____First Name____" << endl;
    myTree.firstName(Tree, Tree -> name);
    
    return 0;
}

/* OUTPUT
Enter names with a weight on their own separtate lines, enter empty line to quit: 
Jim
150
Tom
212
Michael
174
Abe
199
Richard
200
April
117
Claire
124
Bobby
109
Bob
156
Kevin
145
Jason
182
Brian
150
Chris
175
Steven
164
Annabelle
99


____Pre-Order____
Jim: 150
Abe: 199
April: 117
Annabelle: 99
Claire: 124
Bobby: 109
Bob: 156
Brian: 150
Chris: 175
Jason: 182
Tom: 212
Michael: 174
Kevin: 145
Richard: 200
Steven: 164

____In-Order____
Abe: 199
Annabelle: 99
April: 117
Bob: 156
Bobby: 109
Brian: 150
Chris: 175
Claire: 124
Jason: 182
Jim: 150
Kevin: 145
Michael: 174
Richard: 200
Steven: 164
Tom: 212

____Post-Order____
Annabelle: 99
Bob: 156
Chris: 175
Brian: 150
Bobby: 109
Jason: 182
Claire: 124
April: 117
Abe: 199
Kevin: 145
Steven: 164
Richard: 200
Michael: 174
Tom: 212
Jim: 150

____Height____
Height of Tree: 6

____Leaves____
Annabelle: 99
Bob: 156
Chris: 175
Jason: 182
Kevin: 145
Steven: 164
Number of Leaves: 6

____Search____
Enter a name to search for individual's weight:
Sven
Name does not exist.

____Lowest Weight____
Lowest Weight: 99

____First Name____
First name Alphabeticaly: Abe
*/