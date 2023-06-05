const addon = require("bindings")("addon");

console.log(addon);
const o = new addon.Rectangle(2, 3);
const c = new addon.Circle(2);
console.log(o.getArea());
console.log(c.getArea());
