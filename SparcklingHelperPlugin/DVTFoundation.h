@interface DVTDeveloperAccount : NSObject
{
/*    DVTDispatchLock *_lock;
    BOOL _alwaysLogInUsingQA;
    BOOL _enabled;
    DVTDeveloperAccountSession *_session;
    DVTDeveloperAccountCredentials *_accountCredentials;
    NSString *_userDescription;*/
}

+ (id)keyPathsForValuesAffectingUserDescriptionOrBestGuess;
+ (id)keyPathsForValuesAffectingHasPassword;
+ (id)keyPathsForValuesAffectingPassword;
+ (id)accountWithPropertyListRepresentation:(id)arg1 keychain:(struct OpaqueSecKeychainRef *)arg2 error:(id *)arg3;
+ (id)accountWithIdentity:(struct OpaqueSecIdentityRef *)arg1;
+ (id)accountWithCredentials:(id)arg1;
@property BOOL enabled; // @synthesize enabled=_enabled;
@property BOOL alwaysLogInUsingQA; // @synthesize alwaysLogInUsingQA=_alwaysLogInUsingQA;
@property(copy, nonatomic) NSString *userDescription; // @synthesize userDescription=_userDescription;
//@property(copy) DVTDeveloperAccountCredentials *accountCredentials; // @synthesize accountCredentials=_accountCredentials;
@property(readonly) NSDictionary *propertyListRepresentation;
@property(readonly) NSString *userDescriptionOrBestGuess;
@property(readonly) BOOL hasPassword;
@property(copy) NSString *password;
@property(readonly) _Bool isCertBased;
- (BOOL)isEqual:(id)arg1;
- (unsigned long long)hash;
@property(readonly, copy) NSString *username;
- (void)revokeSession:(id)arg1;
- (id)sessionIfAvailable;
- (id)sessionByLoggingInIfNeeded:(id *)arg1;
- (id)_sessionByLoggingIn:(id *)arg1;
- (id)init;
@end



@protocol DVTDeveloperProfileAccountProvider <NSObject>
@property(readonly) NSString *typeIdentifier;
- (BOOL)importAccountsFromKeychain:(struct OpaqueSecKeychainRef *)arg1 propertyList:(NSDictionary *)arg2 numberOfAccounts:(unsigned long long *)arg3 error:(id *)arg4;
- (BOOL)exportAccountsToKeychain:(struct OpaqueSecKeychainRef *)arg1 propertyList:(id *)arg2 numberOfAccounts:(unsigned long long *)arg3 error:(id *)arg4;
@end

@interface DVTDeveloperAccountManager : NSObject <DVTDeveloperProfileAccountProvider>
{}

+ (id)sharedAccountManager;
@property(retain, nonatomic) DVTDeveloperAccount *defaultAccount; // @synthesize defaultAccount=_defaultAccount;
@property(readonly) NSString *typeIdentifier;
- (BOOL)importAccountsFromKeychain:(struct OpaqueSecKeychainRef *)arg1 propertyList:(id)arg2 numberOfAccounts:(unsigned long long *)arg3 error:(id *)arg4;
- (BOOL)exportAccountsToKeychain:(struct OpaqueSecKeychainRef *)arg1 propertyList:(id *)arg2 numberOfAccounts:(unsigned long long *)arg3 error:(id *)arg4;
- (void)removeAccountsObject:(id)arg1;
- (void)addAccountsObject:(id)arg1;
@property(readonly, nonatomic) NSOrderedSet *accounts;
- (id)_mutableAccounts;
- (void)updateUserDefaults;
- (id)_accountsByCreatingFromDefaults;
- (id)_accountsByCreatingFromKeychain;
- (_Bool)hasAccountWithUsername:(id)arg1;
- (id)accountWithUsername:(id)arg1;
@end

@interface DVTSigningCertificateManager : NSObject
{
/*    DVTDispatchLock *_certificateLock;
    NSMutableSet *_signingCertificates;
    NSMutableSet *_signingIdentityCertificates;
    DVTSigningCertificateSource *_certificateSource;*/
}

+ (id)defaultCertificateManager;
+ (void)initialize;
- (void)_delayedPostCertificatesChangedNotification;
- (void)forceFullSync;
- (void)signingCertificateSourceShouldDoFullResetFromSigningCertificates:(id)arg1;
- (void)signingCertificateSourcePrivateKeyStatusForCertificatesMayHaveChanged:(id)arg1;
- (void)signingCertificateSource:(id)arg1 didRemoveCertificate:(id)arg2;
- (void)signingCertificateSource:(id)arg1 didAddCertificate:(id)arg2;
@property(readonly) NSSet *signingIdentityCertificates;
@property(readonly) NSSet *signingCertificates;
- (id)logAspect;
@property(readonly, copy) NSString *description;
- (void)primitiveInvalidate;
- (id)initWithCertificateSource:(id)arg1;
- (id)init;

@end

@interface DVTSigningCertificate : NSObject
{
}

+ (id)keychainSearchList;
@property(readonly) id underlyingType; // @synthesize underlyingType=_underlyingType;
@property(readonly) NSString *portalTeamName; // @synthesize portalTeamName=_portalTeamName;
- (id)_valueInSubjectNameSectionFromCertificate:(struct OpaqueSecCertificateRef *)arg1 forOID:(id)arg2;
- (id)_dateFromCertificate:(struct OpaqueSecCertificateRef *)arg1 forOID:(id)arg2;
- (id)certificateData;
- (id)defaultDesignatedRequirementsForIdentifier:(id)arg1;
@property(readonly) NSString *serialNumber; // @synthesize serialNumber=_serialNumber;
@property(readonly) NSString *sha1Hash; // @synthesize sha1Hash=_sha1Hash;
@property(readonly, getter=isForServer) BOOL forServer;
@property(readonly, getter=isTrusted) BOOL trusted;
@property(readonly, getter=isExpired) BOOL expired;
@property(readonly) NSDate *expirationDate; // @synthesize expirationDate=_expirationDate;
@property(readonly) NSDate *issueDate; // @synthesize issueDate=_issueDate;
@property(readonly, getter=isIdentity) BOOL identity;
@property(readonly) NSString *portalMemberID; // @synthesize portalMemberID=_portalMemberID;
- (id)portalTeamName:(struct OpaqueSecCertificateRef *)arg1;
@property(readonly) NSString *portalTeamID; // @synthesize portalTeamID=_portalTeamID;
- (BOOL)isFromPortal;
@property(readonly) NSString *commonName; // @synthesize commonName=_commonName;
@property(readonly) NSString *trimmedName; // @synthesize trimmedName=_trimmedName;
@property(readonly) NSString *certificateKind; // @synthesize certificateKind=_certificateKind;
- (long long)compare:(id)arg1;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (struct OpaqueSecCertificateRef *)certificateRef;
- (id)description;
- (id)initWithUnderlyingType:(id)arg1 logAspect:(id)arg2;

@end


@interface DVTDeviceManager : NSObject
{
}

+ (id)defaultDeviceManager;
+ (void)initialize;
- (id)deviceLocatorForDeviceType:(id)arg1;
- (id)searchForDevicesWithType:(id)arg1 options:(id)arg2 timeout:(double)arg3 error:(id *)arg4;
- (id)searchForDeviceWithType:(id)arg1 options:(id)arg2 genericOnly:(BOOL)arg3 timeout:(double)arg4 error:(id *)arg5;
- (id)_searchForDevicesWithType:(id)arg1 options:(id)arg2 genericOnly:(BOOL)arg3 allowMultiple:(BOOL)arg4 timeout:(double)arg5 error:(id *)arg6;
- (id)_waitForDeviceUsingLocatorsToOptions:(id)arg1 genericOnly:(BOOL)arg2 allowMultiple:(BOOL)arg3 timeout:(double)arg4 error:(id *)arg5;
- (id)_lookUpAvailableDevicesUsingLocatorsToOptions:(id)arg1 genericOnly:(BOOL)arg2 allowMultiple:(BOOL)arg3 error:(id *)arg4;
- (id)_deviceLocatorForDeviceSpecifierPrefix:(id)arg1 error:(id *)arg2;
- (BOOL)locateOnlyLocalComputerWithError:(id *)arg1;
- (void)locateOnlyLocalComputer;
- (void)stopLocating;
- (BOOL)startLocatingWithError:(id *)arg1;
- (void)startLocating;
- (void)_adjustAvailableDevicesForChangeKind:(unsigned long long)arg1 addedObjects:(id)arg2 removedObjects:(id)arg3;
- (void)_stopObservingDevice:(id)arg1;
- (void)_startObservingDevice:(id)arg1;
- (id)_discoverDeviceLocators;
- (id)deviceAtDeviceLocation:(id)arg1;
- (id)_deviceLocatorForDeviceLocationScheme:(id)arg1;
- (id)devicesMatchingPredicate:(id)arg1;
- (id)init;

// Remaining properties
@property(copy) NSSet *availableDevices; // @dynamic availableDevices;
@property(readonly, copy) NSMutableSet *mutableAvailableDevices; // @dynamic mutableAvailableDevices;

@end

@interface DVTCodesignableDeviceSnapshot : NSObject
{
    BOOL _supportsProvisioning;
    NSString *_name;
    NSString *_nameForDeveloperPortal;
    NSString *_identifier;
    NSString *_platformIdentifier;
    NSSet *_proxiedDevices;
}

+ (id)snapshotFromCodesignableDevice:(id)arg1;
@property(copy) NSSet *proxiedDevices; // @synthesize proxiedDevices=_proxiedDevices;
@property BOOL supportsProvisioning; // @synthesize supportsProvisioning=_supportsProvisioning;
@property(copy) NSString *platformIdentifier; // @synthesize platformIdentifier=_platformIdentifier;
@property(copy) NSString *identifier; // @synthesize identifier=_identifier;
@property(copy) NSString *nameForDeveloperPortal; // @synthesize nameForDeveloperPortal=_nameForDeveloperPortal;
@property(copy) NSString *name; // @synthesize name=_name;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface DVTAppIDFeatures : NSObject <NSCopying>
{
    NSDictionary *_flags;
    NSSet *_cloudContainers;
    NSSet *_applicationGroups;
    NSSet *_omcIdentifiers;
}

+ (id)paymentPassAccessEntitlement;
+ (id)inAppPaymentsEntitlement;
+ (id)userNameForFlag:(id)arg1;
@property(readonly) NSSet *omcIdentifiers; // @synthesize omcIdentifiers=_omcIdentifiers;
@property(readonly) NSSet *applicationGroups; // @synthesize applicationGroups=_applicationGroups;
@property(readonly) NSSet *cloudContainers; // @synthesize cloudContainers=_cloudContainers;
@property(readonly) NSDictionary *flags; // @synthesize flags=_flags;
- (BOOL)allowsFeatures:(id)arg1 missingFeatures:(id *)arg2;
@property(readonly) NSString *userDescription;
- (id)description;
- (id)plistRepresentation;
- (id)copyWithZone:(struct _NSZone *)arg1;
@property(readonly) BOOL requiresExplicitAppID;
@property(readonly) DVTAppIDFeatures *enabledFeatures;
- (id)featuresBySettingValue:(id)arg1 forKey:(id)arg2;
- (BOOL)isEqual:(id)arg1;
- (id)initWithFlags:(id)arg1 cloudContainers:(id)arg2 applicationGroups:(id)arg3 omcIdentifiers:(id)arg4;
- (id)init;

@end

@interface DVTLogAspect : NSObject
{
    NSString *_name;
    BOOL _signalInstruments;
    BOOL _takeTimeProfile;
    int _logLevel;
    NSArray *_activeLoggers;
}

+ (id)logAspectWithName:(id)arg1;
+ (id)allAspects;
+ (int)defaultLogLevel;
+ (void)initialize;
@property(copy) NSArray *activeLoggers; // @synthesize activeLoggers=_activeLoggers;
@property BOOL takeTimeProfile; // @synthesize takeTimeProfile=_takeTimeProfile;
@property BOOL signalInstruments; // @synthesize signalInstruments=_signalInstruments;
@property int logLevel; // @synthesize logLevel=_logLevel;
@property(readonly) NSString *name; // @synthesize name=_name;
- (id)description;
- (void)_logAndOutdentAtLogLevel:(int)arg1 withFormat:(id)arg2;
- (void)_logAndIndentAtLogLevel:(int)arg1 withFormat:(id)arg2;
- (void)_logAtLogLevel:(int)arg1 withFormat:(id)arg2;
- (id)initWithName:(id)arg1 logLevel:(int)arg2 signalInstruments:(BOOL)arg3 takeTimeProfile:(BOOL)arg4 activeLoggers:(id)arg5;
- (id)init;

@end


