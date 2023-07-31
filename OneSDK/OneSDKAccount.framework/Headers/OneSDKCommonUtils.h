//
//  OneSDKCommonUtils.h
//  ThirdPartyLoginDemo
//
//  Created by tanghongtu on 2018/9/13.
//  Copyright © 2018年 ywzc-2016A. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface OneSDKCommonUtils : NSObject

typedef enum{
    LOCAL_TEST = 1,
    ONLINE_TEST = 2,
    RELEASE = 3,
}RUNNING_TYPE;

+ (NSString *)getStringFromPList:(NSString *)key;

/*!
 @method
 @brief 获取指定Bundle里指定plist的Dictionary
 @param key 该Dictonary的Key
 @param bundle 指定Bundle的名称
 @param pList 指定plist的名称
 @return 指定Key的Dictionary
 */
+ (NSDictionary *)getDicsFromBundlePList:(NSString *)key
                              bundleName:(NSString *)bundle
                               pListName:(NSString *)pList;

/*!
 @method
 @brief 获取指定Bundle的Info.plist的字符串
 @param key 该字符串的Key
 @param bundle 指定Bundle的名称
 @param pList 指定plist的名称
 @return 指定Key的字符串
 */
+ (NSString *)getStringFromBundlePList:(NSString *)key
                            bundleName:(NSString *)bundle
                             pListName:(NSString *)pList;

+ (int)getRunningType;

+ (UIViewController *)getRootController;

/**
 获取屏幕宽度，单位pt
 
 @return 屏幕宽度
 @note 获取设备分辨率使用 getResolutionRatio
 */
+ (CGFloat)getScreenWidth;

/**
 获取屏幕长度，单位pt
 
 @return 屏幕长度
 @note 获取设备分辨率使用 getResolutionRatio
 */
+ (CGFloat)getScreenHeight;

/**
 获取屏幕缩放比
 
 @return 屏幕缩放比
 */
+ (CGFloat)getScreenScale;

/**
 Unicode字符串 转 UTF-8字符串
 @param unicodeStr Unicode编码的字符串
 @return UTF-8编码的字符串
 */
+ (NSString *)replaceUnicode:(NSString *)unicodeStr;

@end
