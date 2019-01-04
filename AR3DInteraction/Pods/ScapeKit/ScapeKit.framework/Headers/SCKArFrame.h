// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ar.djinni

#import "SCKArAnchor.h"
#import "SCKArCamera.h"
#import "SCKArLight.h"
#import "SCKArPointCloud.h"
#import <Foundation/Foundation.h>
@protocol SCKVideoFrame;

/** public data object */
@interface SCKArFrame : NSObject
- (nonnull instancetype)initWithVideoFrame:(nullable id<SCKVideoFrame>)videoFrame
                                    camera:(nonnull SCKArCamera *)camera
                             lightEstimate:(nonnull SCKArLight *)lightEstimate
                                   anchors:(nonnull NSArray<SCKArAnchor *> *)anchors
                          rawFeaturePoints:(nonnull SCKArPointCloud *)rawFeaturePoints;
+ (nonnull instancetype)arFrameWithVideoFrame:(nullable id<SCKVideoFrame>)videoFrame
                                       camera:(nonnull SCKArCamera *)camera
                                lightEstimate:(nonnull SCKArLight *)lightEstimate
                                      anchors:(nonnull NSArray<SCKArAnchor *> *)anchors
                             rawFeaturePoints:(nonnull SCKArPointCloud *)rawFeaturePoints;

@property (nonatomic, readonly, nullable) id<SCKVideoFrame> videoFrame;

@property (nonatomic, readonly, nonnull) SCKArCamera * camera;

@property (nonatomic, readonly, nonnull) SCKArLight * lightEstimate;

@property (nonatomic, readonly, nonnull) NSArray<SCKArAnchor *> * anchors;

@property (nonatomic, readonly, nonnull) SCKArPointCloud * rawFeaturePoints;

@end