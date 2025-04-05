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

#include "tree.h"
#include "array_list.h"
#include "std_dds_core.h"

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#include <string.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif

typedef struct treeNode {
    void *value;
    char *key;    
    ArrayList *children;
} TreeNode;

TreeNode *TreeNodeInit(const char *key, void *value){
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL) {
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] TreeNode malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(TreeNode));
        #endif
        return NULL;
    }
 
    node->key = malloc(sizeof(char) * strlen(key) + 1);
    if(node->key == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] TreeNode->key malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(char) * strlen(key) + 1);
        #endif
        free(node);
        return NULL;
    }
    strcpy(node->key, key);

    node->value = value;
    node->children = ArrayListInit(4); 
    if(node->children == NULL){
        free(node->key);
        free(node);
        return NULL;
    }

    return node;
}

TreeNode *TreeNodeGet(const TreeNode *parent, const char *key){
    if (parent == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] TreeNodeGet failed. TreeNode value is NULL.\n");
        #endif
        return NULL;
    }

    for(size_t i = 0; i < ArrayListGetLength(parent->children); i++){
        TreeNode *child = (TreeNode *)ArrayListGetAt(parent->children, i);
        if(child == NULL){
            continue;
        }

        if(strcmp(key, child->key) == 0){
            return child;
        }
    }

    return NULL;
}

TreeNode *treeSearch(const TreeNode *parent, const char *key){
    ArrayList *children = parent->children;

    for(size_t i = 0; i < ArrayListGetLength(children); i++){
        TreeNode *child = (TreeNode *)ArrayListGetAt(children, i);
        if(child == NULL){
            continue;
        }

        if(strcmp(key, child->key) == 0){
            return child;
        }
        
        TreeNode *result = treeSearch(child, key);
        if(result != NULL){
            return result;
        }
    }

    return NULL;
}

TreeNode *TreeGet(const TreeNode *tree, const char *key){
    if (tree == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] TreeNodeGet failed. TreeNode value is NULL.\n");
        #endif
        return NULL;
    }

    return treeSearch(tree, key);
}

TreeNode *TreeNodeAdd(TreeNode *parent, const char *key, void *value){
    if (parent == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] TreeNodeAdd failed. TreeNode value is NULL.\n");
        #endif
        return NULL;
    } 

    TreeNode *node = TreeNodeInit(key, value);
    if(node == NULL){
        return NULL;
    }

    STD_DDS_RESULT result = ArrayListAppend(parent->children, node);
    if(result != STD_DDS_SUCCESS){
        return NULL;
    }

    return node;
}

STD_DDS_RESULT TreeNodeAddNode(TreeNode *parent, TreeNode *child){
    if (parent == NULL || child == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] TreeNodeAddNode failed. TreeNode value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    } 

    return ArrayListAppend(parent->children, child);
}

TreeNode *treeRemoveSearch(TreeNode *parent, const char *key){
    if(parent == NULL){
        return NULL;
    }

    ArrayList *children = parent->children;

    for(size_t i = 0; i < ArrayListGetLength(children); i++){
        TreeNode *child = (TreeNode *)ArrayListGetAt(children, i);
        if(child == NULL){
            continue;
        }
        
        if(strcmp(key, child->key) == 0){
            return (TreeNode *)ArrayListRemoveAt(children, i);
        }
        
        TreeNode *result = treeRemoveSearch(child, key);
        if(result != NULL){
            return result;
        }
    }

    return NULL;
}

TreeNode *TreeRemove(TreeNode *tree, const char *key){
    if (tree == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] TreeRemove failed. TreeNode value is NULL.\n");
        #endif
        return NULL;
    }

    return treeRemoveSearch(tree, key);
}

TreeNode *TreeNodeRemove(TreeNode *parent, const char *key){
    if (parent == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] TreeNodeRemove failed. TreeNode value is NULL.\n");
        #endif
        return NULL;
    }
    
    size_t i;
    size_t length = ArrayListGetCapacity(parent->children);

    for(i = 0; i < length; i++){
        TreeNode *child = (TreeNode *)ArrayListGetAt(parent->children, i);
        if(child == NULL){
            continue;
        }

        if(strcmp(key, child->key) == 0){
            break;
        }

        if(i == length - 1){
            return NULL;
        }
    }

    return ArrayListRemoveAt(parent->children, i);
}

void *TreeNodeGetValue(const TreeNode *node){
    if (node == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] TreeNodeGetValue failed. TreeNode value is NULL.\n");
        #endif
        return NULL;
    }

    return node->value;
}

char *TreeNodeGetKey(const TreeNode *node){
    if (node == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] TreeNodeGetKey failed. TreeNode value is NULL.\n");
        #endif
        return NULL;
    }

    return node->key;
}

ArrayList *TreeNodeGetChildren(TreeNode *node){
    if (node == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] TreeNodeGetChildren failed. TreeNode value is NULL.\n");
        #endif
        return NULL;
    }

    return node->children;
}

void treeNodeFree(TreeNode *node){
    if(node == NULL){
        return;
    }

    for(size_t i = 0; i < ArrayListGetLength(node->children); i++){
        TreeNode *child = ArrayListGetAt(node->children, i);
        if(child != NULL){
            treeNodeFree(child);
        }
    }

    ArrayListFree(node->children);
    free(node);
}

STD_DDS_RESULT TreeFree(TreeNode *tree){
    if (tree == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] TreeNodeFree failed. TreeNode value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    treeNodeFree(tree);

    return STD_DDS_SUCCESS;
}
