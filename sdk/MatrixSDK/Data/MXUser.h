/*
 Copyright 2014 OpenMarket Ltd
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "MXJSONModels.h"

@class MXEvent;

/**
 `MXUser` represents a user in Matrix.
 */
@interface MXUser : NSObject

/**
 The user id.
 */
@property (nonatomic, readonly) NSString *userId;

/**
 The user display name.
 */
@property (nonatomic, readonly) NSString *displayname;

/**
 The url of the user of the avatar.
 */
@property (nonatomic, readonly) NSString *avatarUrl;

/**
 The presence status.
 */
@property (nonatomic, readonly) MXPresence presence;

/**
 The time since the last activity by the user.
 This value in milliseconds is recomputed at each property reading.
 */
@property (nonatomic, readonly) NSUInteger lastActiveAgo;

/**
 Create an instance for an user ID.
 
 @param userId The id to the user.
 
 @return the newly created MXUser instance.
 */
- (instancetype)initWithUserId:(NSString*)userId;

/**
 Update the MXUser data with a m.room.member event.
 
 @param roomMemberEvent The event.
 */
- (void)updateWithRoomMemberEvent:(MXEvent*)roomMemberEvent;


/**
 Update the MXUser data with a m.presence event.
 
 @param roomMemberEvent The event.
 */
- (void)updateWithPresenceEvent:(MXEvent*)presenceEvent;

@end