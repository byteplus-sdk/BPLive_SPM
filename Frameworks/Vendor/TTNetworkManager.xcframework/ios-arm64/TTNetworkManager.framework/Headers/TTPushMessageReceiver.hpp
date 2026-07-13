//
//  TTPushMessageReceiver.h
//  TTPushManager
//
//  The TTNetworkManager is licensed under the MIT License.
//  Copyright (c) 2023 Bytedance Inc.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
#include <string>
#include <memory>
#include <map>

@interface TTPushMessageReceiver : NSObject

// return < 0 means unknown message
- (int32_t)dispatch:(const int32_t)service
             method:(const int32_t)method
    payloadEncoding:(const std::string &)payloadEncoding
        payloadType:(const std::string &)payloadType
            payload:(const std::string &)payload
              seqid:(const uint64_t)seqid
              logid:(const uint64_t)logid
            headers:(std::shared_ptr<std::map<std::string, std::string> >)headers;
@end
#endif
