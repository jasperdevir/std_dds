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

#include <stdio.h>

void PrintBSTreeNode(const BSTreeNode *node, int indent, int indentStep) {
    if (!node) return;

    if (node->right) {
        PrintBSTreeNode(node->right, indent + indentStep, indentStep);
    }

    for (int i = 0; i < indent; i++){
        printf(" ");
    }
    printf("->%d\n", node->value);

    if (node->left) {
        PrintBSTreeNode(node->left, indent + indentStep, indentStep);
    }
}

void PrintBSTree(const BSTreeNode* tree){
    PrintBSTreeNode(tree, 0, 2);
}

int main(void){
    printf("\n== std_dds Binary Search Tree Example ==\n");

    printf("\n-- BSTreeNodeInit() --\n");

    int a1 = 4;
    printf("Initialising BSTree with a value of '%d'.\n", a1);
    BSTreeNode *treeA = BSTreeNodeInit(a1);

    int b1 = 8;
    printf("Initialising BSTree with a value of '%d'.\n", b1);
    BSTreeNode *treeB = BSTreeNodeInit(b1);

    printf("\n-- BSTreeInsert() --\n");

    int a2 = 10;
    printf("Inserting '%d' into 'treeA'.\n", a2);
    BSTreeInsert(treeA, a2);

    int a3 = 2;
    printf("Inserting '%d' into 'treeA'.\n", a3);
    BSTreeInsert(treeA, a3);

    int a4 = 9;
    printf("Inserting '%d' into 'treeA'.\n", a4);
    BSTreeInsert(treeA, a4);

    int b2 = 1;
    printf("Inserting '%d' into 'treeB'.\n", b2);
    BSTreeInsert(treeB, b2);

    int b3 = 12;
    printf("Inserting '%d' into 'treeB'.\n", b3);
    BSTreeInsert(treeB, b3);

    int b4 = 6;
    printf("Inserting '%d' into 'treeB'.\n", b4);
    BSTreeInsert(treeB, b4);

    printf("\n'treeA' Result:\n");
    PrintBSTree(treeA);

    printf("\n'treeB' Result:\n");
    PrintBSTree(treeB);

    printf("\n-- BSTreeJoin() --\n");

    printf("Joining 'treeA' and 'treeB' to create 'treeC'.\n");
    BSTreeNode *treeC = BSTreeJoin(treeA, treeB);

    printf("\n-- BSTreeRemove() --\n");

    printf("Removing '%d' from 'treeC'.\n", b4);
    BSTreeRemove(treeC, b4);

    printf("\n'treeC' Result:\n");
    PrintBSTree(treeC);

    printf("\n-- BSTreeGet() --\n");

    printf("Getting '%d' node from 'treeC'.\n", a3);
    BSTreeNode *a3Node = BSTreeGetNode(treeC, a3);
    if(a3Node == NULL){
        printf("Getting '%d' node from 'treeC' was unsuccessful. Exiting.\n", a3);
        return 1;
    } else {
        printf("Successfully recieved '%d' node from 'treeC'.\n", a3);
    }

    printf("\n-- BSTreeNodeFree() --\n");
    
    printf("Freeing BSTree.\n");
    BSTreeFree(treeC);

    return 0;
}
