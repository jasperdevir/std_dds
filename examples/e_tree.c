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
#include "std_dds_utils.h"
#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintHTMLTree(TreeNode *node, int indent){
    if(node == NULL){
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
        return;
    }

    printf("%s<%s>\n", indentStr, key);

    void *value = TreeNodeGetValue(node);
    if(value != NULL){
        printf("%s%s\n", indentStr, (char *)value);
    } 
    
    ArrayList *children = TreeNodeGetChildren(node);
    if(children != NULL){
        for(i = 0; i < ArrayListGetLength(children); i++){
            TreeNode *child = ArrayListGetAt(children, i);
            if(child != NULL){
                PrintHTMLTree(child, indent + 2);
            }
        }
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

    return strcpy(heapStr, str); 
}

int main(void){
    STD_DDS_RESULT result;

    printf("\n== std_dds Tree Example ==\n");

    printf("\n-- TreeNodeInit() --\n");

    const char *rootKey = "html";
    printf("Initialising a TreeNode with key '%s'.\n", rootKey);    
    TreeNode *tree = TreeNodeInit(rootKey, NULL);
    if(tree == NULL){
        printf("TreeNodeInit() failed. Exiting.\n");
        return 1;
    }

    const char *bodyKey = "body";
    printf("Initialising a TreeNode with key '%s'.\n", bodyKey);
    TreeNode *body = TreeNodeInit(bodyKey, NULL); 
    if(body == NULL){
        printf("TreeNodeInit() failed. Exiting.\n");
        return 1;
    }

    printf("\n-- TreeNodeAddNode() --\n");

    printf("Adding child to '%s' with key '%s'.\n", rootKey, bodyKey);
    result = TreeNodeAddNode(tree, body);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Adding child to '%s' with key '%s' was unsuccessful. Exiting.\n", rootKey, bodyKey);
        return 1;
    }

    printf("\nResult:\n");
    PrintHTMLTree(tree, 0);
    
    printf("\n--TreeNodeAdd() --\n");

    const char *keyA = "h1";
    char *textA = HeapStr("Hello World"); 
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", bodyKey, keyA, textA);
    if(TreeNodeAdd(body, keyA, textA) == NULL){
        printf("Adding child '%s' to '%s' failed. Exiting.\n", keyA, bodyKey);
        return 1;
    }

    const char *keyB = "h2";
    char *textB = HeapStr("Subtitle");
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", bodyKey, keyB, textB);
     if(TreeNodeAdd(body, keyB, textB) == NULL){
        printf("Adding child '%s' to '%s' failed. Exiting.\n", keyB, bodyKey);
        return 1;
    }

    const char *keyC = "h5";
    char *textC = HeapStr("Author Name");
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", bodyKey, keyC, textC);
     if(TreeNodeAdd(body, keyC, textC) == NULL){
        printf("Adding child '%s' to '%s' failed. Exiting.\n", keyC, bodyKey);
        return 1;
    }

    const char *keyD = "p";
    char *textD = HeapStr("Welcome to my page!");
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", bodyKey, keyD, textD);
    if(TreeNodeAdd(body, keyD, textD) == NULL){
        printf("Adding child '%s' to '%s' failed. Exiting.\n", keyD, bodyKey);
        return 1;
    }

    const char *keyE = "p";
    char *textE = HeapStr("Here is a link: ");
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", bodyKey, keyE, textE);
    TreeNode *p = TreeNodeAdd(body, keyE, textE);
    if(p == NULL) {
        printf("Adding child '%s' to '%s' failed. Exiting.\n", keyE, bodyKey);
        return 1;
    }

    const char *keyF = "a";
    char *textF = HeapStr("www.google.com");
    printf("Adding child to '%s' with key '%s' and value '%s'.\n", keyE, keyF, textF);
    if(TreeNodeAdd(p, keyF, textF) == NULL){
        printf("Adding child '%s' to '%s' failed. Exiting.\n", keyF, keyE);
        return 1;
    } 

    printf("\nResult:\n");
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
        printf("Successfully removed key '%s' with value '%s' from Tree.\n", keyD, (char *)value);
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
        printf("Successfully removed key '%s' with value '%s' from '%s'.\n", keyC, (char *)value, bodyKey);
        free(nodeResult);
    }

    printf("\nResult:\n");
    PrintHTMLTree(tree, 0);
    

    printf("\n-- TreeGet() --\n");

    printf("Getting '%s' from the Tree.\n", keyF);
    nodeResult = TreeGet(tree, keyF);
    if(nodeResult == NULL){
        printf("Getting key '%s' from Tree was unsuccessful. Exiting.\n", keyF); 
        return 1;
    } else {
        value = TreeNodeGetValue(nodeResult);
        printf("Successfully retrieved key '%s' with value '%s' from Tree.\n", keyF, (char *)value);
    }

    printf("\n-- TreeNodeGet() --\n");

    printf("Get '%s' from '%s'.\n", keyA, bodyKey);
    nodeResult = TreeNodeGet(body, keyA);
    if(nodeResult == NULL){
        printf("Getting key '%s' from '%s' was unsuccessful. Exiting.\n", keyA, bodyKey); 
        return 1;
    } else {
        value = TreeNodeGetValue(nodeResult);
        printf("Successfully retrieved key '%s' with value '%s' from '%s'.\n", keyA, (char *)value, bodyKey);
    }

    printf("\n-- TreeFree() --\n");

    printf("Freeing the Tree.\n");
    TreeFree(tree);
    
    free(textA);
    free(textB);
    free(textC);
    free(textD);
    free(textE);
    free(textF);

    return 0;
}
