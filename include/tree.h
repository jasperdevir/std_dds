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

TreeNode *TreeNodeInit(const char *key, void *value);

TreeNode *TreeNodeGet(const TreeNode *parent, const char *key);
TreeNode *TreeGet(const TreeNode *tree, const char *key);

TreeNode *TreeNodeAdd(TreeNode *parent, const char *key, void *value);
STD_DDS_RESULT TreeNodeAddNode(TreeNode *parent, TreeNode *child);

TreeNode *TreeNodeRemove(TreeNode *parent, const char *key);
TreeNode *TreeRemove(TreeNode *tree, const char *key);

void *TreeNodeGetValue(const TreeNode *node);
char *TreeNodeGetKey(const TreeNode *node);
ArrayList *TreeNodeGetChildren(TreeNode *node);

STD_DDS_RESULT TreeFree(TreeNode *tree);

#endif // STD_DDS_TREE_H
