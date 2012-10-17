//
//  AppDelegate.m
//  QRCodeEncoderExample
//
//  Created by Sebastian Hunkeler on 17.10.12.
//  Copyright (c) 2012 Institut für Software, HSR. All rights reserved.
//

#import "AppDelegate.h"
#import <QRCodeEncoder/QRCodeEncoder.h>

#define QR_CODE_IMAGE_DIMENSION 350

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    [self.dataTextField setStringValue:@"Hello World!"];
    [self generateQRCode:self];
}

- (IBAction)generateQRCode:(id)sender
{
    NSString* content = self.dataTextField.stringValue;
    //first encode the string into a matrix of bools, TRUE for black dot and FALSE for white. Let the encoder decide the error correction level and version
    DataMatrix* qrMatrix = [QREncoder encodeWithECLevel:QR_ECLEVEL_AUTO version:QR_VERSION_AUTO string:content];
    self.imageView.image = [QREncoder renderDataMatrix:qrMatrix imageDimension:QR_CODE_IMAGE_DIMENSION];
}
@end
