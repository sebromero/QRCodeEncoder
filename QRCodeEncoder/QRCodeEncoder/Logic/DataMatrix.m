

#import "DataMatrix.h"


@implementation DataMatrix
{
    NSInteger _dimension;
    BOOL** _data;
}

@synthesize dimension = _dimension;

- (id)initWith:(NSInteger)dimension
{
    self = [super init];
    if (self) {
        _dimension = dimension;
        _data = (BOOL**) malloc(sizeof(BOOL*) * _dimension);
        for (int y=0; y <_dimension; ++y) {
            _data[y] = (BOOL*)malloc(sizeof(BOOL) * _dimension);
        }
    }
    return self;
}

- (void)set:(BOOL)value x:(NSInteger)x y:(NSInteger)y {
    _data[y][x] = value;
}

- (BOOL)valueAt:(NSInteger)x y:(NSInteger)y {
    return _data[y][x];
}

- (NSString*)description {
    NSMutableString* description = [NSMutableString stringWithCapacity:self.dimension * self.dimension];
    for (NSUInteger y=0; y<self.dimension; y++) {
        for (NSUInteger x=0; x<self.dimension; x++) {
            [description appendFormat:@"%d", [self valueAt:x y:y]];
        }
        [description appendString:@"\n"];
    }
    return description;
}

- (void)dealloc {
    for (NSUInteger y=0; y < self.dimension; ++y) {
        free(_data[y]);
    }
    free(_data);
}

@end
