//
//  SparcklingHelperPlugin.h
//  SparcklingHelperPlugin
//
//  Created by mzp on 7/13/15.
//  Copyright © 2015 mzp. All rights reserved.
//

#import <AppKit/AppKit.h>

@class SparcklingHelperPlugin;

static SparcklingHelperPlugin *sharedPlugin;

@interface SparcklingHelperPlugin : NSObject

+ (instancetype)sharedPlugin;
- (id)initWithBundle:(NSBundle *)plugin;

@property (nonatomic, strong, readonly) NSBundle* bundle;
@end