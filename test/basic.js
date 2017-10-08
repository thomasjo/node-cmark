const { describe, it } = require('tap').mocha
const { expect } = require('chai')

const cmark = require('..')

describe('Rendering', () => {
  it('throws an error when the first argument is missing', () => {
    expect(() => cmark.toHtml()).to.throw(Error)
  })

  it('throws an error when the first argument is missing', () => {
    expect(() => cmark.toHtml(undefined)).to.throw(TypeError)
  })

  it('throws an error when the first argument is a null reference', () => {
    expect(() => cmark.toHtml(null)).to.throw(TypeError)
  })

  it('returns HTML for the given markdown', () => {
    const markdown = 'foo [bar]()'
    const expected = '<p>foo <a href="">bar</a></p>\n'

    const result = cmark.toHtml(markdown)
    expect(result).to.equal(expected)
  })
})
