//
//  SparcklingHelperPlugin.m
//  SparcklingHelperPlugin
//
//  Created by mzp on 7/13/15.
//  Copyright © 2015 mzp. All rights reserved.
//

#import "SparcklingHelperPlugin.h"
#import "IDEKit.h"
#import "DVTFoundation.h"

@interface SparcklingHelperPlugin()

@property (nonatomic, strong, readwrite) NSBundle *bundle;
@end

@implementation SparcklingHelperPlugin

+ (instancetype)sharedPlugin
{
    return sharedPlugin;
}

- (id)initWithBundle:(NSBundle *)plugin
{
    if (self = [super init]) {
        self.bundle = plugin;

        id dm = [DVTDeviceManager defaultDeviceManager];
        [dm addObserver:self forKeyPath:@"availableDevices" options:NSKeyValueObservingOptionNew context:nil];    
    }
    return self;
}

- (DVTDeveloperAccount*)getAccount {
    id am =  [DVTDeveloperAccountManager sharedAccountManager];
    for (id account in [am accounts]) {
        if([[account username] isEqual:@"mzpppp+free@gmail.com"]) {
            return account;
        }
    }
    return nil;
}

- (DVTSigningCertificate*) getCertificate {
    id cm = [DVTSigningCertificateManager defaultCertificateManager];
    for (id c in [cm signingCertificates]) {
        if( [[c commonName] isEqual:@"iPhone Developer: mzpppp+free@gmail.com (78KR9QS4P3)"]) {
            return c;
        }
    }
    return nil;
}

- (id) getDevice {
    id dm = [DVTDeviceManager defaultDeviceManager];
    for (id d in [dm availableDevices]) {
        if([[d name] isEqual: @"mzpPhone"]) {
            return [DVTCodesignableDeviceSnapshot snapshotFromCodesignableDevice:d];
        }
    }
    return nil;
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    id device = [self getDevice];

    if(device != nil) {
        id account = [self getAccount];
        id certificate = [self getCertificate];
        id aspect = [DVTLogAspect logAspectWithName: @"sparckling"];

        NSLog(@"--------");
        NSLog(@"%@", account);
        NSLog(@"%@", certificate);
        NSLog(@"%@", device);

        [[IDECodesignIssueResolutionPortalSource defaultPortalSource]
         requestDevelopmentProvisioningProfileForAccount:account
         signingCertificate:certificate
         platformIdentifier:@"com.apple.platform.watchos"
         bundleIdentifiers:[NSSet setWithObject:@"jp.mzp.ios-app-sample-test5"]
         requiredCodesignableDevices: [NSSet setWithObject: device]
         requiredFeatures: [[DVTAppIDFeatures alloc] init]
         logAspect:aspect];
    }
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
