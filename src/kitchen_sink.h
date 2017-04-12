#pragma once

inline std::string convert_to_string(const v8::Local<v8::Value>& value)
{
  return *v8::String::Utf8Value(value.As<v8::String>());
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
