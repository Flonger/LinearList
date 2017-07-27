//
//  LinearList.h
//  LinearList
//
//  Created by 薛飞龙 on 2017/7/27.
//  Copyright © 2017年 薛飞龙. All rights reserved.
//

#ifndef LinearList_h
#define LinearList_h

#include <stdio.h>

typedef int LinearListValue;

//线性表
typedef struct {
    int capacity;              //容量
    int count;                 //长度
    LinearListValue * value;   //节点数据的指针
}LinearList;

/**
 打印线性表
 */
void printList(LinearList * list);
/**
 创建一个线性表
 */
LinearList * creatList(int capacity);

/**
 销毁线性表
 */
void releasaList(LinearList * list);

/**
 清空线性表
 */
void clearList(LinearList * list);

/**
 获取线性表的长度
 */
int getListCount(LinearList * list);

/**
 获取index的值
 */
LinearListValue getValueWithCount(LinearList * list,int index);

/**
 插入数据
 */
void insertValue(LinearList * list, int index, LinearListValue value);

/**
 添加数据
 */
void addValue(LinearList * list, LinearListValue value);

/**
 设置数据
 */
void setValue(LinearList * list, int index, LinearListValue value);

/**
 删除索引的数据
 */
void deleteIndex(LinearList * list, int index);


/**
 删除所有值得数据
 */
void deleteValue(LinearList * list, LinearListValue value);

void isEmpty(LinearList * list);
#endif /* LinearList_h */
