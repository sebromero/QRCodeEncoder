//
//  AppDelegate.h
//  QRCodeEncoderExample
//
//  Created by Sebastian Hunkeler on 17.10.12.
//  Copyright (c) 2012 Institut für Software, HSR. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;
@property (weak) IBOutlet NSImageView *imageView;
@property (weak) IBOutlet NSTextField *dataTextField;

- (IBAction)generateQRCode:(id)sender;

@end
