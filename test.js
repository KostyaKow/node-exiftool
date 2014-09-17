var ffi = require('ffi');

var libExif = new ffi.Library('./libnodeexiftool',
      { 'test': ['int', ['string']] });

libExif.test('Hello, Kernel! -node.js');
