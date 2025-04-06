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

#ifndef STD_DDS_TREE_H
#define STD_DDS_TREE_H

#include "array_list.h"
#include "std_dds_core.h"

typedef struct treeNode TreeNode;

/**
 * Initialise and allocate memory for a TreeNode object.
 * @param key The key identifier of the Treenode.
 * @param value The value of the TreeNode.
 * @return A pointer to the initialised TreeNode.
 * Returns NULL if memory allocation failed.
**/
TreeNode *TreeNodeInit(const char *key, void *value);

/**
 * Get the first node that matches a specified key from the immediate children of a TreeNode.
 * @param parent The TreeNode to search.
 * @param key The key identifier to find.
 * @return A pointer to the TreeNode found.
 * Returns NULL if the children of the TreeNode does not contain a node with the specified key.
**/
TreeNode *TreeNodeGet(const TreeNode *parent, const char *key);

/**
 * Get the first node that matches a specified key from a tree.
 * @param tree The root node of the tree to search.
 * @param key The key identifier to find.
 * @return A pointer to the TreeNode found.
 * Returns NULL if the tree does not contain a node with the specified key.
**/
TreeNode *TreeGet(const TreeNode *tree, const char *key);

/**
 * Initialise a TreeNode object and add it to the children of another TreeNode.
 * @param parent The TreeNode to add to.
 * @param key The key identifier of the new TreeNode.
 * @param value The value of the new TreeNode.
 * @return A pointer to the added TreeNode.
**/
TreeNode *TreeNodeAdd(TreeNode *parent, const char *key, void *value);

/**
 * Add a TreeNode to the children of another TreeNode.
 * @param parent The TreeNode to add to.
 * @param child The TreeNode to add to the parent.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT TreeNodeAddNode(TreeNode *parent, TreeNode *child);

/**
 * Remove the first node that matches a specified key from the immediate children of a TreeNode.
 * @param parent The TreeNode to remove a node from.
 * @param key The key identifier to find.
 * @return A pointer to the TreeNode removed.
 * Returns NULL if the children of the TreeNode does not contain a node with the specified key.
**/
TreeNode *TreeNodeRemove(TreeNode *parent, const char *key);

/**
 * Remove the first node that matches a specified key from a tree.
 * @param tree The root node of the tree to remove a node from.
 * @param key The key identifier to find.
 * @return A pointer to the TreeNode removed.
 * Returns NULL if the tree does not contain a node with the specified key.
**/
TreeNode *TreeRemove(TreeNode *tree, const char *key);

/**
 * Get the value of a TreeNode.
 * @param node The TreeNode to query.
 * @return The value of a TreeNode.
 * Returns NULL if the node is NULL.
**/
void *TreeNodeGetValue(const TreeNode *node);

/**
 * Get the key identifier of a TreeNode.
 * @param node The TreeNode to query.
 * @return The key of a TreeNode.
 * Returns NULL if the node is NULL.
**/
char *TreeNodeGetKey(const TreeNode *node);

/**
 * Get the children of a TreeNode.
 * @param node The TreeNode to query.
 * @return The children of a TreeNode as an ArrayList.
 * Returns NULL if the node is NULL.
**/
ArrayList *TreeNodeGetChildren(TreeNode *node);

/**
 * Free the allocated memory for a tree and its children.
 * DOES NOT free the values of each node.
 * @param tree The tree to free.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT TreeFree(TreeNode *tree);

#endif // STD_DDS_TREE_H
