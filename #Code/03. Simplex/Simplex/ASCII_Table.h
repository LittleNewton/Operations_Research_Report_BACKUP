/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：ASCII_Table.h
* 文件标识：
* 摘 要：接受一系列的C标准类型，用ASCII表格的形式输出。
*
* 当前版本：1.0
* 作 者：刘鹏
* 完成日期：2018年5月9日
*
*/


#pragma once

/*
+------------------------------+
|            Basket            |
+----+-----------------+-------+
| Id | Name            | Price |
+----+-----------------+-------+
|  1 | Dummy product 1 |  24.4 |
|  2 | Dummy product 2 |  21.2 |
|  3 | Dummy product 3 |  12.3 |
+----+-----------------+-------+
|    | Total           |  57.9 |
+----+-----------------+-------+

* Table Name = strcpy("Table Name", No.)
* double => char * => strlen(char *) => Number of elements in this row => each elements 

*/

#include <string.h>

typedef struct single_char_Dynamic_Array {

};