//Igor Łonak

template <typename KEY_TYPE, typename DATA_TYPE>
class BST{

    struct Node{
        DATA_TYPE data;
        KEY_TYPE key;
        Node* left;
        Node* right;
    };
public:
    Node* first;

    BST(){
        first=NULL;
    }

    ~BST(){
        postDelete(first);
    }


    bool add(Node** node, KEY_TYPE k, DATA_TYPE d){

        if(*node == NULL){
            Node* temp = new Node;
            temp->key = k;
            temp->data = d;
            temp->left=NULL;
            temp->right = NULL;
            *node = temp;
            return true;
        }
        else{
            if(!(k <(*node)->key) && !((*node)->key < k))
                return false;
            else if(k < (*node)->key){
                return add(&(*node)->left, k,d);
            }
            else{
                return add(&(*node)->right, k,d);
            }
        }
    }

    bool Insert(KEY_TYPE k, DATA_TYPE d){
        return add(&first,k,d);
    }

    DATA_TYPE* find(Node* node, KEY_TYPE k){
        if(node == NULL)
            return NULL;
        if(!(node->key < k) && !(k < node->key))
            return &node->data;
        else if(node->key < k)
            return find(node->right,k);
        else
            return find(node->left,k);
    }

    DATA_TYPE* Search(KEY_TYPE k){
        return find(first,k);
    }


    void Preorder(Node *node){

        if(node == NULL) return;

        std::cout<<node->key<<node->data;
        Preorder(node->left);
        Preorder(node->right);
    }

    void Inorder(Node *node){
        if(node == NULL) return;

        Inorder(node->left);
        std::cout<<node->key<<node->data;
        Inorder(node->right);
    }

    void Postorder(Node *node){
        if(node == NULL) return;

        Postorder(node->left);
        Postorder(node->right);
        std::cout<<node->key<<node->data;
    }

    void postDelete(Node *node){
        if(node == NULL) return;

        postDelete(node->left);
        postDelete(node->right);
        delete node;
    }


    void PreOrder(){
        Preorder(first);
    }

    void InOrder(){
        Inorder(first);
    }

    void PostOrder(){
        Postorder(first);
    }

    int height(Node* node)
    {
        if (node == NULL)
            return -1;
        else
        {
            int left = height(node->left);
            int right = height(node->right);

            if (left < right)
                return(right+1);
            else return(left+1);
        }
    }

    int Height(){
        if(first!=NULL)
            return height(first);
        return -1;
    }

    void LevelOrder()
    {
        int h = height(first) + 1;
        int i;
        for (i = 1; i <= h; i++)
            printLevel(first, i);
    }

    void printLevel(Node* node, int level)
    {
        if (node == NULL)
            return;
        if (level == 1)
            std::cout << node->key << node->data;
        else if (level > 1)
        {
            printLevel(node->left, level-1);
            printLevel(node->right, level-1);
        }
    }

    Node* min(Node* node)
    {
        Node* current = node;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    Node* deleteNode( Node* node, KEY_TYPE key, bool* deleted){

        if (node == NULL)
            return node;

        if (key < node->key)
            node->left = deleteNode(node->left, key,deleted);

        else if (node->key < key)
            node->right = deleteNode(node->right, key,deleted);

        else {
            if (node->left==NULL && node->right==NULL) {
                if(node==first)
                    first=NULL;
                delete node;
                *deleted=true;
                return NULL;
            }
            else if (node->left == NULL) {
                Node* temp = node->right;
                if(node==first)
                    first=temp;
                delete node;
                *deleted=true;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                if(node==first)
                    first=temp;
                delete node;
                *deleted=true;
                return temp;
            }

            Node* temp = min(node->right);
            node->key = temp->key;
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->key,deleted);
        }
        return node;
    }

    bool Delete (KEY_TYPE k){

        bool deleted=false;

        deleteNode(first,k,&deleted);

        return deleted;
    }
};

