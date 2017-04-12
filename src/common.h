#pragma once

#include <nan.h>
#include <v8.h>

namespace cmark {

void initialize();
std::string markdown_to_html(const std::string& markdown, const int options);

}  // namespace cmark
