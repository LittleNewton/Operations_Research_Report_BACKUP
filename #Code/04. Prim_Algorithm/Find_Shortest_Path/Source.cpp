/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Source.cpp
* 文件标识：见配置管理计划书
* 摘 要：测试Prim算法
*
* 当前版本：1.0
* 作 者：刘鹏
* 创建日期：2018年6月20日
* 完成日期：2018年6月
*
* 取代版本：0.9
* 原作者 ：刘鹏
* 完成日期：
*/

/*
* A unit test and example of how to use the simple C hashmap
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "HashMap.h"

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024*1024)

typedef struct data_struct_s
{
    char key_string[KEY_MAX_LENGTH];	// This is a string pointer.
    int number;
} data_struct_t;

int main(char* argv, int argc)
{
    int index;
    int error;
    map_t mymap;
    char key_string[KEY_MAX_LENGTH];
    data_struct_t *value;

    mymap = hashmap_new();

    /* First, populate the hash map with ascending values */
    for (index = 0; index < KEY_COUNT; index += 1) {
        /* Store the key string along side the numerical value so we can free it later */
        value = (data_struct_t *)malloc(sizeof(data_struct_t));
        snprintf(value->key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);
        value->number = index;

        error = hashmap_put(mymap, value->key_string, value);
        assert(error == MAP_OK);
    }

	char findX[] = "";
	any_t *ans = 0;

	printf("%d\n", hashmap_get(mymap, findX, ans));
	printf("%s", *ans);
	printf("\n\n--------------------\n");
	return 0;

    /* Now, check all of the expected values are there */
    for (index = 0; index < KEY_COUNT; index += 1){
        snprintf(value->key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);

        error = hashmap_get(mymap, key_string, (void**)(&value));

        /* Make sure the value was both found and the correct number */
        assert(error == MAP_OK);
        assert(value->number == index);
    }

    /* Make sure that a value that wasn't in the map can't be found */
    snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, KEY_COUNT);

    error = hashmap_get(mymap, key_string, (void**)(&value));

    /* Make sure the value was not found */
    assert(error == MAP_MISSING);

    /* Free all of the values we allocated and remove them from the map */
    for (index = 0; index<KEY_COUNT; index += 1)
    {
        snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);

        error = hashmap_get(mymap, key_string, (void**)(&value));
        assert(error == MAP_OK);

        error = hashmap_remove(mymap, key_string);
        assert(error == MAP_OK);

        free(value);
    }

    /* Now, destroy the map */
    hashmap_free(mymap);

    return 1;
}