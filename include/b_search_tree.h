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

#ifndef STD_DDS_B_SEARCH_TREE_H
#define STD_DDS_B_SEARCH_TREE_H

#include "std_dds_core.h"

#include <stddef.h>

typedef struct bSTreeNode {
    int value;
    struct bSTreeNode *left;
    struct bSTreeNode *right;
} BSTreeNode;

/**
 * Initialise and allocate memory for a BSTreeNode object.
 * @param value The value of the BSTreeNode.
 * @return A pointer to the initialised BSTreeNode.
 * Returns NULL if memory allocation failed.
**/
BSTreeNode *BSTreeNodeInit(const int value);

/**
 * Search a tree for a specific value.
 * @param tree The root node of the tree to search.
 * @param value The value to search for.
 * @return A pointer to the node that contains the value.
 * Returns NULL if the value is not within the tree.
**/
BSTreeNode *BSTreeGetNode(BSTreeNode *tree, const int value);

/**
 * Insert a value into a tree at the next avaliable leaf.
 * @param tree The root node of the tree to insert the value into.
 * @param value The value to insert.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT BSTreeInsert(BSTreeNode *tree, const int value);

/**
 * Insert a value into a tree at the next avaliable leaf.
 * @param tree The root node of the tree to insert the value into.
 * @param value The value to insert.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT BSTreeRemove(BSTreeNode *tree, const int value);

/**
 * Join two trees into a single tree.
 * @param tree1 The first tree to join.
 * @param tree2 The second tree to join.
 * @return A pointer to the new root node of the combined trees.
**/
BSTreeNode *BSTreeJoin(BSTreeNode *tree1, BSTreeNode *tree2);


/**
 * Calculate the total height of a tree.
 * @param tree The root node of the tree to query.
 * @return The total height of the tree.
 * Returns -1 if tree is NULL.
**/
size_t BSTreeGetHeight(const BSTreeNode *tree);

/**
 * Calculate the max width of a tree.
 * @param tree The root node of the tree to query.
 * @return The max width of the tree.
 * Returns -1 if tree is NULL. 
**/
size_t BSTreeGetMaxWidth(const BSTreeNode *tree);

/**
 * Free the allocated memory for a tree and its nodes.
 * @param tree The root node of the tree to free.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT BSTreeFree(BSTreeNode *tree);

#endif // STD_DDS_B_SEARCH_TREE_H
