// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from location.djinni

#import <Foundation/Foundation.h>

/**
 * (public)
 * Representing geolocation coordinates
 */
@interface SCKCoordinates : NSObject
- (nonnull instancetype)initWithLatitude:(double)latitude
                               longitude:(double)longitude;
+ (nonnull instancetype)coordinatesWithLatitude:(double)latitude
                                      longitude:(double)longitude;

@property (nonatomic, readonly) double latitude;

@property (nonatomic, readonly) double longitude;

@end
