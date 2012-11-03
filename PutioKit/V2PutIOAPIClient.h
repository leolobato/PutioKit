//
//  V2PutIOClient.h
//  Puttio
//
//  Created by orta therox on 24/03/2012.
//  Copyright (c) 2012 ortatherox.com. All rights reserved.
//

#import "PutioKit.h"
#import "AFNetworking.h"

@interface V2PutIOAPIClient : AFHTTPClient

+ (id)setup;
- (BOOL)ready;

@property NSString *apiToken;

- (void)getAccount:(void(^)(PKAccount *account))onComplete failure:(void (^)(NSError *))failure;

- (void)getFolderItems:(PKFolder *)folder :(void(^)(NSArray *filesAndFolders))onComplete failure:(void (^)(NSError *))failure;
- (void)getAdditionalInfoForFile:(PKFile *)file :(void(^)())onComplete failure:(void (^)(NSError *error))failure;
- (void)getMP4InfoForFile:(PKFile *)file :(void(^)(PKMP4Status *status))onComplete failure:(void (^)(NSError *error))failure;

- (void)getTransfers:(void(^)(NSArray *transfers))onComplete failure:(void (^)(NSError *error))failure;

- (void)requestDeletionForDisplayItem:(NSObject <PKFolderItem> *)item :(void(^)(id userInfoObject))onComplete failure:(void (^)(NSError *error))failure;

- (void)requestMP4ForFile:(PKFile *)file failure:(void (^)(NSError *error))failure;

- (void)requestTorrentOrMagnetURLAtPath:(NSString *)path :(void(^)(id userInfoObject))onComplete failure:(void (^)(NSError *error))failure;

@end