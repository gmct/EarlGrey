//
// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

#import "TestLib/Analytics/GREYAnalyticsDelegate.g3only.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Provides methods for tracking EarlGrey usage using Google Analytics.
 *
 *  @remark To opt out of Analytics use XCTestCase::grey_setEnableAnalytics: and set it to @c NO.
 *          Do not make this change in your app's tearDown, since terminating the app before doing
 *          so can cause it to crash. It's recommended to do this in setup right after launching
 *          your app.
 *          Sample code to opt out of analytics:
 *          @code
 *          - (void)setUp {
 *            [super setUp];
 *            // Launch App if not already launched.
 *            [GREYConfiguration.sharedConfiguration setValue:@NO
 *                                               forConfigKey:kGREYConfigKeyAnalyticsEnabled];
 *          }
 *          @endcode
 */
@interface GREYAnalytics : NSObject

/**
 *  @return The singleton instance.
 */
+ (instancetype)sharedAnalytics;

/**
 *  @return The current delegate for custom handling of analytics payload data. To reset
 *          GREYAnalytics to its default behavior, set this to @c nil.
 */
@property(nonatomic, weak) id<GREYAnalyticsDelegate> delegate;

/**
 *  Called when an EarlGrey invocation occurs using any @code [EarlGrey XXX] @endcode statements.
 */
- (void)didInvokeEarlGrey;

@end

NS_ASSUME_NONNULL_END