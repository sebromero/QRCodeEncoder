Pod::Spec.new do |s|
  s.name     = 'QRCodeEncoder'
  s.version  = '1.0.0'
  s.license  = 'MIT'
  s.summary  = 'QRCode encoder for OS X'
  s.homepage = 'https://github.com/lightforce/QRCodeEncoder'
  s.authors  = { 'Sebastian Hunkeler' => 'hunkeler.sebastian@gmail.com' }
  s.source   = { :git => 'https://github.com/lightforce/QRCodeEncoder.git', :tag => "1.0.0" }
  s.requires_arc = true

  s.osx.deployment_target = '10.7'
  s.public_header_files = 'QRCodeEncoder/Headers/QRCodeEncoder.h', 'QRCodeEncoder/Logic/*.h'
  s.source_files = 'QRCodeEncoder/Logic/*.{h,m}'
  s.frameworks = 'Cocoa'
end