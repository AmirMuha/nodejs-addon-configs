#include <cstdint>
#include <iostream>
#include <napi/napi.h>

class Rectangle : public Napi::ObjectWrap<Rectangle> {
protected:
  uint32_t width;
  uint32_t height;
public:
  Rectangle(const Napi::CallbackInfo &info);
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Napi::Value GetArea(const Napi::CallbackInfo &info);
};

class Circle : public Napi::ObjectWrap<Circle> {
protected:
  float ratio;
public:
  Circle(const Napi::CallbackInfo &info);
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Napi::Value GetArea(const Napi::CallbackInfo &info);
};

Circle::Circle(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Circle>(info) {
  Napi::Env env = info.Env();
  Napi::Number r = info[0].As<Napi::Number>();
  Circle::ratio = r;
  Napi::HandleScope scope(env);
};

Rectangle::Rectangle(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Rectangle>(info) {
  Napi::Env env = info.Env();
  uint32_t w = info[0].As<Napi::Number>().Int32Value();
  uint32_t h = info[1].As<Napi::Number>().Int32Value();
  Rectangle::width = w;
  Rectangle::height = h;
  Napi::HandleScope scope(env);
};

Napi::Value Circle::GetArea(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  return Napi::Number::New(env, 3.1415 * Circle::ratio * Circle::ratio);
}

Napi::Value Rectangle::GetArea(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  return Napi::Number::New(env, Rectangle::width * Rectangle::height);
}

Napi::Object Circle::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = DefineClass(
      env, "Circle", {InstanceMethod("getArea", &Circle::GetArea)});
  Napi::FunctionReference *constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  exports.Set("Circle", func);
  return exports;
};

Napi::Object Rectangle::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = DefineClass(
      env, "Rectangle", {InstanceMethod("getArea", &Rectangle::GetArea)});
  Napi::FunctionReference *constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  exports.Set("Rectangle", func);
  return exports;
};

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Rectangle::Init(env, exports);
  Circle::Init(env, exports);
  return exports;
}

NODE_API_MODULE(addon, Init)
