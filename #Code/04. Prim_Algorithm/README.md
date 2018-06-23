# 实验No.04 ```2018-06-21```

编程实现算法图论中的Prim算法，根据这个算法，找出一个无向图的支撑树，如果图不连通，那就找出所有的支撑子图。

图（Graph）的数据结构为邻接映射表（Adjacent Map），要实现Map，首先要实现哈希映射，这里采用的哈希函数是CRC32.

## 1. API of HashMap

此模块由开源者提供。具体参见代码中给出的email.

```C
typedef struct _hashmap_element {
    char *key;                  // The key of the node
    int in_use;                 // 0, unused; 1, has been used
    any_t data;                 // void pointer, container for arbitary datatype
} hashmap_element;

// A hashmap has some maximum size and current size,
// as well as the data to hold.
typedef struct _hashmap_map {
    int table_size;             // Capacity
    int size;                   // used
    hashmap_element *data;      // low level struct array
} hashmap_map;
```

API

```C
- map_t hashmap_new()
- unsigned long crc32(const unsigned char *s, unsigned int len)
- unsigned int hashmap_hash_int(hashmap_map * m, char* keystring)
- int hashmap_hash(map_t in, char* key)
- int hashmap_rehash(map_t in)
- int hashmap_put(map_t in, char* key, any_t value)
- int hashmap_get(map_t in, char* key, any_t *arg)
- int hashmap_iterate(map_t in, PFany f, any_t item)
- int hashmap_remove(map_t in, char* key)
- void hashmap_free(map_t in)
- int hashmap_length(map_t in)
```

```null
- hashmap_new           :新建一个空的哈希表
- crc32                 :输入key与其长度，做一个按位比特操作
- hashmap_hash_int      :哈希函数，给出一个key在给定map下的
- hashmap_hash          :这个函数类似桶数组循环赋值，从hash_int开始找空位，最多找8次
- hashmap_rehash        :加倍哈希表的容量
- hashmap_put           :往哈希表里放一个node
- hashmap_get           :从哈希表里取一个value出来，这里的value采取的是赋值式（或许这并不是一个很好的实现方式，但是很管用）
- hashmap_iterate       :????????????????
- hashmap_remove        :移除一个键值对
- hashmap_free          :释放内存
- hashmap_length        :获得哈希表的已经使用的长度
```