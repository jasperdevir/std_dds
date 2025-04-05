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

#ifndef STD_DDS_CORE_H
#define STD_DDS_CORE_H

#define STD_DDS_MAX_KEY 256

/* RESULT CODES */

/**
 * When an std_dds function does not need to return a value or a pointer
 * it will return a result code 'STD_DDS_RESULT'.
**/

#define STD_DDS_RESULT unsigned int

/**
 * A result code of 0 is a success.
**/

#define STD_DDS_SUCCESS 0

/**
 * Result codes 1 to 999 are non-critical errors.
**/

#define STD_DDS_NULL_PARAM 100

#define STD_DDS_OUT_OF_BOUNDS 200

#define STD_DDS_NOT_FOUND 210

#define STD_DDS_DUPLICATE_VALUE 300

/**
 * Result codes 1000 onward are critical errors.
**/

#define STD_DDS_MALLOC_FAILED 1000

#define STD_DDS_REALLOC_FAILED 1010

#define STD_DDS_CALLOC_FAILED 1020

#endif // STD_DDS_CORE_H

