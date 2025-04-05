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
#include "std_dds_core.h"

#include <stdio.h>

void PrintResultCode(STD_DDS_RESULT result){
    switch(result){
        default: 
            printf("[%d] Unknown STD_DDS_RESULT\n", result);
            break;
        case STD_DDS_SUCCESS:
            printf("[%d] STD_DDS_SUCCESS\n", result);
            break;
        case STD_DDS_NULL_PARAM:
            printf("[%d] STD_DDS_NULL_PARAM\n", result);
            break;
        case STD_DDS_OUT_OF_BOUNDS:
            printf("[%d] STD_DDS_OUT_OF_BOUNDS\n", result);
            break;
        case STD_DDS_NOT_FOUND:
            printf("[%d] STD_DDS_NOT_FOUND\n", result);
            break;
        case STD_DDS_DUPLICATE_VALUE:
            printf("[%d] STD_DDS_DUPLICATE_VALUE\n", result);
            break;
        case STD_DDS_MALLOC_FAILED:
            printf("[%d] STD_DDS_MALLOC_FAILED\n", result);
            break;
        case STD_DDS_CALLOC_FAILED:
            printf("[%d] STD_DDS_CALLOC_FAILED\n", result);
            break;
        case STD_DDS_REALLOC_FAILED:
            printf("[%d] STD_DDS_REALLOC_FAILED\n", result);
            break;
    }
}
