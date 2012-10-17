

#import <Foundation/Foundation.h>


@interface DataMatrix : NSObject

@property (readonly,nonatomic) NSInteger dimension;

- (id)initWith:(NSInteger)dimension;
- (NSInteger)dimension;
- (void)set:(BOOL)value x:(NSInteger)x y:(NSInteger)y;
- (BOOL)valueAt:(NSInteger)x y:(NSInteger)y;

@end
