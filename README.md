# Operations_Research_Report

　　云南大学数学与统计学院李建平教授讲授的**运筹学通论**实验报告
	
## 1.实验No.01 ```2017-03-18```

### 1.1 本实验的重要性
　　第一份实验是为后期的某个或者某些个实验进行辅助，所以需要**认真测试**，由于Visual C并不支持动态数组，而后期实验又有可能需要这个无限扩展的功能，所以这个实验的代码自行实现了一个动态数组。

### 1.2 代码解释

　　问题参见```./Word/20151910042-刘鹏-运筹学实验-01.docx```

　　对于如何构建能容纳**任意类型**的动态数组这个问题，我暂时还没有找到好的方法，或许可能的一种是利用enum，但是这仍旧需要改动态数组库。希望后期能够解决这个问题。
　　
　　本段代码大量使用指针，指针数组，所以可能不太利于阅读代码。详见以下摘要，与算法相比，**数据结构显得更加重**要，因为任何算法都要依托某种数据结构。
``` 
typedef struct char_LinkedList {
    char_LinkedList *head;
    char elements;			// partition must be integer less than 10
    int times;				// 这是一个容器，放置一个数组，用指针作为头
    char_LinkedList *next;
}char_LinkedList;

typedef struct Dynamic_Array {
    double *A;				// 底层数组
    int capacity;			// 底层数组的容量
    int n;					// 底层数组的占用量
}Dynamic_Array;

typedef struct Div {
    double up;
    double down;
    double value;
    char state[10];			// NaN or Negative，长度不定
                            // 这个state必须是malloc而来的，坚决不能直接用
}Div;

typedef struct Div_Dynamic_Array {
    Div *A;             // 底层结构体数组的头指针，不能动！
    int capacity;       // 底层结构体数组的容量
    int n;              // 底层数组的占用量
}Div_Dynamic_Array;
```
 - ```char_LinkedList```： 字符串链表，用来存放字符串参数；
 - ```Dynamic_Array```： 动态数组。准确说来这个数组是用来放置double变量的，它后期用于放置从字符串参数中读出的double数值；
 - ```Div_Dynamic_Array```：存放```Div```指针节点动态数组
 - ```Div```： 存放四个状态值，分别是分母，分子，商，分母对应情况下的状态：```NaN，分母为零```，```Negative，分母为负```，```Normal，其他情况```。

### 1.3 使用说明

　　切换到可执行文件所在的目录，打开shell，如Windows PowerShell，可能的交互式界面如下：

```
PS > .\div.exe "( -3.14,20 ,-256, 0 ,6,5,12121,4588, 89)" "(3.14, -1, 256,3.2222,2,0,5633.2,168,78)"
argument 1 is
(-3.14, 20.00, -256.00, 0.00, 6.00, 5.00, 12121.00, 4588.00, 89.00)

argument 2 is
(3.14, -1.00, 256.00, 3.22, 2.00, 0.00, 5633.20, 168.00, 78.00)

The answer C = (-1.00 , -20.00 , -1.00 , 0.00 , 3.00 , NaN , 2.15 , 27.31 , 1.14 )
Minimal Value is -1.00 , position is (1.00, 3.00)

PS >
```

　　实际使用情况视shell情况而定，此代码未在gcc下调试过。

### 1.4 后期可能的更新

- 优化部分代码；
- 修改报告Word文档的格式；
- 用gcc调试，适用于Linux bash shell.

## 2. 实验No.02 ```2017-03-28```

　　实现一个简单的线性规划问题。

　　这个算法相当简单，而且输入的系数矩阵是一个简单的行向量，所以直接输出就可以。但是其中的原理以及原理的证明非常有意思。我将完成这个证明。

### 2.1 本实验的重要性

　　作为**单纯形算法**的一个简单应用，我将本实验的主要部分放在证明与理解上，如果还有时间，会把这个程序在尽可能靠前的提交里写得尽可能复杂一点。

### 2.2 代码解释

　　待续。
