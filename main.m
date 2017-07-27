//
//  main.m
//  LinearList
//
//  Created by 薛飞龙 on 2017/7/27.
//  Copyright © 2017年 薛飞龙. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LinearList.h"



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        
        
        LinearList * list = creatList(10);
        addValue(list, 1);
        addValue(list, 2);
        addValue(list, 3);
        printList(list);
        
        releasaList(list);

    }
    return 0;
}
