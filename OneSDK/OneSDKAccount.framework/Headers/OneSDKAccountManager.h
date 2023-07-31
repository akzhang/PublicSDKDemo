//
//  OneSDKAccountManager.h
//  OneSDKAccountManager
//
//  Created by tanghongtu on 2018/9/7.
//  Copyright © 2018年 zengzhifeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OneSDKLoginResult.h"
#import "OneSDKCheckEnvResult.h"
#import "OneSDKPhoneLoginResult.h"

typedef enum{
    BAITIAN_PALTFORM_LOGIN = 0,
    WECHAT_PLATFORM_LOGIN = 1,
    QQ_PLATFORM_LOGIN = 2,
    WEIBO_PLATFORM_LOGIN = 3
}OneSDKAccountPlatform;//登录使用的平台

//返回码
static int const SUCCESS_ONE_SDK_RESULT_CODE = 0;
static int const FAILURE_ONE_SDK_RESULT_CODE = -1;
static int const CANCELL_ONE_SDK_RESULT_CODE = -2;
//返回消息
static NSString * const SUCCESS_ONE_SDK_RESULT_MSG = @"登录成功";
static NSString * const FAILURE_ONE_SDK_RESULT_MSG = @"登录失败";
static NSString * const CANCELL_ONE_SDK_RESULT_MSG = @"登录取消";

//事件通知
static NSString * const EVENT_NOTIFICATION_START_3RD_LOGIN = @"start3rdLogin";
static NSString * const EVENT_NOTIFICATION_3RD_LOGIN_CALLBACK = @"get3rdCallback";
static NSString * const EVENT_NOTIFICATION_ONEKEY_LOGIN_TRACK = @"onekeyLoginTrack";

@protocol OneSDKAccountDelegate <NSObject>

//第三方登录结果回调
- (void)loginCallback:(OneSDKLoginResult *)result;

//一键登录预取号结果回调
- (void)onPhoneCheckEnvResult:(OneSDKCheckEnvResult *)result;
//一键登录结果回调
- (void)onPhoneLoginResult:(OneSDKPhoneLoginResult *)result;

@end

@interface OneSDKAccountManager : NSObject

@property (nonatomic, weak) id<OneSDKAccountDelegate> delegate;
@property (nonatomic, copy) NSString *gameID;
//@property (nonatomic, retain) UIViewController *viewController;
@property (nonatomic, weak) UIViewController *viewController;

+ (instancetype)sharedInstance;

- (void)initSDK:(id<OneSDKAccountDelegate>)delegate
         gameID:(NSString *)gameID
 viewController:(UIViewController *)viewController;

/**
 登录可选平台

 @param platform 平台
 */
- (void)loginWithPlatform:(OneSDKAccountPlatform)platform;

/**
 一键登录 - 初始化一键登录SDK
 */
- (void)initOneKeyLoginSdk:(NSString *)authSdkInfo;

/**
 一键登录 - 检测环境是否支持一键登录 且 预取号是否成功
 @param timeout 超时时间，单位s
 */
- (void)checkOneKeyLoginEnv:(int)timeout;

/**
 一键登录 - 开始一键登录
 @param timeout 超时时间，单位s
 */
- (void)startOneKeyLogin:(int)timeout;

//===================================================================
//                       生命周期方法
//===================================================================

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url;

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

- (BOOL)application:(UIApplication *)application
continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void
                                                                        (^_Nonnull)(NSArray *_Nullable))restorationHandler;

@end
