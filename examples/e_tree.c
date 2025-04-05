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
#include "std_dds_core.h"
#define STD_DDS_ERROR_MSG
#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintHTMLTree(TreeNode *node, int indent){
    if(node == NULL){
        printf("NODE IS NULL\n");
        return;
    }

    int i;

    char *indentStr = malloc(sizeof(char) * (indent + 1));
    if(indentStr == NULL){
        return;
    }

    for(i = 0; i < indent; i++){
        indentStr[i] = ' ';
    }
    indentStr[indent] = '\0';

    char *key = TreeNodeGetKey(node);
    if(key == NULL){
        printf("KEY IS NULL\n");
    } else {
        printf("%s<%s> ", indentStr, key);
        void *value = TreeNodeGetValue(node);
        if(value != NULL){
            printf("%s\n", (char *)value);
        } else {
            printf("\n");
        }
    }
    
    ArrayList *children = TreeNodeGetChildren(node);
    if(children != NULL){
        printf("Children Length: %zu\n", ArrayListGetLength(children));
        for(i = 0; i < ArrayListGetLength(children); i++){
            TreeNode *child = (TreeNode *)ArrayListGetAt(children, i);
            if(child != NULL){
                PrintHTMLTree(child, indent + 2);
            }
        }
    } else {
        printf("NO CHILDREN\n");
    }
    
    printf("%s</%s>\n", indentStr, key);

    free(indentStr);
}

char *HeapStr(const char *str){
    size_t len = strlen(str) + 1;
    char *heapStr = malloc(sizeof(char) * len);
    if(heapStr == NULL){
        return NULL;
    }

    for(size_t i = 0; i < len; i++){
        heapStr[i] = str[i];
    }

    return heapStr;
}

int main(void){
    STD_DDS_RESULT result;

    printf("\n== std_dds Tree Example ==\n");

    printf("\n-- TreeNodeInit() --\n");
    printf("Initialising trees.\n");
    const char *rootKey = "html";
    TreeNode *tree = TreeNodeInit(rootKey, NULL);
    if(tree == NULL){
        printf("TreeNodeInit() failed. Exiting.\n");
        return 1;
    }
    const char *bodyKey = "body";
    TreeNode *body = TreeNodeInit(bodyKey, NULL); 
    if(body == NULL){
        printf("TreeNodeInit() failed. Exiting.\n");
        return 1;
    }

    printf("\n-- TreeNodeAddNode() --\n");

    printf("Adding child '%s' to '%s'.\n", bodyKey, rootKey);
    result = TreeNodeAddNode(tree, body);
    if(result != STD_DDS_SUCCESS){
        printf("Adding child '%s' to '%s' failed. Exiting [%d]\n", bodyKey, rootKey, result);
        return 1;
    }

    printf("\n--TreeNodeAdd() --\n");

    const char *keyA = "h1";
    char *textA = HeapStr("Hello"); 
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", bodyKey, keyA, textA);
    if(TreeNodeAdd(body, keyA, textA) == NULL){
        printf("Adding child '%s' to '%s' failed. Exiting\n", keyA, bodyKey);
        return 1;
    }

    const char *keyB = "h2";
    char *textB = HeapStr("Subtitle");
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", bodyKey, keyB, textB);
     if(TreeNodeAdd(body, keyB, textB) == NULL){
        printf("Adding child '%s' to '%s' failed. Exiting\n", keyB, bodyKey);
        return 1;
    }

    const char *keyC = "h5";
    char *textC = HeapStr("Author");
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", bodyKey, keyC, textC);
     if(TreeNodeAdd(body, keyC, textC) == NULL){
        printf("Adding child '%s' to '%s' failed. Exiting\n", keyC, bodyKey);
        return 1;
    }

    const char *keyD = "p";
    char *textD = HeapStr("Welcome to my page! Here is a link: ");
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", bodyKey, keyD, textD);
    TreeNode *p = TreeNodeAdd(body, keyD, textD);
    if(p == NULL) {
        printf("Adding child '%s' to '%s' failed. Exiting\n", keyD, bodyKey);
        return 1;
    }

    const char *keyE = "a";
    char *textE = HeapStr("www.google.com");
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", keyD, keyE, textE);
    if(TreeNodeAdd(body, keyE, textE) == NULL){
        printf("Adding child '%s' to '%s' failed. Exiting\n", keyE, keyE);
        return 1;
    }

    const char *keyF = "p";
    char *textF = HeapStr("Goodbye for now!");
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", bodyKey, keyF, textF);
    if(TreeNodeAdd(body, keyF, textF) == NULL){
        printf("Adding child '%s' to '%s' failed. Exiting\n", keyF, bodyKey);
        return 1;
    }

    printf("Result:\n");
    PrintHTMLTree(tree, 0);

    TreeNode *nodeResult;
    void *value;
    
    printf("\n-- TreeRemove() --\n");

    printf("Removing '%s' from the Tree.\n", keyD);
    nodeResult = TreeRemove(tree, keyD);
    if(nodeResult == NULL){
        printf("Removing key '%s' from Tree was unsuccessful. Exiting.\n", keyD); 
        return 1;
    } else {
        value = TreeNodeGetKey(nodeResult);
        printf("Succesfully removed key '%s' with value '%s' from Tree.\n", keyD, (char *)value);
        free(nodeResult);
    }

    printf("\n-- TreeNodeRemove() --\n");

    printf("Removing '%s' from '%s'.\n", keyC, bodyKey);
    nodeResult = TreeNodeRemove(body, keyC);
    if(nodeResult == NULL){
        printf("Removing key '%s' from '%s' was unsuccessful. Exiting.\n", keyC, bodyKey); 
        return 1;
    } else {
        value = TreeNodeGetValue(nodeResult);
        printf("Succesfully removed key '%s' with value '%s' from '%s'.\n", keyC, (char *)value, bodyKey);
        free(nodeResult);
    }
    

    printf("\n-- TreeGet() --\n");

    printf("Getting '%s' from the Tree.\n", keyE);
    nodeResult = TreeGet(tree, keyE);
    if(nodeResult == NULL){
        printf("Getting key '%s' from Tree was unsuccessful. Exiting.\n", keyE); 
        return 1;
    } else {
        value = TreeNodeGetValue(nodeResult);
        printf("Succesfully retrieved key '%s' with value '%s' from Tree.\n", keyE, (char *)value);
    }

    printf("\n-- TreeNodeGet() --\n");

    printf("Get '%s' from '%s'.\n", keyA, bodyKey);
    nodeResult = TreeNodeGet(body, keyA);
    if(nodeResult == NULL){
        printf("Geting key '%s' from '%s' was unsuccessful. Exiting.\n", keyA, bodyKey); 
        return 1;
    } else {
        value = TreeNodeGetValue(nodeResult);
        printf("Succesfully retrieved key '%s' with value '%s' from '%s'.\n", keyA, (char *)value, bodyKey);
    }

    printf("\n-- TreeFree() --\n");

    printf("Freeing the Tree.\n");
    TreeFree(tree);

    return 0;
}
