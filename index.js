const cmark = require("bindings")("cmark.node")

module.exports = cmark

// NOTE: Silly stuff to make manual testing more convenient during early development...
if (process.argv.length > 2) {
  const args = process.argv.slice(2)
  console.log(cmark.toHtml(args[0]))
}
