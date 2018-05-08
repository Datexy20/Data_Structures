#ifndef BST_T_H
#define BST_T_H
/*--------------- B S T _ T . h --------------

PURPOSE
Define a binary search tree class template.


CHANGES
11-05-2016 gpc - Created for EECE322
*/
#include <cassert>
#include <ostream>

using namespace std;

#include "CursorCntl.h"
#include "QueueT.h"

//----- c l a s s    B S T -----

template <typename NodeData>
class BST
{
private:
   // Tree node class definition
   struct Node
   {
     // Constructors
	  Node() : left(0), right(0) {}
	  Node(const NodeData &d) : data(d), left(0), right(0) { }

	  // Data Members
     NodeData    data;    // The "contents" of the node
     Node        *left;   // Link to the left successor node
     Node        *right;  // Link to the right successor node
   };

public:
   // Constructor
   BST() : root(0), current(0) { }

   // True if the tree is empty
   bool Empty() const { return root == 0;}

   // Search for an entry in the tree. If the entry is found,
   // make it the "current" entry. If not, make the current entry 
   // NULL. Return true if the entry is found; otherwise return false. 
   bool Search(NodeData &d);
    
   // Add a new node to the tree.
   void Insert(NodeData &d);

   // Delete the current node.
   void Delete();

   // Output the tree to the "os" in the indicated sequence.
   void OutputInOrder(ostream &os) const;    // Output inorder
   void OutputPreOrder(ostream &os) const;   // Output preorder
   void OutputPostOrder(ostream &os) const;  // Output postorder
   void OutputByLevel(ostream &os) const;          // Output by level

   // Retrieve the data part of the current node.
   NodeData Current() { return current->data; }

   // Show the binary tree on the screen.
   void ShowTree() const;
private:
   Node *root;      // Points to the root node
   Node *current;   // Points to the current node
   Node *parent;    // Points to current node's parent

   // Recursive Search
   bool RSearch(Node *subTree, NodeData &d);

   // Recursive Insert
   void RInsert(Node *&subTree, NodeData &d);

   // Recursive Traversal Functions
   void ROutputInOrder(Node *subTree, ostream &os) const;
   void ROutputPreOrder(Node *subTree, ostream &os) const;
   void ROutputPostOrder(Node *subTree, ostream &os) const;
   // Find the parent of leftmost right successor of the current node.
   Node *ParentOfLeftMostRightSucc(Node *node, Node *parent) const;

   // Show the binary tree on the screen.
   void RShowTree(Node *subTree, int x, int y) const;
};


/*--------------- S e a r c h ( ) ---------------

PURPOSE
Search a BST for a specific data value. If found
make that node the current node.

INPUT PARAMETERS
d - the item to look up

RETURN VALUE
true if found, otherwise false.
*/
template <typename NodeData>
bool BST<NodeData>::Search(NodeData &d)
{
	parent = 0;
	return RSearch(root, d);
}

const unsigned XRoot = 40;        // Column number for root node

/*--------------- R S h o w T r e e ( ) ---------------

PURPOSE
Recursive function to display a tree on the right half of the screen
using (crude) character graphics.

INPUT PARAMETERS
subTree   -- the root of the sub-tree to display
x         -- the cursor x coordinate index
y         -- the cursor y coordinate
*/
template <typename NodeData>
void BST<NodeData>::RShowTree(Node *subTree, int x, int y) const
{
  const unsigned VertSpacing = 7;   // Vertical spacing constant
  const unsigned HorizSpacing = 10; // Horizontal spacing of tree nodes
  const unsigned MaxLevels = 4;     // The number of levels that fit on the screen

  // If the tree is not empty display it..
  if (subTree != 0 && x < MaxLevels)
    {
    // Show the left sub-tree.
    RShowTree(subTree->left, x+1, y+VertSpacing/(1<<x));

    // Show the root.
    gotoxy(XRoot+HorizSpacing*x, y);
	subTree->data.Show(cout);
	cout << endl;

    // Show the right subtree.
    RShowTree(subTree->right, x+1, y-VertSpacing/(1<<x));
    }
}

/*--------------- S h o w T r e e ( ) ---------------

PURPOSE
Display a tree on the right half of the screen using (crude)
character graphics.This function calls RShowTree() which does
the work.
*/
template <typename NodeData>
void BST<NodeData>::ShowTree() const
{
  const unsigned YRoot = 11;      // Line number of root node
  const unsigned ScrollsAt = 24;  // Screen scrolls after line 24
    
  int xOld;                       // Old cursor x coordinate
  int yOld;                       // Old cursor y coordinate

  // Save cursor position
  getxy(xOld, yOld);

  // Has the screen scrolled yet?
  int deltaY = 0;

  if (yOld > ScrollsAt)
    deltaY = yOld - ScrollsAt+1;

  // Clear the right half of the screen.
  for (int y=0; y<ScrollsAt+1; y++)
    {
    gotoxy(XRoot,y+deltaY);
    clreol();
    }

  // Show the tree and offset if scrolled.
  RShowTree(root, 0, YRoot+deltaY);   

  // Restore old cursor position.
  gotoxy(xOld,yOld);      
}
#endif