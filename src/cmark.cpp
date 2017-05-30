#include <cmark.h>
#include <nan.h>

#include "common.h"
#include "kitchen_sink.h"
#include "sync.h"

NAN_METHOD(get_libcmark_version)
{
  set_return_value(info, convert_to_value(cmark::version));
}

NAN_MODULE_INIT(init)
{
  cmark::initialize();

  Nan::Export(target, "toHtml", cmark::render_html);
  Nan::Export(target, "getLibraryVersion", get_libcmark_version);

  Nan::Set(target, convert_to_value("version"), convert_to_value(cmark::version));
}

NODE_MODULE(cmark, init)
