#include <cmark.h>
#include <nan.h>

#include "common.h"
#include "sync.h"

NAN_MODULE_INIT(init)
{
  cmark::initialize();
  Nan::Export(target, "toHtml", cmark::render_html);
}

NODE_MODULE(cmark, init)
