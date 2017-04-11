#include <cmark.h>
#include <nan.h>
#include <v8.h>

NAN_METHOD(markdown_to_html)
{
  auto markdown = info[0]->ToString();
  // info.GetReturnValue().Set(Nan::New<v8::String>("test...").ToLocalChecked());
  info.GetReturnValue().Set(markdown);
}

NAN_MODULE_INIT(init)
{
  Nan::Export(target, "markdownToHtml", markdown_to_html);
}

NODE_MODULE(cmark, init)
