/* std_dds - Standard Dynamic Data Structures
 * Copyright (C) 2025 Jasper Devir <jasperdevir.jd@gmail.com>
 *
 * std_dds is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * std_dds is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with std_dds.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "b_search_tree.h"
#include "std_dds_core.h"

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif

BSTreeNode *BSTreeNodeInit(const int value){
    BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
    if (node == NULL) {
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] BSTreeNode malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(BSTreeNode));
        #endif
        return NULL;
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

BSTreeNode *bSTreeSearch(BSTreeNode *root, const int value){
    if(root == NULL){
        return NULL;
    } else if (root->value == value){
        return root;
    } else if (value > root->value){
        BSTreeNode *right = bSTreeSearch(root->right, value);
        if(right != NULL){
            return right;
        }
    } else if (value < root->value){
        BSTreeNode *left = bSTreeSearch(root->left, value);
        if(left != NULL){
            return left;
        }
    }

    return NULL;
}

BSTreeNode *BSTreeGetNode(BSTreeNode *tree, const int value){
    if (tree == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] BSTreeGetNode failed. BSTreeNode value is NULL.\n");
        #endif
        return NULL;
    }

    return bSTreeSearch(tree, value);
}

BSTreeNode *bSTreeInsert(BSTreeNode *tree, const int value){
    if(tree == NULL){
        return NULL;
    } else if (
        (tree->right == NULL && value > tree->value) ||
        (tree->left == NULL && value < tree->value)
    ){
        return tree;
    } 

    return NULL;
}



STD_DDS_RESULT BSTreeInsert(BSTreeNode *tree, const int value){
    if (tree == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] BSTreeInsert failed. BSTreeNode value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    BSTreeNode *parent = bSTreeInsert(tree, value);
    if(parent == NULL){
        return STD_DDS_NOT_FOUND;
    }

    BSTreeNode *node = BSTreeNodeInit(value);
    if(value > parent->value){
        parent->right = node;
    } else {
        parent->left = node;
    }

    return STD_DDS_SUCCESS;
}

BSTreeNode *BSTreeJoin(BSTreeNode *tree1, BSTreeNode *tree2){
    if (tree1 == NULL && tree2 == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] BSTreeJoin failed. Both BSTreeNode value's are NULL.\n");
        #endif
        return NULL;
    }

    if(tree1 == NULL){
        return tree2;
    } else if (tree2 == NULL){
        return tree1;
    } else {
        BSTreeNode *curr = tree2;
        BSTreeNode *parent = NULL;

        while(curr->left != NULL){
            parent = curr;
            curr = curr->left;
        }

        if(parent != NULL){
            parent->left = curr->right;
        }

        curr->left = tree1;

        return curr;
    }
}

BSTreeNode *bSTreeRemove(BSTreeNode *root, const int value){
    if(root != NULL){
        if(value < root->value){
            root->left = bSTreeRemove(root->left, value);
        } else if (value > root->value){
            root->right = bSTreeRemove(root->right, value);
        } else {
            BSTreeNode *prev = root;
            if(root->left == NULL && root->right == NULL){
                root = NULL;
            } else if (root->left == NULL){
                root = root->right;
            } else if (root->right == NULL){
                root = root->left;
            } else {
                root = BSTreeJoin(root->left, root->right);
            }
            
            free(prev);
        }
    }

    return root;
}

STD_DDS_RESULT BSTreeRemove(BSTreeNode *tree, const int value){
    if (tree == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] BSTreeRemove failed. BSTreeNode value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

     BSTreeNode* newTree = bSTreeRemove(tree, value);

    if (newTree == tree) {
        return STD_DDS_NOT_FOUND;    
    }

    return STD_DDS_SUCCESS;
}

void bSTreeFree(BSTreeNode *tree){
    if(tree == NULL){
        return;
    }

    bSTreeFree(tree->left);
    bSTreeFree(tree->right);

    free(tree);
}

STD_DDS_RESULT BSTreeFree(BSTreeNode *tree){
    if (tree == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] BSTreeFree failed. BSTreeNode value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    bSTreeFree(tree);

    return STD_DDS_SUCCESS;
}




