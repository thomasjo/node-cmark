const cmark = require("bindings")("cmark.node")

console.log(cmark.markdownToHtml("test123"))
