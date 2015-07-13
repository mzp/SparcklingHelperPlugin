//
//  NSObject_Extension.m
//  SparcklingHelperPlugin
//
//  Created by mzp on 7/13/15.
//  Copyright © 2015 mzp. All rights reserved.
//


#import "NSObject_Extension.h"
#import "SparcklingHelperPlugin.h"

@implementation NSObject (Xcode_Plugin_Template_Extension)

+ (void)pluginDidLoad:(NSBundle *)plugin
{
    static dispatch_once_t onceToken;
    NSString *currentApplicationName = [[NSBundle mainBundle] infoDictionary][@"CFBundleName"];
    if ([currentApplicationName isEqual:@"Xcode"]) {
        dispatch_once(&onceToken, ^{
            sharedPlugin = [[SparcklingHelperPlugin alloc] initWithBundle:plugin];
        });
    }
}
@end
