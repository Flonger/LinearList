//
//  LinearList.c
//  LinearList
//
//  Created by 薛飞龙 on 2017/7/27.
//  Copyright © 2017年 薛飞龙. All rights reserved.
//

#include "LinearList.h"
#include <stdlib.h>

LinearList * creatList(int capacity){
    if (capacity < 0) {
        return NULL;
    }
    LinearList * list = malloc(sizeof(LinearList));
    if (list) {
        list -> capacity = capacity;
        list -> count = 0;
        list -> value = malloc(sizeof(LinearListValue) * capacity);
    }
    return list;
}

void printList(LinearList * list){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    
    printf("list{\n");
    printf("\tcount = %d;\n",list -> count);
    printf("\tcapacity = %d;\n",list -> capacity);
    printf("\tvalue = [");
    for (int i = 0; i < list -> count; i++) {
        printf("%d",list -> value[i]);
        if (i < list -> count -1) {
            printf(",");
        }
    }
    printf("];\n}\n\n");

}

void releasaList(LinearList * list){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    
    free(list -> value);
    free(list);
}


void clearList(LinearList * list){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    list -> count = 0;
    
}

int getListCount(LinearList * list){
    if (list == NULL) {
        printf("list is NULL");
        return 0;
    }
    return list -> count;
}

LinearListValue getValueWithCount(LinearList * list,int index){
    if (list == NULL) {
        printf("list is NULL");
        return 0;
    }
    return list -> value[index];
}

void insertValue(LinearList * list, int index, LinearListValue value){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    if (index < 0 || index > list -> count || list -> count == list -> capacity) {
        return;
    }
    
    //从index开始挪动后面的数据
    for (int i = list -> count - 1; i >= index; i--) {
        list -> value[i + 1] = list -> value[i];
    }
    //设置新的值到index
    list -> value[index] = value;
    
    //设置count
    list -> count ++;
}

void addValue(LinearList * list, LinearListValue value){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    insertValue(list, list -> count, value);
}

void setValue(LinearList * list, int index, LinearListValue value){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    if (index < 0 || index >= list -> count) {
        return;
    }
    list -> value[index] = value;
}

void deleteIndex(LinearList * list, int index){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    if (index < 0 || index >= list -> count) {
        return;
    }
    
    for (int i = index + 1; i < list -> count; i++) {
        list -> value[i-1] = list -> value[i];
    }
    //数量减少
    list -> count --;
}


void deleteValue(LinearList * list, LinearListValue value){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    //定义一个初始记录
    int removeCount = 0;
    //遍历所有元素
    for (int i = 0; i < list -> count; i++) {
        if (list -> value[i] == value) {
            //删除记录加1
            removeCount ++;
        }else{
            //挪动
            list -> value[i - removeCount] = list -> value[i];
        }
    }
    //个数减去删除的个数
    list -> count -= removeCount;
    
    
}







