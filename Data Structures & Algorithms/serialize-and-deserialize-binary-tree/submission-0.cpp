class Codec {
public:

    string serialize(TreeNode* root) {
        string ans = "";

        if(root == NULL){
            return "";
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size; i++){
                 TreeNode* node = q.front();
                 q.pop();

                 if(node == NULL){
                    ans += "NULL ";
                    continue;
                 }

                 ans += to_string(node -> val) + " ";

                 q.push(node -> left);
                 q.push(node -> right);
            }
        } 

        return ans; 
    }
    
    TreeNode* deserialize(string data) {

        if(data.size() == 0){
            return NULL;
        }

        stringstream ss(data);

        string str;
        ss >> str;

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            ss >> str;

            if(str != "NULL"){

                TreeNode* leftNode = new TreeNode(stoi(str));

                node -> left = leftNode;

                q.push(leftNode);
            }

            ss >> str;

            if(str != "NULL"){

                TreeNode* rightNode = new TreeNode(stoi(str));

                node -> right = rightNode;

                q.push(rightNode);
            }
        }

        return root;
    }
};