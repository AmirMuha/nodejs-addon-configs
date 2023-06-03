const addon = require("bindings")("addon");

const returnValue = addon.HelloWorld(123, 456);
console.log("=--------RETURN VALUE : ", returnValue);
