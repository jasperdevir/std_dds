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

typedef struct bSTreeNode {
    int value;
    struct bSTreeNode *left;
    struct bSTreeNode *right;
} BSTreeNode;

BSTreeNode *BSTreeNodeInit(const int value);

BSTreeNode *BSTreeGetNode(BSTreeNode *tree, const int value);

STD_DDS_RESULT BSTreeInsert(BSTreeNode *tree, const int value);

STD_DDS_RESULT BSTreeRemove(BSTreeNode *tree, const int value);

BSTreeNode *BSTreeJoin(BSTreeNode *left, BSTreeNode *right);

STD_DDS_RESULT BTreeFree(BSTreeNode *tree);

#endif // STD_DDS_B_SEARCH_TREE_H
