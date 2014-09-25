var ffi = require('ffi');

var libExif = new ffi.Library('./libnodeexiftool',
      {  'test':        ['int',     ['string']],
         'get_data':    ['string',  ['string']],
         'system_str':  ['string',  ['string']] });

//libExif.test('Hello, Kernel! -node.js');
//console.log(libExif.system_str('echo "hi"'));
//console.log(libExif.get_data('test.o'));
console.log(libExif.system_str('echo "hi"'))
