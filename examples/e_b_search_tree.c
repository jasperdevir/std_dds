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
#include "std_dds_utils.h"
#include "b_search_tree.h"

#include <stdio.h>

void PrintBSTreeNode(const BSTreeNode *node, int depth, char prefix) {
    if (!node) {
        return;
    }

    if (node->right) {
        PrintBSTreeNode(node->right, depth + 1, '/');
    }

    for (int i = 0; i < depth - 1; i++){
        printf("    ");
    }
    if(depth > 0){
        printf(" %c--", prefix);
    }

    printf("%d\n", node->value);

    if (node->left) {
        PrintBSTreeNode(node->left, depth + 1, '\\');
    }
}

int main(void){
    STD_DDS_RESULT result;

    printf("\n== std_dds Binary Search Tree Example ==\n");

    printf("\n-- BSTreeNodeInit() --\n");

    int a1 = 4;
    printf("Initialising BSTree with a value of '%d'.\n", a1);
    BSTreeNode *treeA = BSTreeNodeInit(a1);
    if(treeA == NULL){
        printf("Failed to initialise BSTreeNode. Exiting.\n");
        return 1;
    }

    int b1 = 8;
    printf("Initialising BSTree with a value of '%d'.\n", b1);
    BSTreeNode *treeB = BSTreeNodeInit(b1);
    if(treeB == NULL){
        printf("Failed to initialise BSTreeNode. Exiting.\n");
        BSTreeFree(treeA);
        return 1;
    }

    printf("\n-- BSTreeInsert() --\n");

    int a2 = 10;
    printf("Inserting '%d' into 'treeA'.\n", a2);
    result = BSTreeInsert(treeA, a2);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert into tree. Exiting.\n");
        BSTreeFree(treeA);
        BSTreeFree(treeB);
        return 1;
    }

    int a3 = 2;
    printf("Inserting '%d' into 'treeA'.\n", a3);
    result = BSTreeInsert(treeA, a3);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert into tree. Exiting.\n");
        BSTreeFree(treeA);
        BSTreeFree(treeB);
        return 1;
    }

    int a4 = 9;
    printf("Inserting '%d' into 'treeA'.\n", a4);
    result = BSTreeInsert(treeA, a4);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert into tree. Exiting.\n");
        BSTreeFree(treeA);
        BSTreeFree(treeB);
        return 1;
    }

    int b2 = 1;
    printf("Inserting '%d' into 'treeB'.\n", b2);
    result = BSTreeInsert(treeB, b2);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert into tree. Exiting.\n");
        BSTreeFree(treeA);
        BSTreeFree(treeB);
        return 1;
    }

    int b3 = 12;
    printf("Inserting '%d' into 'treeB'.\n", b3);
    result = BSTreeInsert(treeB, b3);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert into tree. Exiting.\n");
        BSTreeFree(treeA);
        BSTreeFree(treeB);
        return 1;
    }

    int b4 = 6;
    printf("Inserting '%d' into 'treeB'.\n", b4);
    result = BSTreeInsert(treeB, b4);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert into tree. Exiting.\n");
        BSTreeFree(treeA);
        BSTreeFree(treeB);
        return 1;
    }

    printf("\n'treeA' Result:\n");
    PrintBSTreeNode(treeA, 0, '-');

    printf("\n'treeB' Result:\n");
    PrintBSTreeNode(treeB, 0, '-');

    printf("\n-- BSTreeJoin() --\n");

    printf("Joining 'treeA' and 'treeB' to create 'treeC'.\n");
    BSTreeNode *treeC = BSTreeJoin(treeA, treeB);
    if(treeC == NULL){
        printf("Failed to join 'treeA' and 'treeB'. Exiting.\n");
        BSTreeFree(treeA);
        BSTreeFree(treeB);
        return 1;
    }

    printf("\n-- BSTreeRemove() --\n");

    printf("Removing '%d' from 'treeC'.\n", b4);
    result = BSTreeRemove(treeC, b4);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to remove '%d' from 'treeC'. Exiting.\n", b4);
        BSTreeFree(treeC);
        return 1;
    }

    printf("\n'treeC' Result:\n");
    PrintBSTreeNode(treeC, 0, '-'); 

    printf("\n-- BSTreeGet() --\n");

    printf("Getting '%d' node from 'treeC'.\n", a3);
    BSTreeNode *a3Node = BSTreeGetNode(treeC, a3);
    if(a3Node == NULL){
        printf("Getting '%d' node from 'treeC' was unsuccessful. Exiting.\n", a3);
        BSTreeFree(treeC);
        return 1;
    }
    
    printf("Successfully recieved '%d' node from 'treeC'.\n", a3);
    
    printf("\n-- BSTreeNodeFree() --\n");
    
    printf("Freeing BSTree.\n");
    BSTreeFree(treeC);

    return 0;
}
