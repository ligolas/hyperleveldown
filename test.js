var addon = require('./build/Release/put');

var fn = addon();
console.log(fn()); // 'hello world'