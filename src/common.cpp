#include "common.h"

#include <cmark.h>
#include <core-extensions.h>
#include <parser.h>
#include <registry.h>

void cmark::initialize()
{
  cmark_register_plugin(core_extensions_registration);
}

std::string cmark::markdown_to_html(const std::string& markdown, const int options)
{
  const auto parser = cmark_parser_new(options);

  cmark_parser_feed(parser, markdown.c_str(), markdown.size());
  const auto nodes = cmark_parser_finish(parser);
  const auto html = cmark_render_html(nodes, options, parser->syntax_extensions);

  cmark_node_free(nodes);
  cmark_parser_free(parser);

  return html;
}
