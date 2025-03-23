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

/* 
Define STD_DDS_ERROR_MSG to print error messages to stderr output
Define STD_DDS_WARNING_MSG to print warning messages to stdout output
Note: STD_DDS_WARNING_MSG automatically defines STD_DDS_ERROR_MSG

E.g.
    #define STD_DDS_WARNING_MSG
    // Both error and warning messages are now enabled
*/

#include "array_list.h"
#include "linked_list.h"
#include "d_linked_list.h"
#include "stack.h"
#include "queue.h"