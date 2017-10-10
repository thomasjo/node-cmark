#include "sync.h"

#include <cmark.h>
#include <core-extensions.h>
#include <nan.h>
#include <v8.h>

#include "common.h"

NAN_METHOD(cmark::render_html_sync)
{
  if (!info[0]->IsString()) {
    Nan::ThrowTypeError("Expected argument 1 to be of type String.");
    return;
  }

  const auto markdown = *Nan::Utf8String(info[0]->ToString());
  const auto html = cmark::markdown_to_html(markdown, 0);

  auto return_value = info.GetReturnValue();
  return_value.Set(Nan::New(html).ToLocalChecked());
}
