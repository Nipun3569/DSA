#include <utility>

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1;
    int suc = -1;

    TreeNode* temp = root;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            // If the key is found
            if (temp->left != NULL)
            {
                // Find predecessor in the left subtree
                TreeNode* predNode = temp->left;
                while (predNode->right != NULL)
                {
                    predNode = predNode->right;
                }
                pred = predNode->data;
            }

            if (temp->right != NULL)
            {
                // Find successor in the right subtree
                TreeNode* sucNode = temp->right;
                while (sucNode->left != NULL)
                {
                    sucNode = sucNode->left;
                }
                suc = sucNode->data;
            }

            break; // Key found, no need to continue
        }
        else if (temp->data > key)
        {
            // Key is in the left subtree
            suc = temp->data;
            temp = temp->left;
        }
        else
        {
            // Key is in the right subtree
            pred = temp->data;
            temp = temp->right;
        }
    }

    return make_pair(pred, suc);
}
