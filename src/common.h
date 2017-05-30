#pragma once

#include <string>
#include <cmark_version.h>
#include <nan.h>
#include <v8.h>

namespace cmark {

static const std::string version = CMARK_VERSION_STRING;

void initialize();
std::string markdown_to_html(const std::string& markdown, const int options);

}  // namespace cmark
