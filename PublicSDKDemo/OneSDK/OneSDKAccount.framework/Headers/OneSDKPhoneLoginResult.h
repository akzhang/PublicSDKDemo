//
//  OneSDKPhoneLoginResult.h
//  OneSDKAccount
//
//  Created by zhangzhurong on 2020/7/31.
//  Copyright © 2020年 zhangzhurong. All rights reserved.
//

#import <Foundation/Foundation.h>

//一键登录成功
static int const PHONE_LOGIN_SUCCESS = 0;
//一键登录失败，选择其他登录方式
static int const PHONE_LOGIN_OTHER_ACCOUNT = -1;

@interface OneSDKPhoneLoginResult : NSObject

//SDK状态码
@property (nonatomic, assign) int statusCode;
//第三方SDK返回的code
@property (nonatomic, assign) int code;
//第三方SDK返回的msg
@property (nonatomic, strong) NSString *msg;
//第三方SDK返回的token
@property (nonatomic, strong) NSString *loginToken;

//第三方SDK返回的原始的数据对象
@property (nonatomic, strong) NSDictionary *data;

@end
