const addon = require("./build/Release/qrcode_scanner");

const text = addon.scanImage();

console.log(text);