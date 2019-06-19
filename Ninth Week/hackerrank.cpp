//TopView
    void topView(Node * root) {
        map<int, pair<int, int>> mapa;
        print(root, 0, 0, mapa);
        for(auto it: mapa){
            cout << it.second.first << " ";
        }

    }

    void print(Node * root, int hd, int level, auto &map){
        if(root == nullptr){
            return;
        }
        if(map.find(hd) == map.end() || level < map[hd].second){
            map[hd] = {root->data, level};
        }
        
        print(root->left, hd-1, level+1, map);
        print(root->right, hd+1, level+1, map);
    }
 
//Binary Search Tree : Lowest Common Ancestor
    Node *lca(Node *root, int v1,int v2) {
		if(root == nullptr){
            return nullptr;
        }
        if(root->data > v1 && root->data > v2){
            return lca(root->left, v1, v2);
        }
        if(root->data < v1 && root->data < v2){
            return lca(root->right, v1, v2);
        }

        return root;
    }
    
//Binary Search Tree : Insertion
    Node * insert(Node * root, int data) {
        if(root == nullptr){
            root = new Node(data);
        }
        if(root->data > data){
            root->left = insert(root->left, data);
        }
        if(root->data < data){
            root->right = insert(root->right, data);
        }

        return root;
    }
    
//Level Order Traversal
    void levelOrder(Node * root) {
        int level = levelTree(root);
        for(int i = 0; i < level; i++){
            print(root, i);
        }
    }

    void print(Node * root, int level){
        if(root == nullptr){
            return;
        }
        if(level == 0){
            cout << root->data << " ";
        }else if(level > 0){
            print(root->left, level-1);
            print(root->right, level-1);
        }
    }

    int levelTree(Node * root){
        if(root == nullptr){
            return 0;
        }
        int levelL = levelTree(root->left);
        int levelR = levelTree(root->right);
        if(levelL > levelR){
            return (levelL+1);
        }else{
            return (levelR+1);
        }
    }
    
//Height of binary tree
    int height(Node* root) {
        if(root == nullptr){
            return 0;
        }
        if((root->left == nullptr) && (root->right == nullptr)){
            return 0;
        }

        return 1 + maior(height(root->left), height(root->right));
    }

    int maior(int left, int right){
        if(left > right){
            return left;
        }else{
            return right;
        }
    }
    
//Inoder transversal
    void inOrder(Node *root) {
        if(root == nullptr){
            return;
        }

        inOrder(root->left);
        cout << root->data;
        cout << " ";
        inOrder(root->right);

        return;
    }
    
//Postorder transversal
     void postOrder(Node *root) {
        if(root == nullptr){
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data;
        cout << " ";

        return;
    }

//Preorder transversal
    void preOrder(Node *root) {
        if(root == nullptr){
            return;
        }
        cout << root->data;
        cout << " ";
        preOrder(root->left);
        preOrder(root->right);

        return;
    }
