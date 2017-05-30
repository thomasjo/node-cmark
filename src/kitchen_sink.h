#pragma once

#include <string>
#include <nan.h>
#include <v8.h>

inline std::string convert_to_string(const v8::Local<v8::Value>& value)
{
  const Nan::Utf8String utf8_string(value.As<v8::String>());
  return *utf8_string;
}

inline v8::Local<v8::Value> convert_to_value(const std::string& string)
{
  return Nan::New(string).ToLocalChecked();
}

inline void set_return_value(const Nan::FunctionCallbackInfo<v8::Value>& info, const v8::Local<v8::Value>& value)
{
  auto return_value = info.GetReturnValue();
  return_value.Set(value);
}
