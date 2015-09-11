class TreeNode
{
public:
    TreeNode();
    TreeNode(const TreeNode& rhs);
    TreeNode& operator=(const TreeNode &rhs);
    ~TreeNode() { delete left; delete right; };
private:
    string value;
    int count;
    TreeNode* left;
    TreeNode* right;
};

TreeNode::TreeNode(): count(0), left(nullptr),right(nullptr) { }

TreeNode::TreeNode(const TreeNode &rhs):
    value(rhs.value), count(rhs.count)
{
    *left = *rhs.left;
    *right = *rhs.right;
}

TreeNode& operator=(const TreeNode &rhs)
{
    auto newp1 = new TreeNode(*rhs.left);
    auto newp2 = new TreeNode(*rhs.right);
    value = rhs.value;
    count = rhs.value;
    delete left;
    delete right;
    *left = newp1;
    *right = newp2;
    return *this;
}

class BinStrTree
{
public:
    BinStrTree(): root(nullptr) { }
    BinStrTree(const BinStrTree& rhs):root(new TreeNode(*rhs.root)) {  }
    BinStrTree& operator=(const BinStrTree& rhs) { auto p = new BinStrTree(*rhs.root); delete root; root = p; return *this; }
    ~BinStrTree() { delete root; }
private:
    TreeNode *root;
};
