//
//  OneSDKCheckEnvResult.h
//  OneSDKAccount
//
//  Created by zhangzhurong on 2020/7/31.
//  Copyright © 2020年 zhangzhurong. All rights reserved.
//

#import <Foundation/Foundation.h>

//环境支持且预取号成功
static int const PHONE_CHECK_ENV_SUCCESS = 0;
//环境不支持一键登录
static int const PHONE_CHECK_ENV_FAIL_UNSUPPORT = -1;
//预取号失败
static int const PHONE_CHECK_ENV_FAIL_PRELOGIN = -2;

@interface OneSDKCheckEnvResult : NSObject

//SDK状态码
@property (nonatomic, assign) int statusCode;
//第三方SDK返回的code
@property (nonatomic, assign) int code;
//第三方SDK返回的msg
@property (nonatomic, strong) NSString *msg;
//第三方SDK返回的原始的数据对象
@property (nonatomic, strong) NSDictionary *data;

@end
