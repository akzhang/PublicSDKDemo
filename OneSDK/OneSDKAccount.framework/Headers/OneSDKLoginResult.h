//
//  OneSDKLoginResult.h
//  OneSDKAccount
//
//  Created by tanghongtu on 2018/9/10.
//  Copyright © 2018年 zengzhifeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OneSDKLoginResult : NSObject

@property (nonatomic, assign) int code;
@property (nonatomic, copy) NSDictionary *data;
@property (nonatomic, copy) NSString *msg;

@end
